#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
public:
    int add(int a, int b);
    int sub(int a, int b);
    int mul(int a, int b);
    int div(int a, int b);
    int calculate(int a, int b, char op);

};
#endif