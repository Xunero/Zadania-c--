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

int max(int array[], int x, int bigger) {
    if (x == 50) {
       return bigger; 
    } else {
        if (bigger < array[x])  {
            bigger = array[x];
            max(array, x+1, bigger);
        } else {
            max(array, x+1, bigger);
        }
    }
}

int zad4() {
    int array[50], ran, bigger = 0, x = 0;

    for (int i = 0; i < 50; i++)
    {
        ran = rand()%101;
        array[i] = ran;
    }

    cout <<"Najwieksza liczba to: " << max(array,x,bigger) << endl;

    return 0;
}

int NWD(int liczba0, int liczba1, int dzielnik) {
    if (liczba1 == 0)
    {
        return liczba0;
    } else{
        dzielnik = liczba1;
        liczba1 = liczba0 % liczba1;
        liczba0 = dzielnik;
        NWD(liczba0,liczba1,dzielnik);
    }    
    
}

int zad5() {
    int liczba0 = 0, liczba1 = 0, dzielnik = 0;
    cout << "Podaj dwie liczby: " << endl;
    cin >> liczba0;
    cin >> liczba1; 
    cout << "NWD = " << NWD(liczba0,liczba1,dzielnik) << endl;
    return 0;
}

void hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Przenies krazek z " << source << " na " << destination << endl;
    } else {
        hanoi(n-1, source, auxiliary, destination);
        cout << "Przenies krazek z " << source << " na " << destination << endl;
        hanoi(n-1, auxiliary, destination, source);
    }
}

int zad6() {
    int ilosc;
    cout << "Podaj liczbe krazkow" << endl;
    cin >> ilosc;
    hanoi(ilosc, 'A', 'B', 'C');
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
    case 4:
        zad4();
        break;
    case 5:
        zad5();
        break;
    case 6:
        zad6();
        break;
    default:
        break;
    }

    if (chose > 6 || chose < 1) return 0;
    else main();
}
