#include "./helpers.hpp"

#include <iostream>

namespace helpers {

void prinmsg(const std::string& msg)
{
    std::cout << msg << std::endl;
}

std::tuple<int64_t, int64_t> calculateAdjacent(const int64_t index,
                                             const int64_t maskN)
{
    int64_t left  {index};
    int64_t right {index};

    if (maskN == maskF) {
		int64_t var = index & maskF;
		int64_t clr = index & (~maskF);

		int64_t var_l = (var - coefF) & maskF;
		int64_t var_r = (var + coefF) & maskF;

        left  = var_l | clr;
        right = var_r | clr;

        return std::make_tuple(left, right);
    }

    if (maskN == maskD) {
        right = index + coefD;
        left = index - coefD;

        if (left < 0) {
            left = index;
            return std::make_tuple(left, right);
        }

        if (size <= right) {
            right = index;
            return std::make_tuple(left, right);
        }

        int64_t fraction = index / minC;
        int64_t fractionR = right / minC;

        if (fraction != fractionR) {
            right = index;
            return std::make_tuple(left, right);
        }

        int64_t fractionL = left / minC;
        if (fraction != fractionL) {
            left = index;
            return std::make_tuple(left, right);
        }

        return std::make_tuple(left, right);
    }

    if (maskN == maskC) {
        right = index + coefC;
        left = index - coefC;

        if (left < 0) {
            left = index + maxC;
            return std::make_tuple(left, right);
        }

        if (size <= right) {
            right = index - maxC;
            return std::make_tuple(left, right);
        }

        int64_t fraction = index / minR;
        int64_t fractionR = right / minR;

        if (fraction != fractionR) {
            right = index - maxC;
            return std::make_tuple(left, right);
        }

        int64_t fractionL = left / minR;
        if (fraction != fractionL) {
            left = index + maxC;
            return std::make_tuple(left, right);
        }

        return std::make_tuple(left, right);
    }

    if (maskN == maskR) {
        right = index + coefR;
        if (size <= right) {
            right = index - maxR;
            left  = index - coefR;

            return std::make_tuple(left, right);
        }
        if (index < coefR) {
            left = index + maxR;

            return std::make_tuple(left, right);
        }
        left = index - coefR;
        return std::make_tuple(left, right);
    }

    return std::make_tuple(left, right);
}

void calculateDimIdx(int64_t index)
{

	int32_t r = 0;
	int32_t c = 0;
	int32_t d = 0;
	int32_t f = 0;

	int64_t iL = index;

	if (iL < size) {
		while (coefR <= iL) {
			++r;
			iL -=coefR;
		}
		while (coefC <= iL) {
			++c;
			iL -= coefC;
		}
		while (coefD <= iL) {
			++d;
			iL -= coefD;
		}
		f = int32_t(iL);
	}
	printf("arr[ %i ][ %i ][ %i ][ %i ];\n",r,c,d,f);

}

int32_t calculateDimIdx(int32_t& r,
						int32_t& c,
						int32_t& d,
						int32_t& f,
						int64_t index)
{
	int64_t iL = index;

	if (iL < size) {
		while (coefR <= iL) {
			++r;
			iL -=coefR;
		}
		while (coefC <= iL) {
			++c;
			iL -= coefC;
		}
		while (coefD <= iL) {
			++d;
			iL -= coefD;
		}
		f = int32_t(iL);
	}

	return 0;
}

} // namespace helpers

