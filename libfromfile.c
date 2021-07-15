/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fromfile.h"


// ファイルサイズを調べる
long fsize(FILE* fp){
    fpos_t p, p1, p2;
    if(fgetpos(fp, &p) ||
        fseek(fp, 0, SEEK_END) ||
        fgetpos(fp, &p2) ||
        fseek(fp, 0, SEEK_SET) ||
        fgetpos(fp, &p1) ||
        fsetpos(fp, &p))
    return -1;
    return p2.__pos - p1.__pos;
}

DFloat dFloatfromfile(const char* filename){
    FILE* fp;
    DFloat data;
    if(fp = fopen(filename, "r")){
        long filesize;
        if((filesize = fsize(fp)) == -1) exit(EXIT_FAILURE);
        data.data = (double*)malloc(filesize);
        data.size = filesize / sizeof(double);
        long len = fread(data.data, sizeof(double), filesize / sizeof(double), fp);
        fclose(fp);        
    }else{
        exit(EXIT_FAILURE);
    }
    return data;
}

void dFloatprint(DFloat data){
    char* str = (char*)malloc(data.size * 16);
    char tmp[16];
    str[0] = '[';
    str[1] = 0;
    long sum = 0;
    for(long i = 0; i < data.size; i++){
        sum += sprintf(tmp, "%lf, ", data.data[i]);
        strcat(str, tmp);
    }
    str[sum-1] = ']';
    str[sum] = 0;
    puts(str);
    free(str);
}

void dFloatfree(DFloat data){
    free(data.data);
}
