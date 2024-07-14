#pragma once
#include "include/simple_moving_average.h"
#include <chrono>
#include <iostream>

template<typename RealType = double>
void test(const std::list<size_t>& win_sizes, size_t seq_len) {
	namespace chr = std::chrono;
	auto rand_seq = alg::randn_seq<RealType>(0, 1, seq_len);
	for (auto& win_size : win_sizes) {
		auto begin_tp = chr::steady_clock::now();
		auto result = alg::fSMA(rand_seq, win_size);
		auto diff = chr::duration_cast<chr::milliseconds>(chr::steady_clock::now() - begin_tp);
		auto points_per_sec = (result.size() * 1000) / double(diff.count());
		std::cout << "For averaging window of size " << win_size << ", performance is " << int(points_per_sec)  << " points per second;" << std::endl;

	}
}