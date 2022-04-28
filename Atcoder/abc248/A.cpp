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

const int MOD = 998244353;
const int INF = 1e18;

int M;
int fans[55][2505];

int dp(int n, int k){

	
	if(k < 0){
		return 0;
	}

	if(n == 0){
		return 1;
	}

	// if(n == 0 && k > M){
	// 	return 0;
	// }

	if(fans[n][k] != -1){
		return fans[n][k];
	}


	int ans = 0;

	for(int i = 1; i<= M; i++){
		ans += dp(n-1, k - i);
		ans = ans % MOD;
	}

	fans[n][k] = ans % MOD;


	return ans;

}

void solve(){
	
	int n, k;
	cin>>n>>M>>k;

	for(int i = 0; i<55; i++){
		for(int j = 0; j<2505; j++){
			fans[i][j] = -1;
		}
	}

	cout<<(dp(n, k) ) % MOD<<'\n';

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