/*
Task:              2208 Another Game
Sender:            franfill
Submission time:   2021-12-01 11:10:15
Language:          C++17
Result:            ACCEPTED
*/
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
