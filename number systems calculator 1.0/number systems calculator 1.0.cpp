#include <iostream>
#include <string>
#include <bitset> // Include the required header file for std::bitset
#include <sstream>
#include <algorithm>

// Convert a number from one base to another
std::string convert_base(const std::string& number, int from_base, int to_base) {
    // Convert the number to decimal
    int decimal_number = 0;
    int power = 1;
    for (int i = number.size() - 1; i >= 0; i--) {
        int digit = 0;
        if (number[i] >= '0' && number[i] <= '9') {
            digit = number[i] - '0';
        }
        else if (number[i] >= 'a' && number[i] <= 'z') {
            digit = number[i] - 'a' + 10;
        }
        else if (number[i] >= 'A' && number[i] <= 'Z') {
            digit = number[i] - 'A' + 10;
        }
        decimal_number += digit * power;
        power *= from_base;
    }

    // Convert the decimal number to the desired base
    std::stringstream ss;
    if (to_base == 2) {
        ss << std::bitset<32>(decimal_number).to_string();
    }
    else if (to_base == 8) {
        ss << std::oct << decimal_number;
    }
    else if (to_base == 10) { // Convert to base 10
        ss << decimal_number;
    }
    else if (to_base == 16) {
        ss << std::hex << decimal_number;
    }
    else {
        ss << "Unsupported base: " << to_base;
    }
    return ss.str();
}

int main() {
    std::cout << "Hello, I am a calculator for converting numbers to different number systems (2,8,10,16) \n";
    std::string number;
    int from_base, to_base;

    while (true) {
        std::cout << "Please enter the number you want to convert (or q to quit): ";
        std::cin >> number;

        if (number == "q") {
            std::cout << "Thank you for using our number base converter. Goodbye!\n";
            break;
        }

        std::cout << "What is the current number base (2, 8, 10, 16)? ";
        std::cin >> from_base;
        std::cout << "What number base do you want to convert to (2, 8, 10, or 16)? ";
        std::cin >> to_base;

        std::string converted = convert_base(number, from_base, to_base);
        std::cout << "Your number in base " << to_base << " is: " << converted << std::endl;
    }

    return 0;
}
