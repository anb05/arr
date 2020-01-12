#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <tuple>
#include <cstdint>

namespace helpers {

constexpr int64_t dimR = 8;
constexpr int64_t dimC = 8;
constexpr int64_t dimD = 40;
constexpr int64_t dimF = 256;

constexpr int64_t size = dimR * dimC * dimD * dimF;

constexpr int64_t coefF = 1;
constexpr int64_t coefD = coefF * dimF;
constexpr int64_t coefC = coefD * dimD;
constexpr int64_t coefR = coefC * dimC;

constexpr int64_t maskF = (dimF - 1) * coefF;
constexpr int64_t maskD = (dimD - 1) * coefD;
constexpr int64_t maskC = (dimC - 1) * coefC;
constexpr int64_t maskR = (dimR - 1) * coefR;

constexpr int64_t minF = 0;
constexpr int64_t maxF = (dimF - 1) * coefF;
constexpr int64_t minD = coefD;
constexpr int64_t maxD = (dimD - 1) * coefD;
constexpr int64_t minC = coefC;
constexpr int64_t maxC = (dimC - 1) * coefC;
constexpr int64_t minR = coefR;
constexpr int64_t maxR = (dimR - 1) * coefR;


void prinmsg(const std::string& msg);

std::tuple<size_t, size_t> calculateAdjacent(const int64_t index,
                                             const int64_t maskN);

} // namespace helpers

#endif

