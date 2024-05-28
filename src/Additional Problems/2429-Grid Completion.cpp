/*
Task:              Grid Completion
Sender:            franfill
Submission time:   2024-05-28 19:32:39 +0300
Language:          C++17
Result:            ACCEPTED
*/
#include <iostream>
using namespace std;
using ll = long long;
const int MAXN = 500;
const int MOD = 1000000007;

ll DPA[MAXN+1][MAXN+1];
ll DPB[MAXN+1][MAXN+1][MAXN+1];
ll CHOOSE[MAXN+1][MAXN+1];
ll FACT[MAXN+1];
char grid[MAXN][MAXN];

int main() {
  FACT[0] = 1;
  for (int i = 1; i < MAXN; i++)
    FACT[i] = FACT[i-1]*i % MOD;
  for (int i = 0; i < MAXN; i++) {
    CHOOSE[i][0] = 1;
    for (int j = 1; j <= i; j++)
      CHOOSE[i][j] = (CHOOSE[i-1][j-1] + CHOOSE[i-1][j]) % MOD;
  }

  int RA = 0, RB = 0, RAB = 0, CAB = 0, OSTA = 0, OSTB = 0;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> grid[i][j];

  for (int i = 0; i < N; i++) {
    bool a = false, b = false;
    for (int j = 0; j < N; j++)
      a |= grid[i][j] == 'A', b |= grid[i][j] == 'B';
    RA += !a, RB += !b, RAB += !a && !b;
  }

  for (int j = 0; j < N; j++) {
    bool a = false, b = false;
    for (int i = 0; i < N; i++)
      a |= grid[i][j] == 'A', b |= grid[i][j] == 'B';
    CAB += !a && !b;
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int cnt = 0;
      for (int k = 0; k < N; k++)
        cnt += (grid[i][k] != '.') + (grid[k][j] != '.');
      if (cnt == 2 && grid[i][j] == 'A')
        OSTB++;
      if (cnt == 2 && grid[i][j] == 'B')
        OSTA++;
    }

  DPA[0][0] = 1;
  for (int ost = 0; ost <= MAXN; ost++)
    for (int r = max(ost, 1); r <= MAXN; r++)
      DPA[ost][r] = ((ost > 1 ? (ost-1) * DPA[ost-2][r-1] : 0) % MOD
        + (r-ost) * DPA[max(ost-1,0)][r-1] % MOD) % MOD;

  int ONLY_B = RB-RAB;
  for (int blc = 0; blc <= MAXN; blc++) {
    DPB[blc][0][0] = 1;
    for (int ost = 0; ost <= N; ost++) {
      for (int r = max(ost, 1); r <= ONLY_B; r++)
        DPB[blc][ost][r] = ((ost > 1 ? (ost-1) * DPB[blc][ost-2][r-1] : 0) % MOD
          + (r-ost) * DPB[blc][max(ost-1,0)][r-1] % MOD) % MOD;
      for (int r = max(ost+blc, ONLY_B+1); r <= MAXN; r++)
        DPB[blc][ost][r] = ((ost > 0 ? ost * DPB[blc][ost-1][r-1] : 0) % MOD
          + (r-ost-blc) * DPB[blc][ost][r-1] % MOD) % MOD;
    }
  }
  
  ll ans = 0;
  for (int v = 0; v <= min(CAB, RAB); v++)
    ans += CHOOSE[RAB][v] * CHOOSE[CAB][v] % MOD * FACT[v] % MOD
      * DPA[OSTA+v][RA] % MOD
      * DPB[CAB-v][OSTB][RB-v] % MOD;
  cout << ans % MOD << "\n";
}
