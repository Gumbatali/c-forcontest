#include <iostream>
#include <iostream>


int main() {
    int day, month, year;
    std::cin >> day >> month >> year;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day >= 29) {
        std::cout << day-28 <<" " << month + 1 <<" " << year << std::endl;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day >= 28) {
                std::cout  << day-27<<" " << 3<<" " << year << std::endl;
            } else {
                std::cout  << day + 2<<" " << month<<" " << year << std::endl;
            }
        } else {
            if (day >= 27) {
                std::cout << day-26<<" " << 3 <<" "<< year << std::endl;
            } else {
                std::cout <<  day + 2<<" "  << month<<" "  << year << std::endl;
            }
        }
    } else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day >=30) {
        std::cout  << day-29 <<" "<< month + 1 <<" " << year << std::endl;
    } else if (month == 12 && day >= 30) {
        std::cout << day-29 <<" "<< 1 <<" "<<  year + 1 << std::endl;
    } else {
        std::cout << day + 2<<" " << month<<" " << year << std::endl;
    }

    return 0;
}