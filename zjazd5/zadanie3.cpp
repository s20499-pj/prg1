#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string name[n];
	string heroclass[n];
	
	for(int i=0; i<n; i++)
	{
		cin >> name[i];
	}

	for(int j=0; j<n; j++)
	{
		cin >> heroclass[j];
	}

	srand(time(NULL));

	for(int i=0; i<n; i++)
	{
		cout << name[i] << "-";
		int x;
		do
		{
			x=rand()%n;
		}
		while(heroclass[x]=="0");
		
		cout <<heroclass[x]<<endl;
		heroclass[x]="0";
	}

	return 0;
}

