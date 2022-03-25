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

void solve(){
	int n; cin>>n;

	vector<int> arr(n);
	int ones = 0;
	int zeros = 0;
	set<int> S;
	for(int i = 0; i<n; i++){

		cin>>arr[i];
		S.insert(arr[i]);
		ones += (arr[i] == 1);
		zeros += (arr[i] == 0);

	}

	if(sz(S) == 1){
		cout<<"YES\n";
		return;
	}

	// if(ones >= 1 && zeros >= 1){
	// 	cout<<"NO\n";
	// 	return;
	// }

	if(ones == 0){
		cout<<"YES\n";
		return;
	}



	//
	vector<int> arr1 = arr;
	sort(all(arr1));

	debug(arr1);

	for(int i = 0; i<n-1; i++){
		// debug(arr[i+1] - arr[i])
		if(arr1[i+1] - arr1[i] == 1){	
			cout<<"NO\n";
			return;
		}
	}

	// sort(all(arr1));
	// if(arr1[0] == arr1[n-1]){
	// 	cout<<"YES\n";
	// 	return;
	// }

	// if(ones >= 1){
	// 	cout<<"NO\n";
	// 	return;
	// }

	cout<<"YES\n";



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