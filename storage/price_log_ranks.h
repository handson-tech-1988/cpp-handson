//
//

#ifndef CPP_HANDS_PRICE_LOG_RANKS_H
#define CPP_HANDS_PRICE_LOG_RANKS_H

#include <unordered_map>

class StockPrice {
    int latest_ts;
    struct Node {
        int price;
        Node* prev;
        Node* next;
    };
    Node head;
    std::unordered_map<int, Node*> map;
private:
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }
    /**
     *
     * @param node
     * @param begin [begin, end]插在中间
     * @param end
     */
    void insert(Node* node, Node* begin, Node* end) {
        Node* prev = begin;
        Node* cur = begin->next;
        if (begin == end) { // empty
            node->next = &head;
            node->prev = &head;
            head.prev = node;
            head.next = node;
        } else {
            while (cur != end && cur->price > node->price) {
                prev = cur;
                cur = cur->next;
            }
            node->next = cur;
            node->prev = prev;
            prev->next = node;
            cur->prev = node;
        }
    }
public:
    void update(int timestamp, int price) {
        this->latest_ts = max(this->latest_ts, timestamp);
        auto found = this->map.find(timestamp);
        if (found != this->map.end()) {
            if (found->second->price == price) {
                return;
            }
            Node* end = found->second->next;
            this->remove(found->second);
            this->insert(found->second, &head, end);
        } else {
            this->insert(found->second, &head, &head);
        }
    }
    int current() const {
        return this->map.find(latest_ts)->second->price;
    }
    int min_price() const {
        return head.prev->price;
    }
    int max_price() const {
        return head.next->price;
    }
};


#endif //CPP_HANDS_PRICE_LOG_RANKS_H
