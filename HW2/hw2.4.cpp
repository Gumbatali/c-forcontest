#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> field(n, std::string(m, '0'));

    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        field[x - 1][y - 1] = '*';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == '*') {
                std::cout << "* ";
            } else {
                int count = 0;
                for (int ni = -1; ni <= 1; ++ni) {
                    for (int nj = -1; nj <= 1; ++nj) {
                        int newi = i + ni;
                        int newj = j + nj;
                        if (newi >= 0 && newi < n && newj >= 0 && newj < m && field[newi][newj] == '*') {
                            count++;
                        }
                    }
                }
                std::cout << count<<' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}