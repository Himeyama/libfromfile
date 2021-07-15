/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#include <fromfile.h>

int main(void){
    DFloat data = dFloatfromfile("testDBL.bin");
    dFloatprint(data);
    dFloatfree(data);

    return 0;
}

// make main
// LD_LIBRARY_PATH=. ./main

