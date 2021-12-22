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
  vector<int> arr(n);

  for(int i = 0; i<n; i++) cin>>arr[i];

  int l = 0; int r = n-1;
  while(arr[l] == arr[r] && l<r){
    l++;
    r--;
  }

  if(l == r){
    cout<<"YES\n";
    return;
  }

  //first remove l
  int temp = arr[l];
  vector<int> A;
  for(int i = 0; i<n; i++){
    if(arr[i]!=temp) A.PB(arr[i]);
  }

  // for(auto v: A){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';

  int n1 = sz(A);
  bool pos = true;
  for(int i = 0; i<n1/2; i++){
    if(A[i] != A[n1 - i - 1]){
      pos = false;
      break;
    }
  }

  if(pos){
    cout<<"YES\n";
    return;
  }

  temp = arr[r];
  A.clear();
  for(int i = 0; i<n; i++){
    if(arr[i]!=temp) A.PB(arr[i]);
  }

  // for(auto v: A){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';


  n1 = sz(A);
  pos = true;
  for(int i = 0; i<n1/2; i++){
    if(A[i] != A[n1 - i - 1]){
      pos = false;
      break;
    }
  }

  if(pos){
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
