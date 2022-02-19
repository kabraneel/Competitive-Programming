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

const int N = 1e3 + 5;
int n, k;
vector<vector<int>> dp(N, vector<int> (12*N, -1));
vector<int> temp(1005, INF);
vector<int> b(1005);
vector<int> c(1005);

void pre(){

	temp[1] = 0;
	// temp[0] = 
	for(int i = 1; i<1005; i++){
		for(int j = 1; j<=i; j++){
			if(i+ i/j < 1005){
				temp[i + i/j] = min(temp[i + i/j], temp[i] + 1);
			}
		}
	}

}
// vector<int> b(N);
// vector<int> c(N);

int solver(int n, int k){

	int ans = 0;

	if(dp[n][k] != -1){
		return dp[n][k];
	}

	if(n == 0){
		return 0;
	}

	if(k - temp[b[n-1]] >= 0){
		ans = max(ans, c[n-1] + solver(n-1, k - temp[b[n-1]]));
	}

	ans = max(ans, solver(n-1, k));

	return dp[n][k] = ans;

}




void solve(){

	cin>>n>>k;
	k = min(k, 12 * n);
	// vector<pair<int,int>> arr(n);
	// vector<int> temp(n);
	// vector<int> cost(n);

	// for(int i = 0; i<10; i++){
	// 	cout<<temp[i]<<" ";
	// }
	for(int i = 0; i<1005; i++){
		for(int j = 0; j<=k; j++){
			dp[i][j] = -1;	
		}
		c[i] = 0;
		b[i] = 0;
	}

	for(int i = 0; i<n; i++){
		cin>>b[i];
	}

	for(int i = 0; i<n; i++){
		cin>>c[i];
	}

	// for(int i = 0; i<n; i++){
	// 	int count = 0;
	// 	bool pos = 0;
	// 	// if(arr[i].first == 1){
	// 	// 	temp[i] = 0;
	// 	// 	continue;
	// 	// }
	// 	while(arr[i].first > 0){
	// 		if(arr[i].first % 2 == 1 && arr[i].first!=1) pos = 1;
	// 		arr[i].first = arr[i].first/2;
	// 		count++;
	// 	}

	// 	if(pos){
	// 		temp[i] = count;
	// 	}
	// 	else{
	// 		temp[i] = count - 1;
	// 	}
	// }

	// for(auto v: temp){
	// 	cout<<v<<" ";
	// }
	// debug(temp);



	cout<<solver(n, k)<<'\n';




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

	pre();
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