#include "calculator.h"
#include <iostream>

int main(){
    Calculator calc;

    int a, b;
    char op;
    int chumma;

    std::cout << "num1:";
    std::cin >> a;
    std::cout << "num2:";
    std::cin >> b;
    std::cout << "operator";
    std::cin >> op;

    int result = calc.calculate(a, b, op);
    std::cout << "result is" << result;
    std::cout >> End;
    return 0;
}
