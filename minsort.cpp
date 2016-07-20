//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom neposrednog 
izbora, u ovom slucaju  minimalnog elementa. Osnovna ideja na kojoj se zasniva
ova metoda je pronalazenje minimalnog elementa medju nesortiranim elementima i 
njegova zamjena prvim elementom u nesortiranom dijelu niza.Ponavljajuci ovaj 
postupak n-1 puta dobija se sortiran niz. Slozenost ovog algoritma je 
O(exp(2*ln(n))). */

#pragma hdrstop
#include <stdio.h>//standardna biblioteka za ulaz izlaz
#include <conio.h>//funkcija getch

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int a[11];//cjelobrojni niz, maksimalno 10 elemenata
        int i,j,n,t; //deklaracija promjenjivih, iskljucivo na pocetku programa
        printf("Unesite niz prirodnih brojeva; maksimalno 10 elem.(za kraj unosa unesite -1):\n");
        //ispis teksta
        i=0;
        while (i!=-1)//while petlja; uslov
                {i++;//i=i+1, inkrementacija
                scanf("%d",&a[i]);//ucitavanje promjenjivih, cjelobrojni tip
                if (a[i]==-1)
                        {n=i-1;
                        i=-1;}}
       for (i=1;i<=n-1;i++)//for petlja; inicijalizacija, uslov, korak
                for (j=i+1;j<=n;j++)//ugnjezdena for petlja
                        if (a[i]>a[j])
                                {t=a[i];
                                a[i]=a[j];
                                a[j]=t;}//zamjena promjenjivih; pomocna
                                //promjenjiva t
        printf("Sortiran niz (u rastucem redoslijedu):\n");
        //\n prelazak u novi novi red
        //sortiran niz u opadajucem redoslijedu dobijamo ispisom od n-tog do
        //prvog clana niza
        //isto smo mogli postici dovodjenjem najveceg elementa na prvo mjesto...
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);//ispis promjenjivih
        getch();//cuva ispis na ekranu do unosa bilo kog znaka
        return 0;//funkcija main vraca cjelobrojnu vrijednost
}
//---------------------------------------------------------------------------
 
