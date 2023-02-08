#include HEADER

int main(int argc, char** argv){
    ifstream in_stream{argv[1]}; 
    #ifdef PART_1
        std::cout << "Result of Part 1 = " << part1( in_stream ) << '\n'; 
    #endif
    #ifdef PART_2
        reset_ifstream ( in_stream );
        std::cout << "Result of Part 2 = " << part2( in_stream ) << '\n'; 
    #endif
}    
