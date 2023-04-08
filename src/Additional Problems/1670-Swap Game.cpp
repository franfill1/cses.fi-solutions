/*
Task:              1670 Swap Game
Sender:            franfill
Submission time:   2022-12-02 17:57:00
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

bool vis[9][9][9][9][9][9][9][9][9];

int main()
{
	array < int , 9 > st;
	array < int , 9 > en;
	for (int i = 0; i < 9; i++)
	{
		cin >> st[i];
		st[i]--;
		en[i] = i;
	}
	auto add = [&] (array < int , 9 > &p) -> void
	{
		vis[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]][p[6]][p[7]][p[8]] = true;
	};
	auto check = [&] (array < int , 9 > &p) -> bool
	{
		return vis[p[0]][p[1]][p[2]][p[3]][p[4]][p[5]][p[6]][p[7]][p[8]];
	};
	add(st);
	queue < pair < int, array < int , 9 > > > q;
	q.emplace(0, st);
	while(!q.empty())
	{
		auto &[d, p] = q.front();
		q.pop();
		if (p == en)
		{
			cout << d << "\n";
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			if (i % 3 < 2)
			{
				swap(p[i], p[i+1]);
				if (!check(p))
				{
					q.emplace(d+1, p);
					add(p);
				}
				swap(p[i], p[i+1]);
			}
			if (i < 6)
			{
				swap(p[i], p[i+3]);
				if (!check(p))
				{
					q.emplace(d+1, p);
					add(p);
				}
				swap(p[i], p[i+3]);
			}
		}
	}
}
