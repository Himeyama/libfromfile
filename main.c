/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#include <fromfile.h>

int main(void){
    DFloat data;

    double d[100];
    data.data = d;
    data.size = 100;
    for(int i = 0; i < 100; i++){
        d[i] = i / 10.0;
    }
    dFloat2file("testDBL.bin", data);

    DFloat data2 = dFloatFromFile("testDBL.bin");
    dFloatPrint(data2);
    dFloatFree(data2);


    return 0;
}

// make main
// LD_LIBRARY_PATH=. ./main

