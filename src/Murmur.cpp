#include <cstdio>
#include <cstdlib>
#include <string>
#include <assert.h>
#include <sys/time.h>

#include "Common.h"

using namespace std;

int readKeys(IntType a[], const char * FilePath){
    FILE * Fi = fopen(FilePath, "r");
    IntType x;
    int n = 0;
    while (EOF != fscanf(Fi, "%x", &x)){
        a[n++] = x;
    }
    return n;
}

void Murmur(IntType a[], HashTable h[]){
    IntType x = 0;
    int w = sizeof(IntType) * 8 - 10;
    for (int i = 0; i < N; i++){
        x = a[i];
        h[i].key = x;
        x ^= x >> 33;
        x *= 0xff51afd7ed558ccd;
        x ^= x >> 33;
        x *= 0xc4ceb9fe1a85ec53;
        x ^= x >> 33;
        h[i].hash = x >> w;
    }
}

void WriteHashTable(HashTable h[], const char * FilePath){
    FILE * Fo = fopen(FilePath, "w");
    for (int i = 0; i < N; i++){
        fprintf(Fo, "%8x %8x\n", h[i].key, h[i].hash);
    }
}

int main(){
    for (int i = 0; i < M; i++){
        IntType* a = new IntType[N];
        int n = readKeys(a, KeyFile[i]);
        assert(n == N);

        struct timeval T;
        gettimeofday(&T, NULL);
        LL totalTime = (LL)T.tv_sec * (LL)1e6 + (LL)T.tv_usec ;

        HashTable* H = new HashTable[N];
        Murmur(a, H);

        gettimeofday(&T, NULL);
        totalTime = (LL)T.tv_sec * (LL)1e6 + (LL)T.tv_usec - totalTime;
        printf("%s takes %d us\n", MHashFile[i], totalTime);

        WriteHashTable(H, MHashFile[i]);
        
        delete[] a;
        delete[] H;
    }
}
