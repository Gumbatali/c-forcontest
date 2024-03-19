#include <iostream>

int main() {
    int r1;
    int l1;
    int r2;
    int l2;
    std::cin >> r1;
    std::cin >> l1;
    std::cin >> r2;
    std::cin >> l2;

    if (abs(l1 - l2) == abs(r1 - r2)) {
        std::cout << "YES" << std::endl;
    }
    else if (r1 == r2 || l1 == l2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
