//this program is to solve d/dr(dQ/dr)=-0.5*r*exp(-r).
#include "iostream"
#include "fstream"
#include "conio.h"
#include "math.h"
#include "iomanip"
using namespace std;
float f(float x);
int main()
{
        float R,SM,SZ,SP,EXACT,CONS,R0,RF;
        double H=1,n;
        int j;
        cout<<"\nThis program is to solve d/dr(dQ/dr)=-0.5*r*exp(-r) bymeans of numerov algorithm method.\n\n";
        cout<<"\ninput R0:";
        cin>>R0;
        cout<<"\ninput RF:";
        cin>>RF;
        float PH[20];
        PH[0]=0;
        cout<<"\nPH[0]="<<PH[0];
        PH[1]=1-.5*(H+2)*exp(-H);
        cout<<"\nPH[1]="<<PH[1];
        n=floor((RF-R0)/H);
        CONS=H*H/12;
        SM=0;
        cout<<"\nSM="<<SM;
        SZ=-.5*H*exp(-H);
        cout<<"\nSZ="<<SZ;
        cout<<"\n\n";
        cout<<setiosflags(ios::left)<<setw(15)<<"R:\t";
        cout<<setiosflags(ios::left)<<setw(15)<<"EXACT:\t";
        cout<<setiosflags(ios::left)<<setw(15)<<"PH[j+1]s:\t";
        cout<<setiosflags(ios::left)<<"PH[j+1]-EXACT:\n";
        cout<<"------------------------------------------------\n";

        for(j=1;j<n;j++)
        {
                R=(j+1)*H;
                SP=-.5*R*exp(-R);
                PH[j+1]=2*PH[j]-PH[j-1]+CONS*(SP+10*SZ+SM);
                SM=SZ;
                SZ=SP;
                EXACT=1.00-.50*(R+2.00)*exp(-R);
                cout<<setiosflags(ios::left)<<setw(15)<<R<<"\t";
                cout<<setiosflags(ios::left)<<setw(18)<<EXACT<<"\t";
                cout<<setiosflags(ios::left)<<setw(20)<<PH[j+1]<<"\t";
                cout<<setiosflags(ios::left)<<setw(20)<<PH[j+1]-EXACT<<"\t";
                cout<<"\n";
        }
        getch();
        return 0;
}
