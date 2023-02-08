#pragma once
#include <benchmark/benchmark.h>

template<typename Callable>
static void bench_part(benchmark::State &state, Callable&& func, const char* filename){
    ifstream in_stream = create_ifstream_from_filename( filename ); 
    for (auto _ : state){
        // measure the result !!!
        benchmark::DoNotOptimize( func(in_stream) ); 
        reset_ifstream( in_stream );  
    }
}

#define Register(name, func)           \
    benchmark::RegisterBenchmark(name, \
            bench_part<decltype(func)>, func, argv[1]);
