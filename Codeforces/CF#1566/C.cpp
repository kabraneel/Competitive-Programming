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

  char arr[n][2];
  FOR(j,0,2){
    FOR(i,0,n){
        cin>>arr[i][j];
    }
  }

  int ans = 0;
  // bool check  = false;
  vector<bool> taken(n);
  int count = 0;
  FOR(i,0,n){

    // if(arr[i][0] == '1' && arr[i][1] == '1'){
    //   check = true;
    // }

    if((arr[i][0] == '1' && arr[i][1] == '0') || (arr[i][0] == '0' && arr[i][1] == '1')){
      ans += 2;
      // count = 0;
      continue;
    }

    if(arr[i][0] == '0' && arr[i][1] == '0'){
      if( (i-1)>=0 && !taken[i-1] && (arr[i-1][0] == '1' && arr[i-1][1] == '1')){
        taken[i-1] = true;
        ans+= 2;
      }

      else if((i+1)<n && !taken[i+1] && (arr[i+1][0] == '1' && arr[i+1][1] == '1')){
        ans += 2;
        taken[i+1] = true;
      }
      // count++;
      else{
        ans+=1;
      }
    }

    // if(arr[i][0] == '1' && arr[i][1] == '1'){
    //   if(count > 0){
    //     ans += 1 + count;
    //     count = 0;
    //   }
    // }
  }

  ans += count;

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
