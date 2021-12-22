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
  for(int i = 0; i<n; i++) arr[i] = i+1;

  vector<int> left(n);
  vector<int> right(n);

  for(int i = 0; i<n; i++){
    cin>>right[i];
    cin>>left[i];
  }
  // for(int i = 0; i<n; i++)

  // vector<bool> done(n, true);
  // int count = 0;
  //
  //
  // for(int i = 0; i<n; i++){
  //   if(right[i] > count){
  //
  //   }
  // }
  int low = 1;
  int high = n;

  int ans = -1;

  while(low <= high){

    int mid = (low + high)/2;
    //is mid possible

    int temp = 0;
    int count1 = 0;
    int count2 = mid - 1;
    for(int i = 0; i<n; i++){
      if(count1 <= left[i] && right[i] >= count2){
        temp++;
        count1++;
        count2--;
      }

      if(temp == mid){
        break;
      }
    }

    // cout<<"temp -> "<<count1<<" "<<count2<<" "<<temp<<'\n';

    if(temp == mid){
      // cout<<"this is possible == " << mid<<"\n";
      //ans can be more
      ans = mid;
      low = mid + 1;
    }

    if(temp < mid){
      // ans = ma;
      cout<<"this is not possible -> " <<mid<<'\n';
      high = mid - 1;
    }

    // else{
    //   cout<<mid<<'\n';
    //   return;
    // }

  }

  cout<<max(ans, low - 1)<<'\n';

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
