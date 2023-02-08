#include HEADER
#include "bench.hpp"

// header for benchmarking the registered functions.
int main(int argc, char** argv){
    
    std::ios::sync_with_stdio(false);
    #ifdef PART_1
        Register("Part 1", part1);
    #endif
    #ifdef PART_2
        Register("Part 2", part2);
    #endif 

    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
    ::benchmark::Shutdown();
}
