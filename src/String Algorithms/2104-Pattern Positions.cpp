/*
Task:              2104 Pattern Positions
Sender:            franfill
Submission time:   2022-10-13 16:19:17
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

const int first = 'a' - 1;
const int last = 'z' + 1;
const int alphabet = last - first + 1;

template < typename T >
ostream& operator <<(ostream &os, vector < T > &v)
{
	for (auto &x : v)
		os << x << " ";
	return os;
}

vector < int > suffix_array(string s)
{
	s += (char)first;
	int N = s.size();
	vector < int > arr(N), cla(N, 0);
	iota(arr.begin(), arr.end(), 0);
	sort(arr.begin(), arr.end(), [&] (int i, int j) {return s[i] < s[j];});
	int classes = 1;
	for (int i = 1; i < N; i++)
	{
		if (s[arr[i]] != s[arr[i-1]])
			classes++;
		cla[arr[i]] = classes - 1;
	}
	//cerr << "arr: " << arr << "\n";
	//cerr << "cla: " << cla << "\n";

	for (int p = 1; (1<<p) < N*2; p++)
	{
		//cerr << "iteration " << p << "\n";
		vector < int > cnt(classes, 0);
		for (int c : cla)
			cnt[c]++;
		//cerr << "cnt: " << cnt << "\n";
		for (int c = 1; c < classes; c++)
			cnt[c] += cnt[c-1];
		vector < int > narr(N);
		for (int i = N-1; i >= 0; i--)
		{
			int idx = (arr[i] - (1<<(p-1)) + N*2) % N;
			//cerr << i << " " << idx << " " << cla[idx] << "\n";
			narr[--cnt[cla[idx]]] = idx;
		}
		arr = narr;
		//cerr << "arr: " << arr << "\n";
		vector < int > ncla(N, 0);
		classes = 1;
		//cerr << arr[0] << ": " << cla[arr[0]] << " " << cla[(arr[0]   + (1<<(p-1))) % N] << "!\n";
		for (int i = 1; i < N; i++)
		{
			//cerr << arr[i] << ": " << cla[arr[i]] << " " << cla[(arr[i]   + (1<<(p-1))) % N] << "!\n";
			auto a = make_pair(cla[arr[i]]  , cla[(arr[i]   + (1<<(p-1))) % N]);
			auto b = make_pair(cla[arr[i-1]], cla[(arr[i-1] + (1<<(p-1))) % N]);
			if (a != b)
				classes++;
			ncla[arr[i]] = classes - 1;
		}
		cla = ncla;
		//cerr << "cla: " << cla << "\n";
	}
	return arr;
}

struct sparse_table
{
	int N, P;
	vector < vector < int > > tab;
	sparse_table( vector < int > &v)
	{
		N = v.size();
		tab.emplace_back(v);
		for (P = 1; (1<<P) < N; P++)
		{
			tab.emplace_back(N-(1<<P)+1);
			for (int i = 0; i+(1<<P) <= N; i++)
				tab[P][i] = min(tab[P-1][i], tab[P-1][i + (1<<(P-1))]);
		}
	}

	int get(int l, int r)
	{
		int s = r-l;
		int p = 31 - __builtin_clz(s);
		return min(tab[p][l], tab[p][r-(1<<p)]);
	}
};

int main()
{
	string s;
	cin >> s;
	auto v = suffix_array(s);
	sparse_table tab(v);
	int N = s.size();
	int k;
	cin >> k;
	//cerr << v << "\n";
	while(k--)
	{
		string pat;
		cin >> pat;
		int len = pat.size();
		int l;
		{
			int a = 0, b = N+1;
			while(a < b-1)
			{
				int m = (a+b)/2;
				if (s.substr(v[m], len) < pat)
					a = m;
				else
					b = m;
			}
			l = b;
		}
		int r;
		{
			int a = l-1, b = N+1;
			while(a < b-1)
			{
				int m = (a+b)/2;
				if (s.substr(v[m], len) == pat)
					a = m;
				else
					b = m;
			}
			r = b;
		}
		if (l == r)
			cout << -1 << "\n";
		else
			cout << tab.get(l, r)+1 << "\n";
	}
}
