#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

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
    cout << "Podaj promien,wysokosc oraz tworzaca stozka " << endl;
    cin >> wysokosc;
    cin >> promien;
    cin >> tworzaca;

    float objetosc = 0.33 * M_PI * pow(promien,2) * wysokosc;
    float pole = M_PI * promien * (promien+tworzaca);

    cout <<"Objetosc stozka = " << objetosc << "\nPole stozka = " << pole << endl;
    return 0;
}

int walec() {
    float promien, wysokosc;
    cout << "Podaj promien i wysokosc " << endl;
    cin >> promien;
    cin >> wysokosc;

    float objetosc = M_PI*pow(promien,2)*wysokosc;
    float pole = 2 * M_PI * pow(promien,2) + 2* M_PI* promien * wysokosc;

    cout <<"Objetosc walec = " << objetosc << "\nPole walec = " << pole << endl;
    return 0;
}

int zad1() {
    cout << "1.Kula \n2.Prostopadloscian \n3.Stozek\n 4. Walec" << endl;
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
        case 4:
            walec();
            break;    
        default:
            break;
    }
    return 0;
} 

int zad2() {
    int ilosc=0,suma = 0;
    float ocena,srednia;

    cout <<"Wpisz 0 aby przestac" << endl; // bez pytania ilu az 0
    cout << "Oceny: " << endl;

    do
    {
        cin >> ocena;
        if (ocena > 0)
        {
            suma = ocena + suma;
            ilosc++;
        }

    } while (ocena > 0);
    

    
    
    srednia = suma / (float)ilosc ;
    cout << "Srednia ocen to: " << endl;
    cout << fixed << setprecision(2) << srednia;

    if(srednia > 4.1) cout << "\nStudentowi nalezy sie stypendium" << endl;
    else cout << "\nStudentowi nie nalezy sie stypendium" << endl;

    return 0;
}

int zad3() {
    int pietra,how;
    cout <<"Podaj wielkosc piramidy" << endl;  
    cin >> pietra;
    cout << "Ma stac normalnie czy na glowie 1/2" << endl;
    cin >> how;

    if (how != 1 || how !=2)
    {
        cout << "Ma stac normalnie czy na glowie 1/2, wprowadza 1 albo 2" << endl;
        cin >> how;
    }
    
    if (how == 1)
    {
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
    }else
    
    for (int i = pietra; i >= 1; i--)   {
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
    string sentence;
    char delimiter;
    char skip;

    cout << "Podaj zdanie: " << endl;
    cin.ignore();
    getline(cin, sentence);

    cout << "Podaj litere do pominiecia: "<< endl;
    cin.ignore();
    cin >> delimiter;

    cout << "Podaj znak do pominiecia: " << endl;
    cin.ignore();
    cin >> skip;

    // policz wszystkie litery
    int letters_all = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (isalpha(sentence[i])) {
            letters_all++;
        }
    }
    cout << "Ilosc liter w zdaniu (lacznie ze spacjami): " << letters_all << endl;

    // policz litery bez spacji
    int letters_no_space = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (isalpha(sentence[i]) && sentence[i] != ' ') {
            letters_no_space++;
        }
    }
    cout << "Ilosc liter w zdaniu (bez spacji): " << letters_no_space << endl;

    // policz litery bez podanego znaku
    int letters_no_delimiter = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (isalpha(sentence[i]) && sentence[i] != delimiter) {
            letters_no_delimiter++;
        }
    }
    cout << "Ilosc liter w zdaniu (bez znaku " << delimiter << "): " << letters_no_delimiter << endl;

    // wypisz wszystkie wyrazy
    cout << "Wszystkie wyrazy w zdaniu: " << endl;
    vector<string> words;
    string word;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ' && sentence[i] != delimiter) {
            word += sentence[i];
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }

    // podziel zdanie na części w oparciu o podany znak
    cout << "Podzial zdania na czesci w oparciu o znak " << skip << ": " << endl;
    vector<string> parts;
    word = "";
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != skip) {
            word += sentence[i];
        } else {
            if (!word.empty()) {
                parts.push_back(word);
                word = "";
            }
        }
    }
    if (!word.empty()) {
        parts.push_back(word);
    }
    for (int i = 0; i < parts.size(); i++) {
        cout << parts[i];
        if (i < parts.size() - 1) {
            cout << skip;
        }
    }
    cout << endl;

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