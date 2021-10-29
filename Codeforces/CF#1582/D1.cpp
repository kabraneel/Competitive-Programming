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
  int minele = INF;

  for(int i = 0; i<n; i++){
    cin>>arr[i];
    minele = min(minele, abs(arr[i]));
    // if(minele == )
  }

  // sort(all(arr));

  int tsum = 0;
  vector<int> b(n); 
  for(int i = 0; i<n; i++){
    int temp = arr[i];
    if(temp < 0){
      temp *= -1;
    }

    if(arr[i] % minele != 0){
      // make this positive

      b[i] = (arr[i]/temp) * (minele / __gcd(temp, minele));
    }

    else{
      b[i] = arr[i]/temp;
    }

    tsum += arr[i] * b[i];
  }

  for(int i = 0; i<n; i++){
    if(abs(arr[i]) == minele){
      tsum -= minele;
      b[i] = -1 * (minele/arr[i]) * (tsum / minele);
      break;
    }
  }

  // cout<<tsum<<'\n';
  // cout<<minele *

  for(auto v: b){
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
