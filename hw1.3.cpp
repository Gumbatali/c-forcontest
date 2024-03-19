#include <iostream>

int main() {
    int v;
    int t;
    int right;
    std::cin >> v;
    std::cin >> t;
    right=v*t;
    if (v<0){
        while (right<0){
         right+=109;
        }
    }
    else{
        while (right>109){
        right-=109;
    }
    }
    std::cout << right << std::endl;
    return 0;
}
