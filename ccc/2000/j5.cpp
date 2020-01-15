// Problem ID: 
// By 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#define MAXN 105
using namespace std;
typedef pair<int,int> pii;

string url[MAXN], html[MAXN];
vector<int> adj[MAXN];
map<string,int> url_to_i;
bool vis[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N; cin.ignore();
    string s;
    for (int i = 0; i < N; i++)
    {
        getline(cin, url[i]);
        url_to_i.insert({url[i],i});
        while (getline(cin, s) && s != "</HTML>")
            html[i].append(s);
    }

    for (int i = 0; i < N; i++)
    {
        int j = -1;
        while ((j = html[i].find("A HREF=", j+1)) != -1)
        {
            int endquote = html[i].find("\"", j+8);
            string dest = html[i].substr(j+8, endquote-j-8);
            cout << "Link from " << url[i] << " to " << dest << '\n';
            auto it = url_to_i.find(dest);
            if (it != url_to_i.end())
            {
                adj[i].push_back(it->second);
            }
        }
    }

    string src, dest;
    while (getline(cin, src) && src != "The End")
    {
        getline(cin, dest);
        memset(vis, 0, sizeof vis);
        vis[url_to_i[src]] = true;
        queue<int> Q;
        Q.push(url_to_i[src]);
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for (int v : adj[u])
                if (!vis[v])
                    vis[v] = true, Q.push(v);
        }
        cout << "Can";
        if (!vis[url_to_i[dest]]) cout << "'t";
        cout << " surf from " << src << " to " << dest << ".\n";
    }

    return 0;
}
