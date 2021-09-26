// na ho paega humse
// nai_aati_coding
// i love PD
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

const int N = 2e5 + 10;

int parent[N];
int sizee[N];
int total;


int find_set(int x){
    if (parent[x] == x) return x;
    parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_sets(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    total--;
    if (sizee[x] > sizee[y]) swap(x,y);
    parent[x] = y;
    if (sizee[x] == sizee[y]) sizee[y]++;
}

void initialize(int n){
    FOR(i,0,n+1){
        parent[i] = i;
        sizee[i] = 1;
    }
    total = n;
}


void solve(){

  int n,m; cin>>n>>m;
  vector<pair<int, pair<int,int>>> edges(m);

  FOR(i,0,m){
    int x, y, cost; cin>>x>>y>>cost;
    edges[i] = MP(cost, MP(x, y));
  }

  initialize(n);
  int ans = 0;


  sort(all(edges));
  int ind = -1;

  for(int i = 0; i<m; i++){

    int x = edges[i].second.first;
    int y = edges[i].second.second;

    if(total == 1){
      ind = i;
      break;
    }

    if(find_set(x) != find_set(y)){
      union_sets(x,y);
    }

    else{
      // cout<<x<<" "<<y<<'\n';
      if(edges[i].first > 0){
        ans += edges[i].first;
      }
      // cout<<"im here, and the ans "<<ans<<'\n';
    }

    // cout<<total<<'\n';


  }

  if(ind == -1){
    // cout<<"0\n";
    cout<<ans<<'\n';
    return;
  }


  for(int j = ind; j<m; j++){
    if(edges[j].first < 0){
      continue;
    }
    else{
      ans += edges[j].first;
      // ind = j;
      // break;
    }
  }

  // cout<<ind<<'\n';


  // int ans = 0;
  // // for(int i = ind; i<m; i++){
  // //   ans += edges[i].first;
  // // }

  cout<<ans<<'\n';

}

signed main(){

  #ifndef ONLINE_JUDGE
  freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  freopen("/home/kabraneel/coding/error.txt","w",stderr);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
