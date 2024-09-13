#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Airplane.h"
using namespace std;

class ConfigFileParser {
public:
    static vector<Airplane*> parseFile(const string& filename);
};
