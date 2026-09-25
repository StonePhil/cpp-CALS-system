#include <iostream>
#include <string>
#include <limits>


//declares the start of the main program and returns 0 by the end of it
//with 0 indicating successful completion with no errors
//(return of any other integer indicates an error)
int main() {
    std::string name;
    int num1= 0;
    int num2 = 0;

    std::cout << "enter your name: ";
    
    //getline is used instead of the "cin" operator to capture the full text string
    //in case the user uses space between two text strings
    std::getline(std::cin, name);

    std::cout << "Welcome " << name << " to C.A.L.S!\n\n";

    //standard "cin" operator used for number input
    //the "while" loop allows for repeated attempts in case
    //the user inputs non-number symbol(s) and clear the fail state
    std::cout << "enter first integer: ";
    while (!(std::cin >> num1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //removes the bad input
        std::cout << "invalid input, try again(first integer): ";
    }

    std::cout << "enter second integer: ";
    while (!(std::cin >> num2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "invalid input, try again(second integer): ";
    }

    std::cout << "\n-results-\n";
    std::cout << "added: " << (num1+ num2) << "\n";
    std::cout << "multiplied: " << (num1* num2) << "\n";

    //"static_cast<float>" method explicitly turns the "int a" into a float variable
    //right before the operation, so now the resulting variable is also a float
    if (num2 != 0) {
        std::cout << "divided: " << (static_cast<float>(num1) / num2) << "\n";
        std::cout << "remainder (modulo operation): " << (num1% num2) << "\n";
    } else {
        //stops from dividing by zero
        std::cout << "divided: undefined (can't divide by zero)\n";
        std::cout << "remainder (modulo): undefined (can't divide by zero)\n";
    }

    std::cout << "\nGoodbye " << name << ", see you again at C.A.L.S!\n";

    return 0;
}
