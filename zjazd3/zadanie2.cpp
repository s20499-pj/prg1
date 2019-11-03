#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
int a[5];
int b[5];
int c[5];
int d[5];
int e[5];
float wynika=0;
float wynikb=0;
float wynikc=0;
float wynikd=0;
float wynike=0;
float srednia;

for (int i=0; i<5; i++)
{
	cin >> a[i];
	wynika+=a[i];
}
for (int i=0; i<5; i++)
{
        cin >> b[i];
        wynikb+=b[i];
}
for (int i=0; i<5; i++)
{
        cin >> c[i];
        wynikc+=c[i];
}
for (int i=0; i<5; i++)
{
        cin >> d[i];
        wynikd+=d[i];
}
for (int i=0; i<5; i++)
{
        cin >> e[i];
        wynike+=e[i];
}
srednia=(wynika+wynikb+wynikc+wynikd+wynike)/25;
cout << srednia << endl;

if(wynika/5>srednia) cout <<"1"<< endl;
if(wynikb/5>srednia) cout <<"2"<< endl;
if(wynikc/5>srednia) cout <<"3"<< endl;
if(wynikd/5>srednia) cout <<"4"<< endl;
if(wynike/5>srednia) cout <<"5"<< endl;



return 0;
}
