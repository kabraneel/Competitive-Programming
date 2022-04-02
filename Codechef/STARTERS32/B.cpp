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
	string s; cin>>s;

	vector<pair<int,int>> zeros;
	int i = 0;
	while(i<n){
		int key = s[i];
		int count = 0;
		while(i<n && s[i] == key){
			count++;
			i++;
		}
		if(key == '0'){
			zeros.PB({i - count + 1, count});
		}
	}

	// debug(zeros);

	vector<pair<int,int>> ans;
	for(int i = 0; i<sz(zeros); i++){

		if(zeros[i].first != 1){
			ans.PB({1, zeros[i].first - 1});
			ans.PB({1, zeros[i].second + zeros[i].first - 1});
		}
			// cout<<"1 "<<zeros[i].first - 1<<'\n';

		// cout<<zeros[i].first<<" "<<zeros[i].second<<'\n';

	}
	
	cout<<sz(ans)<<'\n';
	for(auto v: ans){
		cout<<v.first<<" "<<v.second<<'\n';
	}



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