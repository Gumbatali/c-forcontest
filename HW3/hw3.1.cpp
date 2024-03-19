#include <iostream>
#include <fstream>
#include <cctype>


void sol(std::ifstream& file, int& lt, int& w, int& ln){
    char c;
    bool word = false;
    while (file.get(c)){
        if (isalpha(c)){
            lt ++;
            if (!word){
                word = true;
            }
        }
        else {
            if (word){
                word = false;
                w++;
            }
        }

        if (iscntrl(c)){
            ln ++;
        }
    }
}

int main(){
    std::ifstream file("input.txt");
    int lt = 0;
    int w = 0;
    int ln = 0;
    if (file.is_open()){
        sol(file, lt, w, ln);
        file.close();
        std::cout << "Input file contains:" << std::endl;
        std::cout << lt << " letters" << std::endl;
        std::cout << w << " words" << std::endl;
        std::cout << ln << " lines" <<std::endl;
    }
    return 0;
}