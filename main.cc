#include <iostream>

int print(int a) {
    std::cout << "Hello, World!" << a << std::endl;
    return 0;
}

//int main() {
//    int a = 0;
//    int b = 3;
//    print(a + b);
//    return 0;
//}

//
// g++ main.cpp -O2 -o main
// otool -tvV main | grep -i main -A 20
//
//

//main:
//(__TEXT,__text) section
//        __Z5printi:
//00000001000009a0        pushq   %rbp
//00000001000009a1        movq    %rsp, %rbp
//00000001000009a4        pushq   %r14
//00000001000009a6        pushq   %rbx
//00000001000009a7        subq    $0x10, %rsp
//00000001000009ab        movl    %edi, %ebx
//00000001000009ad        movq    0x65c(%rip), %rdi ## literal pool symbol address: __ZNSt3__14coutE
//00000001000009b4        leaq    0x5b5(%rip), %rsi ## literal pool for: "Hello, World!"
//00000001000009bb        movl    $0xd, %edx
//00000001000009c0        callq   __ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m ## std::__1::basic_ostream<char, std::__1::char_traits<char> >& std::__1::__put_character_sequence<char, std::__1::char_traits<char> >(std::__1::basic_ostream<char, std::__1::char_traits<char> >&, char const*, unsigned long)
//00000001000009c5        movq    %rax, %rdi
//00000001000009c8        movl    %ebx, %esi
//00000001000009ca        callq   0x100000d66 ## symbol stub for: __ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
//00000001000009cf        movq    %rax, %rbx
//00000001000009d2        movq    (%rbx), %rax
//00000001000009d5        movq    -0x18(%rax), %rsi
//00000001000009d9        addq    %rbx, %rsi
//00000001000009dc        leaq    -0x18(%rbp), %r14
//--
//_main:
//0000000100000a50        pushq   %rbp
//0000000100000a51        movq    %rsp, %rbp
//0000000100000a54        movl    $0x3, %edi
//0000000100000a59        callq   __Z5printi ## print(int)
//0000000100000a5e        xorl    %eax, %eax
//0000000100000a60        popq    %rbp
//0000000100000a61        retq
//0000000100000a62        nopw    %cs:(%rax,%rax)
//__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m:
//0000000100000a70        pushq   %rbp
//0000000100000a71        movq    %rsp, %rbp
//0000000100000a74        pushq   %r15
//0000000100000a76        pushq   %r14
//0000000100000a78        pushq   %r13
//0000000100000a7a        pushq   %r12
//0000000100000a7c        pushq   %rbx
//0000000100000a7d        subq    $0x28, %rsp
//0000000100000a81        movq    %rdx, %r14
//0000000100000a84        movq    %rsi, %r15
//0000000100000a87        movq    %rdi, %rbx





