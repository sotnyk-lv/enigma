//
// Created by danyl on 6/6/2021.
//

#ifndef ENIGMA_TIME_COUNTING_H
#define ENIGMA_TIME_COUNTING_H

#include <chrono>
#include <atomic>

inline std::chrono::high_resolution_clock::time_point get_current_time_fenced() {
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
};


template<class D>
inline double to_seconds(const D& d)
{
    auto result = std::chrono::duration_cast<std::chrono::microseconds>(d).count()/1000000.00;
    return result;
};

#endif //ENIGMA_TIME_COUNTING_H
