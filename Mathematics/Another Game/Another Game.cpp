#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		bool f = false;
		for (int i = 0; i < n; i++)
		{
			int e;
			cin >> e;
			if (e%2)
			{
				f = true;
			}
		}
		cout << (f?"first":"second") << "\n";
	}
}

