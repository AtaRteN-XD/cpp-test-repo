#include <iostream>
#include <string>
#include <cmath>

using Number = double;

void ReadNumber(Number& first_number){
    if (!(std::cin >> first_number)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
    }
}

void Output(Number& result, Number& first_number){
    std::cout << result << std::endl;
    first_number = result;
    result = 0;
}

void RunCalculatorCycle(){
    std::string command;
    Number first_number = 0;
    Number second_number = 0;
    Number saved_number = 0;
    Number result = 0;
    bool was_saved_number = false;
    if (!(std::cin >> first_number)) {
        ReadNumber(first_number);
    }

    while (std::cin >> command) {
        if (command == "+"||command == "-"||command == "*"||command == "/"||command == "**") {
            if (!(std::cin >> second_number)) {
                ReadNumber(first_number);
            }
            if (command == "+") {
                first_number += second_number;
            } 
            else if (command == "-") {
                first_number -= second_number;
            } 
            else if (command == "*") {
                first_number *= second_number;
            } 
            else if (command == "/") {
                first_number /= second_number;
            }
            else if(command == "**"){
                first_number = std::pow(first_number, second_number);
            }
        }
        else if (command == "=") {
            result += first_number;
            Output(result, first_number);
        }
        else if (command == "c") {
            first_number = 0;
        } 
        else if (command == "q"){
            break;
        } 
        else if (command == ":") {
            ReadNumber(first_number);
        } 
        else if (command == "s") {
            saved_number = first_number;
            was_saved_number = true;
        }
        else if (command == "l") {
            if (was_saved_number == true){
                first_number = saved_number;
            }
            else{
                std::cerr << "Error: Memory is empty" << std::endl;
            }
        }
        else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            break;
        }
    }
}