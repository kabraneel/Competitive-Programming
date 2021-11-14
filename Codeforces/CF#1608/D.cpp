// na ho paega humse
// nai_aati_coding
// i love CS
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
  int n; cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++) cin>>arr[i];

  string s; cin>>s;
  vector<int> blues;
  vector<int> reds;
  int bsize = 0, rsize = 0;

  for(int i = 0; i<n; i++){
    if(s[i] == 'B') blues.PB(arr[i]);
    else reds.PB(arr[i]);
  }

  bsize = sz(blues); rsize = sz(reds);

  sort(all(blues));

  //make the smallest blue 1
  int counter = 1;
  for(int i = 0; i<bsize; i++){
    if(blues[i] >= counter) counter++;
    else{
      cout<<"NO\n";
      return;
    }
  }

  sort(all(reds));
  for(int i = 0; i<rsize; i++){
    if(reds[i] <= counter) counter++;
    else{
      cout<<"NO\n";
      return;
    }
  }

  cout<<"YES\n";


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
