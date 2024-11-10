//
//

#include <vector>
#include <iostream>

struct Node {
    int val_ = 0;
    union {
        Node* next_ = nullptr;
        int lid_;
        int idx_;
    };
    static Node* ValOf(int val) {
        Node* n = new Node();;
        n->val_ = val;
        return n;
    }
};

struct Heap {
    void Push(Node* n) {

    }
    Node* Pop() {
        return nullptr;
    }
};

class MergeSortList {
public:
    typedef std::vector<Node > data_list;
    void Merge(std::vector<data_list>& lists, data_list& output) {
        int n = 0;
        Heap heap;
        uint32_t size = 0;
        for (auto& l : lists) {
            if (!l.empty()) {
                n++;
                size += l.size();
                heap.Push(&l[0]);
            }
        }

        output.resize(size);
        while (n > 0) {
            Node* min = heap.Pop();
            if (min->idx_ < lists[min->lid_].size()) {
                Node* newNode = &lists[min->lid_][min->idx_];
                newNode->idx_ = min->idx_ ++;
                heap.Push(newNode);
            } else {
                n--;
            }
            output.push_back(*min);
        }

    }

    Node* Merge(std::vector<Node*>& lists) {
        int n = 0;
        Heap heap;
        for (auto& l : lists) {
            if (l != nullptr) {
                n++;
                heap.Push(l);
            }
        }
        Node* resultHead = Node::ValOf(-1);
        Node* resultTail = resultHead;
        while (n > 0) {
            Node* min = heap.Pop();
            if (min->next_ != nullptr) {
                heap.Push(min->next_);
            } else {
                n--;
            }
            resultTail->next_ = min;
            min->next_ = nullptr;
            resultTail = min;
        }
        Node* tmp = resultHead->next_;
        delete resultHead;
        return tmp;
    }

    static int find(const std::vector<int64_t >& a, int begin, int target) {
        if (begin >= a.size()) {
            return -1;
        }
        int end = a.size() - 1;
        while (end >= begin) {
            int mid = (begin + end) / 2;
            if (a[mid] == target) {
                return mid;
            } else if (a[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1 * begin;
    }

    static void MergeSortArray(const std::vector<int64_t >& a, const std::vector<int64_t >& b, std::vector<int64_t >& result) {
        std::vector<std::pair<int64_t, const std::vector<int64_t>*>> stats(2);
        int turn = 0;
        stats[0] = {0, &a};
        stats[1] = {0, &b};
        while (stats[turn].first < stats[turn].second->size()) {
            int other = ( 1 + turn) % 2;
            int target = stats[turn].second->at(stats[turn].first);
            int found = find(*stats[other].second, stats[other].first, target);
            if (found > 0) {
                result.push_back(stats[other].second->at(found));
                stats[other].first = found + 1;
            } else {
                stats[other].first = found * -1;
            }
            turn = other;
        }
    }

};

struct A {
    short s; // 2
    char a[10]; // 10
    long  l; // 8 + 4
    int i; // 4
    short s1; // 2
}; // 16 + 8 + 8 = 32

struct B {
    short s; // 2
    char a; // 1
    long  l; // 8 + 5
    int i; // 4
    short s1; // 2
}; // 8 + 8 + 8 = 24

int main(int argc, char* argv[]) {

    int size = sizeof(struct B);

    std::cout << "size:" << size << std::endl;


    std::vector<int64_t > a = {1,3,8, 10};
    std::vector<int64_t > b = {3, 7, 10};
    std::vector<int64_t > c = {};
    MergeSortList::MergeSortArray(a, b, c);
    std::cout << "data:" << std::endl;
    for (int d : c) {
        std::cout << d << std::endl;
    }
}
