//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom binarnog
umetanja. Razlikuje se od metode umetanja po algoritmu koji je u njemu primjenjen
za odredjivanje mjesta na koje treba umetnuti odgovarajuci element u sortirani
dio niza. Slozenost ovog algoritma je O(log(n)). */  



#pragma hdrstop
#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int a[11];
        int i,n,x,L,D,m,j;
        printf("Unesite niz prirodnih brojeva; maksimalno 10 elem.(za kraj unosa unesite -1):\n");
        i=0;
        while (i!=-1)
                {i++;
                scanf("%d",&a[i]);
                if (a[i]==-1)
                        {n=i-1;
                        i=-1;}
                }
        for (i=2;i<=n;i++)
                {x=a[i];
                L=1;//lijevi kraj sortiranog dijela niza
                D=i-1;//desni kraj sortiranog dijela niza
                while (L<=D)//izlazak iz petlje kada se lijevi i desni kraj
                //sortiranog niza poklope
                        {m=(L+D)/2;
                        if (x<a[m])
                                D=m-1;
                                        else L=m+1;
                        }//ako je x u lijevoj polovini sortiranog niza pomjera
                        //se desni kraj, u suprotnom pomjera se lijevi kraj
                for (j=i-1;j>=L;j--)
                        a[j+1]=a[j];//pomjeranje sortiranog dijela niza udesno
                a[L]=x;//umetnuli smo x na odgovarajuce mjesto u sortiranom dijelu niza
                }
        printf("Sortiran niz (u rastucem redoslijedu):\n");
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 
