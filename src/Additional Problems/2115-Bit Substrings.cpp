/*
Task:              2115 Bit Substrings
Sender:            franfill
Submission time:   2023-04-16 20:17:44
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using cpx = complex < ld >;
 
vector < cpx > fft(vector < cpx > a, bool invert)
{
	int n = a.size();
	int i=0, j=0;
	for (int k = 1; k < n; k++)
	{
		i ^= k&-k;
		j ^= (n>>1)/(k&-k);
		if (i < j)
			swap(a[i], a[j]);
	}
 
	for (int len = 2; len <= n; len<<=1)
		for (int i = 0; i + len <= n; i += len)
		{
			ld ang = 2*M_PI/len * (invert?-1:1);
			cpx cur(1), w = polar((ld)1.0, ang);
			for (int j = i; j < i + len/2; j++)
			{
				auto x = a[j], y = a[j+len/2];
				a[j] = x + cur*y;
				a[j+len/2] = x - cur*y;
				cur *= w;
			}
		}
 
	if (invert)
		for (int i = 0; i < n; i++)
			a[i] /= n;
	return a;
}
 
vector < ll > multiply(vector < ll > &a, vector < ll > &b)
{
	vector < cpx > Ca(a.begin(), a.end()), Cb(b.begin(), b.end());
	int n = 1;
	while(n < a.size() + b.size())
		n <<= 1;
	Ca.resize(n);
	Cb.resize(n);
	auto Va = fft(Ca, false), Vb = fft(Cb, false);
	vector < cpx > Vc(n);
	for (int i = 0; i < n; i++)
		Vc[i] = Va[i] * Vb[i];
	vector < cpx > Cc = fft(Vc, true);
	vector < ll > c(n);
	for (int i = 0; i < n; i++)
		c[i] = round(Cc[i].real());
	return c;
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int cur = 1;
	vector < ll > p;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			p.emplace_back(cur);
			cur = 0;
		}
		cur++;
	}
	p.emplace_back(cur);
	p.resize(n+1, 0);
	vector < ll > q(n+1);
	for (int i = 0; i <= n; i++)
		q[i] = p[n-i];
	p.resize(2*n+2);
	q.resize(2*n+2);
	vector < ll > r = multiply(p, q);
	cout << (r[n]-n-1)/2 << " ";
	for (int i = 1; i <= n; i++)
		cout << r[i+n] << " ";
	cout << "\n";
}
