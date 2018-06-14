#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>
#include <sstream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

class Praca{

    public:
        int id;
        string typPracy;
        string tytul;
        string nazwiskoAutora;
        string imieAutora;
        int rok;
        string nazwiskoPromotora;
        string imionaPromotora;
        string slowaKluczowe;
        string streszczenie;
        string nowa_praca;

         Praca() {
        id = 0;
        typPracy = "";
        tytul = "";
        nazwiskoAutora = "";
        imieAutora = "";
        rok = 0;
        nazwiskoPromotora = "";
        imionaPromotora = "";
        slowaKluczowe = "";
        streszczenie = "";
    }

    ~Praca()
    {

    }
};

class Biblioteka{

    public:

        int ilePrac;
        Praca prace [1000];


        Biblioteka()
        {
            ilePrac = 0;
        }

        void odczyt(const char *nazwaPliku)
        {
            ifstream we(nazwaPliku);

            if (we.is_open())
            {
                int i = 0;
                string wiersz;
                string s;
                while(!we.eof()&& i<=ilePrac)
                {
                    getline(we,wiersz);
                    if(wiersz =="") break;
                    istringstream iss(wiersz);
                    iss >> prace[i].id;

                    getline(we,wiersz);
                    prace[i].typPracy = wiersz;

                    getline(we,wiersz);
                    prace[i].tytul = wiersz;

                    getline(we,wiersz);
                    prace[i].imieAutora = wiersz;

                    getline(we,wiersz);
                    prace[i].nazwiskoAutora = wiersz;

                    getline(we,wiersz);
                    istringstream ass(wiersz);
                    ass >> prace[i].rok;

                    getline(we,wiersz);
                    prace[i].imionaPromotora = wiersz;

                    getline(we,wiersz);
                    prace[i].nazwiskoPromotora = wiersz;

                    getline(we,wiersz);
                    prace[i].slowaKluczowe = wiersz;

                    getline(we,wiersz);
                    prace[i].streszczenie = wiersz;

                    ilePrac+=1;
                    ++i;
                }
            }else cout<<"error, blad wczytania"<<endl;
            we.close();
        }

        void wyswietlJednaPrace(int i)
        {
                            cout<<"Id: "<<prace[i].id<<endl;
                            cout<<"Typ: "<<prace[i].typPracy<<endl;
                            cout<<"Autor: "<<prace[i].imieAutora<< " " << prace[i].nazwiskoAutora<<endl;
                            cout<<"Tytul: "<<prace[i].tytul<<endl;
                            cout<<"Slowa kluczowe: "<<prace[i].slowaKluczowe<<endl;
                            cout<<"Rok: "<<prace[i].rok<<endl;
                            cout<<"Promotor :" << prace[i].imionaPromotora<< " "<<prace[i].nazwiskoPromotora<<endl;
                            cout<<"Streszczenie: " <<prace[i].streszczenie<<endl;
                            cout<<"---------------------------------------------------------------"<<endl;
        }
        void wyswietl()
                {
                    cout<<"---------------------------------------------------------------"<<endl;
                    for(int i = 0; i < ilePrac; i++)
                        {
                            wyswietlJednaPrace(i);
                        }
                }

        void wyswietlSkrocone()
        {
            for(int i = 0; i < ilePrac; i++)
                {
                    char znak = prace[i].imieAutora[0];
                    cout<<prace[i].id<<" "<<prace[i].typPracy <<" "<<znak<<". "
                            <<prace[i].nazwiskoAutora<< " ,," <<prace[i].tytul <<"'' "<<prace[i].rok<<endl;
                }
        }

        void dodaj(const char *nazwaPliku)
        {
            int liczbaDodania = 0;
            cout <<"Ile prac chcesz dodac tym razem?: " ;
            do{
            cin >> liczbaDodania;
            if(liczbaDodania <0) cout <<"Nie moze byc ujemna wartosc"<<endl;
            }while (liczbaDodania<0);

            int rozmiar = ilePrac;

            ofstream wy(nazwaPliku, ios::app);
            if(wy.is_open())
            {
                if (ilePrac<1000)
                    {
                        for(int i = rozmiar; i <rozmiar+liczbaDodania; ++i)
                        {
                            cout<<"Podaj konkretne dane: " <<endl;
                                int sprawdz;

                                    do{
                                    sprawdz=0;
                                    cout<<"Id: ";
                                    cin >> prace[i].id;

                                    for(int j = 0; j<ilePrac ; j++)
                                    {
                                        if(prace[i].id==prace[j].id)
                                            {
                                            sprawdz+=1;
                                            }
                                    }

                                    if(prace[i].id <0) cout <<"Nie moze byc ujemna wartosc"<<endl;
                                    if(sprawdz!=0) cout<<"Blad unikatowosci id"<<endl;
                                    }while(prace[i].id <0 || sprawdz !=0);

                                    wy<<"\n"<<prace[i].id<<"\n"; cout<<endl;
                                    cin.clear();
                                    cin.ignore(1000, '\n');

                                    do{
                                cout<<"Typ: ";

                                    getline(cin,prace[i].typPracy);
                                    if(prace[i].typPracy!= "inz" && prace[i].typPracy!= "lic" && prace[i].typPracy!= "mgr") cout<<"Zly typ pracy" << endl;
                                    }while(prace[i].typPracy!= "inz" && prace[i].typPracy!= "lic" && prace[i].typPracy!= "mgr");
                                    wy<<prace[i].typPracy<<"\n"; cout<<endl;

                                cout<<"Tytul: ";
                                    getline(cin,prace[i].tytul);
                                    wy<<prace[i].tytul<<"\n";cout<<endl;

                                cout<<"Imie autora: ";
                                    getline(cin,prace[i].imieAutora);
                                    wy<<prace[i].imieAutora<<"\n";cout<<endl;

                                cout<<"Nazwisko autora: ";
                                    getline(cin,prace[i].nazwiskoAutora);
                                    wy<<prace[i].nazwiskoAutora<<"\n";cout<<endl;

                                    do{
                                cout<<"Rok: ";

                                    cin>>prace[i].rok;
                                    if(prace[i].rok <2000) cout<<"Za stara praca"<<endl;
                                    }while(prace[i].rok <2000);
                                    wy<<prace[i].rok<<"\n";cout<<endl;
                                    cin.clear();
                                    cin.ignore(1000, '\n');

                                cout<<"Imiona promotora :";
                                    getline(cin,prace[i].imionaPromotora);
                                    wy<<prace[i].imionaPromotora<<"\n";cout<<endl;

                                cout<<"Nazwisko promotora :";
                                    getline(cin,prace[i].nazwiskoPromotora);
                                    wy<<prace[i].nazwiskoPromotora<<"\n";cout<<endl;

                                cout<<"Slowa kluczowe: ";
                                    getline(cin,prace[i].slowaKluczowe);
                                    wy<<prace[i].slowaKluczowe<<"\n";cout<<endl;

                                do{
                                cout<<"Streszczenie: ";

                                    getline(cin,prace[i].streszczenie);
                                    if(prace[i].streszczenie.length() -1>1000) cout<<"Za dlugie streszczenie"<<endl;
                                }while(prace[i].streszczenie.length()-1>1000);
                                    wy<<prace[i].streszczenie;cout<<endl;

                                    ilePrac++;
                        }
            }   else cout<<"Nie odczytano pliku!" <<endl;

            wy.close();
            }
        }

        void edycja()
        {

                int id;
                int wybor;
                int nrPracy = -1;
                do{
                cout<<"Jaka prace chcesz poprawic? Podaj id: ";
                cin>>id;

                    for(int i =0; i<ilePrac;++i )
                    {
                        if(prace[i].id == id) nrPracy = i;
                    }

                        if(nrPracy == -1) cout<<"Praca o podanym id nie istnieje"<<endl;

                }while(nrPracy==-1);

                do
                {
                    cout<<"\n\t1.id\n\t2.Imie Autora\n\t3.Nazwisko Autora\n\t4.Tytul\n\t5.Slowa kluczowe\n\t6.Rok\n\t7.Imiona promotora\n\t8.Nazwisko promotora\n\t9.Typ\n\t10.Streszczenie\n\t0.Koniec"<<endl;

                    cin>>wybor;

                    switch(wybor)
                    {
                        case 1:
                                cout<<"Aktualne id: "<<prace[nrPracy].id<<endl;

                                int sprawdz;
                                 do{
                                    cout<<"Czym te dane zastapic? : ";
                                    sprawdz=0;
                                    cin >> prace[nrPracy].id;

                                    for(int j = 0; j<ilePrac ; j++)
                                    {
                                        if(prace[nrPracy].id==prace[j].id)
                                            {
                                            sprawdz+=1;
                                            }
                                    }

                                    if(prace[nrPracy].id <0) cout <<"Nie moze byc ujemna wartosc"<<endl;
                                    if(sprawdz!=0) cout<<"Blad unikatowosci id"<<endl;
                                    }while(prace[nrPracy].id <0 || sprawdz !=0);


                                break;
                        case 2:
                                cout<<"Aktualne imie autora: "<<prace[nrPracy].imieAutora<<endl;
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].imieAutora;
                                break;
                        case 3:
                                cout<<"Aktualne nazwisko autora: "<<prace[nrPracy].nazwiskoAutora<<endl;
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].nazwiskoAutora;
                                break;
                        case 4:
                                cout<<"Aktualne tytul: "<<prace[nrPracy].tytul<<endl;
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].tytul;
                                break;
                        case 5:
                                cout<<"Aktualne slowa kluczowe: "<<prace[nrPracy].slowaKluczowe<<endl;
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].slowaKluczowe;
                                break;
                        case 6:
                                cout<<"Aktualne rok: "<<prace[nrPracy].rok<<endl;
                                do{
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].rok;
                                if(prace[nrPracy].rok <2000) cout<< "Za stara praca";
                                }while(prace[nrPracy].rok <2000);
                                break;
                        case 7:
                                cout<<"Aktualne imiona promotora: "<<prace[nrPracy].imionaPromotora<<endl;
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].imionaPromotora;
                                break;
                        case 8:
                                cout<<"Aktualne nazwisko promotora: "<<prace[nrPracy].nazwiskoPromotora<<endl;
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].nazwiskoPromotora;
                                break;
                        case 9:
                                cout<<"Aktualne typ pracy: "<<prace[nrPracy].typPracy<<endl;
                                do{
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].typPracy;
                                if(prace[nrPracy].typPracy!= "inz" && prace[nrPracy].typPracy!= "lic" && prace[nrPracy].typPracy!= "mgr") cout<<"Zly typ pracy" << endl;
                                }while(prace[nrPracy].typPracy!= "inz" && prace[nrPracy].typPracy!= "lic" && prace[nrPracy].typPracy!= "mgr");
                                break;
                        case 10:
                                cout<<"Aktualne streszczenie: "<<prace[nrPracy].streszczenie<<endl;
                                cout<<"Czym te dane zastapic? : ";
                                cin>>prace[nrPracy].streszczenie;
                                break;
                        case 0:
                                break;
                    }
                }while(wybor!=0);
    }
        void zaktualizujDane(const char *nazwaPliku)
    {
         ofstream wy(nazwaPliku);
            if(wy.is_open())
            {
                for(int i = 0; i <ilePrac; ++i)
                    {
                                    wy<<prace[i].id<<"\n";

                                    wy<<prace[i].typPracy<<"\n";

                                    wy<<prace[i].tytul<<"\n";

                                    wy<<prace[i].imieAutora<<"\n";

                                    wy<<prace[i].nazwiskoAutora<<"\n";

                                    wy<<prace[i].rok<<"\n";

                                    wy<<prace[i].nazwiskoPromotora<<"\n";

                                    wy<<prace[i].imionaPromotora<<"\n";

                                    wy<<prace[i].slowaKluczowe<<"\n";

                                    wy<<prace[i].streszczenie<<"\n";
                    }
            }
            wy.close();
            }

        bool szukajWszystkichFraz( string & tekst, string szukanaFraza )
        {
            bool zwrot = false;
            int znalezionaPozycja = -1;
            znalezionaPozycja = tekst.find( szukanaFraza );
            if(znalezionaPozycja != -1) zwrot = true;
            return zwrot;
        }

        void wyszukaj()
        {
            int sett;
            int wart;
            string nazw;

            do
            {
                bool czyIstnieje[ilePrac] = {};
                cout<< "Na podstawie czego chcesz wyszukac prace?: ";

                cout<< "\n\t1.Nazwisko autora\n\t2.Nazwisko promotora\n\t3.Tytul\n\t4.Slowa kluczowe\n\t5.Streszczenie\n\t6.Rok powstania\n";

                cin>>sett;

                switch(sett)
                {
                        case 1:
                            {
                                system("cls");
                                cout<<"Podaj nazwisko autora: ";
                                cin>>nazw;

                                for(int i = 0; i <ilePrac; i++)
                                {

                                    if(prace[i].nazwiskoAutora == nazw)
                                        {
                                            czyIstnieje[i] = true ;

                                        }
                                    else czyIstnieje[i] = false;
                                }

                                int rok = 2040;
                                for(int j = rok; j >=2000;j--)
                                    {
                                        for(int i = 0; i <ilePrac; i++)
                                        {
                                            if(czyIstnieje[i] == true && prace[i].rok == j)
                                            {
                                                 wyswietlJednaPrace(i);
                                            }
                                        }
                                    }

                                break;
                                }
                        case 2:
                            {
                                system("cls");
                                cout<<"Podaj nazwisko promotora: ";
                                cin>>nazw;

                                for(int i = 0; i <ilePrac; i++)
                                {
                                    if(prace[i].nazwiskoPromotora == nazw)   czyIstnieje[i] = true ;
                                    else czyIstnieje[i] = false;
                                }

                                int rok = 2040;
                                for(int j = rok; j >=2000;j--)
                                    {
                                        for(int i = 0; i <ilePrac; i++)
                                        {
                                            if(czyIstnieje[i] == true && prace[i].rok == j)
                                            {
                                                 wyswietlJednaPrace(i);
                                            }
                                        }
                                    }
                                break;
                                }
                        case 3:
                            {
                                system("cls");
                                cout<<"Podaj tytul: ";
                                cin>>nazw;

                                for(int i = 0; i <ilePrac; i++)
                                {
                                    if( szukajWszystkichFraz(prace[i].tytul,nazw) == true)   czyIstnieje[i] = true ;
                                    else czyIstnieje[i] = false;
                                }

                               int rok = 2040;
                                for(int j = rok; j >=2000;j--)
                                    {
                                        for(int i = 0; i <ilePrac; i++)
                                        {
                                            if(czyIstnieje[i] == true && prace[i].rok == j)
                                            {
                                                 wyswietlJednaPrace(i);
                                            }
                                        }
                                    }
                                break;
                                }
                        case 4:
                            {
                                system("cls");
                                cout<<"Podaj Slowa kluczowe: ";
                                cin>>nazw;

                                for(int i = 0; i <ilePrac; i++)
                                {
                                    if( szukajWszystkichFraz(prace[i].slowaKluczowe,nazw) == true)   czyIstnieje[i] = true ;
                                    else czyIstnieje[i] = false;
                                }

                                int rok = 2040;
                                for(int j = rok; j >=2000;j--)
                                    {
                                        for(int i = 0; i <ilePrac; i++)
                                        {
                                            if(czyIstnieje[i] == true && prace[i].rok == j)
                                            {
                                                 wyswietlJednaPrace(i);
                                            }
                                        }
                                    }
                                break;
                                }
                        case 5:
                            {
                                system("cls");
                                cout<<"Podaj streszczenie: ";
                                cin>>nazw;

                                for(int i = 0; i <ilePrac; i++)
                                {
                                    if( szukajWszystkichFraz(prace[i].streszczenie,nazw) == true)   czyIstnieje[i] = true ;
                                    else czyIstnieje[i] = false;
                                }

                                int rok = 2040;
                                for(int j = rok; j >=2000;j--)
                                    {
                                        for(int i = 0; i <ilePrac; i++)
                                        {
                                            if(czyIstnieje[i] == true && prace[i].rok == j)
                                            {
                                                 wyswietlJednaPrace(i);
                                            }
                                        }
                                    }
                                break;
                                }
                        case 6:
                            {
                                system("cls");
                                cout<<"Podaj rok powstania: ";
                                cin>>wart;

                                for(int i = 0; i <ilePrac; i++)
                                {
                                    if(prace[i].rok == wart)   czyIstnieje[i] = true ;
                                    else czyIstnieje[i] = false;
                                }

                              int rok = 2040;
                                for(int j = rok; j >=2000;j--)
                                    {
                                        for(int i = 0; i <ilePrac; i++)
                                        {
                                            if(czyIstnieje[i] == true && prace[i].rok == j)
                                            {
                                                 wyswietlJednaPrace(i);
                                            }
                                        }
                                    }
                                break;
                                }
                        default:
                                system("cls");
                                cout<<"Nie ma opcji o takim nr:\n";
                }
            }while(sett!=0);
        }

        void liczbaPracNaPromotora()
        {

            string nazw;
            int licznik = 0;
            for(int i =0; i < ilePrac; i++)
            {
                for(int j =0; j < ilePrac; j++)
                {
                if(prace[i].nazwiskoPromotora == prace[j].nazwiskoPromotora) licznik++;
                }
                cout<<"Promotor: "<<prace[i].imionaPromotora<<" "<<prace[i].nazwiskoPromotora<<". Liczba prac = "<<licznik<<endl;
                licznik=0;
            }
        }

        void zliczaniePrac()
        {
            int liczbaPracLic = 0;
            int liczbaPracMgr = 0;
            int liczbaPracInz = 0;

            for(int i=0 ; i < 1000; i++)
            {
                if(prace[i].typPracy=="lic")
                    liczbaPracLic++;

                if(prace[i].typPracy=="inz")
                    liczbaPracInz++;

                if(prace[i].typPracy=="mgr")
                    liczbaPracMgr++;
            }
            cout << "Liczba wszystkich prac wynosi: " << ilePrac << endl;
            cout << "Liczba prac licencjackich wynosi: " << liczbaPracLic << endl;
            cout << "Liczba prac inzynierskich wynosi: " << liczbaPracInz << endl;
            cout << "Liczba prac magisterskich wynosi: " << liczbaPracMgr << endl << endl;

        }

        void topDziesiec()
        {
            string slowa[ilePrac];
            int ile[ilePrac];
        }
        void podMenu()
        {

            system("cls");
            int sett;
            do
            {
                cout<<"Wybierz funkcje:\n\n\t1.Wyswietlanie prac z podzialem na typy\n\t2.Liczba prac poszczegolnych promotorow\n\t3.Top 10 slow kluczowych\n";
                cin>>sett;
                switch(sett)
                {
                    case 1:
                            system("cls");
                            zliczaniePrac();
                            break;
                    case 2:
                            system("cls");
                            liczbaPracNaPromotora();
                            break;
                    case 3:
                            system("cls");
                            topDziesiec();
                            break;
                    case 0:
                            system("cls");
                            break;
                }

            }while(sett != 0 );
        }
};



int main()
{

    const char *sciezka = "G:\\Uczelnia\\2 semestr\\C++\\Projekt\\prace.txt";

    Biblioteka *bibl = new Biblioteka();


       int wybor;
        bibl->odczyt(sciezka);

   do{

         cout<<"Wybierz opcje...\n\n\t1.Wyswietl prace\n\t2.Wyswietl skrocone info\n\t3.Dopisz do prac\n\t4.Edycja prac\n\t5.Wyszukiwarka prac\n\t6.Funkcje dodatkowe"<<endl;


        cin>>wybor;

        switch(wybor)
        {
            case 1:
                    system("cls");
                    bibl->wyswietl();
                    cout<<endl;
                    break;
            case 2:
                    system("cls");
                    bibl->wyswietlSkrocone();
                    cout<<endl;
                    break;
            case 3:
                    system("cls");
                    bibl->dodaj(sciezka);
                    cout<<endl;
                    break;
            case 4:
                    system("cls");
                    bibl->edycja();
                    bibl->zaktualizujDane(sciezka);
                    break;
            case 5:
                    system("cls");
                    bibl->wyszukaj();
                    break;
            case 6:
                    system("cls");
                    bibl->podMenu();

                    break;
            case 0:
                    system("cls");
                    cout <<"Program zakonczyl dzialanie..."<<endl;
                    break;
            default:
                    system("cls");
                    cout<<"Nie ma opcji o takim nr:\n";
        }
    } while(wybor !=0);

    delete [] sciezka;

    return 0;
}
