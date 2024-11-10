//
//

#include <vector>
#include <iostream>

struct Topk {
    /**
     *
     * @param data
     * @param k >= 1
     * @return
     */
    static int topk(std::vector<int>& data, int k) {
        return topk(data, 0, data.size(), k);
    }

    static int topk(std::vector<int>& data, int begin, int end, int k) {
        if (k<=0) {
            return data[k - 1];
        }
        int pivVal = data[begin];
        int pGroup2 = begin;
        int pCur = begin + 1;
        while (pCur <= end) {
            if (data[pCur] >= pivVal) {
                pCur++;
            } else {
                int tmp = data[pCur];
                data[pCur] = data[pGroup2];
                data[pGroup2] = tmp;
                pCur++;
                pGroup2++;
            }
        }
        if (pGroup2 == begin) {
            if (k == 1) {
                return data[begin];
            } else {
                return topk(data, begin + 1, end, k - 1);
            }
        } else {
            if (pGroup2 - begin >= k) {
                return topk(data, begin, pGroup2 - 1, k);
            } else {
                int g1 = pGroup2 - begin;
                return topk(data, pGroup2, end, k - g1);
            }
        }
    }
};

int main(int argc, char **argv) {
    std::vector<int> a = {3,2,1,5,6,4};
    int output = Topk::topk(a, 5);
    // System.out.println(topk(a, 5));
    // System.out.println( a[5 - 1] );
    std::cout << output << std::endl;
}