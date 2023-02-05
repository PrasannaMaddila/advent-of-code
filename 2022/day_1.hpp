#ifndef DAY_1_HPP
#define DAY_1_HPP

#include "../utils/util.hpp"

int parse_and_work (ifstream& in_stream, std::function<int(vector<int>&)> worker ){
    string buffer;
    vector<int> elves; 

    short num_newlines = 0;
    int curr_sum = 0; 
    while(num_newlines < 2){ 
        while (getline(in_stream, buffer)){
            if (buffer.empty()) {
                num_newlines += 1; 
                break; 
            } 
            else{ 
                num_newlines = 0; // reset the counter 
                curr_sum += stoi(buffer); 
            } // end of if-else
        } // end of inner loop 

        elves.push_back(curr_sum);
        curr_sum = 0;  
    }// end of outer loop
    return worker ( elves ); 
}

#define PART_1
int part1(ifstream& in_stream){
    auto part1_lambda = [](vector<int>& elves){ 
        return *std::max_element( elves.begin(), elves.end()); 
    }; 
    return parse_and_work ( in_stream, part1_lambda );  
}

#define PART_2
int part2(ifstream& in_stream){
    auto part2_lambda = [](vector<int>& elves){ 
        long elf_sum = 0; 
        std::partial_sort( elves.begin(), elves.begin() + 3, elves.end(), std::greater_equal<int>());
        std::for_each(elves.begin(), elves.begin() + 3, [&elf_sum](int& elem) {
                elf_sum += elem; 
                });
        return elf_sum;
    }; 
    return parse_and_work ( in_stream, part2_lambda );  
}
#endif
