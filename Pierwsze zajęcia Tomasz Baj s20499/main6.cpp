#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{

int i;
int j;
cout << "podaj ilość pętli" <<endl;
cin >> j;
for (i=0; i<j; j=j-1)
{
	cout << "C++ zna pętle "<< j << endl;
}
cout << "C++ wie kiedy przestać "<<endl;
return 0;
}
