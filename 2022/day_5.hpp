#pragma once
#include "../utils/util.hpp"
#include<deque>

using std::deque;
using std::function;
using crate = char;
using crates = deque<crate>;
using pile_type = vector< crates >; 
using worker_type = function< void(array<int, 3>&, pile_type&) >;

const int NUM  = 0;
const int SRC  = 1;
const int DEST = 2;

inline int get_stack_num( int pos ) {
    // equation is 4*x - 1 = buffer.size().
    // 3x per crate , and x-1 spaces per line.
    return ( pos + 1 ) / 4;
}
void disp_pile( pile_type& pile ) {
    std::cout << '\n';
    for( auto const& stack: pile ){
        std::cout << "|> "; 
        if (!stack.empty()) 
            for (char cr: stack) 
                std::cout << cr << ' ';
        std::cout << '\n';
    }
}

string parse_and_work(ifstream& stream, worker_type worker){
    string buffer;
    pile_type pile; 
    array<string, 3> words; 
    array<int, 3> instr;
    stringstream sstr;

    // read the first line to get number of stacks 
    std::getline(stream, buffer, '\n');
    for ( int i = 0; i < get_stack_num(buffer.size()); i++) 
        pile.push_back( crates() ); 
    reset_ifstream( stream ); 

    // now to read the stacks and get the output.
    while ( std::getline( stream, buffer, '\n' ) ){
        if ( buffer.find('[') == string::npos ) break;
        for (int i=0; i < buffer.size(); i++){
            if (buffer[i] == '[')
                pile.at( get_stack_num(i) ).push_front( buffer[++i] );
        }
    }
    std::getline( stream, buffer, '\n');    // Get the cursor to the first instruction line.

    while( std::getline(stream, buffer, '\n') ){
        if ( buffer.empty() ) break;        // Only working on non-empty lines.
        sstr << buffer;                     // Using the sstream to parse.
        for (int i=0; i<3; i++)             // Reading each move instruction
            sstr >> words[i] >> instr[i];

        instr[SRC] -= 1; instr[DEST] -= 1;  // decrement to put them in range.
        worker( instr, pile );              // call the worker 
        sstr.clear();                       // clean up the stringstream after use!!!
    }
    
    // Putting the top crate into buffer and returning. 
    buffer.clear(); 
    std::for_each( pile.begin(), pile.end(), [&buffer](crates cr){
            buffer += cr.back();
            });
    return buffer;
}

#define PART_1
string part1(ifstream& stream){
    worker_type worker = [](array<int, 3>& instr, pile_type& pile){
         for ( int ctr = instr[NUM]; ctr > 0; ctr-- ){
            pile.at( instr[DEST] )
                .push_back( pile.at(instr[SRC]).back() );
            pile.at(instr[SRC]).pop_back();
        }// end of instruction
    };

    return parse_and_work( stream, worker );
}

#define PART_2
string part2(ifstream& stream){
    worker_type worker = [](array<int, 3>& instr, pile_type& pile){
        int pos = pile.at( instr[DEST] ).size();        // inserting at this location 
        for ( int ctr = instr[NUM]; ctr > 0; ctr-- ){
            pile.at( instr[DEST] )
                .insert( pile.at(instr[DEST]).begin() + pos, pile.at(instr[SRC]).back() );
            pile.at(instr[SRC]).pop_back();
        }// end of instruction
    };

    return parse_and_work( stream, worker );
}
