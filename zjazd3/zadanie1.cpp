#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
int x[5];
float srednia=0;

for (int i=0; i<5; i++)
{
	cin >> x[i];
	srednia+=x[i];
}
cout << srednia/5;
return 0;
}
