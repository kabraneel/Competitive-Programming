// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define int long long
#ifdef KABRANEEL
#define LOCAL
#include "/home/kabraneel/coding/debug.h"
#else
#define debug(x...)
#define debugln(x...)
#endif

#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

int dp[105][2];

int findval(vector<int> &arr){

	int a1 = 0;
	int a2 = 0;
	int x = 0;
	// int tsum = 0
	for(int i = 0; i<sz(arr); i++){
		a1 += arr[i];
		a2 += arr[i] * arr[i];
	}

	a1 = a1 * a1;
	return ((2*sz(arr) - 4) * a2 + 2*a1)/2;

}


int solver(vector<int> &arr, vector<int> &brr, int ind, int swapped){

	if(ind == 0){
		return findval(arr) + findval(brr);
	}

	// if(min(dp[ind][0], dp[ind][1]) != -1){
	// 	return min(dp[ind][0], dp[ind][1]);
	// }
	// xsetwacom --set 10 Area 0 0 45600 28500


	if(dp[ind][swapped] != -1){
		return dp[ind][swapped];
	}

	if(swapped == 0){
		dp[ind][0] = min(solver(arr, brr, ind-1, 0), solver(arr, brr, ind-1, 1));
	}

	else{
		swap(arr[ind], brr[ind]);
		dp[ind][1] = min(solver(arr, brr, ind-1, 0), solver(arr, brr, ind-1, 1));
		swap(arr[ind], brr[ind]);
	}

	return dp[ind][swapped];


	// return -1;
}


void solve(){
	int n; cin>>n;
	vector<int> arr(n);
	vector<int> brr(n);

	for(int i = 0; i<105; i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	for(int i = 0; i<n; i++) cin>>arr[i];
	for(int i = 0; i<n; i++) cin>>brr[i];

	// vector<int> tarr = arr;
	// vector<int> tbrr = brr;

	// swap(tarr[n-1], tbrr[n-1]);
	int x1 = solver(arr, brr, n-1, 0);
	swap(arr[n-1], brr[n-1]);

	for(int i = 0; i<105; i++){
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	int x2 = INF;
	x2 = solver(arr, brr, n-1, 1);

	cout<<min(x1, x2)<<'\n';
}

signed main(){

	#ifdef KABRANEEL
	freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
	freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
	freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	auto start = chrono::high_resolution_clock::now();

	int t=1;
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