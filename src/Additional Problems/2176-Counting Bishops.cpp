/*
Task:              Counting Bishops
Sender:            franfill
Submission time:   2024-03-17 12:56:50 +0200
Language:          C++17
Result:            ACCEPTED
*/
#pragma GCC optimize("Ofast")
#include<iostream>
#pragma GCC target("avx2")
using namespace std;
using ll = long long;
const int MAXN = 500;
const ll MOD = 1000000007;

int A[MAXN+1], B[MAXN+1];
ll DPA[MAXN+1][MAXN+11], DPB[MAXN+1][MAXN+11];
ll buff[MAXN+1][MAXN+11];

void solve() {
  for (int i = 0; i <= MAXN; i++)
    DPA[i][0] = 1;

  for (int i = 1; i <= MAXN; i++) {
    for (int cnt = 0; cnt+A[i] <= min(MAXN, MAXN-i+4); cnt++) {
      for (int k = 0; k < min(MAXN+10, cnt+A[i]+i+1); k++) {
        buff[cnt][k] = 0;
        if (cnt + A[i] <= MAXN)
          buff[cnt][k] += DPA[cnt+A[i]][k];
        if (cnt + A[i]-1 <= MAXN && k > 0 && cnt+A[i] > 0)
          buff[cnt][k] += DPA[cnt+A[i]-1][k-1]*(cnt + A[i]);
        buff[cnt][k] %= MOD;
      }
    }
    swap(buff, DPA);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  if (k >= n*2)
    cout << 0 << "\n";
  else {
    for (int s = 0; s < n*2-1; s++)
      if (s % 2)
        A[n-abs(n-1-s)]++;
      else
        B[n-abs(n-1-s)]++;
    solve();
    swap(A, B);
    swap(DPA, DPB);
    solve();

    ll ans = 0;
    for (int k1 = 0; k1 <= k; k1++) {
      if (k-k1 < MAXN+11 && k1 < MAXN+11)
        ans += DPA[0][k1]*DPB[0][k-k1] % MOD;
    }
    cout << ans % MOD << "\n";
  }
}
