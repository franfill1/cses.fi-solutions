/*
Task:              Filling Trominos
Sender:            franfill
Submission time:   2024-03-17 11:57:38 +0200
Language:          C++17
Result:            ACCEPTED
*/
#include <cassert>
#include<iostream>
#include <queue>
#include <set>
#include<string>
using namespace std;

struct tiling {
  const int width, height, num;
  int const * grid;
  tiling(int const * g, int w, int h, int n) : width(w) , height(h) , num(n) , grid(g) {}
};


namespace grids {
  int three_two[3][2] = {
    {0,0},
    {0,1},
    {1,1},
  };

  int six_three[6][3] = {
    {0,0,1},
    {0,1,1},
    {2,2,0},
    {2,0,0},
    {1,1,2},
    {1,2,2},
  };

  int nine_five[9][5] = {
    {0,0,1,0,0,},
    {0,1,1,2,0,},
    {3,3,2,2,1,},
    {3,4,4,1,1,},
    {1,1,4,3,3,},
    {1,2,0,0,3,},
    {2,2,0,2,2,},
    {0,0,1,2,0,},
    {0,1,1,0,0,},
  };
}

tiling three_two((int*)grids::three_two, 3, 2, 2);

tiling six_three((int*)grids::six_three, 6, 3, 3);

tiling nine_five((int*)grids::nine_five, 9, 5, 5);

const int MAXN = 100;
int res[MAXN][MAXN];
char out[MAXN][MAXN];
vector < pair < int , int > > pos[MAXN*MAXN/3];
int n, m;
int base = 0;

void fill(int start_i, int start_j, tiling t) {
  for (int i = 0; i < t.width; i++)
    for (int j = 0; j < t.height; j++) {
      res[start_i+i][start_j+j] = t.grid[i*t.height+j] + base;
      pos[res[start_i+i][start_j+j]].emplace_back(start_i+i, start_j+j);
    }
  base += t.num;
}

void fill_rows(int start_i, int dim) {
  if (dim == 3) {
    assert(m % 2 == 0); 
    for (int start_j = 0; start_j < m; start_j += 2)
      fill(start_i, start_j, three_two);
  }
  else if (dim == 6) {
    int start_j = 0;
    if (m % 2 != 0) {
      fill(start_i, start_j, six_three);
      start_j += 3;
    }
    for (; start_j < m; start_j += 2)
      for (int k = 0; k < 2; k++)
        fill(start_i + k*3, start_j, three_two);
  }
  else {
    int start_j = 0;
    assert(dim == 9);
    if (m % 2 != 0) {
      assert(m > 3);
      fill(start_i, start_j, nine_five);
      start_j += 5;
    }
    for (; start_j < m; start_j += 2)
      for (int k = 0; k < 3; k++)
        fill(start_i + k*3, start_j, three_two);
  }
}

void solve() {
  base = 0;
  cin >> n >> m;
  bool rev = false;
  if (m % 3 == 0 && (n % 3 != 0 || n > m)) {
    swap(n, m);
    rev = true;
  }
  if (n * m % 3 || (n == 3 && m % 2) || m == 1)
    cout << "NO\n";
  else {
    if (n == 3) {
      fill_rows(0, 3);
    }
    else {
      int start_i = 0;
      if ((n/3) % 2) {
        fill_rows(start_i, 9);
        start_i += 9;
      }
      for (; start_i < n; start_i += 6)
        fill_rows(start_i, 6);
    }
    for (int i = 0; i < n*m / 3; i++) {
      set < char > vis;
      for (auto [x, y] : pos[i]) {
        if (x > 0)
          vis.insert(out[x-1][y]);
        if (x < n-1)
          vis.insert(out[x+1][y]);
        if (y > 0)
          vis.insert(out[x][y-1]);
        if (y < m-1)
          vis.insert(out[x][y+1]);
      }
      char c = 'A';
      while(vis.count(c))
        c++;
      for (auto [x, y] : pos[i])
        out[x][y] = c;
    }
    cout << "YES\n";
    if (!rev) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
          cout << out[i][j];
        cout << "\n";
      }
    }
    else {
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++)
          cout << out[i][j];
        cout << "\n";
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        out[i][j] = 0, res[i][j] = 0;
    base = 0;
    for (int i = 0; i < n*m/3; i++)
      pos[i].resize(0);
  }
}

int main() {
  int t;
  cin >> t;
  while(t--)
    solve();
}
