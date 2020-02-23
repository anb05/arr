#include "./helpers.hpp"

#include <iostream>

namespace helpers {

void print_msg(const std::string& msg)
{
    std::cout << msg << std::endl;
}

// НЕ ИСПОЛЬЗОВАТЬ
// Старый вариант с перепутанными размерностями, но общими подходами.
// Сделать ПОЛНОЕ Описание и перенести на бумагу !!!!.
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
    int32_t d = 0;
    int32_t r = 0;
    int32_t c = 0;
    int32_t f = 0;

    int64_t iL = index;

    if (iL < size) {
        while (coefD <= iL) {
            ++d;
            iL -= coefD;
        }
        while (coefR <= iL) {
            ++r;
            iL -=coefR;
        }
        while (coefC <= iL) {
            ++c;
            iL -= coefC;
        }
        f = int32_t(iL);
    }
    printf("arr[ %i ][ %i ][ %i ][ %i ];\n",d,r,c,f);

}

int32_t calculateDimIdx( int32_t& d,
                         int32_t& r,
                         int32_t& c,
                         int32_t& f,
                         int64_t index)
{
    int64_t iL = index;

    if (iL < size) {
        while (coefD <= iL) {
            ++d;
            iL -= coefD;
        }
        while (coefR <= iL) {
            ++r;
            iL -=coefR;
        }
        while (coefC <= iL) {
            ++c;
            iL -= coefC;
        }
        f = int32_t(iL);
    }

    return 0;
}

std::tuple<int64_t, int64_t> calcAdjacent(const int64_t index,
                                      const int32_t dim/*подавать маску*/)
{
    int64_t left  {index};
    int64_t right {index};
    const int64_t maskN {dim};

    if (maskN == maskF) {
        int64_t var = index & maskF;
        int64_t clr = index & (~maskF);

        int64_t var_l = (var - coefF) & maskF;
        int64_t var_r = (var + coefF) & maskF;

        left  = var_l | clr;
        right = var_r | clr;

        return std::make_tuple(left, right);
    }

    if (maskN == maskC) {
        int64_t var = index & maskC;
        int64_t clr = index & (~maskC);

        int64_t var_l = (var - coefC) & maskC;
        int64_t var_r = (var + coefC) & maskC;

        left  = var_l | clr;
        right = var_r | clr;

        return std::make_tuple(left, right);
    }

    if (maskN == maskR) {
        int64_t var = index & maskR;
        int64_t clr = index & (~maskR);

        int64_t var_l = (var - coefR) & maskR;
        int64_t var_r = (var + coefR) & maskR;

        left  = var_l | clr;
        right = var_r | clr;

        return std::make_tuple(left, right);
    }

    if (maskN == maskD) {
        right = index + coefD;

        if (size <= right) {
            right = index;
            left = index - coefD;
            return std::make_tuple(left, right);
        }
        if (index < coefD) {
            left = index;
            return std::make_tuple(left, right);
        }
        left = index - coefD;
        return std::make_tuple(left, right);
    }

    return std::make_tuple(left, right);
}

void calcDimIdx( int32_t& d,
                 int32_t& r,
                 int32_t& c,
                 int32_t& f,
                 int64_t index)
{
    d = 0;
    r = 0;
    c = 0;
    f = 0;

    f = index & maskF;
    c = (index & maskC) >> shiftRightC;
    r = (index & maskR) >> shiftRightR;
    d = int32_t(index  >> shiftRightD);
}

std::tuple<int32_t, int32_t, int32_t, int32_t> calcDimIdx(int64_t idx)
{
    int32_t d {0};
    int32_t r {0};
    int32_t c {0};
    int32_t f {0};

    d = idx / minD;
    idx %= minD;

    r = idx / minR;
    idx %= minR;

    c = idx / minC;
    f = idx % minC;

    return std::make_tuple(d,r,c,f);
}

} // namespace helpers

