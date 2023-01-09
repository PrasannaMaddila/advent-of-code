#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>

#include<fstream>
#include<string>
#include<sstream>

using namespace std; 

vector<int> split_string_by(string str, char delim){
    // Splits a string by delim and returns 
    // the vector results.
    stringstream ss(str); 
    vector<int> results;
    string word;  
    while ( getline(ss, word, delim) ){
        results.push_back(stoi(word)); 
    }
    return results; 
}

vector<vector<int>> read_file_and_tokenise_input(string filename){
    // Read the file
    ifstream fd; 
    fd.open(filename, ifstream::in);
    if(!fd.is_open()){
        cout << "File not found!" ; 
        exit(0); 
    }

    stringstream str_stream;
    str_stream << fd.rdbuf();
    string str = str_stream.str(); 

    // Tokenising my string 
    size_t pos = 0; 
    vector<vector<int>> tokens;
    string item; 
    while ((pos = str.find("\n\n")) != string::npos) {
        item = str.substr(0, pos);
        tokens.push_back( split_string_by(item, '\n') ); 
        str.erase(0, pos + 2);
    }
    return tokens; 
}

int main(){
    // Tokenising my string. 
    auto tokens = read_file_and_tokenise_input("input_1.txt"); 
    int best_elf = 0, curr_elf=0;
    for(auto& vec: tokens){
        for (auto& token: vec){ 
            curr_elf += token; 
        } 
        best_elf = max(best_elf, curr_elf); 
        curr_elf = 0; 
    }
    
    partial_sort(tokens.begin(), tokens.begin()+3, tokens.end(), 
            [](vector<int> left, vector<int> right){
                return accumulate(left.begin(), left.end(), 0) > accumulate(right.begin(), right.end(), 0); 
            });

    cout << "Best elf : " << best_elf << endl ; 
    best_elf = 0;
    for (int i = 0; i < 3; i++){
        best_elf += accumulate(tokens[i].begin(), tokens[i].end(), 0); 
    }
    cout << "First three: " << best_elf << endl ; 
}
