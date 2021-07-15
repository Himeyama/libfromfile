/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#ifndef FROMFILE_H
#define FROMFILE_H

#include <stdio.h>

typedef struct __DFloat{
    double* data;
    long size;
} DFloat;

long fsize(FILE* fp);
DFloat dFloatfromfile(const char* filename);
void dFloatprint(DFloat data);
void dFloatfree(DFloat data);
DFloat dFloatfromfilep(const char* filename, double *p);

#endif