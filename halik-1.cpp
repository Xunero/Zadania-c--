#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
#include <iomanip>

int factorial(int n) {

    if (n == 0 ) {
        return 1;
    }
    else if (n > 0)
    {
        return n * factorial(n-1);
    }
    
}

int zad1() {
    int value, fact;

    cout << "Podaj liczbe do silni:" << endl;
    cin >> value;

    fact = factorial(value)
    cout << "Silnia z " << value << "jest rowna" << fact << endl;

}

int star(int deapth){
    int amount = deapth;

    if (amount > 0)
    {
        cout << "*"
        --amount;
    }
    star(deapth-1);
    return 0;
}

int zad2() {
    int deapth;
    cout << " Podaj wielkosc" << endl;
    cin >> deapth;

    star(deapth);

}

int fibonaci(int value) {
    

}

int zad3() {
    int value;

    cout << "Podaj wartosc" << endl;
    cin >> value;

    fi = fibonaci(value)
    cout << "Wartosc: " << value << " jest rowna " << fi << endl;
    return 0;
}
int main() {
    int chose;

    cout << "Podaj zadanie 1-6" << endl;
    cin >> chose;

    switch (chose)
    {
    case 1:
        zad1();
        break;
    case 2:
        zad2();
        break;
    case 3:
        zad3();
        break;
    default:
        break;
    }
    
}
