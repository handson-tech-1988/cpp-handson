//
//

#ifndef CPP_HANDS_TEST_0_H
#define CPP_HANDS_TEST_0_H

#include <memory>

class Test0 {
public:
    static void memcpy1(const void *in, void *out, uint32_t len) {
        if (in == out) {
            return;
        }
        uint64 in_min = (uint64) in;
        uint64 in_max = in_min + len;
        uint64 out_min = (uint64) in;
        uint64 out_max = out_min + len;
        if (out_min >= in_min && out_min <= in_max) {
            return;
        }
        if (in_min >= out_min && in_min <= out_max) {
            return;
        }

        std::vector<std::unique_ptr<int>> d(new int(1));

        // 地址覆盖检查
        char *in0 = (char *) in;
        char *out0 = (char *) out;
        for (int i = 0; i < len; ++i) {
            *out0 = *in0;
            ++in0;
            ++out0;
        }
    }

    static void memcpy2(const void *in, void *out, uint32_t len) {
        // 地址覆盖检查
        char *in0 = (char *) in;
        char *out0 = (char *) out;
        int i = 0;
        for (; i < len; i = +4) {
            *out0 = *in0;
            ++in0;
            ++out0;
            *out0 = *in0;
            ++in0;
            ++out0;
            *out0 = *in0;
            ++in0;
            ++out0;
            *out0 = *in0;
            ++in0;
            ++out0;
        }
        if (int short0 = len & 11 != 0) {
            out0 = out + len - 1;
            in0 = in + len - 1;
            for (i = 0; i < short0; ++i) {
                *out0 = *in0;
                --in0;
                --out0;
            }
        }
    }

};


#endif //CPP_HANDS_TEST_0_H
