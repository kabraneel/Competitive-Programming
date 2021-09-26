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
  int n,k; cin>>n>>k;
  string s; cin>>s;

  int ans = 0;
  for(int i = 0; i<k; i++){
    // int count1 = 0;
    // int count2 = 0;
    vector<int> counts;
    for(int j = i; j<n; j+=k){
      counts.PB(s[j] - '0');
    }

    int m = sz(counts);


    if(m == 1){
      ans += (counts[0] == 1);
      continue;
    }



    for(int x = 0; x<m; x++){
      if(counts[x] == 0) continue;

      if(x == 0){
        if(counts[0] == 1 && counts[1] == 0){
          ans++;
          counts[1] = 1;
        }
      }
      else if (x == m - 1){
        if(counts[x] == 1 && counts[x-1] == 0) ans++;
      }
      else{
        if(counts[x] == 1 && (counts[x-1] ==0 && counts[x+1] == 0)){
          counts[x+1] = 1;
          ans++;
        }
      }
    }

  }

  cout<<ans<<"\n";
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
