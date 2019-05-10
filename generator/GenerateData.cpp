#include "GenerateData.hpp"



GenerateData(std::string file, int size, int max){
    manageFile = new ManageFile(file);
}

std::string genstr()
{
    static const int SIZE = 6;
    static int counter = 0;
    char tab[SIZE+1];
    int value = counter ++;
    for (int i=0; (i<SIZE && value) || (i == 0 && value == 0); i++) {
        int dig = value % 26;
        value /= 26;
        tab[i] = 'A' + dig;
        tab[i+1]= 0;
    }
    return std::string(tab);
}

void genfile(int size, int max)
{
    std::string name[size];
    std::string ref[size][max];
    int nrefs[size];

    for (int i=0; i<size; i++) {
        name[i] = genstr();
        nrefs[i] = 1 + (rand() % (max-1));
    }

    for (int i=0; i<size; i++) {
        for (int r=0; r<nrefs[i]; r++) {
            int iref = rand() % size;
            ref[i][r] = name[iref];
        }
    }

    for (int i=0; i<size; i++) {
        std::cout << name[i];
        for (int r=0; r<nrefs[i]; r++) {
            std::cout << ' ' << ref[i][r];
        }
        std::cout << '\n';
    }
}

