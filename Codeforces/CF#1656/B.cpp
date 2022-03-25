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






						#define KabraCodeAbra


/*

Solution for Codeforces Educational Round 125 Problems A-D : Contest Like.
All codes can be found at my Github Repository in the following link.






*/




#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

// Kabra Code Abra

void solve(){
	// set<int> S;
	map<int,int> M;
	int k;
	int n; cin>>n;
	cin>>k;
	vector<int> arr(n);

	for(int i = 0; i<n; i++){
		cin>>arr[i];
		M[arr[i]]++;
	}

	debug(M);

	for(int i = 0; i<n; i++){
		// if(k - arr[i] == arr[i]){
		// 	if(M[arr[i]] > 2){
		// 		cout<<"YES\n";
		// 		return;
		// 	}
		// 	continue;
		// }

		if(M.find(arr[i] - k) != M.end()){
			cout<<"YES\n";
			return;
		}
	}

	cout<<"NO\n";
	return;

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