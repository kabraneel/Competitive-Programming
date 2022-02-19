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
	for(int  i = 0; i<n; i++) cin>>arr[i];

	int men = 1;
	int i = 0;
	while(i<n && arr[i] == men){
		i++;
		men++;
	}

	if(i != n){
		
		//need to get men to ith position

		int j = 0;
		for(j = 0; j<n; j++){
			if(arr[j] == men) break;
		}

		for(int x = 0; x<i; x++){
			cout<<arr[x]<<" ";
			debug(arr[x]);
		}
		debug("here");

		for(int x = j; x>=i; x--){
			cout<<arr[x]<<" ";
			debug(arr[x]);

		}
		debug("here");

		for(int x = j+1; x<n; x++){
			cout<<arr[x]<<" ";
			debug(arr[x]);

		}
		debug("here");

		cout<<'\n';
		return;
		// arr.reverse(arr.begin() + i, arr.begin() + j);

	}

	for(auto v:arr){
		cout<<v<<' ';
	}
	cout<<'\n';
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