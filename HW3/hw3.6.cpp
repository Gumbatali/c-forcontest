#include <string>

std::string ExtractDigits(const std::string& s) {
    std::string new_s;

    for (char c : s) {
        if (std::isdigit(c)) {
            new_s += c;
        }
    }

    return new_s;
}
