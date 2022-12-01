/*
Task:              1688 Company Queries II
Sender:            franfill
Submission time:   2022-09-19 21:31:05
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#define pb push_back
#define pii pair < int, int >
#define f first
#define s second
 
using namespace std;

int lca(int u, int v, int LOG, vector < int > &depth, vector < vector < int > > &up)
{
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int j = 0; j < LOG; j++) if (k & (1 << j)) u = up[u][j];

    if (u == v) return v;
    for (int j = LOG - 1; j >= 0; j--) if (up[u][j] != up[v][j]) 
    {
        u = up[u][j];
        v = up[v][j];
    }
    return up[u][0];
}

int main()
{
	int N, Q;
    cin >> N >> Q;
    N++;
    int LOG = ceil(log2(N));

    vector < vector < int > > up(N, vector < int >(LOG));
    vector < int > depth(N, 0);
    up[0][0] = up[1][0] = 0;
    for (int i = 2; i < N; i++)
    {
        int a;
        cin >> a;
        up[i][0] = a;
        depth[i] = depth[a] + 1;
    }
    for (int j = 1; j < LOG; j++) for (int i = 0; i < N; i++) up[i][j] = up[ up[i][j - 1] ][j - 1];
    
    while (Q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v, LOG, depth, up) << "\n";
    }
}
