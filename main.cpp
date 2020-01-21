#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

// Biblioteki potrzebne do obslugi komend


std::string temat, nick; //Temam i nazwa
std::string tresc[12]; // Tresc zadan
std::string odpA[12], odpB[12], odpC[12], odpD[12]; // Odpowiedzi
std::string poprawna[12]; // Poprawne odpowiedzi
std::string odpowiedz;
std::string cos_z_klawiatury;
std::string x;

// Potrzebne do wcyztwania z kalwaitury


char wybor; // Wybory
int punkty=0; // Poczatkowa liczba puntkow
int wybor_w_menu=0; // Obsluga menu

HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);  // Zmiana koloru

int main()
{
    while(wybor_w_menu!=3)  // Petla do menu
    {

    std::cout <<std::endl;
    std::cout << "================="<<std::endl;
    std::cout << "    MILONERZY"<<std::endl;
    std::cout<<"  [ Dawid Kot ]"<<std::endl;                         SetConsoleTextAttribute(uchwyt, 15);
    std::cout << "================="<<std::endl;
    std::cout << "1. Rozpocznij Gre" <<std::endl;
    std::cout << "2. Instrukcja"<<std::endl;
    std::cout << "3. Wyjdz z Gry"<<std::endl;
    std::cout << "================="<<std::endl;

    // Menu Gry

    std::cin >> x;      // Pobiera liczbe do ibslugi menu

     getchar();
     system("cls");  // Dba o czytsosc menu

    if(x=="1") // Petla ktora rozpcozyna gre
    {

    int nr_linii=1;
    std::string linia;
    int nr_pytania=0;

    std::fstream plik;
    plik.open("pytanie.txt", std::ios::in);

    if (plik.good()==false)
    {
        std::cout << "Plik nie istnieje!";
        exit(0);
    }
    while(getline(plik, linia))
    {
       switch(nr_linii)
              {
                  case 1: temat=linia;                    break;
                  case 2: nick=linia;                     break;
                  case 3: tresc[nr_pytania] = linia;      break;
                  case 4: odpA[nr_pytania] = linia;       break;
                  case 5: odpB[nr_pytania] = linia;       break;
                  case 6: odpC[nr_pytania] = linia;       break;
                  case 7: odpD[nr_pytania] = linia;       break;
                  case 8: poprawna[nr_pytania] = linia;   break;

              }

        if (nr_linii==8) {nr_linii=2; nr_pytania++;}
        nr_linii++;
    }

    plik.close();

    for (int i=0; i<=11; i++)
    {
        std::cout <<std::endl<<tresc[i]<<std::endl;         // Wybor odpowiedzi
        Sleep(1000);
        std::cout <<"A. "<<odpA[i]<<std::endl;              // Sleep powoduje, ze pytania wywoluja sie po chwili
        Sleep(900);
        std::cout <<"B. "<<odpB[i]<<std::endl;
        Sleep(900);
        std::cout <<"C. "<<odpC[i]<<std::endl;
        Sleep(900);
        std::cout <<"D. "<<odpD[i]<<std::endl;
        Sleep(500);

        std::cout << "Twoja odpowiedz: ";
        std::cin>>odpowiedz;

        transform(odpowiedz.begin(),odpowiedz.end(),odpowiedz.begin(), ::tolower);
        if (odpowiedz==poprawna[i])
        {
            Sleep(1100);
            std::cout <<"To jest prawidlowa odpowiedz! "<<std::endl;    // Petla odpowiadajaca za przyanawanie punktow za dobra odpowiedz
            punkty++;                                                   // Oraz nie przznawania za zla
        }
        else {
            Sleep(1100);
            std::cout << "Niestety ta odpowiedz jest bledna. Poprawna odpowiedz to: "<<poprawna[i]<<std::endl;
            break;
        }

         getchar();getchar();       // Czystosc programu
         system("cls");



        }   // Wyswietla sie po zakonczeniu gry.
            // Informuje o systemie przeliczania punktow na pieniadze
    Sleep(1000);

    std::cout <<std::endl<< "Gra dobiegla konca! Posiadasz punkt: "<<punkty;
    std::cout <<std::endl;
    SetConsoleTextAttribute(uchwyt, 14);
    std::cout << "1.Punkt = 500zl | 2.Punkty = 1000zl" <<std::endl;
    std::cout << "3.Punkt = 2000zl | 4.Punkty = 5000zl" <<std::endl;
    std::cout << "5.Punkt = 10000zl | 6.Punkty = 20000zl" <<std::endl;
    std::cout << "7.Punkt = 40000zl | 8.Punkty = 75000zl" <<std::endl;
    std::cout << "9.Punkt = 125000zl | 10.Punkty = 250000zl" <<std::endl;
    std::cout << "11.Punkt = 500000zl | 12.Punkty = 1000000zl" <<std::endl;
    std::cout <<std::endl;
    std::cout << "1000zl i 40000zl to kwoty gwarantowane" <<std::endl;
    SetConsoleTextAttribute(uchwyt, 15);

    system("pause");
    system("cls");

    }

    if(x=="2")
    {
        // Instruckaj

        SetConsoleTextAttribute(uchwyt, 13);
        std::cout << "====================================================================="<<std::endl;
        std::cout << "Gra polega na poprawym odpwoiedzaniu na 12pytan."<<std::endl;
        std::cout << "Za kazde dobrze udzielone odpowiedz dostajemy pienadze."<<std::endl;
        std::cout << "Pieniadze mozemy stracic przez zle udzielona odpowiedz"<<std::endl;
        std::cout << "Sa 2 progi gwarantowane: 1000zl, 40000zl"<<std::endl;
        std::cout << "Mozemy rowniez zrezygnowac podczas gry, gdy nie znamy odpwiedzi"<<std::endl;
        std::cout << "Wtedy dostaniemy kwote, ktora juz wygralismy"<<std::endl;
        std::cout << "Kazdy zawodnik mial miec do wykorzystania 3 kola pomocznicze"<<std::endl;
        std::cout << "Kola mozna wykorzystac tylko raz w kazdej grze"<<std::endl;
        std::cout << "Powodzenia!" <<std::endl;
        std::cout << "====================================================================="<<std::endl;
        SetConsoleTextAttribute(uchwyt, 14);
        std::cout <<std::endl;

        system("pause");
        system("cls");

    } // Zamkniecie Gry
    if(x=="3")
    {
        exit(0);
    }

}

    return 0;
}
