//
//

#ifndef CPP_HANDS_SIMD_H
#define CPP_HANDS_SIMD_H

#include <iostream>
#include <immintrin.h>
#include <vector>

// 假设我们使用 float 来模拟 FP16，实际上要转换成 FP16 在硬件支持的情况下可以用其他方式处理
typedef __m256 half_fp16;  // 使用 AVX2 的 256 位寄存器

// 将 FP16 数据加载到 AVX2 寄存器中，假设数据已经是 FP32 进行处理
void load_fp16_to_avx2(const std::vector<float>& input, half_fp16& reg) {
    reg = _mm256_loadu_ps(input.data());  // 加载 FP32 数据到 AVX2 寄存器
}

void print(float* data) {
    std::cout << "Sum pooling result: ";
    for (int i = 0; i < 8; i++ ) {
        std::cout << data[i] << " ";
    }
    std::cout << " ; " << std::endl;
}

// 执行 sum pooling 操作：将 4x4 区域的元素相加
float sum_pooling_fp16(const std::vector<float>& input) {
    half_fp16 reg;  // 用来存储 AVX2 寄存器
    load_fp16_to_avx2(input, reg);

    float result[8];

    // 对 AVX2 中的 8 个 FP32 元素求和
    __m256 sum_result = _mm256_setzero_ps();  // 初始化结果寄存器为零
    sum_result = _mm256_add_ps(sum_result, reg);  // 将 8 个 FP32 元素加和

    _mm256_storeu_ps(result, sum_result);
    print(result);

    // 进行水平加法，将 8 个元素合并成一个结果
    sum_result = _mm256_hadd_ps(sum_result, sum_result);  // 先两两加和

    _mm256_storeu_ps(result, sum_result);
    print(result);

    sum_result = _mm256_hadd_ps(sum_result, sum_result);  // 再两两加和

    // 从寄存器中提取结果
    _mm256_storeu_ps(result, sum_result);
    print(result);

    // 返回结果
    float sum = 0.0f;
    for (int i = 0; i < 8; ++i) {
        sum += result[i];
    }
    return sum;
}

int main() {
    // 假设我们有一个大小为 4x4 的 FP16 数据块
    std::vector<float> input = {
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f
    };

    float sum = sum_pooling_fp16(input); // (1 + 2 + ... + 16) = 8 * 15 = 120
    std::cout << "Sum pooling result: " << sum << std::endl; // 144 => 代码有bug...

    return 0;
}



#endif //CPP_HANDS_SIMD_H
