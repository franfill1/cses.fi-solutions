#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

ll V[40], Va[1<<20], Vb[1<<20];

main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> V[i];
		
	int a = N/2;
	int b = N - a;
	int Na = 1<<a, Nb = 1<<b;
	
	for (int c = 0; c < Na; c++)
	{
		ll sum = 0;
		for (int i = 0; i < a; i++)
			if (c & (1<<i))
				sum += V[i];
		Va[c] = sum;
	}
	
	for (int c = 0; c < Nb; c++)
	{
		ll sum = 0;
		for (int i = 0; i < b; i++)
			if (c & (1<<i))
				sum += V[a+i];
		Vb[c] = sum;
	}

	sort(Va, Va+(1<<a));
	sort(Vb, Vb+(1<<b), greater < int > ());
	ll ans = 0;
	for (ll i = 0, j = 0; i < Na && j < Nb;)
	{
		while(j < Nb && Va[i] + Vb[j] > K)
			j++;
		if (j == Nb)
			break;
		ll nj = j, ni = i;
		while(ni < Na && Va[ni] == Va[i])
			ni++;
		while(nj < Nb && Vb[nj] == Vb[j])
			nj++;
		if (Va[i] + Vb[j] == K)
			ans += (ni-i)*(nj-j), j = nj;
		i = ni;
	}
	cout << ans << "\n";
}


