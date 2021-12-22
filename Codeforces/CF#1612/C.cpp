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

int findval(int x){
  // if(x >= (int) 1.5 * 1e9){
  //   return 2*INF;
  // }
  // int temp = ((x)*(x-1))/2;
  return ((x)*(x-1))/2;
}

int findval1(int x, int k){
  return (x*k) - findval(x+1);
}

void solve(){
  int k,x; cin>>k>>x;

  // x = (x*(x-1))/2;
  // int x = 1.5 * 1e9;
  // cout<< x <<'\n';

  if(k*k <= x){
    cout<<2*k - 1<<'\n';
    return;
  }



  // if(findval(k+1) <= x){

    int l = 1;
    int high = k;
    // int ans = 0;

    while(l <= high){

      // cout<<l<<" "<<high<<'\n';
      int mid = (l+high)/2;
      if(findval(mid) == x){
        // ans = mid;
        // break;
        cout<<mid-1<<'\n';
        return;
      }

      if(findval(mid) <= x && findval(mid+1) >= x){
        // ans = mid+1;
        cout<<mid<<'\n';
        // cout<<findval(mid)<<" "<<findval(mid+1)<<'\n';
        return;
        // break;
      }

      if(findval(mid) > x){
        high = mid -1;
      }

      else{
        l = mid + 1;
      }

    }

    // assert(0);/
    // return;
  // }

  //reached here, second pyramid

  // cout<<"reached here\n";
  high = k-1;
  l = 1;
  x -= findval(k+1);

  // cout<<"x -> "<<x<<'\n';

  while(l <= high){

    // cout<<l<<" "<<high<<'\n';
    int mid = (l+high)/2;
    if(findval1(mid, k) == x){
      // ans = mid;
      // break;
      cout<<k + mid<<'\n';
      return;
    }

    if(findval1(mid, k) <= x && findval1(mid+1, k) >= x){
      // ans = mid+1;
      cout<<k + mid + 1<<'\n';
      // cout<<findval(mid)<<" "<<findval(mid+1)<<'\n';
      return;
      // break;
    }

    if(findval1(mid, k) > x){
      high = mid -1;
    }

    else{
      l = mid + 1;
    }

  }



  cout<< k + l<<'\n';

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
