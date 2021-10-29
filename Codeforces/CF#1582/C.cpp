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
    string s; cin>>s;

    int ans = INF;
    for(int i = 'a'; i<='z'; i++){
      int count = 0;
      bool pos = true;
      //i only get to erase i
      // for(int j = 0; j<(n/2); j++){
      //   if(s[j] == s[n-j-1]){
      //     continue;
      //   }
      //   if(s[j] == i){
      //     count++;
      //     continue;
      //   }
      //   if(s[n-j-1] == i){
      //     count++;
      //     continue;
      //   }
      //   pos = false;
      // }

      int i1 = 0;
      int j1 = n-1;

      while(i1<j1){
        if(s[i1] == s[j1]){
          i1++;
          j1--;
          continue;
        }
        if(s[j1] == i){
          j1--;
          count++;
          continue;
        }
        if(s[i1] == i){
          i1++;
          count++;
          continue;
        }
        else{
          pos = false;
          break;
        }
      }

      if(pos){
        // cout<<(char) i<<" "<<count<<"\n";
        ans = min(ans, count);
      }
    }

    if(ans == INF){
      cout<<"-1\n"; return;
    }

    cout<<ans<<'\n';

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
