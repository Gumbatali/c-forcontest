#include <iostream>
#include <string>

int main() {
    char K;
    std::cin >> K;

    std::string N;
    std::cin >> N;

    int remainder = 0;
    for(char digit : N) {
        remainder = (remainder * 10 + (digit - '0')) % (K - '0');
    }

    std::cout << remainder << std::endl;

    return 0;
}