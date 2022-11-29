#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct point
{
	ll x=0, y=0;
	point(ll x_, ll y_) : x(x_) , y(y_) {};
	point(){};

	void trans(point val)
	{
		x += val.x;
		y += val.y;
	}

	void mirror()
	{
		x = -x;
		y = -y;
	}
};

struct line
{
	point a, b;
	line(point a_, point b_)
	{
		a = a_, b = b_;
	}
};

ll sign(ll val)
{
	return (val>0)-(val<0);
}

point operator +(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}

point inverse(point p)
{
	return point(-p.x, -p.y);
}

point operator -(point a, point b)
{
	return (a+inverse(b));
}

ll operator ^(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}

ll side(line l, point p)
{
	return(sign((l.b-l.a)^(p-l.a)));
}

bool operator < (point a, point b)
{
	return a.x==b.x?(a.y < b.y):(a.x<b.x);
}

vector < point > lower(vector < point > v)
{
	sort(v.begin(), v.end());
	vector < point > res;
	res.push_back(v[0]);
	res.push_back(v[1]);
	for (int i = 2; i < v.size(); i++)
	{
		while(res.size() >= 2 && side({res[res.size()-2], res.back()}, v[i]) == -1) res.pop_back();
		res.push_back(v[i]);
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector < point > v(n);
	for (auto &p : v)
	{
		cin >> p.x >> p.y;
	}
	vector < point > low = lower(v);
	low.pop_back();
	for (auto &p : v) p.mirror();
	vector < point > up = lower(v);
	up.pop_back();
	cout << low.size() + up.size() << "\n";
	for (auto &p : low)
	{
		cout << p.x << " " << p.y << "\n";
	}
	for (auto &p : up)
	{
		cout << -p.x << " " << -p.y << "\n";
	}
}

