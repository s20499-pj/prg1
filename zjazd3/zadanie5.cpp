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
	int palindrom = 1;
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
	l--;
	for (int j=0; j<l; j++)
	{
		if(x[j]!=x[l])
		{
			palindrom=0;
		}
		l--;
	}

        cout << palindrom << endl;
        return 0;
}

