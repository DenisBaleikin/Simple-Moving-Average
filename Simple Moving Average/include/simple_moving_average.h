#pragma once
#include "include/rand.h"

namespace alg {
    template<typename RealTypeSeq = std::list<double>>
    auto simple_moving_average(const RealTypeSeq& seq, size_t win_size) {
        using RealType = RealTypeSeq::value_type;
        std::list<RealType> result;
        auto window = result;

        auto avg = [win_size](const std::list<RealType>& win) {
            RealType sum{};
            for (auto& elem : win) {
                sum += elem;
            }
            return sum / win_size;
        };

        for (auto& elem : seq) {
            window.push_back(elem);
            if (window.size() != win_size) {
                continue;
            }
            result.push_back(avg(window));
            window.pop_front();
        }
        return result;
    }
}