#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string x;
	cin >> x;
	int l=0;
	while(x[l]!=0)
	{
		l++;
	}
	for (int i=0; i<l; i++)
	{
		if (x[i]>=65 && x[i]<=90)
		{
			x[i]=x[i]+32;
		}
	}
	cout << x << endl;
	return 0;
}
