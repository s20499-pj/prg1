#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
int i;
cout << "Podaj liczbę dodatnią";
cin >> i;
if (i>=2 && i<=5)
{
	cout << "Podana liczba jest niepoprawna" << endl;
}
return 0;
}
