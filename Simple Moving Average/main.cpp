#include "include/test.h"


int main()
{
	enum class real_t {FLOAT, DOUBLE};
	const size_t seq_len = 1000000;
	const std::list<size_t> win_size = { 4, 8, 16, 32, 64, 128 };
	const std::list<real_t> types = { real_t::FLOAT, real_t::DOUBLE };

	for (auto& type : types) {
		if (type == real_t::FLOAT) {
			std::cout << "float type: " << std::endl;
			test<float>(win_size, seq_len);
		}
		else {
			std::cout << "double type: " << std::endl;
			test(win_size, seq_len);
		}
	}

	
}
