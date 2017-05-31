#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <assert.h>
#include <algorithm>

using namespace std;

#include "Common.h"

void stat(int f[], const char * FilePath){
    FILE * Fi = fopen(FilePath, "r");
    IntType x, y;
    memset(f,0,HMax*sizeof(f[0]));
    while (EOF != fscanf(Fi, " %llx %llx", &x, &y)){
        y = y & ((((IntType)1) << HBit) - (IntType)1);
        assert(y>=0 && y<HMax);
        f[y]++;
    }
    double mean = (0.0+N)/HMax;
    double var = 0.0, svar = 0.0;
    int ma = 0, mi = 1+N;
    for (int i = 0; i < HMax; i++){
        var = var + (f[i] - mean) * (f[i] - mean);
        mi = min(f[i], mi);
        ma = max(f[i], ma);
    }
    var /= HMax;
    svar = sqrt(var);

    printf("%-25s\tmin: %d, max: %d, std: %.3lf\n", FilePath, mi, ma, svar);
}

int main(){
    int f[HMax];
    for (int i = 0; i < M; i++){
        stat(f, MHashFile[i]);
    }
    return 0;
}