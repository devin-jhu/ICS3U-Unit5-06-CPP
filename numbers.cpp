// Copyright (C) 2022 Devin Jhu All rights reserved
//
// Created by Devin Jhu
// Created on June 2022
// The rounder

#include <iostream>
#include <string>
#include <cmath>


void Rounding(float &number, int roundTo) {
    // rounds the users number to their desired decimal place

    int roundedNumber;
    roundedNumber = pow(10, roundTo);

    // https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/
    number = (static_cast<float>(static_cast<int>(number * roundedNumber + 0.5))
        / roundedNumber);
}


int main() {
    // Takes input, passes to function, then outputs the number

    std::string numberInput;
    std::string decimalString;
    float number;
    int decimal;

    std::cout << "This program rounds numbers" << std::endl;

    // input
    std::cout << "Enter number: ";
    std::cin >> numberInput;
    std::cout << "Enter decimal places to round to: ";
    std::cin >> decimalString;

    // process and output
    try {
        number = std::stof(numberInput);
        decimal = std::stoi(decimalString);
        if (decimal >= 0) {
            Rounding(number, decimal);
            std::cout << "\nThe rounded number is " << number << std::endl;
        } else {
            std::cout << "not a number" << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "not a number" << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
