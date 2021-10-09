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

void solve(){
  int n,m; cin>>n>>m;


  vector<string> matches(2*n);
  for(int i = 0; i<2*n; i++){
    cin>>matches[i];
  }

  set<pair<int,int>> S;
  for(int i = 0; i<2*n; i++){
    S.insert({0, i});
  }

  for(int i = 0; i<m; i++){
    set<pair<int,int>> S1;

    // for(auto v: S){
    //   cout<<v.first<<" "<<v.second<<'\n';
    // }

    for(int j = 0; j<n; j++){
      pair<int,int> p1 = *S.begin();
      S.erase(S.begin());

      pair<int,int> p2 = *S.begin();
      S.erase(S.begin());

      // cout<<matches[p1.second][i]<<" "<<matches[p2.second][i]<<'\n';

      //who wins
      if(matches[p1.second][i] == 'G'){
        if(matches[p2.second][i] == 'G'){
          S1.insert(p1);
          S1.insert(p2);
        }
        if(matches[p2.second][i] == 'C'){
          //p1 wins
          S1.insert({p1.first - 1, p1.second});
          S1.insert(p2);
        }
        if(matches[p2.second][i] == 'P'){
          S1.insert(p1);
          S1.insert({p2.first -1 , p2.second});
        }
      }

      if(matches[p1.second][i] == 'P'){
        if(matches[p2.second][i] == 'P'){
          S1.insert(p1);
          S1.insert(p2);
        }
        if(matches[p2.second][i] == 'G'){
          //p1 wins
          S1.insert({p1.first - 1, p1.second});
          S1.insert(p2);
        }
        if(matches[p2.second][i] == 'C'){
          S1.insert(p1);
          S1.insert({p2.first -1 , p2.second});
        }
      }

      if(matches[p1.second][i] == 'C'){
        if(matches[p2.second][i] == 'C'){
          S1.insert(p1);
          S1.insert(p2);
        }
        if(matches[p2.second][i] == 'P'){
          //p1 wins
          S1.insert({p1.first - 1, p1.second});
          S1.insert(p2);
        }
        if(matches[p2.second][i] == 'G'){
          S1.insert(p1);
          S1.insert({p2.first -1 , p2.second});
        }
      }


    }
    S = S1;

    // for(auto v: S){
    //   cout<<v.first<<" "<<v.second<<'\n';
    // }
    // cout<<"\n\n";
  }

  // vector<int> ans(2*n);
  // int count = 1;
  for(auto v: S){
    // ans[v.second] = count;
    // count++;
    cout<<v.second+1<<"\n";
  }


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
