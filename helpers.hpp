#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <tuple>

namespace helpers {

    constexpr int dimR = 4;
    constexpr int dimC = 4;
    constexpr int dimD = 9;
    constexpr int dimF = 20;

    constexpr int size = dimR * dimC * dimD * dimF;

    constexpr int coefF = 1;
    constexpr int coefD = coefF * dimF;
    constexpr int coefC = coefD * dimD;
    constexpr int coefR = coefC * dimC;


    void prinmsg(const std::string& msg);

    std::tuple<size_t, size_t> calculateAdjacent(size_t index, size_t coefN, size_t size = size);

} // namespace helpers

#endif

