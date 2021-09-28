//https://www.spoj.com/submit/LCA/
// template for LCA from binary lifting
// try to use as black box
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair

void addedge(vector<vector<int>> &adj, int u, int v){
  adj[u].PB(v);
  adj[v].PB(u);
}

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void solve(int count){
  int n; cin>>n;
  vector<vector<int>> adj(n, vector<int> ());
  for(int i=0; i<n; i++){
    int k;
    cin>>k;
    while(k--){
      int temp; cin>>temp;
      adj[i].push_back(temp-1);
      adj[temp-1].push_back(i);
    }
  }

  LCA newlca(adj);
  // struct LCA newlca = struct LCA(adj);
  // newlca.build();
  // LCA lca(adj);

  int q; cin>>q;
  cout<<"Case "<<count<<":\n";
  while(q--){
    int u,v; cin>>u>>v;
    cout<<newlca.lca(u-1, v-1)+1<<'\n';
  }
}

int main(){
  int t; cin>>t;
  int count = 1;
  while(t--){
    solve(count);
    count++;
  }
}
