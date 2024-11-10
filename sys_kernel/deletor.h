//
//

#ifndef CPP_HANDS_DELETOR_H
#define CPP_HANDS_DELETOR_H

#include <atomic>
#include <memory>

class DataLoader {
private:
    std::atomic_int mini_batch_cnt{0};
    /**
     *
     * @return 持有Deleter的指针和状态 => DataLoader的内存被Refs和管理 => 最好定制内存管理器. | mini_batch_cnt=0时才能回收.
     *  std::shared_ptr<std::string> 需要先回收再再回收DataLoader.
     */
    std::shared_ptr<std::string> CreateMiniBatch() {
        mini_batch_cnt++;
        std::string* data = nullptr;
        std::shared_ptr<std::string> ret = std::shared_ptr<std::string>(data, [this](std::string* d) {
            this->mini_batch_cnt--;
        });
        return ret;
    }
 };


#endif //CPP_HANDS_DELETOR_H
