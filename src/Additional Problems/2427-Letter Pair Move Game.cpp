/*
Task:              Letter Pair Move Game
Sender:            franfill
Submission time:   2024-02-27 14:58:09 +0200
Language:          C++17
Result:            ACCEPTED
*/
#include<iostream>
#include <map>
#include <stack>
#include<vector>
#include<queue>
#include<string>
#include<cassert>
using namespace std;

string s;
vector < string > ans;
map < string , string > nxt;

void bfs(int n) {
  queue < string > q;
  for (int i = 0; i < n-2; i++) {
    string s = string(i, 'A') + string(n-i-2, 'B');
    if(n < 8) {
      for (int p = 0; p <= s.size(); p++) {
        string ns = s;
        ns.insert(p, "..");
        nxt[ns] = "";
        q.emplace(ns);
      }
    }
    else {
      s.insert(0, "..");
      nxt[s] = "";
      q.emplace(s);
    }
  }
  while(!q.empty()) {
    string x = q.front();
    q.pop();
    int p = x.find('.');
    assert(p+1 < x.size() && p != x.npos);
    for (int i = 0; i+1 < x.size(); i++)
      if (i != p-1 && i != p && i != p+1) {
        string nx = x;
        swap(nx[i], nx[p]);
        swap(nx[i+1], nx[p+1]);
        if (!nxt.count(nx)) {
          nxt[nx] = x;
          q.emplace(nx);
        }
      }
  }
}

bool solve(int l, int r) {
  string start = s.substr(l, r-l),end = "";
  if (!nxt.count(start)) {
    return false;
  } else {
    start = nxt[start];
    while(start != "") {
      s = s.substr(0, l) + start + s.substr(r);
      ans.emplace_back(s);
      start = nxt[start];
    }
    return true;
  }
}

int main() {
  int n;
  cin >> n;
  cin >> s;
  if (n == 1) {
    cout << 0 << "\n";
    return 0;
  }
  bfs(min(8, n*2));
  if (n <= 4) {
    if (!solve(0, n*2)) {
      cout << "-1\n";
    }
    else {
      cout << ans.size() << "\n";
      for (auto &s : ans)
        cout << s << "\n";
    }
  }
  else {
    int h = s.find('.');
    if (h == 1) {
      swap(s[h], s[h+2]);
      swap(s[h+1], s[h+3]);
      h += 2;
      ans.emplace_back(s);
    }
    if (h != 0) {
      swap(s[h], s[0]);
      swap(s[h+1], s[1]);
      ans.emplace_back(s);
    }

    int r = 2*n;
    int i = 0;
    while(true) {
      solve(i, i+8);
      if (i+8 >= r)
        break;
      bool redo = false;
      for (int j = i+2; j < i+8; j+=2)
        if (s[j] == 'B' && s[j+1] == 'B') {
          redo = true;
          r -= 2;
          swap(s[j], s[i]);
          swap(s[j+1], s[i+1]);
          ans.emplace_back(s);
          swap(s[r], s[j]);
          swap(s[r+1], s[j+1]);
          ans.emplace_back(s);
          swap(s[i+0], s[r]);
          swap(s[i+1], s[r+1]);
          ans.emplace_back(s);
        }
      if (!redo) {
        swap(s[i], s[i+2]);
        swap(s[i+1], s[i+3]);
        ans.emplace_back(s);
        i += 2;
      }
    }
    cout << ans.size() << "\n";
    for (auto &s : ans)
      cout << s << "\n";
  }
}
