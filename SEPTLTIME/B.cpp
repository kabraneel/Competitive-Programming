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
  int l,r; cin>>l>>r;

  if(l == r){
    cout<< (l % 3 == 0) <<'\n';
    return;
  }

  if(r - l == 1){
    int ans = (l%3 == 0) + (r%3 == 0);
    cout<<ans<<'\n';
    return;
  }

  if(r - l == 2){
    int ans = (l%3 == 0) + ((l+1)%3 == 0) + (r%3 ==0);
    cout<<ans<<'\n';
    return;
  }

  if(l%3 == 0 && r%3 == 0){
    cout<< (r - l)/3 + 1<<'\n';
  }

  if(l%3 == 0 && r%3 == 1){
    cout<< (r - l - 1)/3 + 1<<'\n';
  }

  if(l%3 == 0 && r%3 == 2){
    cout<< (r - l - 2)/3 + 1<<'\n';
  }

  if(l%3 == 1 && r%3 == 0){
    cout<< (r - l)/3 + 1<<'\n';
  }

  if(l%3 == 1 && r%3 == 1){
    cout<< (r - l - 1)/3 + 1<<'\n';
  }

  if(l%3 == 1 && r%3 == 2){
    cout<< (r - l - 2)/3 + 1<<'\n';
  }

  if(l%3 == 2 && r%3 == 0){
    cout<< (r - l)/3 + 1<<'\n';
  }

  if(l%3 == 2 && r%3 == 1){
    cout<< (r - l - 1)/3 + 1<<'\n';
  }

  if(l%3 == 2 && r%3 == 2){
    cout<< (r - l - 2)/3 + 1<<'\n';
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
