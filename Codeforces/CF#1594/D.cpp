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

const int N = 2e5 + 5;
vector<pair<int,int>> adj[N];
bool visited[N];
int values[N];
vector<int> temp;
int n, m;
map<pair<int,int>, int> M;


bool flag = false;

void dfs(int i){

  visited[i] = true;

  for(auto to: adj[i]){

    int v = to.first;

    // if(!visited[v]){
    //   // if()
    //   // M.erase(MP(i,v));
    //   if(to.second == -1){ //imposter edge
    //
    //     if(values[i] == 0){
    //       if(values[v] == -1 || values[v] == 1) values[v] = 1;
    //       else flag = true;
    //     }
    //
    //     if(values[i] == 1){
    //       if(values[v] == -1 || values[v] == 0) values[v] = 0;
    //       else flag = true;
    //     }
    //
    //   }
    //
    //   else{
    //     if(values[i] == 0){
    //       if(values[v] == -1 || values[v] == 0) values[v] = 0;
    //       else flag = true;
    //     }
    //
    //     if(values[i] == 1){
    //       if(values[v] == -1 || values[v] == 1) values[v] = 1;
    //       else flag = true;
    //     }
    //   }

    if(values[v] == -1){
      if(to.second == 1){//crewmate
        values[v] = values[i];
      }
      else{
        // values[v] = 1^values[i];
        if(values[i] == 0){
          values[v] = 1;
        }
        else{
          values[v] = 0;
        }
      }
      dfs(v);
    }

    else if(values[v] == 1){
      if((to.second == -1 && values[i] == 1) || (to.second == 1 && values[i] == 0))
        flag = 1;
    }

    else if(values[v] == 0){
      if((to.second == -1 && values[i] == 0) || (to.second == 1 && values[i] == 1))
        flag = 1;
    }
    // else if(to.second == 1 && (values[v] != values[i])){
    //   flag = 1;
    // }
  }

  temp.PB(i);
}


void solve(){

  cin>>n>>m;
  flag = false;
  // M.clear();

  for(int i = 0; i <= n; i++){

    adj[i].clear();
    visited[i] = 0;
    values[i] = -1;

  }

  for(int i = 0; i<m; i++){
    int u,v; cin>>u>>v;
    string s; cin>>s;

    // cout<<u-1<<" "<<v-1<<"\n";

    if(s == "imposter"){
      adj[u-1].PB({v-1, -1});
      // if(M.find(MP(u-1, v-1)) != M.end()){
      //   if(M[MP(u-1, v-1)] == 1){
      //     flag = true;
      //   }
      // }
      // else{
      //   M[MP(u-1, v-1)] = -1;
      // }
      adj[v-1].PB({u-1, -1});
    }

    else{
      adj[u-1].PB({v-1, 1});

      // if(M.find(MP(u-1, v-1)) != M.end()){
      //   if(M[MP(u-1, v-1)] == -1){
      //     flag = true;
      //   }
      // }
      // else{
      //   M[MP(u-1, v-1)] = 1;
      // }
      adj[v-1].PB({u-1, 1});

    }
  }

  int ans = 0;

  for(int i = 0; i<n; i++){
    if(!visited[i]){
      values[i] = 0;
      temp.clear();
      dfs(i);

      int count1 = 0;
      int count2 = 0;

      // for(auto v: temp){
      //   cout<<values[v]<<" ";
      // }
      // cout<<"\n";

      for(auto v: temp){
        if(values[v] == 1) count1++;
        else count2++;
      }

      ans += max(count1, count2);

      if(flag){
        cout<<"-1\n";
        return;
      }
    }
  }

  // for(int i = 0; i<n; i++){
  //
  //   for(auto to: adj[i]){
  //
  //       if(to.second == 1){
  //         //same
  //         if(values[i] != values[to.first]){
  //           cout<<"-1\n";
  //           return;
  //         }
  //       }
  //
  //       else{
  //         if(values[i] == values[to.first]){
  //           cout<<"-1\n";
  //           return;
  //         }
  //       }1
// 3 2
// 1 3 imposter
// 2 3 imposter

  //   }
  // }
  // for(auto v: M){
  //   cout<<v.first.first<<" "<<v.first.second<<" "<<v.second<<'\n';
  //   if(v.second == -1){
  //     if(values[v.first.first] == values[v.first.second]){
  //       cout<<"-1\n";
  //       return;
  //     }
  //   }
  //   else{
  //     if(values[v.first.first] != values[v.first.second]){
  //       cout<<"-1\n";
  //       return;
  //     }
  //   }
  // }

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

  int t;
  cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
