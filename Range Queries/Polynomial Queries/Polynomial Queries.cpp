/*
Task:              1736 Polynomial Queries
Sender:            franfill
Submission time:   2021-08-27 15:09:40
Language:          C++17
Result:            ACCEPTED
*/
// https://cses.fi/problemset/task/1736
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL GAUSS(LL x) { return x * (x + 1) / 2; }

struct nd {
    LL sum = 0;
    LL inc = 0;
    LL lazy = 0;
    nd() {}
    nd(LL _sum) : sum(_sum) {}
};
nd join(nd a, nd b) { return nd(a.sum + b.sum); }

LL N = 1;
vector<nd> t;

void prop(LL i, LL a, LL b) 
{
	t[i].sum += (b - a) * t[i].lazy;
	if (i < N) {
		t[i << 1    ].lazy += t[i].lazy;
		t[i << 1 | 1].lazy += t[i].lazy;
	}
	t[i].lazy = 0;
	t[i].sum += t[i].inc * GAUSS(b - a);
	if (i < N) {
		t[i << 1    ].inc += t[i].inc;
		t[i << 1 | 1].inc += t[i].inc;
		t[i << 1 | 1].lazy += t[i].inc * (b - a) / 2;
	}
	t[i].inc = 0;
}

void inc(int i, int a, int b, int l, int r) {
    prop(i, a, b);
    if (r <= a || b <= l)
        return;
    if (l <= a && b <= r) {
        ++t[i].inc;
        t[i].lazy += (a - l);
        prop(i, a, b);
    } else {
        inc(i << 1    , a, (a + b) / 2, l, r);
        inc(i << 1 | 1, (a + b) / 2, b, l, r);
        t[i] = join(t[i << 1], t[i << 1 | 1]);
    }
}

LL sum(int i, int a, int b, int l, int r) {
    prop(i, a, b);
    if (r <= a || b <= l)
        return 0;
    if (l <= a && b <= r)
        return t[i].sum;
    return sum(i << 1    , a, (a + b) / 2, l, r) + 
           sum(i << 1 | 1, (a + b) / 2, b, l, r);
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (; N < n; N <<= 1);
    t.resize(2 * N);

    for (int i = 0; i < n; ++i)
        cin >> t[i + N].sum;
    for (int i = N - 1; i > 0; --i)
        t[i] = join(t[i << 1], t[i << 1 | 1]);

    for (int x, a, b; q--;) {
        cin >> x >> a >> b;
		
        if (x == 1)
            inc(1, 0, N, a - 1, b);
        else
            cout << sum(1, 0, N, a - 1, b) << "\n";
    }
}
