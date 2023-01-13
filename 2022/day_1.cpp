#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using std::string;
using std::vector; 

int main(){
    string buffer;
    vector<int> elves; 

    short num_newlines = 0;
    int curr_sum = 0; 
    while(num_newlines < 2){ 
        while (getline(std::cin, buffer)){
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

    // part 1 of the code
    std::cout << "Top elf: "<< *std::max_element(elves.begin(), elves.end()) << "\n"; 

    // part 2 of the code 
    long elf_sum = 0;
    std::partial_sort( elves.begin(), elves.begin() + 3, elves.end(), std::greater_equal<int>());
    std::for_each(elves.begin(), elves.begin() + 3, [&elf_sum](int& elem) {
            elf_sum += elem; 
    });
    std::cout << "Top 3 elves carry " << elf_sum << std::endl;

    return 0; 
}
