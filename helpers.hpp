#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <tuple>

namespace helpers {

	constexpr int dimR = 64;
	constexpr int dimC = 64;
    constexpr int dimD = 16;
    constexpr int dimF = 32;

    constexpr int size = dimR * dimC * dimD * dimF;

    constexpr int coefF = 1;
    constexpr int coefD = coefF * dimF;
    constexpr int coefC = coefD * dimD;
    constexpr int coefR = coefC * dimC;

    constexpr int maskF = (dimF - 1) * coefF;
    constexpr int maskD = (dimD - 1) * coefD;
    constexpr int maskC = (dimC - 1) * coefC;
    constexpr int maskR = (dimR - 1) * coefR;


    void prinmsg(const std::string& msg);

	std::tuple<size_t, size_t> calculateAdjacent(size_t index,
												 size_t maskN,
												 size_t coefN);

} // namespace helpers

#endif

