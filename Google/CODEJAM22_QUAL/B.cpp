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
	
	vector<vector<int>> arr(4, vector<int> (3, 0));

	for(int i = 0; i<3; i++){
		for(int j = 0; j<4; j++){
			cin>>arr[j][i];
		}
	}

	for(int i = 0; i<4; i++){
		sort(all(arr[i]));
	}

	int tsum = 0;
	for(int i = 0; i<4; i++){
		tsum += arr[i][0];
	}
	debug(arr);

	if(tsum < (int) 1e6){
		cout<<"IMPOSSIBLE\n";
		return;
	}

	tsum = 0;
	int i = 0;
	vector<int> ans;
	while(tsum < (int) 1e6){
		if(tsum + arr[i][0] > (int) 1e6){
			ans.PB((int) (1e6) - tsum);
			tsum = (int) 1e6;
		}
		else{
			ans.PB(arr[i][0]);
			tsum += arr[i][0];
			i++;
		}

	}

	int n = sz(ans);

	for(int i = 0; i < 4 - n; i++){
		ans.PB(0);
	}

	debug(sz(ans));

	for(auto v: ans){
		cout<<v<<" ";
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
	int count = 1;
	while(t--){

		cout<<"Case #" << count++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}