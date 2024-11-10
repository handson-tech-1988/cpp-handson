////
////
//
//#ifndef CPP_HANDS_VARIANTVISIT_H
//#define CPP_HANDS_VARIANTVISIT_H
//
//#include <variant>
//#include <string>
//#include <iostream>
//
//int main() {
//    using var_t = std::variant<int, char, std::string>;
//    auto f = [](auto &&v) {
//        // 获得v的类型
//        using T = std::decay_t<decltype(v)>;
//        // 根据不同的类型，执行不同的操作
//        if constexpr (std::is_same_v<T, int>) {
//            std::cout << "int : " << v << "\n";
//        }
//        if constexpr (std::is_same_v<T, char>) {
//            std::cout << "char : " << v << "\n";
//        }
//        if constexpr (std::is_same_v<T, std::string>) {
//            std::cout << "string : " << v << "\n";
//        }
//    };
//    var_t v{114};
//    Visit(f, v);
//    v =std::string{ "514"};
//    Visit(f, v);
//    Visit(f, var_t{'a'});
//}
//
//
//class VariantVisit {
//
//};
//
//
//#endif //CPP_HANDS_VARIANTVISIT_H
