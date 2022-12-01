/*
Task:              2110 Substring Distribution
Sender:            franfill
Submission time:   2022-10-14 19:55:23
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

const char first = 'a'-1;
const char last = 'z'+1;
const int alphabet = last-first+1;

template < typename T >
ostream& operator << (ostream& os, vector < T > &v)
{
	for (auto &x : v)
		os << x << " ";
	return os;
}

struct dict_of_bfacts
{
	vector < vector < int > > dict;
	vector < int > suffix_array;
	int N, P;

	dict_of_bfacts(string s)
	{
		s += first;
		N = s.size();
		vector < int > cla(N, 0), arr(N);
		iota(arr.begin(), arr.end(), 0);
		sort(arr.begin(), arr.end(), [&] (int i, int j) {return s[i] < s[j];});
		int classes = 1;
		for (int i = 1; i < N; i++)
		{
			if (s[arr[i]] != s[arr[i-1]])
				classes++;
			cla[arr[i]] = classes-1;
		}
		dict.push_back(cla);

		//cerr << "arr: " << arr << "\n";
		//cerr << "cla: " << cla << "\n";

		for (P = 1; (1<<P) < (N<<1); P++)
		{
			//cerr << "ITERATION: " << P << "\n";
			vector < int > cnt(classes, 0);
			for (int c : cla)
				cnt[c]++;
			for (int c = 1; c < classes; c++)
				cnt[c] += cnt[c-1];
			//cerr << "cnt: " << cnt << "\n";
			vector < int > narr(N);
			for (int i = N-1; i >= 0; i--)
			{
				int idx = (arr[i] - (1<<(P-1)) + N*2) % N;
				//cerr << i << " " << arr[i] << " " << idx << " " << arr[idx] << " " << cla[arr[idx]] << " " << cnt[cla[arr[idx]]] << "\n";
				narr[--cnt[cla[idx]]] = idx;
			}
			arr = narr;
			//cerr << "arr: " << arr << "\n";
			vector < int > ncla(N, 0);
			classes = 1;
			for (int i = 1; i < N; i++)
			{
				auto a = make_pair(cla[arr[i]], cla[(arr[i] + (1<<(P-1))) % N]);
				auto b = make_pair(cla[arr[i-1]], cla[(arr[i-1] + (1<<(P-1))) % N]);
				if (a != b)
					classes++;
				ncla[arr[i]] = classes - 1;
			}
			cla = ncla;
			dict.push_back(cla);
			//cerr << "cla: " << cla << "\n";
		}
		suffix_array = arr;
	}

	int longest_match(int a, int b)
	{
		int ans = 0;
		for (int p = P-1; p >= 0; p--)
			if (dict[p][a] == dict[p][b])
				a += 1<<p, b += 1<<p, ans += 1<<p;
		return ans;
	}
};

int main()
{
	string s;
	cin >> s;
	dict_of_bfacts d(s);
	int N = s.size();
	vector < int > cnt(N+1, 0);
	auto v = d.suffix_array;
	for (int i = 1; i < N; i++)
		cnt[d.longest_match(v[i], v[i+1])]--;
	for (int i = N-1; i > 0; i--)
		cnt[i] += cnt[i+1];
	for (int i = 1; i <= N; i++)
	{
		cnt[i] += N-i+1;
		cout << cnt[i] << " ";
	}
	cout << "\n";
}
