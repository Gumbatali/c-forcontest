#include <iostream>
#include <string>


std::string Password(std::string p) {
    if (p.length() < 8 || p.length() > 14) {
        return "NO";
    }

    int clas = 0;
    bool Upp = false, Low = false, Num = false, Oth = false;
    for (char c : p) {
        if (c >= 33 && c <= 127) {
            if (c >= 'A' && c <= 'Z') {
                Upp = true;
            } else if (c >= 'a' && c <= 'z') {
                Low = true;
            } else if (c >= '0' && c <= '9') {
                Num = true;
            } else {
                Oth= true;
            }
        }
        else{
            return "NO";
        }
    }

    if (Upp) clas++;
    if (Low) clas++;
    if (Num) clas++;
    if (Oth) clas++;

    if (clas < 3) {
        return "NO";
    }
    else{
        return "YES";
    }
}

int main() {
    std::string p;
    std::cin >> p;
    std::cout << Password(p);

    return 0;
}