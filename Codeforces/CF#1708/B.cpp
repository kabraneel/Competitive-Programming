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

const int N = 1e5 + 45;
vector<int> arr(N);
int n;
map<pair<int,int>, int> M;

int dp(int i, int q){

	if(i == n){
		return 0;
	}

	if(q == 0){
		return 0;
	}

	if(M.find({i, q}) != M.end()){
		return M[{i,q}];
	}
	// test
	if(arr[i] > q){
		//choice is there to test or not
		return M[{i, q}] = max( dp(i+1, q), 1 + dp(i+1, q-1) );
	}

	return M[{i,q}] = 1 + dp(i+1, q);

}

void solve(){
	cin>>n;
	int q; cin>>q;
	M.clear();



	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	cout<<dp(0, q)<<'\n';
	debug(M);
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
	int zcount = 1;
	cin>>t;

	while(t--){
		//cout<<"Case #"<<zcount++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}