/*
Task:              1087 Shortest Subsequence
Sender:            franfill
Submission time:   2022-12-02 22:24:19
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
int o[1000001][4];

int main()
{
	int n = 0, c, x;
	while ((c = getchar_unlocked()) >= 'A')
	{
		++n;
		for (x = 0; x < 4; x++) 
			o[n][x] = o[n-1][x];
		if (c == 'A') x = 0;
		else if (c == 'C') x = 1;
		else if (c == 'G') x = 2;
		else if (c == 'T') x = 3;
		o[n][x] = n;
	}
	string res = "";
	while(n+1)
	{
		if (o[n][0] < o[n][1])
		{
			if (o[n][0] < o[n][2])
			{
				if (o[n][0] < o[n][3])
					n = o[n][0], res += 'A';
				else
					n = o[n][3], res += 'T';
			}
			else if (o[n][2] < o[n][3])
				n = o[n][2], res += 'G';
			else
				n = o[n][3], res += 'T';
		}
		else if (o[n][1] < o[n][2])
		{
			if (o[n][1] < o[n][3])
				n = o[n][1], res += 'C';
			else
				n = o[n][3], res += 'T';
		}
		else if (o[n][2] < o[n][3])
			n = o[n][2], res += 'G';
		else
			n = o[n][3], res += 'T';
		--n;
	}
	for (c = res.size()-1; c >= 0; c--)
		putchar_unlocked(res[c]);
}
