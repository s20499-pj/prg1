#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
int n;
cin>>n;
n--;
for(int i=n; i>0; i--)
{
cout<<" ";
}
cout<<"*"<<endl;

for(int i=n; i>0; i--)
{
	for(int j=i; j>0; j--)
	{
	cout<<" ";
	}
	cout<<"*";
	for(int k=0 ;k<(i+0.5)*2;k++)
	{
	cout<<" ";
	}
	cout<<"*"<<endl;
}
return 0;
}


//Tomasz Baj s20499
//Robert Brzoskowski s21162
