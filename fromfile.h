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

long fsize(const char* filename);
DFloat dFloatFromFile(const char* filename);
void dFloatPrint(DFloat data);
void dFloatFree(DFloat data);
DFloat dFloat2file(const char* filename, DFloat data);
DFloat dFloatFromFileP(const char* filename, double *p);

#endif