#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using std::string; 
using std::array; 
using std::vector; 
using std::ifstream; 

//#include <benchmark/benchmark.h>

ifstream create_ifstream_from_filename(const string& filename){
    ifstream stream{filename}; 
    if ( !stream.is_open() ){
        std::cerr << "Opening " << filename << " failed. Exiting"; 
        exit(1); 
    }
    return stream; 
}

void reset_ifstream(ifstream& stream){
    stream.clear(); 
    stream.seekg(0); 
}

#endif
