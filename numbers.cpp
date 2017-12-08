
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20
#define DEBUG 0

int main()
{
    char s1[MAX], s2[MAX], s3[MAX];
    int p, w, i, j, k, n;

    // odczytujemy liczby do dodawania
    printf("Wpisz dwie liczby poprzedzając każdą z nich enterem:\n");
    scanf("%s\n%s", s1, s2);
    if(DEBUG) { printf("DEBUG s1: %s, s2: %s\n", s1, s2); }

    // obliczamy długości każdego z łańcuchów
    i = strlen(s1);
    j = strlen(s2);
    if(DEBUG) { printf("DEBUG strlen(s1): %d, strlen(s2): %d\n", i, j); }

    // w n wyznaczamy długość najkrótszego łańcucha
    n = i;
    if(j < i)
    {
        n = j;
    }
    if(DEBUG) { printf("DEBUG n: %d\n", n); }

    // zerujemy przeniesienie oraz łańcuch wynikowy
    p = 0;
    memset(s3, 0, MAX);
    if(DEBUG) { printf("DEBUG memset s3: %s\n", s3); }

    // sumujemy kolejne od końca cyfry obu łańcuchów
    for(k = 0; k != n; k++)
    {
        w = s1[i-1] + s2[j-1] + p - 96;
        if(DEBUG) { printf("DEBUG w 1st stage: %d\n", w); }
        i = i - 1;
        j = j - 1;
        p = w / 10;
        memcpy(s3+1, s3, sizeof(s3));
        s3[0] = (char) (w % 10) + 48;
        if(DEBUG) { printf("DEBUG s3 1st stage: %s\n", s3); }
    }
    if(DEBUG) { printf("DEBUG s3 1st stage complete: %s\n", s3); }

    // jeżeli łańcuch s1 ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia i umieszczamy w łańcuchu wynikowym
    while(i > 0)
    {
        w = s1[--i] + p - 48;
        if(DEBUG) { printf("DEBUG w 2nd stage: %d\n", w); }
        p = w / 10;
        memcpy(s3+1, s3, sizeof(s3));
        s3[0] = (char) (w % 10) + 48;
        if(DEBUG) { printf("DEBUG s3 2nd stage: %s\n", s3); }
    }
    if(DEBUG) { printf("DEBUG s3 2nd stage complete: %s\n", s3); }

    // jeżeli łańcuch s2 ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia i umieszczamy w łańcuchu wynikowym
    while(j > 0)
    {
        w = s2[--j] + p - 48;
        if(DEBUG) { printf("DEBUG w 3rd stage: %d\n", w); }
        p = w / 10;
        memcpy(s3+1, s3, sizeof(s3));
        s3[0] = (char) (w % 10) + 48;
        if(DEBUG) { printf("DEBUG s3 3rd stage: %s\n", s3); }
    }
    if(DEBUG) { printf("DEBUG s3 3rd stage complete: %s\n", s3); }

    // jeżeli pozostało przeniesienie, to dołączamy je do cyfr
    // w łańcuchu wynikowym
    if(p > 0)
    {
        memcpy(s3+1, s3, sizeof(s3));
        s3[0] = p + 48;
    }

    // wyświetlamy wynik
    printf("wynik: %s\n", s3);

    return 0;
}
