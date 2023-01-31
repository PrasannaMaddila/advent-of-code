#include<iostream>
#include<map>
#include<array>
#include<algorithm>

using std::map;
using std::array; 

// For part 1
enum Move{Rock, Paper, Scissors}; 
using Moveset = map<char, Move>; 

// For part 2
enum Decision{Win=1, Draw=0, Lose=-1};
using Strategy = map<char, Decision>; 

int main(){
    signed int score = 0, result = 0;
    char oppn, self_dec, self_move; 
    
    Moveset OPPN{
        {'A', Rock}, 
        {'B', Paper}, 
        {'C', Scissors}
    }; 
    Moveset SELF_MOVE{
        {'X', Rock}, 
        {'Y', Paper}, 
        {'Z', Scissors}
    }; 
    Strategy SELF_DEC{
        {'X', Win}, 
        {'Y', Draw}, 
        {'Z', Lose}
    }; 
    
    // Index: beats[i][j] = 1 if i beats j, 0 if draw and -1 if loss.
    const array< array<int, 3>, 3> beats = {{
        {0, -1, 1}, 
        {1, 0, -1}, 
        {-1, 1, 0}
    }};
    
    while( std::cin >> oppn >> self_dec ){
        // result = 3 * beats[SELF[self]][OPPN[oppn]] + 3;  
        // decide the move
        int column  = OPPN[oppn]; 
        self_dec = (char) 'X' + *std::find_if( 
                    beats[column].begin(), beats[column].end(), [self_dec](int elem){
                        return self_elem == elem; 
                    });
        
        // then update the result
        result = self_dec;
        score += SELF_MOVE[self_move] + result + 1;  
    }
}

/*int j = OPPN[oppn]; 
switch (SELF_DEC[self_dec]){
    case Win:  result =  1;
    case Lose: result = -1; 
    case Draw: result =  0; 
}*/
