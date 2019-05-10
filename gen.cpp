#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>

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


int main(int argc, char* argv[])
{
	srand(time(0) * getpid());
	int num_lines = 10;
	int max_refs = 5;
	if (argc > 1) {
		num_lines = atoi(argv[1]);
		if (argc > 2) {
			max_refs = atoi(argv[2]);
		}
	}
	genfile(num_lines, max_refs);
	return 0;
}