//
//

#ifndef CPP_HANDS_SIMD_H
#define CPP_HANDS_SIMD_H

#include <iostream>
#include <immintrin.h>
#include <vector>

#include <iostream>
#include <immintrin.h>
#include <vector>

// 定义 AVX2 256 位寄存器，用于存储 8 个 32 位浮动数（FP32）
typedef __m256 float_vec;

// 将 FP16 数据转换为 FP32 并加载到 AVX2 寄存器
void load_fp16_to_fp32_avx2(const std::vector<float>& input, float_vec& reg) {
    reg = _mm256_loadu_ps(input.data());  // 将 FP32 数据加载到 AVX2 寄存器
}

void print(float* data) {
    std::cout << "Sum pooling result: ";
    for (int i = 0; i < 8; i++ ) {
        std::cout << data[i] << " ";
    }
    std::cout << " ; " << std::endl;
}

// 将 FP16 数据转换为 FP32 并加载到 AVX2 寄存器
void load_fp16_to_fp32_avx2_2(const std::vector<float>& input, float_vec& reg) {
    reg = _mm256_loadu_ps(input.data() + 8);  // 将 FP32 数据加载到 AVX2 寄存器
}

// 执行 sum pooling 操作：将 4x4 区域的元素相加
float sum_pooling_fp16(const std::vector<float>& input) {
    float_vec reg;  // 用来存储 AVX2 寄存器
    load_fp16_to_fp32_avx2(input, reg);  // 加载 FP32 数据到寄存器中

    float_vec reg2;  // 用来存储 AVX2 寄存器
    load_fp16_to_fp32_avx2_2(input, reg2);  // 加载 FP32 数据到寄存器中

    float result[8];

    // 对 AVX2 中的 8 个 FP32 元素求和
    __m256 sum_result = _mm256_setzero_ps();  // 初始化结果寄存器为零
    sum_result = _mm256_add_ps(sum_result, reg);  // 将 8 个 FP32 元素加和
    _mm256_storeu_ps(result, sum_result);
    print(result);

    __m256 tmp = _mm256_setzero_ps();

    // 进行水平加法，将 8 个元素合并成一个结果
    sum_result = _mm256_hadd_ps(sum_result, reg2);  // 两两加和 [8, 2] => [4 * 2, 2] => [2 * 2, 2] => [2, 2, 2]
    _mm256_storeu_ps(result, sum_result);
    print(result);


    sum_result = _mm256_hadd_ps(sum_result, tmp);  // 再两两加和
    _mm256_storeu_ps(result, sum_result);
    print(result);

    // 从寄存器中提取结果
    _mm256_storeu_ps(result, sum_result);  // 存储求和结果到数组

    // 返回求和结果
    float sum = 0.0f;
    for (int i = 0; i < 8; ++i) {
        sum += result[i];  // 将所有元素加起来
    }
    return sum;
}

int main() {
    // 假设我们有一个 4x4 的 FP16 数据块（存储为 FP32）
    std::vector<float> input = {
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f
    };

    // 执行 sum pooling 操作
    float sum = sum_pooling_fp16(input);

    // 输出求和结果
    std::cout << "Sum pooling result: " << sum << std::endl; // expected = 136, actual = 144 => bug

    return 0;
}


//int main(int argc, char **argv) {
//    __m256 a = _mm256_set_ps(8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0);
//    __m256 b = _mm256_set_ps(18.0, 17.0, 16.0, 15.0, 14.0, 13.0, 12.0, 11.0);
//
//    __m256 c = _mm256_add_ps(a, b);
//
//    float d[8];
//    _mm256_storeu_ps(d, c);
//
//    std::cout << "result equals " << d[0] << "," << d[1]
//              << "," << d[2] << "," << d[3] << ","
//              << d[4] << "," << d[5] << "," << d[6] << ","
//              << d[7] << std::endl; // 12,14,16,18,20,22,24,26
//
//    return 0;
//}


#endif //CPP_HANDS_SIMD_H
