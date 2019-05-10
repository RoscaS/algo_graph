#pragma once
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>

#include "ManageFile.hpp"

class GenerateData {
public:
    GenerateData(std::string file, int size, int max);
    void genfile(int size, int max);
private:
    std::string genstr();
    ManageFile* managerFile;
};


