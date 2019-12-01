#include <iostream>

using namespace std;

int main()
{
	string tab[10][10];
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			tab[i][j]="  ";
		}
	}
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		tab[9-y][x]="*";
	}

	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			cout<< tab[i][j];
		}
		cout << endl;
	}

	
	return 0;
}


