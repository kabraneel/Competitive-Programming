#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;
#define PB push_back
#define MP make_pair
typedef long long ll;


#define MAXN 100005
vector<pair<int,int>> adj[MAXN];
bool visited[MAXN];
int distanceval1[MAXN];
int parent[MAXN];

void addedge(int x, int y, int w){
    adj[x].PB({y,w});
    adj[y].PB({x,w});
}

void DijsktrasOnSparse(int source, int n){
    set<pair<int,int>> s;
    s.insert({0,source});
    parent[source] = -1;

    FOR(i,0,n){
        visited[i] = 0;
        distanceval[i] = INT_MAX;
        parent[i] = -1;
    }

    while(!s.empty()){
        int cur = s.begin()->second;
        int d = s.begin()->first;
        s.erase(s.begin());

        if (!visited[cur]){
            distanceval[cur] = d;
            visited[cur] = true;
            for(auto &to:adj[cur]){
                if (!visited[to.first]){
                    // for better time complexity
                    if (d+to.second < distanceval[to.first]){
                        parent[to.first] = cur;
                        s.insert({d+to.second, to.first});
                        distanceval[to.first] = d+to.second;
                    }
                }
            }
        }
    }
}

int main(){

  #ifndef ONLINE_JUDGE
      freopen("inputf.txt", "r", stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin>>t;
  while(t--){

    int n,m;
    cin>>n>>m;

    while(m--){
      int u,v;
      int weight;
      cin>>u>>v>>weight;
      addedge(u-1,v-1,weight);
    }

    DijsktrasOnSparse(0,n);

    //distanceval contains distances
    // parent contains parent
    //
  }
  return 0;
}
