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
	for (int i=l; i>0; i--)
	{
		cout<<x[i-1];
	}
	cout << endl;
	return 0;
}
