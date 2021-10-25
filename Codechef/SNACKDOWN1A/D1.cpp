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

int minCost(vector<int> &A, int n){
    // Initialize cost to 0
    int cost = 0;

    // Sort the array
    // sort(A, A + n);

    // Middle element
    int K = A[n / 2];

    // Find Cost
    for (int i = 0; i < n; ++i)
        cost += abs(A[i] - K);

    // If n, is even. Take minimum of the
    // Cost obtained by considering both
    // middle elements
    if (n % 2 == 0) {
        int tempCost = 0;

        K = A[(n / 2) - 1];

        // Find cost again
        for (int i = 0; i < n; ++i)
            tempCost += abs(A[i] - K);

        // Take minimum of two cost
        cost = min(cost, tempCost);
    }

    // Return total cost
    return cost;
}

void solve(){
  int n; cin>>n;
  vector<int> arr(n);


  for(int i = 0; i<n; i++) cin>>arr[i];

  if(n == 2){
    cout<<"0\n";
    return;
  }

  sort(all(arr));

  // if(n == 3){
  //   cout<<min(arr[1] - arr[0], arr[2] - arr[1])<<'\n';
  //   return;
  // }

  // int ans = INF;

  vector<int> temp;
  for(int i = 1; i<n-1; i++){
    temp.PB(arr[i]);
  }

  // for(int i = 0; i<n-1; i++){
  //   //partition is [a1, a2, a3, .. ai] + [ai+1, ai+2, ... an]
  //   int leftgood = arr[i] - arr[0];
  //   int rightgood = arr[n-1] - arr[i+1];
  //
  //   //need to make rightgood = left by increasing ai or decreasing ai+1
  //
  //   // cout<<leftgood<<" "<<rightgood<<'\n';
  //   ans = min(ans, abs(rightgood - leftgood));
  //
  // }

  // int res_l, res_r;  // To store indexes of result pair
  int x = arr[0] + arr[n-1];

    // Initialize left and right indexes and difference between
  //   // pair sum and x
  int diff = INF;
  int l = 0; int r = sz(temp) - 1;
  //
  // // While there are elements between l and r
  while (r > l)
  {
     // Check if this pair is closer than the closest pair so far
     if (abs(temp[l] + temp[r] - x) < diff)
     {
         // res_l = l;
         // res_r = r;
         diff = abs(temp[l] + temp[r] - x);
     }

     // If this pair has more sum, move to smaller values.
     if (temp[l] + temp[r] > x)
         r--;
     else // Move to larger values
         l++;
  }
  
  vector<int> temp2;
  for(int i = 1; i<n; i++){
    temp2.PB(arr[i]);
  }

  vector<int> temp1;
  for(int i = 0; i<n-1; i++){
    temp1.PB(arr[i]);
  }

  diff = min(diff,minCost(temp2, n-1));
  diff = min(diff, minCost(temp1, n-1));

  cout<<diff<<'\n';

}

signed main(){

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
