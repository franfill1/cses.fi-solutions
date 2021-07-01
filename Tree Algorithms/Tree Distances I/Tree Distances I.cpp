#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

vector < pair < ii , ii > > mDe;
vector < vector < int > > t;

int maxDepth(int n, int from)
{
	int a1 = 0, a2 = 0;
	int n1 = -1, n2 = -1;
	for (auto ne : t[n])
	{
		if (ne != from)
		{
			int temp = maxDepth(ne, n);
			if (temp > a1)
			{
				a2 = a1;
				a1 = temp;
				n2 = n1;
				n1 = ne;
			}
			else if (temp > a2)
			{
				a2 = temp;
				n2 = n2;
			}
		}
	}
	mDe[n] = make_pair(make_pair(a1, n1), make_pair(a2, n2));
	return a1+1;
}

void recalc(int n, int from)
{
	if (from != -1)
	{
		int ne = from;
		int temp;
		if (mDe[ne].first.second != n)
		{
			temp = mDe[ne].first.first + 1;
		}
		else
		{
			temp = mDe[ne].second.first + 1;
		}
		
		int a1 = mDe[n].first.first;
		int n1 = mDe[n].first.second;
		int a2 = mDe[n].second.first;
		int n2 = mDe[n].second.second;
		
		if (temp > a1)
		{
			a2 = a1;
			a1 = temp;
			n2 = n1;
			n1 = ne;
		}
		else if (temp > a2)
		{
			a2 = temp;
			n2 = ne;
		}
		mDe[n] = make_pair(make_pair(a1, n1), make_pair(a2, n2));
	}
	for (auto ne : t[n])
	{
		if (ne == from) continue;
		recalc(ne, n);
	}
}

int main()
{
	int N;
	cin >> N;
	t.resize(N);
	mDe.resize(N);
	for (int i = 0 ; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	maxDepth(0, -1);
	recalc(0, -1);
	for (int i = 0; i < N; i++)
	{
		cout << mDe[i].first.first << " ";
	}
}

