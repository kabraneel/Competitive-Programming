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

void solve()
{
  int n; cin>>n;

  vector<int> arr(n);
  vector<int> brr(n);


  FOR(i,0,n) cin>>arr[i];
  FOR(i,0,n) cin>>brr[i];

  vector<int> ans = arr;
  vector<int> temp;

  int fans = 0;
  for(int i = 29; i>=0; i--)
  {
    //if its possible to have the ith bit on
    int count = 0;
    for(int j = 0; j<n; j++)
    {
      if((arr[j] << i) || (brr[j]<<i))
      {
        count++;
      }
    }

    //       00
    //       01
    if(count == n)
    {
      //we can achieve it
      // int mins = 0
      for(int j = 0; j<n; j++)
      {
        if((arr[i] << i) && (brr[i] <<i))
        {
          //need to decide
          ;
        }
        else
        {
          mins++;
          swap(ans[i], brr[i]);
        }
      }
    }
  }



}

signed main()
{

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
