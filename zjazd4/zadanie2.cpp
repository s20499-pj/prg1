#include <iostream>
using namespace std;

int main()
{
int x[3][3];
for (int i=0; i<3; i++)
{
	for (int j=0; j<3; j++)
	{
		cin >> x[j][i];
	}
}

int y[3][3];
for (int i=0; i<3; i++)
{
	for (int j=0; j<3; j++)
	{
		cin >> y[j][i];
	}
}

int z[3][3]={{0,0,0},{0,0,0},{0,0,0}};
for (int i=0; i<3; i++)
{
        for (int j=0; j<3; j++)
        {
                for(int l=0; l<3; l++)
		{
			z[j][i]=z[j][i]+x[l][i]*y[j][l];
		}
		cout << z[j][i] <<" ";
        }
	cout << endl;
}
return 0;
}
