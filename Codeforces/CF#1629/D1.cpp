// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define int long long
#ifndef ONLINE_JUDGE
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

void solve(){
	int n; cin>>n;
	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i<n; i++) cin>>a[i];
	for(int i = 0; i<n; i++) cin>>b[i];


	vector<vector<int>> dp(3005, vector<int> (3005, 0));

	for(int i = a[0]; i<=b[0]; i++){
		dp[i][0] = 1;
	}

	for(int i = 1; i<n; i++){
		int sum = 0;
		for(int j = 0; j<a[i]; j++){
			sum += dp[j][i-1];
		}
		for(int j = a[i]; j<=b[i]; j++){
			sum += dp[j][i-1];
			sum = sum % MOD;
			dp[j][i] = sum;
			dp[j][i] = dp[j][i]%MOD;
		}
	}

	// debug(dp);
	// for(int i = 0; i<=5; i++){
	// 	for(int j = 0; j<=5; j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }

	int ans = 0;
	for(int i = a[n-1]; i<=b[n-1]; i++){
		ans += dp[i][n-1];
		ans = ans% MOD;
		// cout<<ans<<'\n';
	}

	cout<<ans<<'\n';


}

signed main(){

#ifndef ONLINE_JUDGE
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