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
        size_t var = index & maskN;
        size_t clr = index & (~maskN);

		size_t var_l = (var - coefN) & maskN;
		size_t var_r = (var + coefN) & maskN;

        size_t left  = var_l | clr;
        size_t right = var_r | clr;

        return std::make_tuple(left, right);
    }

} // namespace helpers

