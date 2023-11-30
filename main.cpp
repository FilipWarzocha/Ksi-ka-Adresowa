#include <iostream>
#include<stdio.h>
#include<cstdlib>
#include<windows.h>
#include <string>
#include<fstream>
#include <vector>
#include<string>
#include <sstream>

using namespace std;
//system("pause");

fstream plik;
struct daneprzyjaciol {
    string imie;
    string nazwisko;
    string telefon;
    string adres;
    int id;
};

string GetTheLine() {
    string input;
    cin.sync();
    getline(cin,input);
    return input;
}
string GetTheLineFromTheFileToVector(int numberOfPlace, string linia) {

    string output;

    for(int i=numberOfPlace; linia[i]!=124; i++) {

        output+=linia[i];
    }

    return output;
}

int Zliczanieprzyjacol (vector <daneprzyjaciol> &przyjaciele) {
    int ilePrzyjaciol=0;
    string linia;
    int numberOfPlace=0;
    daneprzyjaciol przyjaciel;
    plik.open("Dane Przyjaciol.txt",ios::in);
    if(plik.good()==false) {
        cout<<"Nie masz jeszcze zadnych wprowadzonych przyjaciol"<<endl;
        cout<<"*************************************************"<<endl;
        system("pause");
        plik.close();
        return 0;
    } else {
        while(!plik.eof()) {
            getline(plik,linia);
            numberOfPlace=0;
            przyjaciel.imie=GetTheLineFromTheFileToVector(numberOfPlace,linia);
            //przyjaciel.imie=linia;
            numberOfPlace+=przyjaciel.imie.length()+1;
            przyjaciel.nazwisko=GetTheLineFromTheFileToVector(numberOfPlace,linia);
            //przyjaciel.nazwisko=linia;
            numberOfPlace+=przyjaciel.nazwisko.length()+1;
            przyjaciel.telefon=GetTheLineFromTheFileToVector(numberOfPlace,linia);
            //przyjaciel.telefon=linia;
            numberOfPlace+=przyjaciel.telefon.length()+1;
            przyjaciel.adres=GetTheLineFromTheFileToVector(numberOfPlace,linia);
            //przyjaciel.adres=linia;
            numberOfPlace+=przyjaciel.adres.length()+1;
            przyjaciel.id=atoi(GetTheLineFromTheFileToVector(numberOfPlace,linia).c_str());
            //przyjaciel.id=2;
            przyjaciele.push_back(przyjaciel);
            ilePrzyjaciol++;
        }
        plik.close();
        return ilePrzyjaciol;
    }
}

// funkcja do wprawdzania przyjaciol
int wprowadzaniePrzyjaciela (vector <daneprzyjaciol> &przyjaciele, int ile) {
    system("cls");
    daneprzyjaciol przyjaciel;
    cout<< "wprowadz imie:";
    przyjaciel.imie=GetTheLine();
    cout<< "wprowadz nazwisko:";
    przyjaciel.nazwisko=GetTheLine();
    cout<< "wprowadz numer telefonu:";
    przyjaciel.telefon=GetTheLine();
    cout<< "wprowadz adres:";
    cin.sync();
    getline(cin,przyjaciel.adres);
    przyjaciel.id=ile+1;

    przyjaciele.push_back(przyjaciel);

    return ile+1;
}

void wyswietlanieWszytichPrzyjaciol(vector <daneprzyjaciol> &przyjaciele,int ilosc) {
    for (int i = 0; i<ilosc; i++) {
        cout<<"Imie: "<<przyjaciele[i].imie<<endl;
        cout<<"Nazwisko: "<<przyjaciele[i].nazwisko<<endl;
        cout<<"Telephon: "<<przyjaciele[i].telefon<<endl;
        cout<<"Adres: "<<przyjaciele[i].adres<<endl;
        cout<<"ID: "<<przyjaciele[i].id<<endl;
        cout<<"*************************************"<<endl;
    }
    system("pause");

}

//Procedura do wyswietlania przyjaciol
void wyborWyswietlania(int ilosc,vector <daneprzyjaciol> &przyjaciele ) {
    system("cls");
    int wybor;
    string imie, nazwisko;

    cout<<"<<         Wybierz         >>"<<endl;
    cout<<"1. Znajdz przyjaciela po imieniu"<<endl;
    cout<<"2. Znajdz przyjaciela po nazwisku"<<endl;
    cout<<"3. Wyswietl wszystkich przyjaciol"<<endl;
    cout<<"4. Wroc do menu glownego"<<endl;
    cout<<"Podaj swoj wybor: ";
    cin>>wybor;

    switch (wybor) {
    case 1: {
        // Wyszukiwanie po imieniu
        cout<< "wprowdz imie: ";
        cin>>imie;
        cout<<endl;
        for (int i = 0; i<ilosc; i++) {
            if (imie==przyjaciele[i].imie) {
                cout<<"Imie: "<<przyjaciele[i].imie<<endl;
                cout<<"Nazwisko: "<<przyjaciele[i].nazwisko<<endl;
                cout<<"Telephon: "<<przyjaciele[i].telefon<<endl;
                cout<<"Adres: "<<przyjaciele[i].adres<<endl;
                cout<<"ID: "<<przyjaciele[i].id<<endl;
                cout<<endl;
            }
        }
        system("pause");
        break;
    }
    case 2: {
        //wyszukiwanie po nazwisku
        cout<< "wprowdz nazwisko: ";
        cin>>nazwisko;
        cout<<endl;
        for (int i = 0; i<ilosc; i++) {
            if (nazwisko==przyjaciele[i].nazwisko) {
                cout<<"Imie: "<<przyjaciele[i].imie<<endl;
                cout<<"Nazwisko: "<<przyjaciele[i].nazwisko<<endl;
                cout<<"Telephon: "<<przyjaciele[i].telefon<<endl;
                cout<<"Adres: "<<przyjaciele[i].adres<<endl;
                cout<<"ID: "<<przyjaciele[i].id<<endl;
                cout<<endl;
            }
        }
        system("pause");
        break;
    }
    case 3: {
        wyswietlanieWszytichPrzyjaciol(przyjaciele, ilosc);
        break;
    }
    case 4: {
        break;
    }
    }
}

void ZapisywanieWszystkichPrzyjaciolwPlyku (vector <daneprzyjaciol> przyjaciele,int ilosc) {
    plik.open("Dane Przyjaciol.txt",ios::out);
    int ile=0;
    for(daneprzyjaciol przyjaciel: przyjaciele) {
        plik<<przyjaciel.imie<<"|";
        plik<<przyjaciel.nazwisko<<"|";
        plik<<przyjaciel.telefon<<"|";
        plik<<przyjaciel.adres<<"|";
        plik<<przyjaciel.id<<"|";
        ile++;
        if (ile !=ilosc) {
            plik<<endl;
        }
    }

    plik.close();

}

void  EdycjaDanychPrzyjaciela(vector <daneprzyjaciol> &przyjaciele,int ile) {

    system("cls");
    int idPrzyjaciela;
    cout<<"Podaj ID przyjaciela ktorego dane chcesz edytwac: ";
    cin>> idPrzyjaciela;
    int wybor;

    cout<<"<<<<<<Podaj co chcesz zmienic>>>>>>";
    cout<<"1.Imie"<<endl;
    cout<<"2.Nazwisko"<<endl;
    cout<<"3.Telefon"<<endl;
    cout<<"4.Adres"<<endl;
    cout<<"Wybor: "<<endl;
    cin>>wybor;
    cout<<endl;
    switch (wybor) {
    case 1: {
        for(int i = 0; i<ile; i++) {
            if(przyjaciele[i].id==idPrzyjaciela) {
                cout<<"podaj nowe imie: ";
                przyjaciele[i].imie=GetTheLine();
            }
        }
        break;
    }
    case 2: {
        for(int i = 0; i<ile; i++) {
            if(przyjaciele[i].id==idPrzyjaciela) {
                cout<<"podaj nowe nazwisko: ";
                przyjaciele[i].nazwisko=GetTheLine();
            }
        }
        break;
    }
    case 3: {
        for(int i = 0; i<ile; i++) {
            if(przyjaciele[i].id==idPrzyjaciela) {
                cout<<"podaj nowy numer telefonu: ";
                przyjaciele[i].telefon=GetTheLine();
            }
        }
        break;
    }
    case 4: {
        for(int i = 0; i<ile; i++) {
            if(przyjaciele[i].id==idPrzyjaciela) {
                cout<<"podaj nowy adres: ";
                przyjaciele[i].adres=GetTheLine();
            }
        }
        break;
    }
    }
}

int  UsuniecieDanychPrzyjaciela(vector <daneprzyjaciol> &przyjaciele, int ile) {

    int idPrzyjaciela;
    string wybor;
    cout<<"Podaj ID przyjaciela ktorego dane chcesz edytwac: ";
    cin>> idPrzyjaciela;
    for(int i = 0; i<ile; i++) {
        if(przyjaciele[i].id==idPrzyjaciela) {
            cout<<"Czy na pewno chcesz usunac tego przyjaciela: ";
            cin>>wybor;
            if (wybor == "tak"){
            przyjaciele.erase(przyjaciele.begin() + i);
            return ile-1;
            }
            else{
            return ile;
            }
        }
    }
    return ile;
}

void buzia() {
    string smiley = "      @@@@            @@@@\n     @@@@@@          @@@@@@\n     @@@@@@          @@@@@@\n      @@@@            @@@@\n\n\n\n@                             @\n @@                         @@\n   @@@                   @@@\n      @@@@@         @@@@@\n         @@@@@@@@@@@@@\n";
    cout<<smiley;
    Sleep(3000);
    string liczba;
    getline(cin,liczba);
}

int main() {

    int wybor=0;
    vector <daneprzyjaciol> przyjaciele;
    int iloscPrzyjaciol = 0;

    iloscPrzyjaciol = Zliczanieprzyjacol(przyjaciele);

    while(true) {
        system("cls");
        cout<<"<<    Witaj w menu glownym, wybierz jedna z opcji   >>"<<"\n";
        cout<<"*******************************************************"<<"\n";
        cout<<"1. Wprawdz nowe dane przyjaciela do ksiazki adresowej"<<"\n";
        cout<<"2. Wyswietl przyjjaciela/przyjaciol"<<"\n";
        cout<<"3. Zamknij ten fuckin program. Przeciez i tak nie dziala ja trza"<<"\n";
        cout<<"4. Buzie widze w tym tenczu"<<"\n";
        cout<<"5. Edytuj dane przyjaciela"<<"\n";
        cout<<"6. Usun dane przyjaciela"<<"\n";
        cin>> wybor;
        switch (wybor) {
        case 1: {
            iloscPrzyjaciol = wprowadzaniePrzyjaciela(przyjaciele, iloscPrzyjaciol);
            break;
        }
        case 2: {
            wyborWyswietlania(iloscPrzyjaciol,przyjaciele);
            break;
        }
        case 3: {
            //i tutaj wprowadziæ funkcjê która bêdzie zapisywa³a w pliku wzytic przycio³
            ZapisywanieWszystkichPrzyjaciolwPlyku (przyjaciele, iloscPrzyjaciol);
            exit(0);
            break;
        }
        case 4: {
            buzia();
            break;
        }
        case 5: {
            EdycjaDanychPrzyjaciela (przyjaciele, iloscPrzyjaciol);
            break;
        }
        case 6: {
            iloscPrzyjaciol=UsuniecieDanychPrzyjaciela(przyjaciele, iloscPrzyjaciol);
            break;
        }
        }


    }
    return 0;
}
