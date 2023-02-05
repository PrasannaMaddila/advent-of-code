#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <benchmark/benchmark.h>

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
}

#define Register(name, func) \
    benchmark::RegisterBenchmark(name, bench_part, func, argv[1]);

#endif
