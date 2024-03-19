#include <iostream>

int main() {
    int sign = 1;
    int n;
    float result = 0;
    
    std::cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        result +=  static_cast<float>(sign)/i;
        sign *= -1;
    }
    std::cout << result << std::endl;
    return 0;
}
