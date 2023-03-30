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

int findval(int x1, int x2, int x3, int y1, int y2, int y3){
	return ((y3 - y1) * (y2 - y1)) - ((x3 - x1) * (x2 - x1));
}

void solve(){
	vector<pair<int,int>> arr(4);
	for(int i = 0; i<4; i++){
		cin>>arr[i].first>>arr[i].second;
	}

	int x1 = findval(arr[0].first, arr[2].first, arr[1].first, arr[0].second, arr[2].second, arr[1].second);
	int x2 = findval(arr[0].first, arr[2].first, arr[3].first, arr[0].second, arr[2].second, arr[3].second);
	debug(x1, x2);

	if(x1 * x2 > 0){
		cout << "No\n";
		return;
	}	
	x1 = findval(arr[1].first, arr[3].first, arr[2].first, arr[1].second, arr[3].second, arr[2].second);
	x2 = findval(arr[1].first, arr[3].first, arr[0].first, arr[1].second, arr[3].second, arr[0].second);
	debug(x1, x2);

	if(x1 * x2 > 0){
		cout << "No\n";
		return;
	}

	

	cout << "Yes\n";
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