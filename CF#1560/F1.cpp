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
  if(k == 1){
    string ans;
    string s = to_string(n);
    int x = s.length();

    // char temp = s[0];
    // ans.PB(s[0]);
    // bool pos = false;
    // for(int i = 1; i<x; i++){
    //   if(s[i] > temp){
    //     pos = true;
    //     break;
    //   }
    //   ans.PB(s[i]);
    // }
    for(int i = 0; i<x; i++){
      ans.PB(s[0]);
    }

    if(stoi(ans) >= n){
      cout<<ans<<'\n';
      return;
    }

    // if(s)
    ans.clear();
    for(int i = 0; i<x; i++){
      ans.PB(s[0]+1);
    }
    cout<<ans<<'\n';
    return;
  }


  string ans;
  string s = to_string(n);
  int x = s.length();

  map<int,int> M;
  for(auto v: s){
    M[v]++;
  }

  if(M.size() <= 2){
    cout<<s<<'\n';
    return;
  }

  if(x == 1){
    cout<<s<<"\n";
    return;
  }

  ans.PB(s[0]);
  ans.PB(s[1]);
  char temp1 = max(s[0], s[1]);
  char temp2 = min(s[0], s[1]);
  // cout<<temp1<<" "<<temp2<<"\n";
  bool pos = true;
  for(int i = 2; i<x; i++){
    if(s[i] <= temp2){
      ans.PB(temp2);
    }
    else if(s[i]<=temp1){
      ans.PB(temp1);
    }
    else{
      pos = false;
      break;
    }
  }

  if(pos){
    cout<<ans<<'\n';
    return;
  }


  // if(s[1]!=9){
  //   ans.clear();
  //   ans.PB(s[0]);
  //   for(int i = 1; i<x; i++){
  //     // find first occurence of s[1]?
  //   }
  // }
  ans.clear();
  ans.PB(s[0]);
  // for(int i = 1;i<x; i++){
  //   ans.PB(s[1])
  // }
  ans.PB(s[1] +1);
  for(int i = 2; i<x; i++){
    char j = s[1];
    j++;
    if(s[0] < j){
      j = s[0];
    }
    // int j = min(s[1]+1, s[0]);
    ans.PB(j);
  }

  // if()
  if(stoi(ans) >= n){
    cout<<ans<<'\n';
    return;
  }

  ans.clear();
  ans.PB(s[0]+1);

  for(int i =1 ; i<x; i++){
    ans.PB('0');
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
