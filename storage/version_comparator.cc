//
//

#ifndef CPP_HANDS_TEST_3_H
#define CPP_HANDS_TEST_3_H

#include <string>
#include <iostream>

class Solution {
    /**
     * [begin, end)表示修订号
     */
    struct EditView {
        int begin;
        int end;
        bool HasNext(const std::string &v) const {
            if (end == v.size()) {
                return false;
            }
            return true;
        }

        void Init(const std::string& v) {
            this->begin = 0;
            int i = 0;
            while (i < v.size() && v[i] != '.') {
                i++;
            }
            this->end = i;
        }

        void Next(const std::string& v, EditView& new_edit) {
            if (!HasNext(v)) {
                return;
            }
            std::cout << "v:" << v << std::endl;
            std::cout << "v:before:[" << begin << ", " << end << "), digital:" << Digital(v) << std::endl;
            new_edit.begin = end + 1;
            new_edit.end = new_edit.begin;
            int i = end + 1;
            while (i < v.size() && v[i] != '.') {
                i++;
            }
            new_edit.end = i;
            std::cout << "v:after:[" << begin << ", " << end << "), digital:" << Digital(v) << std::endl;
        }

        bool NextIsZero(const std::string &v) {
            if (!HasNext(v)) {
                return true;
            }
            EditView cur;
            this->Next(v, cur);
            int cur_digital = cur.Digital(v);
            if (cur_digital > 0) {
                return false;
            }
            while (cur.HasNext(v)) {
                this->Next(v, cur);
                int cur_digital = cur.Digital(v);
                if (cur_digital > 0) {
                    return false;
                }
            }
            return true;
        }

        int Digital(const std::string &v) const {
            if (begin >= v.size()) {
                return 0;
            }
            int result = 0;
            int tmp_begin = begin;
            while (tmp_begin < end) {
                result = result * 10 + (v[tmp_begin] - '0');
                tmp_begin ++;
            }
            return result;
        }
    };
public:
    int predicate(std::string& v1, std::string& v2) {
        EditView edit1;
        EditView edit2;
        edit1.Init(v1);
        edit2.Init(v2);
        int digital1 = edit1.Digital(v1);
        int digital2 = edit2.Digital(v2);
        if (digital1 == digital2) {
             while (edit1.HasNext(v1) && edit2.HasNext(v2)) {
                 edit1.Next(v1, edit1);
                 edit2.Next(v2, edit2);
                 int digital1 = edit1.Digital(v1);
                 int digital2 = edit2.Digital(v2);
                 if (digital1 > digital2) {
                     return  1;
                 } else if (digital1 < digital2) {
                     return -1;
                 } else {
                     continue;
                 }
             }
             if (edit1.HasNext(v1) && !edit1.NextIsZero(v1)) {
                 return 1;
             }
            if (edit2.HasNext(v2) && !edit2.NextIsZero(v2)) {
                return -1;
            } else {
                return 0;
            }
        } else if (digital1 > digital2) {
            return  1;
        } else {
            return -1;
        }
    }
};

//int main(int argc, char* argv[]) {
//    std::string a = "1.100.";
//    std::string b = "1.0100.01";
//    int result = Solution().predicate(a, b);
//    std::cout << "result:" <<  result << std::endl;
//    std::cout << "b:" << b << std::endl;
//}


#endif //CPP_HANDS_TEST_3_H
