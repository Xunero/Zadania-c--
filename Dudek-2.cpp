#include <iostream>
#include <cmath>

using namespace std;

double obliczOdsetki(double kapital, double oprocentowanie, int okresKapitalizacji, int czasTrwania)
{
    double odsetki = 0;
    double stopaProcentowa = oprocentowanie / 100.0;

    for (int i = 0; i < czasTrwania; i += okresKapitalizacji) {
        double kapitalZOdsetkami = kapital * pow(1 + stopaProcentowa / okresKapitalizacji, okresKapitalizacji);
        odsetki = kapitalZOdsetkami - kapital;
        kapital = kapitalZOdsetkami;
    }

    return odsetki;
}

int zad1()
{
    double kapital,oprocentowanie,oczekiwaneOdsetki,odsetki = 0 ;
    int okresKapitalizacji, czasTrwania = 0;

    cout << "Podaj kapital poczatkowy, oprocentowanie, okres kapitalizacja (w miesiacach) oraz oczekiwana kwote odsetek " << endl;;
    cin >> kapital >> oprocentowanie >> okresKapitalizacji >> oczekiwaneOdsetki;

    while (odsetki < oczekiwaneOdsetki) {
        czasTrwania += okresKapitalizacji;
        odsetki = obliczOdsetki(kapital, oprocentowanie, okresKapitalizacji, czasTrwania);
    }

    cout << "Aby osiagnac " << oczekiwaneOdsetki << " zl odsetek, nalezy przetrzymac lokate przez " << czasTrwania << " miesiecy." << endl;

    return 0;
}

// funkcja znajdująca największą wartość w tablicy i jej pozycję
void findMax(int arr[], int size, int& maxVal, int& maxPos) {
    maxVal = arr[0];
    maxPos = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxPos = i;
        }
    }
}

// funkcja znajdująca najmniejszą wartość w tablicy i jej pozycję
void findMin(int arr[], int size, int& minVal, int& minPos) {
    minVal = arr[0];
    minPos = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minPos = i;
        }
    }
}

// funkcja obliczająca średnią wartość w tablicy
double findAvg(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

// funkcja znajdująca pozycję wartości podanej przez użytkownika
int findPos(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1; // zwracamy -1, gdy wartość nie występuje w tablicy
}



int zad2() {
    const int SIZE = 15;
    int arr[SIZE],find;
    
    // wczytanie liczb do tablicy
    cout << "Podaj " << SIZE << " roznych liczb calkowitych:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }
    
    // wyznaczenie największej wartości i jej pozycji
    int maxVal, maxPos;
    findMax(arr, SIZE, maxVal, maxPos);
    cout << "Najwieksza wartosc: " << maxVal << ", na pozycji: " << maxPos << endl;

    // wyznaczenie najmniejszej wartości i jej pozycji
    int minVal,minPos;
    findMin(arr, SIZE, minVal, minPos);
    cout << "Najwieksza wartosc: " << minVal << ", na pozycji: " << minPos << endl;
    // srednia
    cout << "Srednia wartosc: " << findAvg(arr, SIZE) << endl;
    
    cout << "Podaj szukana wartosc" << endl;
    cin >> find;
    cout << "Szukana liczba jest na pozycji" << findPos(arr, SIZE, find) << endl; 


    return 0;
}

int zad3() {

}
int main() {
    int chose;

    cout << "Podaj zadanie 1-3" << endl;
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

    if (chose > 6 || chose < 1) return 0;
    else main();
}