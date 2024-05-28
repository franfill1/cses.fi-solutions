/*
Task:              Removing Digits II
Sender:            franfill
Submission time:   2024-03-17 15:51:59 +0200
Language:          C++17
Result:            ACCEPTED
*/
#include <iostream>

using namespace std;
using ll = long long;

const short L = 50, D = 10;

ll dp[L][D][D][D], nb[L][D][D][D];

void init() {
  for (short z = 0; z < L-2; z++)
    for (short m = 0; m < D; m++)
      for (short a = 0; a < D; a++)
        for (short bb = 0; bb < D; bb++)
        {
          short b = bb;
          ll ans;
          short nm = max(m, a);
          if (b >= nm) {
            ans = dp[z][m][a][0]+1;
            b = nb[z][m][a][0];
          }
          else {
            ans = 1;
            b = 10 + b - nm;
            nm = max(m, (short)(a-1));
            if (z != 0) {
              ll add = 1;
              for (short i = 1; i <= z-1; i++) {
                add *= 10;
                ans += add;
              }

              for (short i = 9; i > 0; i--) {
                ll add = dp[z-1][nm][i][b];
                b = nb[z-1][nm][i][b];
                ans += add;
              }
            }
          }
          dp[z][m][a][bb] = ans;
          nb[z][m][a][bb] = b;
        }
}

int main() {
  init();
  string N;
  cin >> N;
  short ar[L];
  fill(ar, ar+L, 0);
  for (short i = 0; i < N.size(); i++)
    ar[i] = N[N.size()-i-1] -'0';

  short b = ar[0];
  ll ans = 0;
  for (short i = 1; i < L; i++) {
    short m = 0;
    for (short j = i+1; j < L; j++)
      m = max(m, ar[j]);
    for (int a = ar[i]; a > 0; a--) {
      ll add;
      short bb = b;
      add = dp[i-1][m][a][b];
      b = nb[i-1][m][a][b];
      ans += add;
    }
  }
  if (b)
    ans++;
  cout << ans << "\n";
}
