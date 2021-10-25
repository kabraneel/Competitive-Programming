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

  if(n == 2){
    cout<<"0\n";
    return;
  }

  sort(all(arr));

  if(n == 3){
    cout<<min(arr[1] - arr[0], arr[2] - arr[1])<<'\n';
    return;
  }
  // int tsum = 0;
  //
  // for(auto v: arr){
  //   tsum += v;
  // }
  //
  // int ans = INF;
  //
  // for(int i = 0; i<n-1; i++){
  //
  //   //first i in the left, others in the right
  //
  //   // split is [a1,a2,a3 .. ai], [ai+1,ai+2, .. an]
  //
  //   //for left side, we have two choices
  //   //either we make a1, a2, a3, ai ->
  //   int right_good = arr[n-1] - arr[i+1];
  //   int thiscost_left =
  //
  // }
  vector<int> A;
  vector<int> B;

  for(int i = 1; i<n-1; i++){
    A.PB(arr[i] - arr[0]);
  }

  for(int i = 1; i<n-1; i++){
    B.PB(arr[n-1] - arr[i]);
  }

  // for(auto v: A){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';
  //
  // for(auto v: B){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';

  reverse(all(B));

  // for(auto v: B){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';

  // int i = 0;
  // int j = n-3;

  // int men = INF;
  // while(i<n-3 && j)

  // for(int i =)
  // int i = 0;
  // int j = 0;

  int a = 0, b = 0;

    // Initialize result as max value
  int n1 = sz(A);
  int m1 = sz(B);
  int result1 = INF;
  // int result2 = INF;

  // Scan Both Arrays upto
  // sizeof of the Arrays
  while (a < m1 && b < n1)
  {

      if (abs(A[a] - B[b]) <= result1 && a+b != n1-1){
        // result2 = result1;
        result1 = abs(A[a] - B[b]);
      }

      // else if(abs(A[a] - B[b]) <= result2 && a!=b){
      //   result2 = abs(A[a] - B[b]);
      // }

      // Move Smaller Value
      if (A[a] < B[b])
          a++;

      else
          b++;

      // cout<<a<<" "<<b<<"\n";
  }

  // if(result1 == INF){
  //
  // }

  cout<<result1<<'\n';

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
