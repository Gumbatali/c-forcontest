#include <iostream>
#include <string>

std::string addOne(std::string N) {
    int carry = 1;
    for (int i = N.length() - 1; i >= 0; i--) {
        int digit = N[i] - '0' + carry;
        if (digit > 9) {
            carry = 1;
            digit -= 10;
        } else {
            carry = 0;
        }
        N[i] = digit + '0';
    }

    if (carry > 0) {
        N = '1' + N;
    }

    return N;
}

int main() {
    std::string N;
    std::cin >> N;

    std::string result = addOne(N);
    std::cout << result << std::endl;

    return 0;
}