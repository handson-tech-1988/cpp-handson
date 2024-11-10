//
//

#include "test.h"
#include <vector>


public class MaxPath {
public:
    /**
     *
     * @param bean_cnts M * N
     */
    static void MaxPath(std::vector<std::vector<int32_t >> bean_s) {
        std::vector<std::vector<int32_t>> bean_sums;
        bean_sums.resize(bean_s.size());
        for (auto& sum : bean_sums) {
            sum.resize(bean_s[0].size());
        }
        bean_sums[0][0] = bean_s[0][j];
        for (int i = 1; i < bean_sums[0].size(); i ++) {
            bean_sums[0][i] = bean_sums[0][i - 1] + bean_s[0][i];
        }
        for (int j = 1; i < bean_sums.size(); i++) {
            bean_sums[j][0] = bean_sums[j -1][0] + bean_s[j][0];
        }
        for (int row = 1, int column = 1; row < bean_sums.size() && column < bean_sums[0].size(); row ++, column++) {
            int from_up = bean_sums[row -1][column] + bean_s[row][column];
            int from_left = bean_sums[row][column - 1] + bean_s[row][column];
            bean_sums[row][column] = max(from_up, from_left);
        }
        std::cout << "max_sum:" << bean_sums[bean_sums.size() - 1][bean_sums[0].size() - 1];

        int row = bean_sums.size() - 1;
        int column = bean_sums.size() - 1;
        while (row != 0 && column != 0) {
            std::cout << "max_sum_path:[" << row << ", " << column << "];
            int presum = bean_sums[row][column] - bean_s[row][column];
            if (row > 0 && column > 0) {
                if (bean_sums[row - 1][column] == presum) {
                    row = = row - 1;
                } else {
                    column = column - 1;
                }
            }
            if (row == 0) {
                column = column - 1;
            }
            if (column == 0) {
                row = row - 1;
            }
        }
        return;
    }
};
