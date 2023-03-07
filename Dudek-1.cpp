#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
#include <iomanip>
#include <cstring>


int kula() {
    float promien;
    cout << "Podaj promien kuli" << endl;
    cin >> promien;
    float objetosc = (4/3)* M_PI * pow(promien, 3);
    float pole = 4*M_PI*pow(promien,2);

    cout << "Kula o promieniu " << promien <<" ma objetosc "<< objetosc << ", oraz pole " << pole <<endl << endl;

    return 0;
}

int prosto() {
    float a,b,c;
    cout << "Podaj dlugosc 1. krawedzi, 2. krawedzi oraz 3. krawedzi" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    float objetosc = a*b*c;
    float pole = (2*a*b) + (2*b*c) + (2*c*a);

    cout <<"Objetosc protopadloscianu = " << objetosc << "\nPole protopadloscianu = " << pole << endl;

    return 0;
}

int stozek() {
    float promien,tworzaca,wysokosc;
    cout << "Podaj promien,wysokosc oraz tworzaca stozka" << endl;
    cin >> wysokosc;
    cin >> promien;
    cin >> tworzaca;

    float objetosc = 0.33 * M_PI * pow(promien,2) * wysokosc;
    float pole = M_PI * promien * (promien+tworzaca);

    cout <<"Objetosc stozka = " << objetosc << "\nPole stozka = " << pole << endl;
    return 0;
}

int zad1() {
    cout << "1.Kula \n2.Prostopadloscian \n3.Stozek" << endl;
    int wybor;
    cin >> wybor;

    switch (wybor) {
        case 1:
            kula();
            break;
        case 2:
            prosto();
            break;
        case 3:
            stozek();
            break;
        default:
            break;
    }
    return 0;
} 

int zad2() {
    int ilosc,suma = 0;
    float ocena,srednia;
    cout <<" Ile ocen chcesz podac ?" << endl;
    cin >> ilosc;
    cout << "Oceny: " << endl;

    for (int i = 0; i <= ilosc-1; i++)
    {
        cin >> ocena;
        suma = ocena + suma;
    }
    
    srednia = suma / (float)ilosc ;
    cout << "Srednia ocen to: " << endl;
    cout << fixed << setprecision(2) << srednia;

    if(srednia > 4.1) cout << "\nStudentowi nalezy sie stypendium" << endl;
    else cout << "\nStudentowi nie nalezy sie stypendium" << endl;

    return 0;
}

int zad3() {
    int pietra;
    cout <<"Podaj wielkosc piramidy" << endl;
    cin >> pietra;

    for (int i = 1; i <= pietra; i++)
    {
        for (int k = 1; k <= pietra - i; k++)
        {
            cout << " ";
        }
        
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
            if (j < i)
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
    

    return 0;
}

int zad4() {

    const int MAX_SIZE = 100;
    char sentence[MAX_SIZE];
    cout << "Podaj zdanie: ";
    cin.getline(sentence, MAX_SIZE);

    // Liczenie ilości liter, liter bez spacji oraz liter bez danego znaku
    int letterCount = 0;
    int letterCountWithoutSpace = 0;
    int letterCountWithoutChar = 0;
    char ignoredChar;

    cout << "Podaj znak, ktory ma zostac zignorowany: ";
    cin >> ignoredChar;
    
    for (int i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            letterCount++;
            if (sentence[i] != ' ') {
                letterCountWithoutSpace++;
            }
            if (sentence[i] != ignoredChar) {
                letterCountWithoutChar++;
            }
        }
    }
    cout << "Ilosc liter: " << letterCount << endl;
    cout << "Ilosc liter bez spacji: " << letterCountWithoutSpace << endl;
    cout << "Ilosc liter bez '" << ignoredChar << "': " << letterCountWithoutChar << endl;

    // Wypisywanie wyrazów w zdaniu
    cout << "Wyrazy w zdaniu:" << endl;
    char* word = strtok(sentence, " ");
    while (word != nullptr) {
        cout << word << endl;
        word = strtok(nullptr, " ");
    }

    // Dzielenie zdania na części w oparciu o znak
    const char DELIMITER = ',';
    char** parts = nullptr;
    int partsCount = 0;
    word = strtok(sentence, &DELIMITER);
    while (word != nullptr) {
        char** newParts = new char*[partsCount+1];
        for (int i = 0; i < partsCount; i++) {
            newParts[i] = parts[i];
        }
        newParts[partsCount] = new char[strlen(word)+1];
        strcpy(newParts[partsCount], word);
        delete[] parts;
        parts = newParts;
        partsCount++;
        word = strtok(nullptr, &DELIMITER);
    }

    // Wypisywanie części zdania
    cout << "Czesci zdania oddzielone '" << DELIMITER << "':" << endl;
    for (int i = 0; i < partsCount; i++) {
        cout << parts[i] << endl;
        delete[] parts[i];
    }
    delete[] parts;

    return 0;
}


int main() {
    cout << "Wybierz zadanie 1-4" << endl;

    int wybor;
    cin >> wybor;

    switch (wybor)
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
    default:
        break;
    }
    return 0;
}