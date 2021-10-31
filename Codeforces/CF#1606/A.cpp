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
  string s; cin>>s;
  int n = s.length();
  // int count = 0;
  // vector<pair<int,int>> counts;
  //
  // int i = 0;
  // int key = s[0];
  // int acount = 0;
  // int bcount = 0;
  // while(i<n){
  //   int x = 0;
  //   while(i<n && s[i] == key){
  //     // acount+= ()
  //     x++;
  //     i++;
  //   }
  //   key = s[i];
  //   counts.PB(MP(i,x));
  // }
  //
  // // for(auto v: counts){
  // //   cout<<v<<" ";
  // // }
  // // cout<<'\n';
  //
  // // for(auto v: counts){
  // //   cout<<v.second<<" ";
  // // }
  // // cout<<'\n';
  //
  // int n1 = sz(counts);
  //
  // if(n1%2){
  //   cout<<s<<'\n';
  //   return;
  // }
  //
  // for(auto v: s){
  //   acount += (v == 'a');
  //   bcount += (v == 'b');
  // }
  //
  // if(min(counts[0].second, counts[n1-1].second) > bcount){
  //
  //   for(auto &v : s){
  //     v = 'a';
  //   }
  //
  //   cout<<s<<"\n";
  //   return;
  //
  // }
  //
  // if(min(counts[0].second, counts[n1-1].second) > acount){
  //
  //   for(auto &v : s){
  //     v = 'b';
  //   }
  //
  //   cout<<s<<"\n";
  //   return;
  //
  // }
  //
  //
  //
  // if(counts[0].second < counts[n1-1].second){
  //   char key1 = s[n-1];
  //   // while(
  //   int i1 = 0;
  //   while(i1 < n && key1 != s[i1]){
  //     s[i1] = key1;
  //     i1++;
  //   }
  //   cout<<s<<'\n';
  //   return;
  // }
  //
  // char key1 = s[0];
  // int j1 = n-1;
  // while(j1>=0 && key1 != s[j1]){
  //   s[j1] = key1;
  //   j1--;
  // }
  //
  // cout<<s<<'\n';

  if(s[0] == s[n-1]){
    // cout<<s<<'\n';
    ;
  }

  else{
    s[0] = s[n-1];
    // cout<<s<<'\n';
  }

  cout<<s<<'\n';


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
