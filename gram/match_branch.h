//
//

#ifndef CPP_HANDS_MATCH_BRANCH_H
#define CPP_HANDS_MATCH_BRANCH_H

#include <vector>
#include <iostream>

class MatchBranch {
    void match(void* input, bool flag) {
        if (flag) {
            std::cout << "true0" << std::endl;
        } else {
            std::cout << "false0" << std::endl;
        }
    }
};

template <bool flag = true>
struct MatchBranchX {
    void match(void* input) {
        if (flag) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
};

struct FieldA {
    std::string f_name_;
    std::vector<int64_t > ids_;
    void execute() {
        MatchBranchX<true> match_branch_x;
        match_branch_x.match(nullptr);
    }
};

// 函数指针本质也是分支，因为不确定下一个指令是谁


#endif //CPP_HANDS_MATCH_BRANCH_H
