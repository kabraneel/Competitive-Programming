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

const int N = 105;
int n;
int x;
vector<pair<int,int>> arr(N);

// bool dp[N][10005];
map<pair<int,int>,bool> dp;

bool solver(int i, int target){

	debug(i, target);
	
	if(i == 0 && target == 0){
		return true;
	}

	if(i == 0){
		return false;
	}

	if(target <= 0){
		return false;
	}


	if(dp.find({i, target}) != dp.end()){
		return dp[{i, target}];
	}

	return dp[{i,target}] = solver(i-1, target - arr[i-1].first) || solver(i-1, target - arr[i-1].second);

}

void solve(){
	
	int n; cin>>n;
	int x; cin>>x;

	for(int i = 0; i<n; i++){
		cin>>arr[i].first>>arr[i].second;
	}

	
	if(solver(n, x)){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}

	debug(dp);

	// for(int i = 0; i<=n; i++){
	// 	for(int j = 0; j<=x; j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }

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
	// cin>>t;
	while(t--){
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}