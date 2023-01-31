#include<iostream>
#include<string>
#include<map>

using std::map; 

// For part 1
enum Move{Rock, Paper, Scissors}; 
using Moveset = map<char, Move>; 

int main(){
    signed int score = 0, result = 0;
    char oppn, self; 
    
    Moveset OPPN{{'A', Rock}, {'B', Paper}, {'C', Scissors}}; 
    Moveset SELF{{'X', Rock}, {'Y', Paper}, {'Z', Scissors}}; 
    
    // Index: beats[i][j] = 1 if i beats j, 0 if draw and -1 if loss.
    const signed int beats[3][3] = {{0, -1, 1}, {1, 0, -1}, {-1, 1, 0}};
    
    while( std::cin >> oppn >> self ){
        result = 3 * beats[SELF[self]][OPPN[oppn]] + 3;  
        score += SELF[self] + result + 1;  
    }
    // Part 1
    std::cout << "This is my score: " << score << std::endl ; 
}
