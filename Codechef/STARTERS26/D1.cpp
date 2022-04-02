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

const int N = 1005;
int arr[N];
int n;

// int dp[N][N];
map<pair<int,int>,int> dp;

int solver(int i, int j, int hpp){

	// if(j == -1)

	// if(dp[i][j] != -1 && j != -1){
	// 	return dp[i][j];
	// }
	

	debug(i,j);

	if(i == n){
		return hpp;
	}

	// if(dp.find({i,j})!= dp.end()){
	// 	return dp[{i,j}];
	// }

	// int x1 = solver(i+1, j, X);
	int x1 = -1;

	if(i == -1){
		x1 = solver(i+1, j, hpp)
	}

	else{
		x1 = solver(i+1, j, hpp + )
	}


	int x2 = -1;
	for(int k = j; k<i; k++){
		X.PB(i);
		x2 = max(x2, solver(i+1, k, X));
		X.pop_back();
	}

	dp[{i,j}] = max(x1, x2);
	return max(x1, x2);
}

void solve(){
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	dp.clear();
	
	vector<int> temp;
	cout<<solver(-1, -1, temp)<<'\n';
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