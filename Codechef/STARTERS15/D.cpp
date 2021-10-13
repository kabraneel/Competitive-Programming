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

const int N = 1e5 + 5;

// int l,r;
// int n = 5;
// vector<int> arr(N);

// int find_smallest(int x){
//
//   int low = 0;
//   int high = 100;
//
//   string temp = to_string(x);
//
//   while(low <= high){
//
//     int mid = (low + high)/2;
//     string temp1 = temp + to_string(arr[mid]);
//     // string temp2 = temp + to_string(arr[high]);
//     // cout<<mid<<" ";
//     int lin = stoi(temp1);
//     // int hin = stoi(temp2);
//     if(lin < l){
//       low = mid + 1;
//     }
//
//     else{
//       high = mid -1;
//     }
//
//   }
//
//   return low;
//
// }
//
// int find_largest(int x){
//
//   int low = 0;
//   int high = 100;
//
//   cout<<x<<"\n";
//   string temp = to_string(x);
//   cout<<temp<<'\n';
//
//   while(low <= high){
//
//     int mid = (low + high)/2;
//     string temp1 = temp;
//
//     temp1 = temp1 + to_string(arr[mid]);
//     // string temp2 = temp + to_string(arr[high]);
//     // cout<<mid<<" ";
//     // cout<<temp1<<"\n";
//     int lin = stoi(temp1);
//     cout<<"Val -> "<<lin<<"\n";
//     // int hin = stoi(temp2);
//     if(lin < r){
//       low = mid + 1;
//     }
//
//     else{
//       high = mid -1;
//     }
//
//   }
//
//   return low;
// }
//

// void solve(){
//
//   cin>>n;
//   cin>>l>>r;
//
//   // cout<<l<<" "<<r<<'\n';
//   for(int i = 0; i<n; i++) cin>>arr[i];
//
//   sort(arr.begin(), arr.begin() + n);
//   int ans = 0;
//
//   for(int i = 0; i<n; i++){
//     int smallest = find_smallest(arr[i]);
//     int largest = find_largest(arr[i]);
//     cout<<largest<<" "<<smallest<<"\n";
//     ans += largest -  smallest;
//   }
//
//   cout<<"ans -> "<<ans<<'\n';
//
//
// }

int p[100];
void precompute() {
  p[1] = 10;
  FOR(i,2,17) p[i] = p[i-1] * 10;
}

void solve(){
  int n, l, r;
  cin >> n >> l >> r;

  vector<int> arr(n);
  FOR(i,0,n) cin >> arr[i];

  sort(all(arr));

  int ans = 0;
  FOR(i,0,n) {

    int s = sz(to_string(arr[i]));
    if (r < arr[i]) continue;


    int l1, r1;

    if (l <= arr[i])
      l1 = 0;


    else {
      int f = l - l % (p[s]);
      int tmp = f + arr[i];

      if (tmp < l)
        f += p[s];

      l1 = f;
      l1 /= p[s];
    }

    int f = r - r % (p[s]);
    int tmp = f + arr[i];

    if (tmp > r)
      f -= p[s];
    // debug(f);
    r1 = f;
    r1 /= p[s];

    // debug(l1, r1)
    auto itl = lower_bound(all(arr), l1);
    auto itr = upper_bound(all(arr), r1);


    ans += (itr - itl);
  }

  cout << ans << "\n";
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

  precompute();
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
