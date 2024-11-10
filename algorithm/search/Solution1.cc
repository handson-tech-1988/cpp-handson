//
//

#ifndef CPP_HANDS_SOLUTION_1_CC
#define CPP_HANDS_SOLUTION_1_CC

#include <vector>
#include <iostream>

struct Node {
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
public:
    Node(int val) {
        this->val = val;
    }
};

class Solution1 {
public:
    static int binarySearch(std::vector<int>& data, int target) {

        int begin = 0;
        int end = data.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (data[mid] == target) {
                return mid;
            } else if (data[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }

    static int binarySearch(Node* tree, int target) {
        Node* cur = tree;
        while (cur != nullptr) {
            if (cur->val == target) {
                return 1;
            } else if (cur->val > target) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        return -1;

    }
};

int main(int argc, char* argv[]) {
    std::vector<int> data = {1,2,8,10};
    int idx = Solution1::binarySearch(data, 8);
    std::cout << "idx:" << idx << std::endl;

    int idx2 = Solution1::binarySearch(data,9);
    std::cout << "idx2:" << idx2 << std::endl;

    Node* n1 = new Node(2);
    Node* n2 = new Node(1);
    Node* n3 = new Node(10);
    Node* n4 = new Node(8);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;

    int idx3 = Solution1::binarySearch(n1, 8);
    std::cout << "idx3:" << idx3 << std::endl;

    int idx4 = Solution1::binarySearch(n1,9);
    std::cout << "idx4:" << idx4 << std::endl;

}


#endif //CPP_HANDS_SOLUTION_1_CC
