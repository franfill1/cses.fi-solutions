/*
Task:              Missing Coin Sum Queries
Sender:            franfill
Submission time:   2024-02-27 11:01:04 +0200
Language:          C++17
Result:            ACCEPTED
*/
#include <cstdint>
#include <iostream>
using namespace std;
 
const int BUCK = 30, P = 18, MAXN = 200000;
 
uint32_t val[MAXN];
uint64_t sum[BUCK][MAXN + 1];
uint32_t tab[BUCK][P][MAXN];
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  uint32_t n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> val[i];
 
  for (uint32_t b = 0; b < BUCK; b++) {
    sum[b][0] = 0;
    for (uint32_t i = 0; i < n; i++)
      if ((1ll << b) <= val[i] && val[i] < (1ll << (b + 1)))
        sum[b][i + 1] = sum[b][i] + val[i], tab[b][0][i] = val[i];
      else
        sum[b][i + 1] = sum[b][i], tab[b][0][i] = 1u<<31;
    
    for (uint32_t p = 1; p < P; p++)
      for (uint32_t i = 0; i + (1<<p) <= n; i++)
        tab[b][p][i] = min(tab[b][p-1][i], tab[b][p-1][i+(1<<(p-1))]);
  }
 
  while(q--) {
    uint32_t l, r;
    cin >> l >> r;
    l--;
 
    uint32_t p = 0;
    while(1<<(p+1) <= (r-l))
      p++;
 
    uint64_t high = 1;
    for (uint32_t b = 0; b < BUCK; b++) {
      uint32_t mi = min(tab[b][p][l], tab[b][p][r-(1<<p)]);
      if (mi <= high)
        high += sum[b][r] - sum[b][l];
    }
    cout << high << "\n";
  }
}
