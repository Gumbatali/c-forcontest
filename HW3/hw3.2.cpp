#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> per(n), inv(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> per[i];
        inv[per[i] - 1] = i + 1;
    }

    for (int num : inv) {
        std::cout << num << " ";
    }

    return 0;
}
