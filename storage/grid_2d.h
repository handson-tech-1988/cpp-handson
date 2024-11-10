//
//

#ifndef CPP_HANDS_TEST_H
#define CPP_HANDS_TEST_H

#include <vector>
#include <iostream>

class Grid2D {
public:
    void Print(int n) const {
        std::vector<std::vector<int>> array(n);
        for (int i = 0; i < n; i++) {
            array[i].resize(n, 0);
        }
        int cnt = 1;
        int row = 0;
        int col = (n - 1) / 2;
        while (cnt <= n * n) {
            array[row][col] = cnt;
            cnt++;
            Next(array, n, row, col);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << array[i][j] << std::endl;
            }
        }
    }

    void Next(const std::vector<std::vector<int>>& array, int n, int& row, int& col) const {
        if (row == 0 && col == (n - 1)) {
            row = 1;
            col = n - 1;
            return;
        }
        if (row == 0 && col != (n - 1)) {
            row = n - 1;
            col = col + 1;
            return;
        }
        if (row != 0 && col == (n - 1)) {
            row = row - 1;
            col = 0;
        }
        row = row - 1;
        col = col + 1;
        if (array[row][col] != 0) {
            row = row + 1 + 1; // recover
            col = col - 1;
        }
    }
};


#endif //CPP_HANDS_TEST_H
