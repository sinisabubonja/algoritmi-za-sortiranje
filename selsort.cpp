//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom selsort. Selsort je
jednostavno prosirenje sortiranja umetanjem koje dopusta direktnu razmjenu
udaljenih elemenata. Prosirenje se sastoji u tome da se kroz algoritam umetanja
prolazi vise puta; u svakom prolazu uzima se neki korak h, dobija se niz u kome su
elementi na rastojanju h sortirani. Sa prolazima se nastavlja sve do koraka h=l,
u kome se dobija potpuno sortirani niz. Metodu Selsort je tesko porediti sa drugim
zato sto je funkcionalni oblik vremena izvrsavanja nepoznat i zavisi od sekvence h.
Za donji algoritam su granice n*exp(2ln(logn)) i exp(1.25*ln(n)). Metod nije
posebno osjetljiv na pocetni redoslijed elemenata, daje zadovoljavajuce vrijeme
izvrsavanja do npr. 5000 elemenata. */


#pragma hdrstop
#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int a[11],p[11];
        int i,n,h,j,x,k,l;
        printf("Unesite niz prirodnih brojeva; maksimalno 10 elem.(za kraj unosa unesite -1):\n");
        i=0;
        while (i!=-1)
                {i++;
                scanf("%d",&a[i]);
                if (a[i]==-1)
                        {n=i-1;
                        i=-1;}
                }
        i=0;
        while (3*i+1<=n)
                {h=3*i+1;
                i++;}//za h se uzima najvece 3*k+1 koje nije vece od n
                //zgodno mada ne i optimalno u odnosu na vrijeme izvrsavanja algoritma
        while (h>0)//postupak se ponavlja do h=1
                {i=0;
                j=0;
                while (i+h<=n)
                        {i=i+h;
                        j++;
                        p[j]=a[i];}//formiramo pomocni niz od svakog h-tog clana
               for (i=2;i<=j;i++)//pomocni niz ima j clanova
                {x=p[i];
                if (x<p[i-1])
                        {k=1;
                        while ((x>p[k])&&(k>=1)&&(k<i-1))
                                k++;
                        for (l=i-1;l>=k;l--)
                                p[l+1]=p[l];
                        p[k]=x;}
                }//sortirali smo pomocni niz metodom umetanja
               i=0;
               j=0;
               while (i+h<=n)
                        {i=i+h;
                        j++;
                        a[i]=p[j];}//niz a je sortiran sa korakom h
               if (h==1)
                h=0;//nema izlaska iz petlje, sve dok se ne dobije korak h=1
               h=h/3;//sledeci korak je cjelobrojna trecina prethodnog
               }
        printf("Sortiran niz (u rastucem redoslijedu):\n");
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);
        getch();
        return 0;
}
//---------------------------------------------------------------------------

