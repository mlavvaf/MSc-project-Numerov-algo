//This program is to find the lowest eigenvalue of streched string
problem by shooting method.
#include "iostream"
#include "fstream"
#include "conio.h"
#include "math.h"
#include "iomanip"
using namespace std;
int main()
{
        float h=.01,tolk=9.999999E-06,dk,PHIOLD,PHIP,g,i,PHIZ,PHIM;
        float n=100,k;
        cout<<"\nThis program is to find the lowest eigenvalue of stretched string problem by shooting method.";
        cout<<"\n------------------------------------------------";
        k=1;
        dk=1;
        g=((k*h)*(k*h))/12;
        PHIM=0;
        PHIZ=0.01;
        for(i=1;i<=n-1;i++)
        {
                PHIP=2*(1-5*g)*PHIZ-(1+g)*PHIM;
                PHIP=PHIP/(1+g);
                PHIM=PHIZ;
                PHIZ=PHIP;
        }
        PHIOLD=PHIP;
        cout<<"\nPHIOLD="<<PHIOLD;
        while (fabs(dk>tolk))
        {
                k=k+dk;
                g=((k*h)*(k*h))/12;
                PHIM=0;
                PHIZ=0.01;
                for(i=1;i<=n-1;i++)
                {
                        PHIP=2*(1-5*g)*PHIZ-(1+g)*PHIM;
                        PHIP=PHIP/(1+g);
                        PHIM=PHIZ;
                        PHIZ=PHIP;
                }
                PHIP=PHIP;
                if(PHIP*PHIOLD<0 )
                {
                        k=k-dk;
                        dk=dk/2;
                }
        }
        cout<<"\n\t\t eigenvalue ="<<k;
        getch();
        return 0;
}
