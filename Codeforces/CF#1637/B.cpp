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

int ans = 0;

void func(vector<int> &arr, int start, int end){
	if(end == sz(arr)){
		return;
	}

	if(start > end){
		func(arr, 0, end+1);
	}

	else{
		//eval 
		//array is arr from start to end 
		vector<int> temp;
		for(int i = start; i<=end; i++){
			temp.PB(arr[i]);
		}

		int n1 = sz(temp);

		for(int i = 0; i<n1; i++){
			if(temp[i] == 0) ans++;
		}

		debug(temp);

		ans+= n1;




		func(arr, start+1, end);
	}

}

void solve(){
	int n; cin>>n;
	vector<int> arr(n);
	ans = 0;
	for(int i = 0; i<n; i++) cin>>arr[i];

	for(int i = 0; i<n; i++){
		// vector<int> temp(n);
		for(int j = i; j<n; j++){
			//array is i to j 
			debug(i,j);
			for(int k = i; k<=j; k++){
				ans++;
				ans += (arr[k] == 0);
			}
			debug(ans);
		}
	}
	debug("here");
	// func(arr, 0, n-1);
	cout<<ans<<'\n';
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