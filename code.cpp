#include <iostream>
#include <string>
#include <iomanip>

// validates input str
bool isValidNumber(const std::string& input) {
    int dotCount = 0;
    bool hasDigits = false;
    size_t i = 0;

    //checks for + or -
    if (input[i] == '+' || input[i] == '-') {
        i++;
    }

    for (; i < input.length(); ++i) {
        char c = input[i];
        if (isdigit(c)) {
            hasDigits = true;
        } else if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                return false; 
            }
        } else {
            return false; //invalid inp
        }
    }

    return hasDigits; //has >=1 digit
}

//format 4 decimal places
std::string formatNumber(const std::string& input) {
    size_t dotPos = input.find('.');
    std::string integerPart = input;
    std::string fractionalPart = "0000"; 

    //if there is decimal, split int
    if (dotPos != std::string::npos) {
        integerPart = input.substr(0, dotPos);
        fractionalPart = input.substr(dotPos + 1);

        //fractial part <= 4
        while (fractionalPart.length() < 4) {
            fractionalPart += '0'; // Pad with zeros
        }
        if (fractionalPart.length() > 4) {
            fractionalPart = fractionalPart.substr(0, 4);
        }
    }

    //combine
    return integerPart + "." + fractionalPart;
}

//display func
void processNumber(const std::string& input) {
    if (isValidNumber(input)) {
        std::string formattedNumber = formatNumber(input);
        std::cout << "The number is: " << formattedNumber << std::endl;
    } else {
        std::cout << "The input is invalid." << std::endl;
    }
}

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter a string (or 'END' to quit): ";
        std::getline(std::cin, input);

        if (input == "END") {
            break;
        }

        if (input.length() > 20) {
            std::cout << "The input exceeds 20 characters and cannot be processed." << std::endl;
        } else {
            processNumber(input);
        }
    }

    return 0;
}
