#include <random>
#include <list>

namespace alg {
    template<class RealType = double>
    RealType randn(RealType mean, RealType stddev) {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::normal_distribution<RealType> distr(mean, stddev);
        return distr(rng);
    }

    template<class RealType = double>
    std::list<RealType> randn_seq(RealType mean, RealType stddev, size_t seq_len) {
        std::list<RealType> seq(seq_len);
        for (auto& elem : seq) {
            elem = randn(mean, stddev);
        }
        return seq;
    }
}
