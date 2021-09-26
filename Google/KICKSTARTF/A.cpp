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

void solve(int count){
  int n; cin>>n;
  string s; cin>>s;

  vector<int> trash;
  for(int i = 0; i<n; i++){
    if(s[i] == '1'){
      trash.PB(i);
    }
  }

  // int current = trash[0];
  int prev = 0;

  if(sz(trash) == 1){

    int ans = 0;
    for(int i = 0; i<n; i++){
      ans += abs(i - trash[prev]);
    }
    cout<<ans<<'\n';
    return;

  }

  int next = -1;
  int current = 1;
  int ans = 0;
  for(int i = 0; i<n; i++){

    //each guy can only go to trash[prev] or trash[next]

    if(next < sz(trash) && next!=-1){
      ans += min(abs(i - trash[prev]), abs(i - trash[next]));
    }

    else{
      ans += abs(i - trash[prev]);
    }

    if(s[i] == '1'){

      if(next != -1){
        prev = next;
        next++;
      }

      else{
        next = 1;
      }
    }

    // cout<<prev<<" "<<next<<" "<<ans<<'\n';

  }

  cout<<ans<<'\n';

}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // auto start = chrono::high_resolution_clock::now();

  int t;
  cin>>t;
  int count = 1;
  while(t--){
    cout<<"Case #"<<count<<": ";
    solve(count);
    count++;
  }

  // auto end = chrono::high_resolution_clock::now();
  // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  //
  // time_taken *= 1e-9;
  //
  // cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
