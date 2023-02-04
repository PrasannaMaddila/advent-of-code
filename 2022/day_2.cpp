#include "util.hpp"
#include<map>

using std::map; 

// Index: beats[i][j] = 1 if i beats j, 0 if draw and -1 if loss.
const signed int beats[3][3] = {{0, -1, 1}, {1, 0, -1}, {-1, 1, 0}};
enum Move{Rock, Paper, Scissors}; 
enum Decision{Lose=-1, Draw=0, Win=1}; 

using Moveset = map<char, Move>; 
using Strategy = map<char, Decision>; 

Moveset OPPN{{'A', Rock}, {'B', Paper}, {'C', Scissors}}; 
Moveset SELF{{'X', Rock}, {'Y', Paper}, {'Z', Scissors}}; 
Strategy ST_SELF{{'X', Lose}, {'Y', Draw}, {'Z', Win}}; 


// Code for part 1
int part1(ifstream& stream) {
    signed int score = 0, round_res = 0;
    char oppn, self; 

    while( stream >> oppn >> self ){
        round_res = 3 * beats[SELF[self]][OPPN[oppn]] + 3;  
        score += SELF[self] + round_res + 1;  
    }
    // Part 1
    return score; 
}

// Code for part 2 
int part2(ifstream& stream){
    signed int score = 0, round_res = 0, self_int = 0;
    char oppn, dec, self_move;
    
    while( stream >> oppn >> dec){
        for(auto const& elem: SELF){
            self_move = elem.first;
            self_int = elem.second; 
            if ( beats[self_int][OPPN[oppn]] == ST_SELF[dec] ) break;  
        }
        
        round_res = 3*ST_SELF[dec] + 3;
        score     += SELF[self_move] + round_res + 1;  
    }
    
    // Part 2
    return score; 
}

int main(int argc, char** argv){
    auto stream = create_ifstream_from_filename(argv[1]); 
    std::cout << "Part 1: score = " << part1(stream) << "\n"; 
    reset_ifstream(stream); 
    std::cout << "Part 2: score = " << part2(stream) << "\n"; 
}
