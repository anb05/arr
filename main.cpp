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
    helpers::prinmsg(msg);

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	uint32_t dimR = helpers::dimR;
	uint32_t dimC = helpers::dimC;
	uint32_t dimD = helpers::dimD;
	uint32_t dimF = helpers::dimF;


	uint64_t arr[dimR][dimC][dimD][dimF];
	uint64_t* addr = &arr[0][0][0][0];
	uint64_t* start = addr;

	uint64_t end = helpers::size;

//	for (uint64_t i = 0; i < end; i++, ++addr) {
//        *addr = i;
//    }

    addr = start;

	printf("coefF = %li\n", helpers::coefF);
	printf("coefD = %li\n", helpers::coefD);
	printf("coefC = %li\n", helpers::coefC);
	printf("coefR = %li\n", helpers::coefR);

    msg = "Проверка линеаризации массива";
    helpers::prinmsg(msg);
    
	for (uint64_t r = 0; r < dimR; r++) {

		for (uint64_t c = 0; c < dimC; c++) {
            
			for (uint64_t d = 0; d < dimD; d++) {
                
				for (uint64_t f = 0; f < dimF; f++) {

					arr[r][c][d][f] = r * helpers::dimC * helpers::dimD * helpers::dimF +
							c * helpers::dimD * helpers::dimF +
							d * helpers::dimF + f;
                    
					printf("arr[%li][%li][%li][%li] = %li;\n",r,c,d,f,arr[r][c][d][f]);

					uint64_t offset = r * dimC * dimD * dimF + c * dimD * dimF + d * dimF + f;

					printf("addr \t\t= %li\n", *(addr + offset));

					printf("offset \t\t= %li\n", offset);
                }
            }

        }
    } // Конец проверки линеаризации массива.

    /*
	uint64_t arr4D[end];


	uint64_t cnt = 0;

	for (uint64_t r = 0; r < dimR; r++, ++cnt) {

		for (uint64_t c = 0; c < dimC; c++, ++cnt) {
            
			for (uint64_t d = 0; d < dimD; d++, ++cnt) {
                
				for (uint64_t f = 0; f < dimF; f++, ++cnt) {
                    
                    arr4D[cnt] = r * dimC * dimD * dimF + c * dimD * dimF + d * dimF + f;

                }
            }

        }
    }
    */

    /*
    printf("Size = %i\n", helpers::size);

    std::cout << "dimR = " << dimR << '\n';
    std::cout << "dimC = " << dimC << '\n';
    std::cout << "dimD = " << dimD << '\n';
    std::cout << "dimF = " << dimF << '\n';

	uint64_t iL = 2080;
    printf("addr = %i\n", *(addr + iL));

	uint64_t coefF = 1;
	uint64_t coefD = coefF * dimF;
	uint64_t coefC = coefD * dimD;
	uint64_t coefR = coefC * dimC;

	uint64_t siblingR = iL - coefR;
	uint64_t siblingC = iL - coefC;
	uint64_t siblingD = iL - coefD;
	uint64_t siblingF = iL - coefF;

	uint64_t r = 0;
	uint64_t c = 0;
	uint64_t d = 0;
	uint64_t f = 0;

    if (end <= iL)
        iL = end;

    if (iL < end) {
        while (coefR < iL) {
            ++r;
            iL -=coefR;
        }
        while (coefC < iL) {
            ++c;
            iL -= coefC;
        }
        while (coefD < iL) {
            ++d;
            iL -= coefD;
        }
        f = iL;
    }

    printf("arr[%i][%i][%i][%i] = %i;\n",r,c,d,f,arr[r][c][d][f]);
    


    r = 0;
    c = 0;
    d = 0;
    f = 0;

    iL = siblingC;

    if (iL < end) {
        while (coefR < iL) {
            ++r;
            iL -=coefR;
        }
        while (coefC < iL) {
            ++c;
            iL -= coefC;
        }
        while (coefD < iL) {
            ++d;
            iL -= coefD;
        }
        f = iL;
    }
    printf("arr[%i][%i][%i][%i] = %i;\n",r,c,d,f,arr[r][c][d][f]);

    */

    /*
	for (uint64_t cnt = 0; cnt < end; cnt++) {

        iL = cnt;

		uint64_t r = 0;
		uint64_t c = 0;
		uint64_t d = 0;
		uint64_t f = 0;

        if (iL < end) {
            while (coefR < iL) {
                ++r;
                iL -=coefR;
            }
            while (coefC < iL) {
                ++c;
                iL -= coefC;
            }
            while (coefD < iL) {
                ++d;
                iL -= coefD;
            }
            f = iL;
        }

        if (arr[r][c][d][f] != *(addr + cnt))
            std::cout << "ERROR !!!!!" << std::endl;

    }
    */

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    std::cout << "Проверка поиска соседей в четырёхмерном массиве по каждой размерности" << std::endl;

    /*
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";


    std::cout << "Проверка поиска соседей по размерности F" << std::endl;

	uint64_t r = 2;
	uint64_t c = 2;
	uint64_t d = 8;
	uint64_t f = 19;

    std::cout << "arr[" << r << "]["
                        << c << "]["
                        << d << "]["
                        << f << "] = "
                        << arr[r][c][d][f] << '\n';

	uint64_t offset = helpers::coefR * r + helpers::coefC * c + helpers::coefD * d + helpers::coefF * f;

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    std::cout << "offset = " << offset << '\n';

    f -= 1;

    std::cout << "arr[" << r << "]["
                        << c << "]["
                        << d << "]["
                        << f << "] = "
                        << arr[r][c][d][f] << '\n';

    offset -= helpers::coefF;

    std::cout << "offset = " << offset << '\n';
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    */
    
    //[[maybe_unused]] auto [left, right] = helpers::calculateAdjacent(10, helpers::coefD);

    printf("Array size = %i\n", helpers::size);
    //printf("maskF = %x\n", helpers::maskF);
    //printf("maskD = %x\n", helpers::maskD);
    //printf("mraskC = %x\n", helpers::maskC);
    //printf("maskR = %x\n", helpers::maskR);

    //helpers::calculateAdjacent(31, helpers::maskF);
    //helpers::calculateAdjacent(31, helpers::maskD);
    //helpers::calculateAdjacent(31, helpers::maskC);
    //helpers::calculateAdjacent(31, helpers::maskR);

    addr = start;


	for (uint64_t r = 0; r < dimR; r++) {
		for (uint64_t c = 0; c < dimC; c++) {
			for (uint64_t d = 0; d < dimD; d++) {
				for (uint64_t f = 0; f < dimF; f++) {
//					printf("arr[%li][%li][%li][%li] = %li\n",r,c,d,f,arr[r][c][d][f]);
					uint64_t offset = helpers::coefR * r +
                                 helpers::coefC * c +
                                 helpers::coefD * d +
                                 helpers::coefF * f;

                    //printf("addr[%li] = %i\n", offset, addr[offset]);

                    assert(arr[r][c][d][f] == addr[offset]);

                    // Check dimF
					auto [leftF, rightF] = helpers::calculateAdjacent(offset, helpers::maskF, helpers::coefF);

					// Check dimD
					auto [leftD, rightD] = helpers::calculateAdjacent(offset, helpers::maskD, helpers::coefD);

					// Check dimC
					auto [leftC, rightC] = helpers::calculateAdjacent(offset, helpers::maskC, helpers::coefC);

					// Check dimR
					auto [leftR, rightR] = helpers::calculateAdjacent(offset, helpers::maskR, helpers::coefR);

					uint64_t left_f  = (f == 0) ? dimF - 1 : f - 1;
					uint64_t right_f = (f == (dimF -1)) ? 0 : f + 1;

					uint64_t left_d = (d == 0) ? dimD - 1 : d - 1;
					uint64_t right_d = (d == (dimD -1)) ? 0 : d + 1;

					uint64_t left_c = (c == 0) ? dimC - 1 : c - 1;
					uint64_t right_c = (c == (dimC -1)) ? 0 : c + 1;

					uint64_t left_r = (r == 0) ? dimR - 1 : r - 1;
					uint64_t right_r = (r == (dimR -1)) ? 0 : r + 1;

					uint64_t left_offset_f = helpers::coefR * r +
                                        helpers::coefC * c +
                                        helpers::coefD * d +
                                        helpers::coefF * left_f;

					uint64_t right_offset_f = helpers::coefR * r +
                                         helpers::coefC * c +
                                         helpers::coefD * d +
                                         helpers::coefF * right_f;

					uint64_t left_offset_d = helpers::coefR * r +
										helpers::coefC * c +
										helpers::coefD * left_d +
										helpers::coefF * f;

					uint64_t right_offset_d = helpers::coefR * r +
										 helpers::coefC * c +
										 helpers::coefD * right_d +
										 helpers::coefF * f;

					uint64_t left_offset_c = helpers::coefR * r +
										helpers::coefC * left_c +
										helpers::coefD * d +
										helpers::coefF * f;

					uint64_t right_offset_c = helpers::coefR * r +
										 helpers::coefC * right_c +
										 helpers::coefD * d +
										 helpers::coefF * f;

					uint64_t left_offset_r = helpers::coefR * left_r +
										helpers::coefC * c +
										helpers::coefD * d +
										helpers::coefF * f;

					uint64_t right_offset_r = helpers::coefR * right_r +
										 helpers::coefC * c +
										 helpers::coefD * d +
										 helpers::coefF * f;

//                    printf("r = %i\tc = %i\td = %i\tf = %i\n",r,c,d,f);
//                    printf("r = %i\tc = %i\td = %i\tleft_f = %i\n",r,c,d,left_f);
//                    printf("r = %i\tc = %i\td = %i\tright_f = %i\n",r,c,d,right_f);
//                    printf("left_offset_f = %i\n", left_offset_f);
//                    printf("right_offset_f = %i\n", right_offset_f);
//                    printf("offset = %i\n",offset);
//                    printf("left = %li\n", left);
//                    printf("right = %li\n", right);


//                    std::string ch;

//                    while (std::cin >> ch) {
//                        printf("ch = %s\n", ch.c_str());
//                        break;
//                    }

					assert(left_offset_f == leftF);
					assert(right_offset_f == rightF);

//					assert(left_offset_d == leftD);
//					assert(right_offset_d == rightD);

//					assert(left_offset_c == leftC);
//					assert(right_offset_c == rightC);

//					assert(left_offset_r == leftR);
					assert(right_offset_r == rightR);
				}
            }
        }
    }

    return 0;
}

