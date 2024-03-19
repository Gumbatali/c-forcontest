#include <string>
#include <iostream>


std::string common_suffix(const std::string& a, const std::string& b) {
    std::string ans;

    int len_a = a.length();
    int len_b = b.length();

    int len = (std::min(len_a, len_b));

    for (int i = 1; i <= len; ++i) {
        if (a[len_a-i]==b[len_b-i]) {
            ans+=a[len_a-i];
        } else {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::string a = "elppe";
    std::string b = "apple";

    std::string suffix = common_suffix(a, b);
    std::cout << "Common suffix: " << suffix << std::endl;

    return 0;
}
