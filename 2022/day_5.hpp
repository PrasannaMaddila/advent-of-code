#pragma once
#include "../utils/util.hpp"
#include<deque>
#include<stdio.h>

using std::deque;

// user defined types
using crate = char;
using crates = deque<crate>;
using pile_type = vector< crates >; 

typedef void (*worker_type)(array<int, 3>&, pile_type&);

const int NUM  = 0;
const int SRC  = 1;
const int DEST = 2;

constexpr inline int get_stack_num( const int pos ) {
    // equation is 4*x - 1 = buffer.size().
    // 3x per crate , and x-1 spaces per line.
    return ( pos + 1 ) / 4;
}

string parse_and_work(ifstream& stream, worker_type worker){
    string buffer;
    pile_type pile; 
    array<int, 3> instr;

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
        sscanf(buffer.c_str(),              // Read from the buffer using sscanf
            "move %d from %d to %d", 
            &instr[0], &instr[1], &instr[2]); 
        instr[SRC] -= 1; instr[DEST] -= 1;  // decrement to put them in range.
        worker( instr, pile );              // call the worker 
    }

    // Putting the top crate into buffer and returning. 
    buffer.clear(); 
    std::for_each( pile.begin(), pile.end(), 
            [&buffer](crates cr){ buffer += cr.back(); });
    return buffer;
}

#define PART_1
string part1(ifstream& stream){
    worker_type worker = [](array<int, 3>& instr, pile_type& pile){
        for ( int ctr = instr[NUM]; ctr > 0; ctr-- ){
            pile.at( instr[DEST] ).push_back( pile.at(instr[SRC]).back() );
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
            pile.at( instr[DEST] ).insert(              // insert begins here.
                pile.at(instr[DEST]).begin() + pos,     // location: begin+offet(pos)
                pile.at(instr[SRC]).back()              // inserting from SRC.back()
            );
            pile.at(instr[SRC]).pop_back();             // pop removes inserted crate from SRC
        }// end of instruction
    };
    return parse_and_work( stream, worker );
}
