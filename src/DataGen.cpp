#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

void genLinear(const char * FilePath, int len){
    FILE * Fo = fopen(FilePath, "w");
    for (int i = 0; i < len; i++)
        fprintf(Fo, "%8x\n", i+1);
}
void genRandom(const char * FilePath, int len){
    printf("RAND_MAX = %d\n", RAND_MAX);
    printf("RAND_MAX = %x\n", RAND_MAX);
    FILE * Fo = fopen(FilePath, "w");
    for (int i = 0; i < len; i++)
        fprintf(Fo, "%8x\n", rand());

}
void genGrid(const char * FilePath, int len){
    string s = "11111111";
    FILE * Fo = fopen(FilePath, "w");
    for (; len; len--){
        fprintf(Fo, "%s\n", s.c_str());
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '9')
                s[i] = 'A';
            else if (s[i] == 'F')
                s[i] = '1';
            else s[i]++;

            if (s[i] != '1')
                break;
        }
    }
}
void genRevGrid(const char * FilePath, int len){
    string s = "11111111";
    FILE * Fo = fopen(FilePath, "w");
    for (; len; len--){
        fprintf(Fo, "%s\n", s.c_str());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '9')
                s[i] = 'A';
            else if (s[i] == 'F')
                s[i] = '1';
            else s[i]++;

            if (s[i] != '1')
                break;
        }
    }
}

int main(){
    int N = 1468000;
    genLinear("../data/Linear.key", 1468000);
    genRandom("../data/Random.key", 1468000);
    genGrid("../data/Grid.key", 1468000);
    genRevGrid("../data/RevGrid.key", 1468000);
    return 0;
}
