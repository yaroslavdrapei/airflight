#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "CommandParams.h"
using namespace std;

class UserInputParser {
public:
    static CommandParams parse(const string& userInput);
};