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
  int n; cin>>n;

  int mat[n][5];

  for(int i = 0; i<n; i++){
    for(int j = 0; j<5; j++){
      cin>>mat[i][j];
    }
  }

  for(int i = 0; i<5; i++){
    for(int j = i+1; j<5; j++){
      int count1 = 0;
      int count2 = 0;
      int count3 = 0;

      for(int k = 0; k<n; k++){
        if(mat[k][i] && mat[k][j]) count3++;
        else if (mat[k][i]) count1++;
        else if (mat[k][j]) count2++;
      }

      /*
      count1 -> day i
      count2 -> day j
      count3 -> both
      */

      if(count1 + count2 + count3 == n && count1 <= n/2 && count2 <= n/2){
        cout<<"YES\n";
        return;
      }

    }
  }

  cout<<"NO\n";

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
