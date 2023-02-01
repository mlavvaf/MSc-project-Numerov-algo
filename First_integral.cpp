// this program solve d/dx(dy/dx)=-4*3.14*3.14y bye means of numerovalgorithm.

#include <iostream>
#include <fstream>
#include <conio.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
        float h=0.1,x0,x,g,EXACT;
        int n=10,i;
        g=(h*(h/12)*4*3.14*3.14);
        x0=0;
        float y[10];
        cout<<"this program solves the differential equation d/dx(dy/dx)=-4*3.14*3.14y.\n\n";
        y[0]=0;

        cout<<"\ny[0]="<<y[0];
        y[1]=exp(-2*3.14*3.14*h*h);
        cout<<"\ny[1]="<<y[1];
        x=x0;
        cout<<"\nx="<<x;
        cout<<"\n----------------------------------------------\n";
        
        cout<<setiosflags(ios::left)<<setw(15)<<"\nx:\t";
        cout<<setiosflags(ios::left)<<setw(15)<<"EXACT:\t";
        cout<<setiosflags(ios::left)<<setw(15)<<"y[i+1]:\t\t";
        cout<<setiosflags(ios::left)<<"y[i+1]-EXACT:\n";
        
        cout<<"------------------------------------------------\n";
        for(i=1;i<=n;i++)
        {
                x=x+h;
                y[i+1]=(2*(1-5*g)*y[i]-(1+g)*y[i-1])/(1+g);
                EXACT=exp(-2*3.14*3.14*x*x);
                cout<<setiosflags(ios::left)<<setw(15)<<x<<"\t";
                cout<<setiosflags(ios::left)<<setw(15)<<EXACT<<"\t\t";
                cout<<setiosflags(ios::left)<<setw(15)<<y[i+1]<<"\t\t";
                cout<<setiosflags(ios::left)<<y[i+1]-EXACT<<"\n";
        }
        getch();
        return 0;
}
