#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> tab;
	int x;

	while(x!=0)
	{
		cin >> x;
		tab.push_back(x);
	}

	for(int i=0; i<tab.size()-1; i++)
	{
		cout<<tab[i]<< " ";
	}
	return 0;
}

