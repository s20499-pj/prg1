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

for (int i=0; i<3; i++)
{
        for (int j=0; j<3; j++)
        {
                cout << x[j][i]+y[j][i]<< " ";
        }
	cout << endl;
}
return 0;
}
