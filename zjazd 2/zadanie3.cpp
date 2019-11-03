#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int i, j;
	cin >> i;
	do
	{
		cin>>j;
		if (i>j) cout<<"Za mało ";
		else if (i<j) cout<<"Za dużo ";
	}
	while(i != j);
	cout<<endl<<"Brawo wygrałeś"<<endl;
	return 0;
}


//Tomasz Baj s20499
//Robert Brzoskowski s21162
