cmake_minimum_required(VERSION 3.11)
project(cpp_hands)

set(CMAKE_CXX_STANDARD 11)

# 检查编译器是否支持 AVX2
include(CheckCXXCompilerFlag)

# 设置 AVX2 相关编译选项
check_cxx_compiler_flag("-mavx2" COMPILER_SUPPORTS_AVX2)
if(COMPILER_SUPPORTS_AVX2)
    message(STATUS "Compiler supports AVX2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2")
else()
    message(WARNING "AVX2 not supported by the compiler")
endif()

add_executable(cpp_hands storage/version_comparator.cc storage/generic/VariantVisit.cc storage/generic/VariantVisit.h arch_kernel/simd.cc arch_kernel/simd.h grammar/object/v_table.cc grammar/object/v_table.h grammar/object/v_table_2.cc grammar/object/v_table_2.h sys_kernel/enable_from_this.cc)

# add_executable(cpp_hands sys_kernel/my_ptr.h sys_kernel/hash_map.h)