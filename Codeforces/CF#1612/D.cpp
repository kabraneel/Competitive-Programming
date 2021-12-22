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
  int a,b, x; cin>>a>>b>>x;
  int mex = max(a,b);
  int men = min(a,b);

  while((mex % men)!= 0){
    // int temp1 = mex - men;
    // mex = max(temp1, men);
    // men = min(temp1, men);

    // if(mex == x || men == x){
    //   cout<<"YES\n";
    //   return;
    // }

    //mex = men
    //men = mex % men

    int nmex = men;
    int nmen = mex % men;

    if((x - mex) % (men) == 0 && x >= mex%men && x <=mex){
      cout<<"YES\n";
      return;
    }

    mex = nmex;
    men = nmen;

    // cout<<mex<<" "<<men<<'\n';

  }

  // cout<<mex<<" "<<men<<'\n';

  // if(mex == x || men == x){
  //   cout<<"YES\n";
  //   return;
  // }

  // cout<<x<<" "<<men<<" "<<mex<<'\n';

  if(x % men == 0 && x <= mex){
    cout<<"YES\n";
    return;
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
