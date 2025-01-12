#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"

void PrintMenu() {
    std::cout << "1. Add" << '\n'
              << "2. Subtract" << '\n'
              << "3. Multiply" << '\n'
              << "4. Divide" << '\n'
              << "5. Power" << '\n'
              << "6. Sin" << '\n'
              << "7. Cos" << '\n'
              << "8. Tan" << '\n'
              << "9. Sqrt" << '\n'
              << "10. Log" << '\n'
              << "11. Ln" << '\n'
              << "12. Factorial" << '\n'
              << "13. Inverse" << '\n'
              << "14. Compare" << '\n'
              << "0. Quit" << '\n';

    std::cout << "Enter your choice: ";
    std::string choice;
    std::cin >> choice;

    int choice_int = std::stoi(choice);
    if (choice_int < 0 || choice_int > 14) {
        std::cout << "Invalid choice" << '\n';
        return;
    } else {
        op = static_cast<OPERATOR>(choice_int);
    }
}

bool ValidateInput() {
    if (op == DIVIDE && operand_2 == 0) {
        std::cout << "Cannot divide by zero" << '\n';
        return false;
    }
    if (op == SQRT && operand_1 < 0) {
        std::cout << "Cannot take square root of a negative number" << '\n';
        return false;
    }
    if (op == LOG && operand_1 <= 0) {
        std::cout << "Cannot take log of a non-positive number" << '\n';
        return false;
    }
    if (op == LN && operand_1 <= 0) {
        std::cout << "Cannot take ln of a non-positive number" << '\n';
        return false;
    }
    if (op == FACTORIAL && operand_1 < 0) {
        std::cout << "Cannot take factorial of a negative number" << '\n';
        return false;
    }
    return true;
}

bool GetInput() {
    if (op == ADD || op == SUBTRACT || op == MULTIPLY || op == COMPARE) {
        std::cout << "Enter the first number: ";
        std::cin >> operand_1;
        std::cout << "Enter the second number: ";
        std::cin >> operand_2;
    }
    if (op == DIVIDE) {
        std::cout << "Enter the dividend: ";
        std::cin >> operand_1;
        std::cout << "Enter the divisor: ";
        std::cin >> operand_2;
    }
    if (op == POWER) {
        std::cout << "Enter the base: ";
        std::cin >> operand_1;
        std::cout << "Enter the exponent: ";
        std::cin >> operand_2;
    }
    if (op == SIN || op == COS || op == TAN) {
        std::cout << "Enter the angle in degrees: ";
        std::cin >> operand_1;
    }
    if (op == SQRT || op == LOG || op == LN || op == FACTORIAL || op == INVERSE) {
        std::cout << "Enter the number: ";
        std::cin >> operand_1;
    }
    if (op == QUIT) {
        return false;
    }
    if (ValidateInput()) {
        Calculate();
    }
    return true;
}

double Calculate() {
    switch (op) {
        case ADD:
            result = operand_1 + operand_2;
            break;
        case SUBTRACT:
            result = operand_1 - operand_2;
            break;
        case MULTIPLY:
            result = operand_1 * operand_2;
            break;
        case DIVIDE:
            result = operand_1 / operand_2;
            break;
        case POWER:
            result = std::pow(operand_1, operand_2);
            break;
        case SIN:
            result = std::sin(operand_1 * pi / 180);
            break;
        case COS:
            result = std::cos(operand_1 * pi / 180);
            break;
        case TAN:
            result = std::tan(operand_1 * pi / 180);
            break;
        case SQRT:
            result = std::sqrt(operand_1);
            break;
        case LOG:
            result = std::log10(operand_1);
            break;
        case LN:
            result = std::log(operand_1);
            break;
        case FACTORIAL:
            result = 1;
            for (int i = 1; i <= operand_1; i++) {
                result *= i;
            }
            break;
        case INVERSE:
            result = 1 / operand_1;
            break;
        case COMPARE:
            if (operand_1 > operand_2) {
                result = operand_1;
            } else {
                result = operand_2;
            }
            break;
        case QUIT:
            break;
    }
    return result;
}

#endif // MENU_CPP