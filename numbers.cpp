
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20
#define DEBUG 1

int main()
{
    char first_num[MAX], second_num[MAX], sum_table[MAX];
    int p; // przeniesiona "do góry" liczba
    int w; // wynik dodawania
    int i, j; // indeksy w łańcuchów
    int k; // licznik pętli
    int short_num; // długość krótszego z łańcuchów

    // odczytujemy liczby do dodawania
    printf("Wpisz dwie liczby poprzedzając każdą z nich enterem:\n");
    scanf("%s\n%s", first_num, second_num);
    if(DEBUG) { printf("DEBUG first_num: %s, second_num: %s\n", first_num, second_num); }

    // obliczamy długości każdego z łańcuchów
    i = strlen(first_num);
    j = strlen(second_num);
    if(DEBUG) { printf("DEBUG strlen(first_num): %d, strlen(second_num): %d\n", i, j); }

    // w short_num wyznaczamy długość najkrótszego łańcucha
    short_num = i;
    if(j < i)
    {
        short_num = j;
    }
    if(DEBUG) { printf("DEBUG short_num: %d\short_num", short_num); }

    // zerujemy przeniesienie oraz łańcuch wynikowy
    p = 0;
    memset(sum_table, 0, MAX); // memset wypełnia zerami wskazaną ilość w tabeli
    if(DEBUG) { printf("DEBUG memset sum_table: %s\n", sum_table); }

    // sumujemy kolejne od końca cyfry obu łańcuchów
    for(k = 0; k != short_num; k++)
    {
        w = first_num[i-1] + second_num[j-1] + p - 96;
        if(DEBUG) { printf("DEBUG w 1st stage w =: %d\n", w); }
        i = i - 1;
        j = j - 1;
        p = w / 10; // uzyskamy w ten sposób pierwszą liczbę, int zje nam reszte
        memcpy(sum_table+1, sum_table, sizeof(sum_table));
        sum_table[0] = (char) (w % 10) + 48; // rzutujemy dla pewności %10 i dodajemy 48 ASCII
        if(DEBUG) { printf("DEBUG sum_table 1st stage: %s\n", sum_table); }
    }
    if(DEBUG) { printf("DEBUG sum_table 1st stage complete: %s\n", sum_table); }

    // jeżeli łańcuch first_num ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia i umieszczamy w łańcuchu wynikowym
    while(i > 0)
    {
        w = first_num[--i] + p - 48;
        if(DEBUG) { printf("DEBUG w 2nd stage w=: %d\n", w); }
        p = w / 10;
        memcpy(sum_table+1, sum_table, sizeof(sum_table));
        sum_table[0] = (char) (w % 10) + 48;
        if(DEBUG) { printf("DEBUG sum_table 2nd stage: %s\n", sum_table); }
    }
    if(DEBUG) { printf("DEBUG sum_table 2nd stage complete: %s\n", sum_table); }

    // jeżeli łańcuch second_num ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia i umieszczamy w łańcuchu wynikowym
    while(j > 0)
    {
        w = second_num[--j] + p - 48;
        if(DEBUG) { printf("DEBUG w 3rd stage: %d\n", w); }
        p = w / 10;
        memcpy(sum_table+1, sum_table, sizeof(sum_table));
        sum_table[0] = (char) (w % 10) + 48;
        if(DEBUG) { printf("DEBUG sum_table 3rd stage: %s\n", sum_table); }
    }
    if(DEBUG) { printf("DEBUG sum_table 3rd stage complete: %s\n", sum_table); }

    // jeżeli pozostało przeniesienie, to dołączamy je do cyfr
    // w łańcuchu wynikowym
    if(p > 0)
    {
        memcpy(sum_table+1, sum_table, sizeof(sum_table)); // kopiujemy sum_table (tyle komorek ile rozmiar sum_table) do sum+table+1
        sum_table[0] = p + 48;
    }

    // wyświetlamy wynik
    printf("wynik: %s\n", sum_table);

    return 0;
}
