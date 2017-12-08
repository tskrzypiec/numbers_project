
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20
#define DEBUG 1

int main()
{
    char s1[MAX], s2[MAX], s3[MAX];
    int p, w, i, j, k, n;

    // odczytujemy liczby do dodawania
    printf("Enter two values separeted by new line:\n");
    scanf("%s\n%s", s1, s2);
    if(DEBUG) { printf("DEBUG s1: %s, s2: %s\n", s1, s2); }

    // obliczamy dÅugoÅci kaÅ¼dego z ÅaÅcuchÃ³w
    i = strlen(s1);
    j = strlen(s2);
    if(DEBUG) { printf("DEBUG strlen(s1): %d, strlen(s2): %d\n", i, j); }

    // w n wyznaczamy dÅugoÅÄ najkrÃ³tszego ÅaÅcucha
    n = i;
    if(j < i)
    {
        n = j;
    }
    if(DEBUG) { printf("DEBUG n: %d\n", n); }

    // zerujemy przeniesienie oraz ÅaÅcuch wynikowy
    p = 0;
    memset(s3, 0, MAX);
    if(DEBUG) { printf("DEBUG memset s3: %s\n", s3); }

    // sumujemy kolejne od koÅca cyfry obu ÅaÅcuchÃ³w
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

    // jeÅli ÅaÅcuch s1 ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia i umieszczamy w ÅaÅcuchu wynikowym
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

    // jeÅli ÅaÅcuch s2 ma jeszcze cyfry, to dodajemy do nich
    // przeniesienia i umieszczamy w ÅaÅcuchu wynikowym
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

    // jeÅli pozostaÅo przeniesienie, to doÅÄczamy je do cyfr
    // w ÅaÅcuchu wynikowym
    if(p > 0)
    {
        memcpy(s3+1, s3, sizeof(s3));
        s3[0] = p + 48;
    }

    // wyÅwietlamy wynik
    printf("s3: %s\n", s3);

    return 0;
}
