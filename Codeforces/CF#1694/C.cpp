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

/*

	tsum = 0
	last ele always <= 0
	              
	| 1 | -1 | 1 | -1 |  |
	

	val == 0
		ptr is on left

	val == 1
		ptr is on right

		2 1 2 0


	| 1 | 3 | 4 | -4 | -2 |

	| 1 | 2 | -3  | 2  | -2 |

	1 2 -3

	1 2 3 -4 -2

	1 2 x -4 -10 -6 -8

	
	 /\
	/  \

*/
void solve(){
	
	int n; cin>>n;
	vector<int> arr(n);
	int tsum = 0;
	bool pos = false;

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	int j = n-1;
	while(j>0 && arr[j] == 0){
		j--;
	}

	for(int i = 0; i<=j; i++){
		tsum += arr[i];
		if(tsum <= 0 && i!=j){
			pos = true;
		}
	}
	debug(pos, tsum);
	if(pos){
		cout<<"No\n";
		return;
	}

	// int i = n-1;
	// while(i >= 0 && arr[i] == arr[n-1]){
	// 	i--;
	// }

	if(tsum == 0){
		if(arr[j-1] >= arr[j]){
			cout<<"Yes\n";
			return;
		}
	}

	cout<<"No\n";



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