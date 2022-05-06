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

bool check(int mid, vector<int> &arr){
	int men1 = INF;
	int men2 = INF;
	int n = arr.size();
	int tcost = 0;
	
	for(int i = 0; i<n; i++){
		if(arr[i] < men1){
			men2 = men1;
			men1 = arr[i];
		}
		else if(arr[i] < men2){
			men2 = arr[i];
		}
	}

	tcost = (men1+1)/2 + (men2 + 1)/2;

	for(int i = 1; i<n-1; i++){
		tcost = min(tcost, 1ll + arr[i-1]/2 + arr[i+1]/2);
		debug("h", tcost);
		tcost = min(tcost, max(arr[i-1], arr[i+1]));
		tcost = min(tcost, (arr[i]+1)/2 + min(arr[i-1], arr[i+1]));
		tcost = min(tcost, (arr[i] + arr[i-1] + 1)/3);
	}

	tcost = min(tcost, (arr[0]+1)/2 + (arr[1] - (arr[0]+1)/2));
	tcost = min(tcost, (arr[n-1] + 1)/2 + (arr[n-2] - (arr[n-1]+1)/2)); 
	return tcost <= mid;

}

void solve(){
		
	int n; cin>>n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	int men1 = INF;
	int men2 = INF;
	// int n = arr.size();
	int tcost = INF;
	
	for(int i = 0; i<n; i++){
		if(arr[i] < men1){
			men2 = men1;
			men1 = arr[i];
		}
		else if(arr[i] < men2){
			men2 = arr[i];
		}
	}

	tcost = (men1+1)/2 + (men2 + 1)/2;

	for(int i = 1; i<n-1; i++){
		tcost = min(tcost, 1ll + arr[i-1]/2 + arr[i+1]/2);
		
		tcost = min(tcost, max(arr[i-1], arr[i+1]));
		tcost = min(tcost, (arr[i]+1)/2 + min(arr[i-1], arr[i+1]));

		// if(arr[i])
		debug(i, tcost);
		
	}

	for(int i = 1; i<n; i++){
		int x = max(arr[i], arr[i-1]);
		int y = min(arr[i], arr[i-1]);

		if(2 * y >= x){
			tcost = min(tcost, (arr[i] + arr[i-1] + 2)/3);
		}
		debug(tcost);
	}

	tcost = min(tcost, (arr[0]+1)/2 + max(0ll ,  (arr[1] - (arr[0] + 1)/2 + 1)/2 )) ;
	debug(tcost);
	
	tcost = min(tcost, (arr[n-1] + 1)/2 + max(0ll ,  (arr[n-2] - (arr[n-1] + 1)/2 + 1)/2 )); 
	debug(tcost);
	
	cout<<tcost<<'\n';

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
	// cin>>t;

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