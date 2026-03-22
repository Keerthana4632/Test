#include<iostream>
#include "calculator.h"

int Calculator::add(int a, int b){
    return a+b;
}

int Calculator::sub(int a, int b){
    return a-b;
}
int Calculator::mul(int a, int b){
    return a*b;
}

int Calculator::div(int a, int b){
    if (b == 0){
        return 0;
    }
    return a/b;
}
int Calculator::calculate(int a, int b, char op){
    switch(op){
        case '+':
            return add(a,b);
        case '-':
            return sub(a,b);
        case '*':
            return mul(a,b);
        case '/':
            return div(a,b);   
        default:
            return 0;                    
    }
    return a+b;
}