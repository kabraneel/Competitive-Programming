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

int arr[1005][1005];

void solve(){
  int n, k; cin>>n>>k;
  vector<int> temp;
  // vector<int> arr(n)
  // int counter = 1;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cin>>arr[i][j];
      // arr[i][j] = counter++;
      temp.PB(arr[i][j]);
      // cout<<arr[i][j]<<" ";
    }

    // cout<<'\n';
  }

  int x = (n)/2 + 1;
  multiset<int> S;
  multiset<int> S1;

  // int arr1[n][n];

  // for(int i = 0; i<n;i++){
  //   for(int j = 0; j<n; j++){
  //     arr1[i][j] = temp[i + j*n];
  //   }
  // }
  // for(int i = 0; i<)
  sort(all(temp));

  for(int i = 0; i<x*n; i++){
    if((i+1)%x) S1.insert(temp[i]);
    else S.insert(temp[i]);
  }


  // for(auto v: temp){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';

  int tsum = 0;
  for(auto v: S){
    tsum += v;
    // cout<<v<<" ";
  }
  // cout<<'\n';


  for(int i = 0; i<x-1; i++){
    S1.erase(S1.begin());
  }

  // cout<<"S1 looks like\n";
  // for(auto v: S1){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';
  // cout<<tsum<<'\n';

  if(tsum > k){
    // break;
    cout<<"-1\n";
    return;
  }

  int ans = *S.begin();

  while(!S1.empty()){
    auto it = S.begin();
    tsum -= *it;
    S.erase(it);

    auto it1 = S1.begin();
    int x1 = *it1;
    S1.erase(it1);

    S.insert(x1);
    tsum += x1;
    // cout<<"tsum is "<<tsum<<"\n";
    if(tsum <= k){
      ans = max(ans, *S.begin());
    }
  }

  cout<<ans<<'\n';


  // cout<<'\n';


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
