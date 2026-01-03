#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int n, m, s;
vector<int> ke[200005];
int visited[200005];

void nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
}

void dfs(int u){
    cout << u << " ";
    visited[u] = 1;
    for(int v : ke[u]){
        if(!visited[v]) dfs(v);
    }
}

int main(){
    #define TASK "main"
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    nhap();
    dfs(s);
}
