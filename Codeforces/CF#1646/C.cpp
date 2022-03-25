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

vector<int> vals;

void pre(){

	int fact = 1;
	int i = 2;
	while(true){
		
		if(fact > 1e12){
			break;
		}
		vals.PB(fact);
		fact = fact * i;
		i++;

	}

	// fact = 1;
	// while(true){

	// 	if(fact > 1e12){
	// 		break;
	// 	}

	// 	vals.PB(fact);
	// 	fact = fact * 2;

	// }

}

int ans = INF;
// int dp(int n, int m, int count){

// 	if(n == 0){
// 		return -1;
// 	}

// 	if(m == 0){
// 		ans = min(ans, count);
// 	}

// 	//two options
// 	// either I take it
// 	// or i dont



// }


void solve(){

	int n; cin>>n;
	
	debug((vals));

	// I wanna reduce one number I can using factorials
	//then use bits to solve it?
	int ans = INF;
	// map<int,

	for(int i = 0; i<(1<<14); i++){

		//
		int tsum = 0;
		int count = 0;
		for(int j = 0; j < 14; j++){
			if((i >> j) & 1){
				//then i know that this should be included
				tsum += vals[j];
				count++;
			}
		}

		int rem = n - tsum;
		if(rem < 0){
			continue;
		}
		// debug(rem);


		for(int i = 0; i<40; i++){
			// cout<<(1ll<<i)<<'\n';
			if(rem & (1ll<<i)){
				count++;
			}
		}

		ans = min(ans, count);
	}

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