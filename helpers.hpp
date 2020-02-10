#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <tuple>
#include <cstdint>

namespace helpers {

// Пока не задействован
constexpr int64_t dimZ = 2;

constexpr int64_t dimD = 40;
constexpr int64_t dimR = 4;
constexpr int64_t dimC = 4;
constexpr int64_t dimF = 256;

constexpr int64_t size = dimR * dimC * dimD * dimF;

constexpr int64_t coefF = 1;
constexpr int64_t coefC = coefF * dimF;
constexpr int64_t coefR = coefC * dimC;
constexpr int64_t coefD = coefR * dimR;
constexpr int64_t coefZ = coefD * dimD;

constexpr int64_t maskF = (dimF - 1) * coefF;
constexpr int64_t maskC = (dimC - 1) * coefC;
constexpr int64_t maskR = (dimR - 1) * coefR;
constexpr int64_t maskD = (dimD - 1) * coefD;

constexpr int64_t minF = 0;
constexpr int64_t maxF = (dimF - 1) * coefF;
constexpr int64_t minC = coefC;
constexpr int64_t maxC = (dimC - 1) * coefC;
constexpr int64_t minR = coefR;
constexpr int64_t maxR = (dimR - 1) * coefR;
constexpr int64_t minD = coefD;
constexpr int64_t maxD = (dimD - 1) * coefD;
//constexpr int64_t minZ = coefZ;
//constexpr int64_t maxZ = (dimZ - 1) * coefZ;


void print_msg(const std::string& msg);

// Старый вариант с перепутанными размерностями.
std::tuple<int64_t, int64_t> calculateAdjacent(const int64_t index,
											   const int64_t maskN);

std::tuple<int64_t, int64_t> calcAdjacent(const int64_t index,
										  const int32_t dim);

void calculateDimIdx(int64_t index);

int32_t calculateDimIdx( int32_t& d,
						 int32_t& r,
						 int32_t& c,
						 int32_t& f,
						 int64_t index);

} // namespace helpers

#endif

