//
//

#ifndef CPP_HANDS_MAX_PRICES_H
#define CPP_HANDS_MAX_PRICES_H

#include <vector>
#include <queue>
#include <iostream>

class MaxPrices {
public:
    int maxprofit(std::vector<int>& prices) {
        int min = prices[0];
        int max = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= max) {
                max = prices[i];
            } else {
                // std::cout << "delta:" << (max - min) << std::endl;
                profit += (max - min);
                min = max = prices[i];
            }
        }
        // std::cout << "delta:" << (max - min) << std::endl;
        profit += (max - min);
        return profit;
    }
};

int main(int argc, char* argv[]) {
    std::vector<int> prices {6,6,4,3,1};
    std::cout << "result :" << MaxPrices().maxprofit(prices) << std::endl;
}


#endif //CPP_HANDS_MAX_PRICES_H
