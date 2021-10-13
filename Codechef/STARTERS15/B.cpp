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


const int N = 1e6 + 10;
vector<bool> visited(N, true);

vector<int> primes;

void Seive(int n){

  visited[0] = false;
  visited[1] = false;

  for(int i=2; i<n; i++){
    if(visited[i]){
      for(int j = i*i; j< n; j = j+i){
        visited[j] = false;
      }
    }
  }

  for(int i = 3; i<n; i++){
    if(visited[i]) primes.PB(i);
  }

}

void solve(){

  int n; cin>>n;

  int a,b; cin>>a>>b;

  int ans1 = 0;
  int ans2 = 0;


  while(n%2 == 0){
    n = n/2;
    ans1++;
  }

  for(auto v: primes){
    while(n % v == 0){
      n = n/v;
      ans2++;
    }
  }

  int fans = 0;
  if(n != 1){
    ans2++;
  }

  if(a >= 0){
    fans += a* ans1;
  }

  else{
    if(ans1){
      fans += a;
    }
  }

  if(b >= 0){
    fans += b* ans2;
  }

  else{
    if(ans2){
      fans += b;
    }
  }


  cout<<fans<<'\n';

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

  Seive(N);

  for(int i = 0; i<10; i++){
    cout<<primes[i]<<" ";
  }

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
