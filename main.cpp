#include "./helpers.hpp"

#include <iostream>
#include <cassert>
#include <string>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const** argv)
{
    std::string msg {
        "\n===========================================================\n\n"
        "Линеаризация многомерного массива\n"
        "Рассматривается четырёхмерный массив\n" };
    helpers::print_msg(msg);

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    int32_t dimD = helpers::dimD;
    int32_t dimR = helpers::dimR;
    int32_t dimC = helpers::dimC;
    int32_t dimF = helpers::dimF;


    int64_t arr[dimD][dimR][dimC][dimF];
    int64_t* addr = &arr[0][0][0][0];
    int64_t* start = addr;

//    int64_t end = helpers::size;

//    for (int64_t i = 0; i < end; i++, ++addr) {
//        *addr = i;
//    }

//    addr = start;

//    printf("coefF = %li\n", helpers::coefF);
//    printf("coefD = %li\n", helpers::coefD);
//    printf("coefC = %li\n", helpers::coefC);
//    printf("coefR = %li\n", helpers::coefR);

//    msg = "Проверка линеаризации массива";
//    helpers::prinmsg(msg);

    for (int64_t d = 0; d < dimD; d++) {

        for (int64_t r = 0; r < dimR; r++) {

            for (int64_t c = 0; c < dimC; c++) {

                for (int64_t f = 0; f < dimF; f++) {

                    arr[d][r][c][f] =
                            d * helpers::dimR * helpers::dimC * helpers::dimF+
                            r * helpers::dimC * helpers::dimF +
                            c * helpers::dimF + f;

//					printf("arr[%lu][%lu][%lu][%lu] = %lu;\n",d,r,c,f,arr[d][r][c][f]);

//					int64_t offset = d * dimR * dimC * dimF + r * dimC * dimF + c * dimF + f;

//					printf("addr \t\t= %lu\n", *(addr + offset));

//					printf("offset \t\t= %lu\n", offset);

//					assert(arr[d][r][c][f] == offset);
//					assert(*(addr + offset) == offset);
                }
            }

        }
    } // Конец проверки линеаризации массива.


    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    std::cout << "Проверка поиска соседей в четырёхмерном массиве по каждой размерности" << std::endl;

    addr = start;

    std::cout << "minD = " << helpers::minD << '\n'
              << "maxD = " << helpers::maxD << '\n'
              << '\n'
              << "minR = " << helpers::minR << '\n'
              << "maxR = " << helpers::maxR << '\n'
              << '\n'
              << "minC = " << helpers::minC << '\n'
              << "maxC = " << helpers::maxC << '\n'
              << '\n'
              << "minF = " << helpers::minF << '\n'
              << "maxF = " << helpers::maxF << '\n';

    for (int64_t d = 0; d < dimD; d++) {
        for (int64_t r = 0; r < dimR; r++) {
            for (int64_t c = 0; c < dimC; c++) {
                for (int64_t f = 0; f < dimF; f++) {

                    int64_t offset = helpers::coefD * d + helpers::coefR * r + helpers::coefC * c + helpers::coefF * f;
                    assert(arr[d][r][c][f] == addr[offset]);
                    std::cout << "arr[ "
                              << d << " ][ "
                              << r << " ][ "
                              << c << " ][ "
                              << f << " ]= "
                              << arr[d][r][c][f] << '\n';

                    int32_t dd {0};
                    int32_t rr {0};
                    int32_t cc {0};
                    int32_t ff {0};
                    helpers::calculateDimIdx(dd,rr,cc,ff,offset);

                    std::cout << "arr[ "
                              << dd << " ][ "
                              << rr << " ][ "
                              << cc << " ][ "
                              << ff << " ]= "
                              <<  '\n';
//					helpers::calculateDimIdx(offset);
                    assert(d == dd);
                    assert(r == rr);
                    assert(c == cc);
                    assert(f == ff);

                    int32_t ddd {0};
                    int32_t rrr {0};
                    int32_t ccc {0};
                    int32_t fff {0};
                    helpers::calcDimIdx(ddd,rrr,ccc,fff,offset);
                    assert(d == ddd);
                    assert(r == rrr);
                    assert(c == ccc);
                    assert(f == fff);

                    auto [D,R,C,F] = helpers::calcDimIdx(offset);

                    assert(D == d);
                    assert(R == r);
                    assert(C == c);
                    assert(F == f);

                    std::cout << std::endl;

                    // Check dimF
                    auto [leftF, rightF] = helpers::calcAdjacent(offset, helpers::maskF);

                    // Check dimC
                    auto [leftC, rightC] = helpers::calcAdjacent(offset, helpers::maskC);

                    // Check dimR
                    auto [leftR, rightR] = helpers::calcAdjacent(offset, helpers::maskR);

                    // Check dimD
                    auto [leftD, rightD] = helpers::calcAdjacent(offset, helpers::maskD);

                    int64_t left_f  = (f == 0) ? dimF - 1 : f - 1;
                    int64_t right_f = (f == (dimF -1)) ? 0 : f + 1;

                    int64_t left_c = (c == 0) ? dimC - 1 : c - 1;
                    int64_t right_c = (c == (dimC -1)) ? 0 : c + 1;

                    int64_t left_r = (r == 0) ? dimR - 1 : r - 1;
                    int64_t right_r = (r == (dimR -1)) ? 0 : r + 1;

                    int64_t left_d = (d == 0) ? 0 : d - 1;
                    int64_t right_d = (d == (dimD -1)) ? dimD - 1 : d + 1;

                    int64_t left_offset_f = helpers::coefR * r + helpers::coefC * c + helpers::coefD * d + helpers::coefF * left_f;

                    int64_t right_offset_f = helpers::coefR * r + helpers::coefC * c + helpers::coefD * d + helpers::coefF * right_f;

                    int64_t left_offset_c = helpers::coefR * r + helpers::coefC * left_c + helpers::coefD * d + helpers::coefF * f;

                    int64_t right_offset_c = helpers::coefR * r + helpers::coefC * right_c + helpers::coefD * d + helpers::coefF * f;

                    int64_t left_offset_r = helpers::coefR * left_r + helpers::coefC * c + helpers::coefD * d + helpers::coefF * f;

                    int64_t right_offset_r = helpers::coefR * right_r + helpers::coefC * c + helpers::coefD * d + helpers::coefF * f;

                    int64_t left_offset_d = helpers::coefR * r + helpers::coefC * c + helpers::coefD * left_d + helpers::coefF * f;

                    int64_t right_offset_d = helpers::coefR * r + helpers::coefC * c + helpers::coefD * right_d + helpers::coefF * f;

                    assert(left_offset_f == leftF);
                    assert(right_offset_f == rightF);

                    assert(left_offset_c == leftC);
                    assert(right_offset_c == rightC);

                    assert(left_offset_r == leftR);
                    assert(right_offset_r == rightR);

                    assert(left_offset_d == leftD);
                    assert(right_offset_d == rightD);
                }
            }
        }
    }

    printf("Success\n");
    return 0;
}
