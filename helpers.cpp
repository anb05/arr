#include "./helpers.hpp"

#include <iostream>

namespace helpers {
    
    void prinmsg(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }

    std::tuple<size_t, size_t> calculateAdjacent(size_t index, size_t coefN, size_t size)
    {
        size_t left {index};
        size_t right {index};

        if (index < coefN) {
            left = size - coefN + index;
            right = index + coefN;
        }
        else {
            left = index - coefN;

            if (index < (size - coefN)) {
                right = index + coefN;
            }
            else {
                right = coefN - (size - index);
            }
        }

        return std::make_tuple(left, right);
    }

} // namespace helpers

