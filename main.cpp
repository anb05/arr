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

                    printf("addr = %i\n", *(addr + offset));
                }
            }

        }
    }

    int arr4D[end];

    /*
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






    
    return 0;
}

