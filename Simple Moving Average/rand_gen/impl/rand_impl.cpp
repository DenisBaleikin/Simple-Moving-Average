#include "../include/rand.h"

double randn(double mean, double stddev) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::normal_distribution<> distr(mean, stddev);
    return distr(rng);
}

std::list<double> randn_seq(double mean, double stddev, size_t seq_len) {
    std::list<double> seq(seq_len);
    for (auto& elem : seq) {
        elem = randn(mean, stddev);
    }
    return seq;
}