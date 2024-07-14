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

    template<typename RealTypeSeq = std::list<double>>
    auto fSMA(const RealTypeSeq& seq, size_t win_size) {
        using RealType = RealTypeSeq::value_type;
        std::list<RealType> result;
        
        auto avg = [](const auto& first_it, const auto& last_it) {
            RealType res{};
            for (auto it = first_it; it != std::next(last_it); ++it) {
                res += *it;
            }
            return res / std::distance(first_it, last_it);
        };

        for (auto first = seq.begin(), last = std::next(first, win_size - 1); last != seq.end(); ++first, ++last) {
            if (first == seq.begin()) {
                result.push_back(avg(first, last));
                continue;
            }
            result.push_back(result.back() - *std::prev(first) / win_size + *last / win_size);
        }
        return result;
    }
}