#include<bits/stdc++.h>
#define maxx 1000000
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
#endif
inline __attribute__((always_inline)) int fast_read_int()
{
    int c, n = 0;
    do
    {
        c = getchar_unlocked();
    } while (c < '0' || c > '9');
    do
    {
        n = (n << 3) + (n << 1) + (c - '0');
        c = getchar_unlocked();
    } while (c >= '0' && c <= '9');
    return n;
}

using namespace std;

int u[maxx];
bool isC[maxx];
int cnt[maxx];

signed main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	vector < int > primes;
	u[1] = 1;
	for (int x = 2; x < maxx; x++)
	{
		if (!isC[x])
		{
			primes.push_back(x);
			u[x] = -1;
		}
		for (int prime : primes)
		{
			if (x*prime >= maxx) break;
			isC[x*prime] = 1;
			if (x % prime == 0)
			{
				u[x*prime] = 0;
				break;
			}
			else
			{
				u[x*prime] = -u[x];
			}
		}
	}

	int n = fast_read_int();

	while(n--)
	{
		cnt[fast_read_int()]++;
	}

	long long ans = 0;

	long long temp;
	for (int d = 1; d < maxx; d++)
	{
		temp = 0;
		for (int i = 0; i*d < maxx; i++)
		{
			temp += cnt[i*d];
		}
		ans += temp*temp*u[d];
	}

	cout << ((ans-cnt[1])>>1) << "\n";
}

