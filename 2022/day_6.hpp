#pragma once
#include "../utils/util.hpp"
#include <deque>

using std::deque; 


int worker(ifstream& stream, const int buflen){
    string buffer, intern_buf;

    // get the buffer into the string.
    stream >> buffer; 

    // now iterate through it 
    for( auto itr = buffer.begin(); itr != buffer.end(); itr++){
        std::copy(itr, itr+buflen, std::back_inserter(intern_buf));
        std::sort(intern_buf.begin(), intern_buf.end()); 

        if ( std::adjacent_find(intern_buf.begin(), intern_buf.end()) == intern_buf.end())
            return std::distance(buffer.begin(), itr) + buflen;
        intern_buf.clear();
    }
    return -1;
}

#define PART_1
int part1(ifstream& stream){
    return worker(stream, 4);
}


#define PART_2
int part2(ifstream& stream){
    return worker(stream, 14);
}
