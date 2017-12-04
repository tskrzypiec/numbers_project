
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string liczba_1,liczba_2,tablica_wynik;
    int przeniesiona_liczba,wynik_dodawania,indeks_liczba_1,indeks_liczba_2,licznik_petli,dlugosc_krotka_liczba;

    // odczytujemy liczby do dodawania

    printf("Podaj 2 liczby, które chcesz dodać, po każdej daj enter\n");

    cin >> liczba_1 >> liczba_2;

    // obliczamy długości każdego z łańcuchów

    indeks_liczba_1 = liczba_1.length();
    indeks_liczba_2 = liczba_2.length();

    // wynik_dodawania dlugosc_krotka_liczba wyznaczamy długość najkrótszego łańcucha

    dlugosc_krotka_liczba = indeks_liczba_1; if(indeks_liczba_2 < indeks_liczba_1) dlugosc_krotka_liczba = indeks_liczba_2;

    // zerujemy przeniesienie oraz łańcuch wynikowy

    przeniesiona_liczba = 0;

    tablica_wynik = "";

    // sumujemy kolejne od końca cyfry obu łańcuchów

    for(licznik_petli = 1; licznik_petli <= dlugosc_krotka_liczba; licznik_petli++)
    {
        wynik_dodawania  = (int)(liczba_1[--indeks_liczba_1]) + (int)(liczba_2[--indeks_liczba_2]) + przeniesiona_liczba - 96;
        przeniesiona_liczba  = wynik_dodawania / 10;
        tablica_wynik = (char)((wynik_dodawania % 10) + 48) + tablica_wynik;
    }

    // jeśli łańcuch liczba_1 ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia indeks_liczba_1 umieszczamy wynik_dodawania łańcuchu wynikowym

    while(indeks_liczba_1)
    {
        wynik_dodawania  = liczba_1[--indeks_liczba_1] + przeniesiona_liczba - 48;
        przeniesiona_liczba  = wynik_dodawania / 10;
        tablica_wynik = (char)((wynik_dodawania % 10) + 48) + tablica_wynik;
    }

    // jeśli łańcuch liczba_2 ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia indeks_liczba_1 umieszczamy wynik_dodawania łańcuchu wynikowym

    while(indeks_liczba_2)
    {
        wynik_dodawania  = liczba_2[--indeks_liczba_2] + przeniesiona_liczba - 48;
        przeniesiona_liczba  = wynik_dodawania / 10;
        tablica_wynik = (char)((wynik_dodawania % 10) + 48) + tablica_wynik;
    }

    // jeśli pozostało przeniesienie, to dołączamy je do cyfr
    // wynik_dodawania łańcuchu wynikowym

    if(przeniesiona_liczba) tablica_wynik = (char)(przeniesiona_liczba + 48) + tablica_wynik;

    // jeśli wynik_dodawania tablica_wynik nie ma cyfr, to wpisujemy tam 0

    if(tablica_wynik == "") tablica_wynik = "0";

    // wyświetlamy wynik

    cout << tablica_wynik << endl;

} 