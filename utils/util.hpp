#pragma once 
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>
#include <sstream>

using std::string; 
using std::array; 
using std::vector; 
using std::ifstream; 
using std::stringstream;

ifstream create_ifstream_from_filename(const string& filename){
    ifstream stream(filename, std::ios::binary); 
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

