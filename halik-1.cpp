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
    return 0;
}

int zad1() {
    int value, fact;

    cout << "Podaj liczbe do silni:" << endl;
    cin >> value;

    fact = factorial(value);
    cout << "Silnia z " << value << " jest rowna " << fact << endl;

    return 0;
}

int star(int deapth){
    int amount = deapth;

    while (amount > 0)
    {
        cout << "*";
        --amount;
    }
     
    cout << endl;
    if(deapth > 0) star(deapth-1);
    return 0;
}

int zad2() {
    int deapth;
    cout << " Podaj wielkosc" << endl;
    cin >> deapth;

    star(deapth);

    return 0;
}

int fibonaci(int value) {
    int fi;
    if (value < 3) return 1;
    fi = fibonaci(value - 2) + fibonaci(value-1);

    return fi;
}

int zad3() {
    int value;
    int fi;
    cout << "Podaj wartosc" << endl;
    cin >> value;

    fi = fibonaci(value);
    cout << "Wartosc: " << value << " jest rowna " << fi << endl;
    return 0;
}

int max(int array[50]) {
    int bigger = array[0];
    
    for (int i = 1; i < 50; i++)
    {
        if (bigger < array[i])
        {
            bigger = array[i];
        }
        
    }
        
    return bigger;
}

int zad4() {
    int array[50],ran,bigger;

    for (int i = 0; i < 50; i++)
    {
        ran = rand()%101;
        array[i] = ran;
    }
    
    bigger = max(array);
    cout <<"Liczba najwieksza to: " << bigger << endl;

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

    if (chose < 6 && chose > 1) return 0;
    else main();
}
