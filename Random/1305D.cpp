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

const int N = 2005;
vector<int> adj[N];

// vector<int> leaves;
vector<int> sizes(N);
vector<bool> visited(N);

int dfs(int i){

  visited[i] = true;
  int ans = 1;

  for(auto v: adj[i]){
    if(!visited[v]){
      ans += dfs(v);
    }
  }

  sizes[i] = ans;
  return ans;
}

void solve(){

  int n; cin>>n;

  for(int i = 0; i<n-1; i++){
    int x,y; cin>>x>>y;
    adj[x-1].PB(y-1);
    adj[y-1].PB(x-1);
  }

  dfs(0);
  set<int> S;

  // for(auto v: sizes){
  //   cout<<v<<" ";
  // }
  for(int i = 0; i<n; i++){
    cout<<sizes[i]<<" ";
  }
  cout<<'\n';

  // int n1 = sz(leaves);
  for(int i = 0; i<n/2; i+=1){
    int x1 = -1; int x2 = -1;
    for(int j = 0; j<n; j++){
      if(sizes[j] == 1){
        // x1 =
        if(x1 == -1){
          x1 = j+1;
        }
        else{
          x2 = j+1;
        }

      }

      if(x2 != -1){
        break;
      }
    }

    sizes[x1-1] = 0;
    sizes[x2-1] = 0;

    for(auto v: adj[x1-1]){
      sizes[v]--;
    }
    for(auto v: adj[x2-1]){
      sizes[v]--;
    }

    for(int i = 0; i<n; i++){
      cout<<sizes[i]<<" ";
    }
    cout<<'\n';
    

    cout<<"? "<<x1<<" "<<x2<<endl;
    int temp; cin>>temp;
    if(temp == x1 || temp == x2){
      cout<<"! "<<temp<<endl;
      return;
    }
  }



}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // auto start = chrono::high_resolution_clock::now();

  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }

  // auto end = chrono::high_resolution_clock::now();
  // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  //
  // time_taken *= 1e-9;
  //
  // cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
