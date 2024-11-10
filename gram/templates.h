//
//

#ifndef CPP_HANDS_TEMPLATES_H
#define CPP_HANDS_TEMPLATES_H

#include <utility>

namespace templates {
struct A {
    A fn() {
        return A();
    }
};
static void Test() {
    decltype(std::declval<A>().fn()) z;
    z.fn();
    decltype(0, int(0)) x;
}
}

class Templates {

};


#endif //CPP_HANDS_TEMPLATES_H
