#include "util.hpp"

int get_score(const string& buffer){
    int score = 0; 
    for(char ch: buffer){
        if (std::islower(ch)) score += ch - 'a' + 1;
        else score += ch - 'A' + 27; 
    }
    return score;  
}

int part1(ifstream& stream){
    int len; 
    string buffer, common, temp; 
    array<string, 2> split_buf; 

    while(stream >> buffer){     
        // split by length
        len = buffer.length() / 2;  
        for (int i = 0; i < 2; i++){
            split_buf[i]  = buffer.substr(i * len, len) ;
            std::sort(split_buf[i].begin(), split_buf[i].end()); 
        }
        
        // get common elements into temp
        std::set_intersection(
                split_buf[0].begin(), split_buf[0].end(), 
                split_buf[1].begin(), split_buf[1].end(), 
                std::back_inserter(temp)
                ); 
        
        // remove duplicates and append them to common
        temp.erase( std::unique( temp.begin(), temp.end() ), temp.end() );
        common += temp;

        // prepare for next iteration
        temp.clear(); 
    }
    return get_score(common);
}

int part2(ifstream& stream){
    array<string, 3> buffer;
    array<string, 2> temp;
    string common;

    while(stream >> buffer[0] >> buffer[1] >> buffer[2]){     
        // prepare them for set_intersection
        for (auto& buf: buffer){
            std::sort(buf.begin(), buf.end()); 
        }
        
        // get common elements into temp
        std::set_intersection(
                buffer[0].begin(), buffer[0].end(), 
                buffer[1].begin(), buffer[1].end(), 
                std::back_inserter(temp[0])
                ); 
        std::set_intersection(
                temp[0].begin(), temp[0].end(), 
                buffer[2].begin(), buffer[2].end(), 
                std::back_inserter(temp[1])
                ); 
        
        // remove duplicates and append them to common
        temp[1].erase( std::unique( temp[1].begin(), temp[1].end() ), temp[1].end() );
        common += temp[1];

        // prepare for next iteration
        for (int i=0; i < 2; i++) temp[i].clear();
    }
    return get_score(common);
}


int main(int argc, char** argv){
    auto stream = create_ifstream_from_filename(argv[1]); 
    std::cout << "Part 1: score = " << part1(stream) << "\n"; 
    reset_ifstream(stream); 
    std::cout << "Part 2: score = " << part2(stream) << "\n"; 
}
