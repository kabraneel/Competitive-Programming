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

bool isprime(int x){
  for(int i = 2; i*i <= x; i++){
    if(x%i == 0){
      return true;
    }
  }

  return false;
}

void solve(){
  int tsum = 0;
  int n; cin>>n;

  vector<int> arr(n);

  int ind = -1;
  int fans = -1;

  for(int i = 0; i<n; i++){
    cin>>arr[i];
    tsum += arr[i];
  }

  if(isprime(tsum)){
    cout<<n<<'\n';
    for(int i = 1; i<=n; i++) cout<<i<<" ";
    cout<<'\n';
    return;
  }

  for(int i = 0; i<n; i++){
    int temp = tsum - arr[i];
    if(isprime(temp) && temp > fans){
      ind = i+1;
      fans = temp;
    }
  }

  cout<<n-1<<'\n';
  for(int i = 1; i<=n; i++){
    if(i == ind) continue;
    cout<<i<<" ";
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
