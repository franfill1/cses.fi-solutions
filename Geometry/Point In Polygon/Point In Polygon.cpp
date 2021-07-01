#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct line;
struct pt;
 
pt operator * (pt p, ll a);
pt operator + (pt a, pt b);
pt operator - (pt a, pt b);
ll operator ^ (pt a, pt b);
bool operator < (pt a, pt b);
 
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
	
	void perturbate()
	{
		ll nx = x * 32786 + y * 95419, ny = x*4 + y * 5;
		x = nx; y = ny;
	}
};
 
struct line
{
	pt a, b;
	line() {};
	line(pt ia, pt ib) : a(ia), b(ib) {};
	void perturbate()
	{
		a.perturbate();
		b.perturbate();
	}
	
	void sort()
	{
		if (b < a)
		{
			swap(a, b);
		}
	}
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
 
bool operator == (pt a, pt b)
{
	return (a.x == b.x) && (a.y == b.y);
}
 
bool operator < (pt a, pt b)
{
	return a.x < b.x ? 1 : a.y < b.y;
}
 
bool operator <= (pt a, pt b)
{
	return a == b || a < b;
}
 
bool operator > (pt a, pt b)
{
	return b < a;
}
 
bool operator >= (pt a, pt b)
{
	return b <= a;
}
 
istream& operator >>(istream& is, pt& p)
{
	is >> p.x >> p.y;
	return is;
}
 
istream& operator >>(istream& is, line& l)
{
	is >> l.a >> l.b;
	return is;
}
 
ostream& operator <<(ostream& os, pt p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
 
int sign(ll v)
{
	return (v > 0) - (v < 0);
}
 
int side(line l, pt p)
{
	return sign((l.a-p)^(l.b-p));
}
 
bool segOverlap(line r, line s)
{
	if (side(r, s.a) != 0 || side(r, s.b) != 0) return false;
	r.perturbate(); s.perturbate();
	r.sort(); s.sort();
	if (r.a.x > s.b.x) swap(r, s);
	return r.b.x >= s.a.x;
}
 
bool segIntersect(line r, line s)
{
	return (side(r, s.a) != side(r, s.b) && side(s, r.a) != side(s, r.b));
}

bool inside(line l, pt p)
{
	if (((l.a - p)^(l.b-p)) != 0) return false;
	else
	{
		l.perturbate();
		p.perturbate();
		l.sort();
		return (l.a.x <= p.x) && (p.x <= l.b.x);
	}
}

ll dPolyArea(vector < pt > P)
{
	ll ans = 0;
	for (int i = 0; i < P.size(); i++)
	{
		int j = (i+1)%P.size();
		ans += P[i]^P[j];
	}
	return ans;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector < line > L(N);
	pt l;
	cin >> l;
	for (int i = 0; i < N-1; i++)
	{
		pt p;
		cin >> p;
		L[i] = {l, p};
		l = p;
	}
	L.back() = {l, L[0].a};
	pt Q {1327869541, 985214736};
	for (int i = 0; i < M; i++)
	{
		pt p;
		cin >> p;
		bool bound = false;
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (inside(L[j], p))
			{
				bound = true;
			}
			if (segIntersect(L[j], {p, Q})) count++;
		}
		if (bound)
		{
			cout << "BOUNDARY\n";
			continue;
		}
		else if (count % 2)
		{
			cout << "INSIDE\n";
		}
		else
		{
			cout << "OUTSIDE\n";
		}
	}
}

