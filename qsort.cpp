//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom quick sort. Osnovna
ideja ove metode je da niz podijelimo proizvoljno odabranim elementom na dvije particije
tako da su u lijevoj elementi manje od njega, u desnoj veci od njega. Isto vazi i
za njihove indekse. Dobijene particije se particionisu dalje rekurzivno sve dok
ne dobijemo sortiran niz. Slozenost ovog algoritma je O(exp(2*log(n))).*/

#pragma hdrstop
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//---------------------------------------------------------------------------

#pragma argsused

int a[11];//globalna promjenjiva, vazi u cijelom programu dok lokalne promjenjive
//vaze samo u blokovima u kojima su deklarisane

int/*tip varijable koju vraca*/ partition/*ime funkcije*/(int L,int D/*argumenti*/)
//;prototip funkcije, moze da se navede samostalno slijedi tijelo funkcije
//funkcija se sama po sebi zove definicija funkcije, sadrzi protoptip i tijelo
//u slucaju da se navede samo prototip na kraju programa se definise funkcija
{
        int r,t;
        r=abs(rand()%(D-L+1))+L;//generise slucajan broj iz segmenta [L,D]
        while (L<=D)//pretrazuje niz sa krajeva i razmjenjuje clanove koji nisu
        //na svojim mjestima (lijevo treba da budu elementi niza manji od a[r],
        //a desno veci
                {
                        while (a[L]<=a[r]) L=L+1;
                        while (a[D]>=a[r]) D=D-1;
                        if (L<=D)
                                {
                                        t=a[L];
                                        a[L]=a[D];
                                        a[D]=t;
                                        L=L+1;
                                        D=D-1;
                                }
                }//kada se ta dva pretrazivanja sretnu a[r] se zamijeni sa jednim
                //od njih, zavisno od pozicije na kojoj se trenutno nalazi
        if (r>L)
                {
                        t=a[r];
                        a[r]=a[L];
                        a[L]=t;
                        r=L;
                }
        if (r<D)
                {
                        t=a[r];
                        a[r]=a[D];
                        a[D]=t;
                        r=D;
                }//vracamo r, poziciju na kojoj se odabrani element nalazi nakon
                //patricionisanja
        return  r;
}

void/*procedura, ne vraca ni jedan tip*/ quicksort(int LL,int DD)
{
        int p;
        if (DD>LL)
                {
                        p=partition(LL,DD);//vrsi se patricionisanje
                        quicksort(LL,p-1);//lijeva particija se patricionise
                        quicksort(p+1,DD);//desna patricija se patricionise
                        //i tako dalje rekurzivno dok ne dobijemo sortiran niz
                }
}//funkcija je rekurzivna jer poziva sama sebe

int main(int argc, char* argv[])
{
        int i,n;
        printf("Unesite niz prirodnih brojeva; maksimalno 10 elem.(za kraj unosa unesite -1):\n");
        i=0;
        while (i!=-1)
                {i++;
                scanf("%d",&a[i]);
                if (a[i]==-1)
                        {
                                n=i-1;
                                i=-1;
                        }
                }
        quicksort(1,n);//sortiramo niz, pozivamo funkciju imenom i argumentima
        printf("Sortiran niz (u rastucem redoslijedu):\n");
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);
        getch();
        return 0;
}
//---------------------------------------------------------------------------

