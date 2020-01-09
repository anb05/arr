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

    int dimR = helpers::dimR;
    int dimC = helpers::dimC;
    int dimD = helpers::dimD;
    int dimF = helpers::dimF;


    int arr[dimR][dimC][dimD][dimF];
    int* addr = &arr[0][0][0][0];
    int* start = addr;

    int end = helpers::size;

    for (int i = 0; i < end; i++, ++addr) {
        *addr = i;
    }

    addr = start;

    /*
    msg = "Проверка линеаризации массива";
    helpers::prinmsg(msg);
    
    for (int r = 0; r < dimR; r++) {

        for (int c = 0; c < dimC; c++) {
            
            for (int d = 0; d < dimD; d++) {
                
                for (int f = 0; f < dimF; f++) {
                    
                    printf("arr[%i][%i][%i][%i] = %i;\n",r,c,d,f,arr[r][c][d][f]);

                    int offset = r * dimC * dimD * dimF + c * dimD * dimF + d * dimF + f;

                    printf("addr \t\t= %i\n", *(addr + offset));

                    printf("offset \t\t= %i\n", offset);
                }
            }

        }
    } // Конец проверки линеаризации массива.
    */

    /*
    int arr4D[end];


    int cnt = 0;

    for (int r = 0; r < dimR; r++, ++cnt) {

        for (int c = 0; c < dimC; c++, ++cnt) {
            
            for (int d = 0; d < dimD; d++, ++cnt) {
                
                for (int f = 0; f < dimF; f++, ++cnt) {
                    
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

    int iL = 2080;
    printf("addr = %i\n", *(addr + iL));

    int coefF = 1;
    int coefD = coefF * dimF;
    int coefC = coefD * dimD;
    int coefR = coefC * dimC;

    int siblingR = iL - coefR;
    int siblingC = iL - coefC;
    int siblingD = iL - coefD;
    int siblingF = iL - coefF;

    int r = 0;
    int c = 0;
    int d = 0;
    int f = 0;

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
    for (int cnt = 0; cnt < end; cnt++) {

        iL = cnt;

        int r = 0;
        int c = 0;
        int d = 0;
        int f = 0;

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

    int r = 2;
    int c = 2;
    int d = 8;
    int f = 19;

    std::cout << "arr[" << r << "]["
                        << c << "]["
                        << d << "]["
                        << f << "] = "
                        << arr[r][c][d][f] << '\n';

    int offset = helpers::coefR * r + helpers::coefC * c + helpers::coefD * d + helpers::coefF * f;

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

    addr = start;

    for (int r = 0; r < dimR; r++) {
        for (int c = 0; c < dimC; c++) {
            for (int d = 0; d < dimD; d++) {
                for (int f = 0; f < dimF; f++) {
                    //printf("arr[%i][%i][%i][%i] = %i\n",r,c,d,f,arr[r][c][d][f]);
                    int offset = helpers::coefR * r + 
                                 helpers::coefC * c +
                                 helpers::coefD * d +
                                 helpers::coefF * f;

                    //printf("addr[%li] = %i\n", offset, addr[offset]);

                    assert(arr[r][c][d][f] == addr[offset]);

                    // Check dimF
                    auto [left, right] = helpers::calculateAdjacent(offset, helpers::coefF);

                    int left_f = (f == 0) ? dimF - 1 : f - 1;
                    int right_f = (f == (dimF -1)) ? 0 : f + 1;

                    int left_offset_f = helpers::coefR * r +
                                        helpers::coefC * c +
                                        helpers::coefD * d +
                                        helpers::coefF * left_f;

                    int right_offset_f = helpers::coefR * r +
                                         helpers::coefC * c +
                                         helpers::coefD * d +
                                         helpers::coefF * right_f;

                    printf("r = %i\tc = %i\td = %i\tf = %i\n",r,c,d,f);
                    printf("r = %i\tc = %i\td = %i\tleft_f = %i\n",r,c,d,left_f);
                    printf("r = %i\tc = %i\td = %i\tright_f = %i\n",r,c,d,right_f);
                    printf("left_offset_f = %i\n", left_offset_f);
                    printf("right_offset_f = %i\n", right_offset_f);
                    printf("offset = %i\n",offset);
                    printf("left = %li\n", left);
                    printf("right = %li\n", right);


                    std::string ch;

                    while (std::cin >> ch) {
                        printf("ch = %s\n", ch.c_str());
                        break;
                    }

                    //assert(left_offset_f == left);
                    //assert(right_offset_f == right);

                }
            }
        }
    }


    return 0;
}

