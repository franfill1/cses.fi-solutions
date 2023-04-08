/*
Task:              2193 Polygon Lattice Points
Sender:            franfill
Submission time:   2022-10-13 16:41:29
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pt
{
	ll x=0, y=0;
	pt(ll x_, ll y_) : x(x_) , y(y_){}
	pt(){}
};

ll operator ^ (pt a, pt b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{
	ll N;
	cin >> N;
	vector < pt > P(N);
	for (auto &p : P)
		cin >> p.x >> p.y;
	ll A = 0;
	for (ll i = 0; i < N; i++)
		A += P[i]^P[(i+1)%N];
	A = abs(A);
	ll b = 0;
	for (ll i = 0; i < N; i++)
	{
		auto p1 = P[i], p2 = P[(i+1)%N];
		ll dx = abs(p1.x - p2.x), dy = abs(p1.y - p2.y);
		ll g = __gcd(dx, dy);
		b += g;
	}
	// A = 2*(a + b/2 - 1) = 2a + b - 2
	// 2a = A - b + 2
	// a = (A-b+2)/2
	ll a = (A-b)/2 + 1;
	cout << a << " " << b << "\n";
}
