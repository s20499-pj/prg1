#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> tab;
	int x;
	int s=0;
	while(x!=0)
	{
		cin >> x;
		tab.push_back(x);
		s=s+x;
	}
	s=s/(tab.size()-1);
	cout<<s;
	return 0;
}

