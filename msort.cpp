//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom merge sort. Osnovna
ideja ovog metoda je da podijelimo niz na pola i obe polovine sortiramo. Zatim te
dve polovine spojimo ponovo na takav nacin da dobijemo sortirani niz. Slozenost
ovog algoritma je O(n*log(n)).*/

#pragma hdrstop
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//trazi header file u direktorijumu include
#include "quicksort.h"//trazi header file u direktorijumu gdje se kod programa
// trenutno nalazi, sadrzi u sebi deklaracije i definicije

//---------------------------------------------------------------------------

#pragma argsused

int t[11], a[11];

int main(int argc, char* argv[])
{
        int i,n,j,k;
        printf("Unesite niz prirodnih brojeva; maksimalno 10 elem.(za kraj unosa unesite -1):\n");
        i=0;
        while (i!=-1)
                {i++;
                scanf("%d",&t[i]);
                if (t[i]==-1)
                        {
                                n=i-1;
                                i=-1;
                        }
                }
        quicksort(1,n/2,t);//podijelimo niz na dva dijela
        quicksort(n/2+1,n,t);//oba dijela sortiramo, u ovom slucaju quick sort metodom
        i=1;
        j=n/2+1;
        k=1;
        while ((i<=n/2)&&(j<=n))//zatim ih merdzujemo tj. slijemo jedan u drugi
                {
                        if (t[i]<=t[j])
                                {
                                        a[k]=t[i];
                                        i++;
                                        k++;
                                }
                        if (t[i]>=t[j])
                                {
                                        a[k]=t[j];
                                        j++;
                                        k++;
                                }
                }
        if (i<n/2)
                for (j=i;j<=n/2;j++)
                        {
                                a[k]=t[j];
                                k++;
                        }
        if (j<n)
                for (i=j;i<=n;i++)
                        {
                                a[k]=t[i];
                                k++;
                        }
        printf("\nSortiran niz (u rastucem redoslijedu):\n");
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);
        getch();
        return 0;
}
//---------------------------------------------------------------------------

