//
//

#include <vector>
#include <iostream>

class FastSort {
public:
    static void FastSort1(std::vector<int>* data) {
        FastSort1(data, 0,data->size() -1);
    }

    static void FastSort1(std::vector<int>* data, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int mVal = data->at(begin);
        int pGroup2 = begin;
        int pCur = begin + 1;
        while (pCur <= end) {
            if (data->at(pCur) >= mVal) {
                pCur++;
            } else {
                int tmp = data->at(pCur);
                data->at(pCur) = data->at(pGroup2);
                data->at(pGroup2) = tmp;
                pCur++;
                pGroup2++;;
            }
        }

        if (pGroup2 == begin) {
            FastSort1(data, begin + 1, end);
        } else {
            FastSort1(data, begin, pGroup2 - 1);
            FastSort1(data, pGroup2, end);
        }
    }
};

int main(int argc, char **argv) {
    std::vector<int> data = {3,2,8,10,7};
    FastSort::FastSort1(&data);

    for (int val : data) {
        std::cout << val << std::endl;
    }
}