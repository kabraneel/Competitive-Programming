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
  int n,a,b; cin>>n>>a>>b;
  vector<int> arr(n,-1);
  arr[n/2] = b;
  arr[n/2 - 1] = a;

  // if(n == 2){
  //   cout<<a<<" "<<b<<'\n';
  //   return;
  // }
  //
  // // set<int
  //
  // int count = n;
  // for(int i = 0; i<n/2 - 1; i++){
  //   // if(count <= a){
  //   //
  //   // }
  //   while(count == b || count == b) count--;
  //   if(count < a ){
  //     cout<<"-1\n";
  //     // break;
  //     return;
  //   }
  //   // if(count == a) count--;
  //   arr[i] = count;
  //   count--;
  //
  // }
  //
  // // cout<<count<<'\n';
  // //
  // // for(auto v: arr){
  // //   cout<<v<<" ";
  // // }
  // // cout<<'\n';
  //
  // for(int j = n/2 + 1; j<n; j++){
  //   while(count == b || count == a) count--;
  //   // if(count == a) count--;
  //   if(count > b){
  //     cout<<"-1\n";
  //     return;
  //   }
  //   arr[j] = count;
  //   count--;
  // }
  //
  // for(auto v: arr){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';

  vector<int> temp;
  int n1 = n;
  for(int i = 0; i<n; i++){
    if(n1 == a || n1 == b ){
      n1--;
      continue;
    }

    temp.PB(n1);
    n1--;
  }

  // temp.erase(a);
  // temp.

  int ind = 0;

  for(int i = 0; i<n; i++){
    if(arr[i]==-1){
      arr[i] = temp[ind];
      ind++;
    }
  }

  for(int i = 0; i<n/2-1; i++){
    if(arr[i] < arr[n/2-1]){
      cout<<"-1\n";
      return;
    }
  }

  for(int j = n/2+1; j<n; j++){
    if(arr[j] > arr[n/2]){
      cout<<"-1\n";
      return;
    }
  }


  for(auto v: arr){
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
