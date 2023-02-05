#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <benchmark/benchmark.h>

using std::string; 
using std::array; 
using std::vector; 
using std::ifstream; 

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

static void bench_part(benchmark::State &state, int(*func)(ifstream&), const char* filename){
    int result = 0; 
    auto in_stream = create_ifstream_from_filename( filename ); 
    for (auto _ : state){
        // measure the result !!!
        benchmark::DoNotOptimize( result = func(in_stream) ); 

        // don't measure the reset !!! 
        state.PauseTiming(); 
        reset_ifstream( in_stream );  
        state.ResumeTiming(); 
    }
    std::cout << "Result : " << result << '\n'; 
}

#define Register(name, func) \
    benchmark::RegisterBenchmark(name, bench_part, func, argv[1]);

#endif
