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
	
	void mirror()
	{
		mirrorX();
		mirrorY();
	}
	
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
	return (a.x == b.x ? (a.y < b.y) : (a.x < b.x));
}
 
bool operator <= (pt a, pt b)
{
	return a == b || a < b;
}
 
/*bool operator > (pt a, pt b)
{
	return b < a;
}*/
 
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

vector < pt > under(vector < pt > P)
{
	sort(P.begin(), P.end());
	vector < pt > hull;
	hull.push_back(P[0]);
	hull.push_back(P[1]);
	for (int i = 2; i < P.size(); i++)
	{
		while(hull.size() > 1 && side({hull.back(), hull[hull.size()-2]}, P[i]) == 1)
		{
			hull.pop_back();
		}
		hull.push_back(P[i]);
	}
	return hull;
}

int main()
{
	int N;
	cin >> N;
	vector < pt > P(N);
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}
	vector < pt > und = under(P);
	for (int i = 0; i < N; i++)
	{
		P[i].mirror();
	}
	vector < pt > ov = under(P);
	cout << und.size() + ov.size() - 2 << "\n";
	for (int i = 0; i < und.size()-1; i++)
	{
		cout << und[i].x << " " << und[i].y << "\n";
	}
	for (int i = 0; i < ov.size()-1; i++)
	{
		cout << -ov[i].x << " " << -ov[i].y << "\n";
	}
}

