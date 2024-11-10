//
//

#include <vector>
#include <iostream>

struct Node {
    int val = 0; //
    Node* next = nullptr; // 抄你吗... 未初始化内存...
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
    void Print() {
        std::cout << val << std::endl;
        if (next != nullptr) {
            this->next->Print();
        }
    }
};

class Solution1 {
public:
    static void InsertSort(std::vector<int> &data) {
        for (int i = 1; i < data.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (data[j + 1] >= data[j]) {
                    break;
                } else {
                    int tmp = data[j + 1];
                    data[j + 1] = data[j];
                    data[j] = tmp;
                }
            }
        }
    }
    static Node* InsertSort(Node* list) {
        if (list == nullptr) {
            return nullptr;
        }

        Node* result = list;
        Node* cur = list->next;
        result->next = nullptr;
        while (cur != nullptr) {
            std::cout << "cur.val = " << cur->val << std::endl;

            Node* tmp = cur->next;
            cur->next = nullptr;
            Node* prev = nullptr;
            Node* fCur = result;
            while (fCur != nullptr && fCur->val < cur->val) {
                prev = fCur;
                fCur = fCur->next;
            }
            std::cout << "prev " << prev << std::endl;
            if (prev == nullptr) {
                std::cout << "prev0 " << cur << std::endl;
                cur->next = result;
                result = cur;
                std::cout << "prev1 " << cur << std::endl;
            } else {
                cur->next = prev->next;
                prev->next = cur;
            }

            cur = tmp;
            std::cout << "prev3 " << cur << std::endl;
            if (cur == nullptr) {
                std::cout << "prev5 " << cur << std::endl;
            }
            std::cout << "prev4 " << cur << std::endl;
        }

        std::cout << "sort end. " << std::endl;

        return result;
    }
};

int main(int argc, char **argv) {
    std::vector<int> data = {5,3,8,4, -1};
    Solution1::InsertSort(data);
    for (int val : data) {
        std::cout << val << std::endl;
    }
    std::cout << "insert_linked_list:" << std::endl;
    Node* n1 = new Node(5);
    Node* n2 = new Node(3);
    Node* n3 = new Node(8);
    Node* n4 = new Node(4);
    Node* n5 = new Node(-1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Node* sorted = Solution1::InsertSort(n1);

    sorted->Print();


}

