//
//

#ifndef CPP_HANDS_TEST_10_H
#define CPP_HANDS_TEST_10_H

#include <iostream>

struct Node {
    int val = 0;
    Node* next = nullptr;
    void Print() {
        std::cout << "val:" <<  val << std::endl;
        if (next != nullptr) {
            next->Print();
        }
    }
    Node(int val) : val(val){}
};

class Solution10 {
public:
    static void ReverseList1(Node* list) {
        if (list == nullptr || list->next == nullptr) {
            return;
        }
        Node* pCur = new Node(list->val);
        pCur->next = list->next;
        list->next = nullptr;

        Node* pResult = nullptr;
        while (pCur != nullptr) {
            Node* tmp = pCur->next;
            pCur->next = pResult;
            pResult = pCur;
            pCur = tmp;
        }
        list->val = pResult->val;
        list->next = pResult->next;
        delete pResult; // 内存回收 => 地址失效
    }

    static Node* ReverseList2(Node* list) {
        Node* result = nullptr;
        while (list != nullptr) {
            Node* tmp = list->next;
            list->next = result;
            result = list;
            list = tmp;
        }
        return result;
    }

    static void ReverseList3(Node*& list) {
        if (list->next == nullptr) {
            return ;
        }
        Node*& result = list;

        Node* cur = list->next;
        result->next = nullptr;

        while (cur != nullptr) {
            Node* tmp = cur->next;
            cur->next = result;
            result = cur;
            cur = tmp;
        }
        return ;
    }
};

int main(int argc, char** argv) {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;


    Solution10::ReverseList3(n1);
    n1->Print();

    delete n1;
//    delete n2;
//    delete n3;
//    delete n4;


}


#endif //CPP_HANDS_TEST_10_H
