//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom shaker sort. Osnovna
ideja ove metode za sortiranje je poboljsanje bubble sort algoritma. Kod bubble
sort metode se javlja asimetrija; ako je na dnu najlaksi mjehuric, on ce isplivati
u jednom koraku, dok ako je na vrhu najtezi mjehuric on u svakom koraku moze da
potone za samo jedno mjesto. Kod shaker sort metode u jednom koraku laksi mjehurici
isplivaju prema povrsini, a u slijedecem koraku tezi mjehurici tonu ka dnu. Slozenost
ovog algoritma je exp(2*ln(n)).*/

#pragma hdrstop
#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int a[11];//niz pocinje nultim elementom, pocetni i krajnji indeksi niza
        //su 0 i 10
        int i,j,n,L,D,k,t;
        printf("Unesite niz prirodnih brojeva; maksimalno 10 elem.(za kraj unosa unesite -1):\n");
        i=0;
        while (i!=-1)
                {i++;
                scanf("%d",&a[i]);
                if (a[i]==-1)
                        {n=i-1;
                        i=-1;}
                }
        L=2;
        D=n;
        k=n;//u slucaju da je niz sortiran
        while (L<=D)
                {for (j=D;j>=L;j--)
                        if (a[j-1]>a[j])
                                {t=a[j-1];
                                a[j-1]=a[j];
                                a[j]=t;
                                k=j;}//indeks mjehurica koji se pomjerio preme gore
                L=k+1;//indeks mjehurica ispod njega
                for (j=L;j<=D;j++)
                        if (a[j-1]>a[j])
                                {t=a[j-1];
                                a[j-1]=a[j];
                                a[j]=t;
                                k=j;}//indeks mjehurica koji se pomjerio prema dole
                D=k-1;//indeks mjehurica iznad njega
                }
        printf("Sortiran niz (u rastucem redoslijedu):\n");
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);
        getch();
        return 0;
}
//---------------------------------------------------------------------------
