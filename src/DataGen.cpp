#include <cstdio>
#include <cstdlib>
#include <string>

#include "Common.h"

using namespace std;

void genLinear(const char * FilePath, IntType len){
    FILE * Fo = fopen(FilePath, "w");
    for (IntType i = 0; i < len; i++)
        fprintf(Fo, "%16llx\n", i+1);
}
void genRandom(const char * FilePath, IntType len){
    printf("RAND_MAX = %d\n", RAND_MAX);
    printf("RAND_MAX = %x\n", RAND_MAX);
    FILE * Fo = fopen(FilePath, "w");
    for (int i = 0; i < len; i++){
        IntType x = rand();
        x = x * ((IntType)1+RAND_MAX) + rand();
        fprintf(Fo, "%16llx\n", x);
    }

}
void genGrid(const char * FilePath, IntType len){
    int K = sizeof(IntType);
    unsigned char s[K];
    for (int i = 0; i < K; i++){
        s[i] = 1;
    }
    FILE * Fo = fopen(FilePath, "w");
    for (; len; len--){
        for (int i = 0; i < K; i++) {
            fprintf(Fo, "%02x", s[i]);
        }
        fprintf(Fo, "\n");
        for (int i = K-1; i >= 0; i--) {
            if (s[i] == 14)
                s[i] = 1;
            else s[i]++;
            if (s[i] != 1)
                break;
        }
    }
}
void genRevGrid(const char * FilePath, IntType len){
    int K = sizeof(IntType);
    unsigned char s[K];
    for (int i = 0; i < K; i++){
        s[i] = 1;
    }
    FILE * Fo = fopen(FilePath, "w");
    for (; len; len--){
        for (int i = 0; i < K; i++) {
            fprintf(Fo, "%02x", s[i]);
        }
        fprintf(Fo, "\n");
        for (int i = 0; i < K; i++) {
            if (s[i] == 14)
                s[i] = 1;
            else s[i]++;
            if (s[i] != 1)
                break;
        }
    }
}

int main(){
    genLinear(KeyFile[0], N);
    genRandom(KeyFile[1], N);
    genGrid(KeyFile[2], N);
    genRevGrid(KeyFile[3], N);
    return 0;
}
