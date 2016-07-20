//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom bubble sort.
Osnovna ideja: Pretpostavimo da su elementi umjesto horizontalno poredani vertikalno.
Zamislimo da vrijednost kljuca svakog elementa predstavlja njegovu tezinu i da su
elementi mjehurici uronjeni u tank sa vodom. Tada svaki prolaz kroz niz tj.
mjehurice rezultuje pomjeranje navise mjehurica koji ima najmanju tezinu. Mjehuric
moze da se pomjera navise sve dok ne naidje na prepreku koju predstavlja mjehuric
koji ima manju tezinu. Tada taj mjehuric ukoliko je moguce nastavlja da se pomjera
navise. Slozenost ovog algoritma je exp(2*ln(n)).*/

#pragma hdrstop
#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int a[11];
        int i,n,j,t;
        printf("Unesite niz prirodnih brojeva; maksimalno 10 elem.(za kraj unosa unesite -1):\n");
        i=0;
        while (i!=-1)
                {i++;
                scanf("%d",&a[i]);
                if (a[i]==-1)
                        {n=i-1;
                        i=-1;}
                }//krajni lijevi indeks - mjehuric gore, krajnji desni - mjehuric dole
        for (i=2;i<=n;i++)//n-1 prolaza kroz mjehurice, u prvom najlaksi se pomjeri gore
                for (j=n;j>=i;j--)//svaki iduci prolaz ne prolazi kroz mjehurice
                //koji su u prethodnim prolazima kao najlaksi pomjereni prema gore
                        if (a[j-1]>a[j])
                                {t=a[j-1];
                                a[j-1]=a[j];
                                a[j]=t;}//zamjenom susjednih mjehurica u svakom
                                //prolazu postizemo to da se najlaksi mjehuric
                                //od preostalih pomjeri prema gore
        printf("Sortiran niz (u rastucem redoslijedu):\n");
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);
        getch();
        return 0;
}
//---------------------------------------------------------------------------
