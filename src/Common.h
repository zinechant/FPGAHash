#define IntType unsigned long long
#define LL unsigned long long
const IntType N = 1468000;
const int M = 4;
const char * KeyFile[M] = {"../data/Linear.key", "../data/Random.key", 
    "../data/Grid.key", "../data/RevGrid.key"};
const char * MHashFile[M] = {"../data/Linear_Mur.hash", 
    "../data/Random_Mur.hash", "../data/Grid_Mur.hash", 
    "../data/RevGrid_Mur.hash"};
const char * THashFile[M] = {"../data/Linear_Tab.hash", 
    "../data/Random_Tab.hash", "../data/Grid_Tab.hash", 
    "../data/RevGrid_Tab.hash"};

const int HBit = 10;
const int HMax = 1<<HBit;

struct  HashTable{
    IntType key;
    IntType hash;
};

