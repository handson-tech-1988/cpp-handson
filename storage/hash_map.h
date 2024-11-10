//
//

#ifndef CPP_HANDS_HASH_MAP_H
#define CPP_HANDS_HASH_MAP_H

#include <cstdint>
#include <bitset>

template<typename Key, typename Value>
struct Node {
    int64_t hash{0};
    Key key;
    Value value;
    Node *next = nullptr;
};

template<typename Key, typename Value, typename Hasher>
class HashMap {
private:
    typedef Node<Key, Value> node_type;
private:
    uint32_t bucket_size;
    node_type **buckets; // node_type*[]
    Hasher hasher;
public:
    HashMap(uint32_t bucket_size) {
        this->bucket_size = bucket_size;
        this->buckets = new Node<Key, Value>*[bucket_size];
    }

    ~HashMap() {
        if (buckets != nullptr) {
            for (int i = 0; i < this->bucket_size; i++) {
                node_type *tmp = buckets[i];
                if (tmp != nullptr) {
                    delete tmp;
                    buckets[i] = nullptr;
                }
            }
            delete[] buckets;
        }
    }

public:
    void Insert(const Key &key, const Value &value) {
        int64_t hash = hasher(key);
        Node<Key, Value> *tmp = Find(key, hash);
        if (tmp != nullptr) {
            *tmp->value = value;
        } else {
            tmp = new Node<Key, Value>();
            tmp->hash = hash;
            tmp->key = key;
            tmp->value = value;
            Node<Key, Value> **bucket = &this->buckets[hash % bucket_size];
            if (*bucket == nullptr) {
                *bucket = tmp;
            } else {
                tmp->next = *bucket;
                *bucket = tmp;
            }
        }
    }

    node_type *Find(const Key &key, int64_t hash) {
        node_type *bucket = this->buckets[hash % bucket_size];
        node_type *head = bucket;
        while (head != nullptr) {
            if (head->hash == hash && head->key == key) {
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
};

int main() {
    std::hash<std::string> hasher;
    HashMap<std::string, std::string, std::hash<std::string>> hash_map(1000);
}



#endif //CPP_HANDS_HASH_MAP_H
