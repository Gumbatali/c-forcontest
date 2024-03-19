#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> ans;
    if (str.empty()) {
        ans.push_back("");
        return ans;
    }
    if (delimiter == '\0') {
        ans.push_back(str);
        return ans;
    }

    std::string token;
    for (char c : str) {
        if (c != delimiter) {
            token += c;
        } else {
            ans.push_back(token);
            token = "";
        }
    }

    if (!token.empty() || str.back() == delimiter || ans.empty()) {
        ans.push_back(token);
    }

    return ans;
}

int main() {
    std::string str;
    std::cin >> str;

    char delimiter;
    std::cin >> delimiter;

    std::vector<std::string> result = split(str, delimiter);
    for (const std::string& s : result) {
        std::cout << s << std::endl;
    }

    return 0;
}
в 3.4.cpp все
#include <string>
#include <iostream>

        std::string join(const std::vector<std::string>& tokens, char c){
    std::string ans;
    for (const std::string& token: tokens){
        ans+=token+c;
    }
    ans.pop_back();
    return ans;

}

