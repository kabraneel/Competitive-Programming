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
  vector<int> arr(n);

  for(int i = 0; i<n; i++) cin>>arr[i];
  int ans = 0;
  // cout<<n<<'\n'
  vector<vector<int>> fans;
  for(int done = n; done > 0; done--){
    int maks = -1*INF;
    int ind = -1;
    for(int i = 0; i<done; i++){
      if(arr[i] > maks){
        maks = arr[i];
        ind = i;
      }
    }

    // if(ind == -1){
    //   cout<<"Here\n";
    //   continue;
    // }

    // if(ind == )

    // vector<int> temp;
    // for(int j = ind; j<done; j++){
    //   temp.PB(arr[j]);
    // }
    //
    // reverse(all(temp));
    if(ind+1 == done){
      continue;
    }
    ans++;
    // reverse(arr.begin() + ind, arr.begin() + done);
    // cout<<ind+1<<" "<<done<<" "<<1<<'\n';

    //shift by one
    vector<int> temp;
    for(int i = ind + 1; i<done; i++)
      temp.PB(arr[i]);

    temp.PB(arr[ind]);

    // cout<<"TEMP\n";
    // for(auto v: temp){
    //   cout<<v<<" ";
    // }
    // cout<<'\n';

    // cout<<done - ind<<'\n';
    for(int i = ind; i<done; i++){
      arr[i] = temp[i - ind];
    }
    //
    fans.PB({ind+1, done, 1});
    // // cout<<'\n';
    // for(int j =)
    // cout<<"Array:\n";
    // for(int i = 0; i<n; i++){
    //   cout<<arr[i]<<" ";
    // }
    // cout<<'\n';

  }

  cout<<ans<<'\n';
  for(auto v: fans){
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<'\n';
  }

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
