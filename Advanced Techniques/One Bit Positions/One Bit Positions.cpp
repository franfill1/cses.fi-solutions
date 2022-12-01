/*
Task:              2112 One Bit Positions
Sender:            franfill
Submission time:   2022-10-17 14:50:01
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

using cpx = complex < double >;

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
			double ang = 2*M_PI/len * (invert?-1:1);
			cpx cur(1), w = polar(1.0, ang);
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

vector < int > multiply(vector < int > &a, vector < int > &b)
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
	vector < int > c(n);
	for (int i = 0; i < n; i++)
		c[i] = round(Cc[i].real());
	return c;
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector < int > a(n), b(n);
	for (int i = 0; i < n; i++)
		a[i] = b[n-i-1] = s[i] - '0';
	vector < int > c = multiply(a, b);
	for (int i = n-2; i >= 0; i--)
		cout << c[i] << " ";
	cout << "\n";
}
