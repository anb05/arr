#include "./helpers.hpp"

#include <iostream>

int main(int argc, char const** argv)
{
    std::string msg {"Learn CMake"};
    helpers::prinmsg(msg);

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    int dimR = helpers::dimR;
    int dimC = helpers::dimC;
    int dimD = helpers::dimD;
    int dimF = helpers::dimF;


    int arr[dimR][dimC][dimD][dimF];
    int* addr = &arr[0][0][0][0];
    int* start = addr;

    int end = dimR * dimC * dimD * dimF;

    for (int i = 0; i < end; i++, ++addr) {
        *addr = i;
    }

    addr = start;

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
    }

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




    printf("Size = %i\n", end);

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

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
    int siblingC = iL + coefC;
    int siblingD = iL + coefD;
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

    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    */

    return 0;
}

