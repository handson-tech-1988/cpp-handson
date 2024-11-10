//
//

#include <iostream>

struct Node {
    int val_ = 0;
    Node* next_ = nullptr;
    static Node* newNode(int val) {
        Node* n = new Node();
        n->val_ = val;
        return n;
    }
    void Print() {
        std::cout << val_ << std::endl;
        if (this->next_ != nullptr) {
            this->next_->Print();
        }
    }
};

struct Solution {
    static Node* reverse(Node* list, int k) {
        Node* totalHead = Node::newNode(-1);
        Node* totalTail = totalHead;

        Node* segHead = nullptr;
        Node* segTail = nullptr;
        Node* cur = list;
        while (cur != nullptr) {
            for (int i = 1; i <= k && cur != nullptr; i++) {
                Node* tmp = cur->next_;
                cur->next_ = segHead;
                segHead = cur;
                if (segTail == nullptr) {
                    segTail = segHead;
                }
                cur = tmp;
            }
            if (cur == nullptr) {
                totalTail->next_ = segHead;
                break;
            } else {
                totalTail->next_ = segHead;
                totalTail = segTail;
                segHead = nullptr;
                segTail = nullptr;
            }
        }

        Node* result = totalHead->next_;
        delete totalHead;
        return result;
    }
};

int main(int argc, char* argv[]) {
    Node* n1 = Node::newNode(1);
    Node* n2 = Node::newNode(2);
    Node* n3 = Node::newNode(3);
    Node* n4 = Node::newNode(4);
    Node* n5 = Node::newNode(5);

    n1->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n4;
    n4->next_ = n5;

    Node* result = Solution::reverse(n1,3);

    result->Print();

}