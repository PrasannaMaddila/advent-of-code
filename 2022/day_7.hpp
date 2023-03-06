#pragma once
#include "../utils/util.hpp"
#include <iomanip>

const string prompt{"$"};
const int max_size = 100000;
inline int tok_type(const string& str){
    if (str == prompt) return 1; 
    if (str ==  "dir") return 2; 
    return 3;                   // has to be a number;
}


#define PART_1
int part1(ifstream& stream){
    unsigned long long result = 0, size; 
    string buffer, word;
    while( std::getline(stream, buffer, '\n')){
        if (std::isdigit(buffer[0])) 
            size = std::stoi(buffer); 
        else
            size = 0;
        std::cout << "comparision: " << size <= max_size << '\n';
        result += (size <= max_size) * size; 
    }
    return result;
}

//#define PART_2
int part2(ifstream& stream){
    int result = 0; 
    return result;
}
