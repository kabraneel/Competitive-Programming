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
  int n, k; cin>>n>>k;
  vector<int> arr(n);

  for(int i = 1; i<=k; i++){
    arr[i-1] = i;
  }

  if(k == n-1){
    cout<<"-1\n";
    return;
  }

  if(k == n){
    for(int i = 1; i<=n; i++){
      cout<<i<<" ";
    }
    cout<<'\n';
    return;
  }

  if(k == 0){


    cout<<n<<" ";
    for(int i = 1; i<n; i++){
      cout<<i<<" ";
    }

    cout<<'\n';

    return;
  }

  // arr[k] =



  arr[k] = n;
  for(int i = k+1; i<n; i++){
    arr[i] = i;
  }

  for(auto v: arr){
    cout<<v<<" ";
  }
  cout<<'\n';
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
