//---------------------------------------------------------------------------
/*Ovaj program vrsi sortiranje niza prirodnih brojeva metodom umetanja. 
Osnovna ideja na kojoj se zasniva ova metoda je da polazeci od pocetnog dijela 
niza koji je vec sortiran, u ovom slucaju od prvog elementa, prvi slijedeci 
element umecemo na odgovarajuce mjesto u sortirani niz, tako da dobijamo novi
sortirani niz. Ponavljajuci ovaj postupak n-1 puta dobija se sortiran niz.
Slozenost ovog algoritma je O(exp(2*ln(n))). */  


#pragma hdrstop
#include <stdio.h>
#include <conio.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int a[11];
        int i,n,x,j,k;
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
                {x=a[i];//prvi clan neuredjenog dijela niza
                if (x<a[i-1])
                        {j=1;
                        while ((x>a[j])&&(j>=1)&&(j<i-1))
                                j++;//x<=a[j], prvo takvo j
                        for (k=i-1;k>=j;k--)//dekrementacija
                                a[k+1]=a[k];//pomjeramo sortirani dio niza udesno
                        a[j]=x;}
                }//umetnuli smo x na odgovarajuce mjesto u sortiranom dijelu niza
        printf("Sortiran niz (u rastucem redoslijedu):\n");
        for (i=1;i<=n;i++)
                printf("%d ",a[i]);
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 
