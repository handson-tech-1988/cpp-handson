//
//

#ifndef CPP_HANDS_TOKENIZOR_H
#define CPP_HANDS_TOKENIZOR_H

#include <string>
#include <vector>

typedef std::string Token;
typedef std::string Tokens;

struct Iterator {
    const Token& Value() {
        return Token();
    }
    Iterator End() {
        return Iterator();
    }
    Iterator Next() {
        return Iterator();
    }
};

bool operator!=(const Iterator& __x, const Iterator& __y) {
    return true;
}

struct Index {
    virtual Iterator Find(const Tokens& tokens, int start) = 0;
};

struct BinaryIndex : Index {
    std::vector<Token> sorted;

    BinaryIndex(const std::vector<Token>& dict) {
        this->sorted = dict;
        std::sort(this->sorted.begin(), this->sorted.end());
    }

    struct BinaryIterator : public Iterator {
        std::string first_token_;
        std::vector<Token>* sorted;
        int cur_idx;
        explicit BinaryIterator(std::string first_token, std::vector<Token>* sorted, int cur_idx) {
            this->first_token_ = first_token;
            this->sorted = sorted;
            this->cur_idx = cur_idx;;
        }
        const Token& Value() {
            return (*this->sorted)[cur_idx];
        }
        Iterator End() {
            return BinaryIterator("", nullptr, -1);
        }
        Iterator Next() {
            int next_ptr = this->cur_idx + 1;
            if ((*sorted)[next_ptr] == this->first_token_) {
                return BinaryIterator(this->first_token_, this->sorted, next_ptr);
            } else {
                return End();
            }
        }
    };

    virtual Iterator Find(const Tokens& tokens, int start) {
        int idx = 0; // 二分查找
        if (idx < tokens.size()) {
            return BinaryIterator(Token(1, tokens[start]), &this->sorted, -1);
        } else {
            return BinaryIterator("", nullptr, -1);
        }
    }

};

class Tokenizor {
public:
    std::vector<std::vector<Token>> tokenize0(const Tokens& value, const std::vector<Token>& dict) {
        Index* index = new BinaryIndex(dict);
        return this->tokenize(index, value, 0);
    }

    /**
     * 递归问题的状态机管理
     *  result(i) = for j { result(i + j) + char(i) }
     *      i处搜索，得到j的集合
     * @param index
     * @param value
     * @param start
     * @return
     */
    std::vector<std::vector<Token>> tokenize(Index* index, const Tokens& value, int start) {
        std::vector<std::vector<Token>> results;
        Iterator ite = index->Find(value, start);
        while (ite != ite.End()) {
            const Token& token = ite.Value();
            std::vector<std::vector<Token>> splits = tokenize(index, value, start + token.size());
            for (auto& split : splits) {
                split.push_back(token);
                results.push_back(split);
            }
        }

        return results;
    }
};


#endif //CPP_HANDS_TOKENIZOR_H
