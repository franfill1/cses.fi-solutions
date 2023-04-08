/*
Task:              2189 Point Location Test
Sender:            franfill
Submission time:   2021-05-22 20:40:25
Language:          C++11
Result:            ACCEPTED
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct line;
struct pt;

pt operator * (pt p, ll a);
pt operator + (pt a, pt b);
pt operator - (pt a, pt b);
ll operator ^ (pt a, pt b);

istream& operator >>(istream& is, pt &p);
ostream& operator <<(ostream& os, pt p);

struct pt
{
	ll x = 0, y = 0;
	pt() {};
	pt(ll ix, ll iy) : x(ix) , y(iy) {};
	
	void mirrorX()
	{
		y = -y;
	};
	
	void mirrorY()
	{
		x = -x;
	};
	
	double norm()
	{
		return sqrt(x*x + y*y);
	};
};

struct line
{
	pt a, b;
	line() {};
	line(pt ia, pt ib) : a(ia), b(ib) {};
};

pt operator * (pt p, ll a)
{
	return {p.x*a, p.y*a};
}

pt operator + (pt a, pt b)
{
	return {a.x + b.x, a.y + b.y};
}

pt operator - (pt a, pt b)
{
	return {a.x - b.x, a.y - b.y};
}

ll operator ^ (pt a, pt b)
{
	return a.x*b.y - a.y*b.x;
}

istream& operator >>(istream& is, pt& p)
{
	is >> p.x >> p.y;
	return is;
}

ostream& operator <<(ostream& os, pt p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

int sign(ll x)
{
	return (x > 0) - (x < 0);
}

int side(line l, pt p)
{
	return sign((l.a-p)^(l.b-p));
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		pt a, b, c;
		cin >> a >> b >> c;
		ll p = side({a, b}, c);
		if (p == 0)
		{
			cout << "TOUCH\n";
		}
		else if (p < 0)
		{
			cout << "RIGHT\n";
		}
		else
		{
			cout << "LEFT\n";
		}
	}
}


