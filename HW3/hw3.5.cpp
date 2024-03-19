#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>


/*

Implement the drive(double distance) method.
which reduces the fuel level depending on
distance traveled and increases mileage.
  Assume that the car consumes 1 liter
  fuel for 10 km.
Implement the refuel(double amount) method to
  add fuel to the tank.
Add a stop() method that prints a message
that the car has been stopped.
Implement an info() method that prints information
about the car: year of manufacture, color, number of doors,
fuel level and mileage.
Implement methods to change colors
car and obtaining current color values,
fuel level and mileage.
In the main function, create several Car objects with different characteristics.
Test all class methods to make sure they work correctly. Try walking some distance, refueling the car, changing its color and then displaying information about it.
*/

struct Car {
    int year;
    std::string color;
    int count_doors;
    int fuel_level;
    int mileage;
    Car(int y, std::string c, int d, double f = 50.0, double dis = 0.0) {
        year = y;
        color = c;
        count_doors = d;
        fuel_level = f;
        mileage = dis;
    };
    void print() {
        std::cout << year << ' ' << color << ' ' << count_doors << ' ' << fuel_level << ' ' << mileage << '\n';
    }
    void drive(double distance) {
        double fuel_consumed = distance / 10;
        if (fuel_consumed <= fuel_level) {
            fuel_level -= fuel_consumed;
            mileage += distance;
        } else {
            std::cout << "Not enough fuel \n";
        }
    }

};


int main() {
    Car car1(2010, "black", 5);
    car1.print();
    car1.drive(100);
    car1.print();
    Car car2(2022, "white", 3);
    car2.print();
    return 0;
}
