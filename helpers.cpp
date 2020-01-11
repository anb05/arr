#include "./helpers.hpp"

#include <iostream>

namespace helpers {
    
    void prinmsg(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }

	std::tuple<size_t, size_t> calculateAdjacent(size_t index,
												 size_t maskN,
												 size_t coefN)
    {
		size_t left  {index};
		size_t right {index};

		if (maskN == maskF) {
			size_t var = index & maskN;
			size_t clr = index & (~maskN);

			size_t var_l = (var - coefN) & maskN;
			size_t var_r = (var + coefN) & maskN;

			left  = var_l | clr;
			right = var_r | clr;
		}
		else if (maskN == maskR) {
			right = index + coefN;
			if (size <= right) {
				right = index - (dimR - 1) * coefR;
				left  = index - coefN;
			}
		}

        return std::make_tuple(left, right);
    }

} // namespace helpers

