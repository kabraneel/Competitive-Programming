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

set<int> S1;
set<int> S2;

vector<int> arr;
vector<int> arr1;

void pre(){
  for(int i = 0; i<10; i++){
    for(int j = i+1; j<10; j++){
      for(int k = 0; k<11; k++){
        for(int t = 0; t <= (1<<k) - 1; t++){
          // string s;
          int x = 0;
          for(int z = 0; z<k; z++){
            if(((1<<z) & t)){
              // s.PB(i + '0');
              x = x*10 + i;
            }
            else{
              // s.PB(j + '0');
              x = x*10 + j;
            }
          }
          S1.insert(x);
        }
      }
    }
  }

  for(int i = 0; i<10; i++){
    int x = 0;
    for(int k = 0; k<10; k++){
      x = x*10 + i;
      S2.insert(x);
    }
  }

  for(auto v: S1){
    arr.PB(v);
  }
  for(auto v: S2){
    arr1.PB(v);
  }
}



void solve(){

  int n,k; cin>>n>>k;

  auto it1 = lower_bound(all(arr1), n);
  int ans1 = *it1;

  auto it2 = lower_bound(all(arr), n);
  int ans2 = *it2;

  if(k == 1){
    cout<<ans1<<'\n';
    return;
  }

  cout<<min(ans1, ans2)<<'\n';
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
  pre();

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
