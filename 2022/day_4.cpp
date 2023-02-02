#include <iostream>
#include <string>
#include <array>
#include <functional>
#include <algorithm>

// all the uses 
using std::string;
using std::array;

array<string, 2> split_by_char(const string& str, char delim){
    array<string, 2> result; 
    auto pos = str.find(delim);
    
    if (pos == string::npos) exit(0); 

    result[0] =  string{str.begin(), str.begin() + pos} ; 
    result[1] =  string{str.begin()+pos+1, str.end()} ;
    
    return result; 
}

int parse_and_get_score( std::function<void(array<int, 4>&, int&)> check){
    
    // bounds is an array of 4: the first two are for
    // the first range, the last two are for the second. 
    array<int, 4> bounds; 
    int score = 0, ctr = 0;
    string buffer;
    
    while(std::cin >> buffer){
        // process the input
        for (const string& range: split_by_char(buffer, ',') ){        
            for (const string& number: split_by_char(range, '-'))
                bounds[ctr++] = std::stoi(number);    
        }
        check(bounds, score);   // call the checking function. 
        ctr = 0;                // reset for next loop
    }//end input
    return score; 
}


int part1(){
    auto part1_check = [](array<int, 4>& bounds, int& score){
            bool check_left  = bounds.at(0) <= bounds.at(2) && bounds.at(1) >= bounds.at(3); 
            bool check_right = bounds.at(0) >= bounds.at(2) && bounds.at(1) <= bounds.at(3); 
            if (check_left || check_right) score += 1; 
        };

    return parse_and_get_score( part1_check ); 
}

int part2(){
    auto part2_check = [](array<int, 4>& bounds, int& score){
            if (bounds[0] > bounds[3]){
                // swap the pairs to get the lowest first.
                for ( int i=0; i < 2; i++) std::swap(bounds[i], bounds[i+2]); 
            }
            bool check_left  = bounds.at(0) <= bounds.at(2) && bounds.at(1) >= bounds.at(3); 
            bool check_partial = bounds[1] >= bounds[2]; 
            if (check_left || check_partial) score += 1; 
        };
    return parse_and_get_score( part2_check ); 
}


int main(){
    //std::cout << "Part 1: " << part1() << std::endl; 
    std::cout << "Part 2: " << part2() << std::endl; 
}
