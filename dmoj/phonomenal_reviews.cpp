// CCC '16 S3 - Phonomenal Reviews

#include <iostream>
#include <set>
#include <queue>
#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_N 100005

using namespace std;

struct node
{
    int i, color = WHITE, d = MAX_N, p = -1;
    bool is_pho = false, in_tree = true;
    vector<int> adj;
};

vector<node> V;
vector<int> V_pho;
bool subtree_has_pho[MAX_N];
int max, s, f, total = -2, max_d = 0, furthest_i = -1;

void dfs_visit(int u, int &max_d, int &furthest_i)
{
    // cout << "visiting " << u << ", p: " << V[u].p << ", d: " << V[u].d << "\n";
    V[u].color = GRAY;

    if (V[u].d > max_d && V[u].is_pho)
    {
        // cout << "max_d := " << V[u].d << ", furthest_i := " << u << "\n";
        max_d = V[u].d;
        furthest_i = u;
    }
    
    for (int i : V[u].adj)
    {
        if (V[i].color == WHITE)
        {
            V[i].p = V[u].i;
            V[i].d = V[u].d + 1;
            dfs_visit(i, max_d, furthest_i);
        }
    }

    // cout << "DONE visiting " << u << "\n";
    V[u].color = BLACK;

    if (V[u].is_pho || subtree_has_pho[u])
    {
        subtree_has_pho[u] = 1;
        if (V[u].p >= 0) subtree_has_pho[V[u].p] = 1;
        total += 2;
        // cout << "is pho or subtree has pho, TOTAL = " << total << "\n";
    }
}

void max_d_dfs(int start, int &max_d, int &furthest_i)
{
    // Clear all of the vertices
    for (node &u : V) {
        u.d = MAX_N;
        u.p = -1;
        u.color = WHITE;
    }

    node &s = V[start];
    s.color = GRAY;
    s.d = 0;

    dfs_visit(s.i, max_d, furthest_i);

    // cout << "\n\n\n\n";
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, t, a, b;
    cin >> n >> m;

    // Initialize array of vertices
    for (i = 0; i < n; ++i) {
        node u;
        u.i = i;
        V.push_back(u);
    }

    // Read in pho restaurants
    for (i = 0; i < m; ++i) {
        cin >> t;
        V[t].is_pho = 1;
        V_pho.push_back(t);
    }

    // Read in edges as adjacency lists
    for (i = 0; i < n-1; ++i) {
        cin >> a >> b;
        V[a].adj.push_back(b);
        V[b].adj.push_back(a);
    }
    
    // for (i = 0; i < n; ++i) {
    //     cout << "adj[" << i << "]: ";
    //     for (int j : V[i].adj) cout << j << ", ";
    //     cout << "\n";
    // }

    max_d_dfs(V_pho[0], max_d, furthest_i);
    // cout << "furthest_i: " << furthest_i << '\n';
    max_d = 0;
    total = -2;
    max_d_dfs(furthest_i, max_d, furthest_i);

    // cout << "total: " << total << ", max_d: " << max_d << ", furthest_i: " << furthest_i << endl;

    cout << total - max_d << '\n';
    return 0;
}
