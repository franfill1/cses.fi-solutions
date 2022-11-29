#include<bits/stdc++.h>
using namespace std;
typedef complex < double > cpx;
const double PI = acos(-1);

vector < cpx > fft (vector < cpx > a, bool invert = false)
{
	int n = a.size();
	int i = 0, j = 0;
	for (int k = 1; k < n; k++)
	{
		i ^= (k&-k); 
		j ^= (n>>1)/(k&-k);
		if (j > i)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1)
	{
		for (int i=0, j=len; j <= n; i += len, j += len)
		{
			double ang = (2*PI/len)*(invert?-1:1);
			cpx cur(1), w = polar(1.0, ang);
			for (int k = i; k < i + len/2; k++)
			{
				cpx f = a[k], s = a[k+len/2];
				a[k] = f + cur*s;
				a[k+len/2] = f - cur*s;
				cur *= w;
				if (invert)
					a[k] /= 2, a[k+len/2] /= 2;
			}
		}
	}
	
	return a;
}

vector < long long > multiply(vector < long long > a, vector < long long > b)
{
	vector < cpx > Ca(a.begin(), a.end()), Cb(b.begin(), b.end());
	int n = 1;
	while(n < a.size() + b.size())
		n <<= 1;
	Ca.resize(n, 0);
	Cb.resize(n, 0);
	vector < cpx > Va = fft(Ca, false), Vb = fft(Cb, false);
	vector < cpx > Vc(n);
	for (int i = 0; i < n; i++)
		Vc[i] = Va[i] * Vb[i];

	vector < cpx > Cc = fft(Vc, true);
	vector < long long > c(n);
	for (int i = 0; i < n; i++)
		c[i] = round(Cc[i].real());
	return c;
}

int main()
{
	int k, n, m;
	cin >> k >> n >> m;
	vector < long long > a(k+1, 0), b(k+1, 0);
	while(n--)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	while(m--)
	{
		int x;
		cin >> x;
		b[x]++;
	}

	vector < long long > c = multiply(a, b);
	for (int i = 2; i <= k*2; i++)
		cout << c[i] << " ";
	cout << "\n";
}

