#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <tuple>
#include <cstdint>

namespace helpers {

	constexpr uint64_t dimR = 4;
	constexpr uint64_t dimC = 4;
	constexpr uint64_t dimD = 5;
	constexpr uint64_t dimF = 16;

	constexpr uint64_t size = dimR * dimC * dimD * dimF;

	constexpr uint64_t coefF = 1;
	constexpr uint64_t coefD = coefF * dimF;
	constexpr uint64_t coefC = coefD * dimD;
	constexpr uint64_t coefR = coefC * dimC;

	constexpr uint64_t maskF = (dimF - 1) * coefF;
	constexpr uint64_t maskD = (dimD - 1) * coefD;
	constexpr uint64_t maskC = (dimC - 1) * coefC;
	constexpr uint64_t maskR = (dimR - 1) * coefR;


    void prinmsg(const std::string& msg);

	std::tuple<size_t, size_t> calculateAdjacent(size_t index,
												 size_t maskN,
												 size_t coefN);

} // namespace helpers

#endif

