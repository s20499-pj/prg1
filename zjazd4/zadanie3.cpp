#include <iostream>
using namespace std;

int main()
{
	int tab[3][3]={0,0,0,0,0,0,0,0,0};
	int x,j,i,k=0;

	while(1)
	{
		cin >> x;
		i=(x-1)/3;
		j=(x-1)%3;
		if(tab[i][j])
		{
			break;
		}
		tab[i][j]=((k++)%2==1)?2:1;
	}
	//cout << 0;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
        	{
			cout << tab[i][j]<< " ";
        	}
        	cout << endl;
	}

	return 0;
}
