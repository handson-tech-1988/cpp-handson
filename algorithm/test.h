//
//

#ifndef CPP_HANDS_TEST_H
#define CPP_HANDS_TEST_H

#include <unordered_map>


struct Node {
    int value;
    Node* next;
};

class Test {
public:
    Node* addSum(Node* a, Node* b) {
        if (a == nullptr || b == nullptr) {
            return nullptr;
        }

        a = reverse(a);
        b = reverse(b);

        Node* sumHead = new Node();
        sum->value = -1;
        Node* sumTail = sumHead;

        int promt = 0;
        while (a != nullptr && b != nullptr) {
            int sum = a->value + b->value + promt;
            if (sum > 10) {
                sum = sum - 10;
                promt = 1;
            } else {
                promt = 0;
            }
            Node* newNode = new Node();
            newNode->value = sum;
            newNode->next = sumHead->next;
            sumHead->next = newNode;

            a = a->next;
            b = b->next;
        }

        while(a != nullptr) {
            int sum = a->value + promt;
            if (sum > 10) {
                sum = sum - 10;
                promt = 1;
            } else {
                promt = 0;
            }
            Node* newNode = new Node();
            newNode->value = sum;
            newNode->next = sumHead->next;
            sumHead->next = newNode;

            a = a->next;
        }

        while(b != nullptr) {
            int sum = b->value + promt;
            if (sum > 10) {
                sum = sum - 10;
                promt = 1;
            } else {
                promt = 0;
            }
            Node* newNode = new Node();
            newNode->value = sum;
            sumTail->next = newNode;
            sumTail = newNode;

            b = b->next;
        }

        if (promt != 0) {
            Node* newNode = new Node();
            newNode->value = promt;
            newNode->next = sumHead->next;
            sumHead->next = newNode;
        }
        // delete head;
        return sumHead->next;
    }

    Node* reverse(Node* a) {
        if (a == nullptr) {
            return nullptr;
        }
        Node* head = new Node();
        head->value = -1;
        while(a != nullptr) {
            Node* tmp = a->next;
            a->next = head->next;
            head->next = a;
            a = tmp;
        }
        //deelete head;
        return head->next;
    }
};


#endif //CPP_HANDS_TEST_H
