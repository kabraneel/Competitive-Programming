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
	vector<vector<int>> temp(n + 1) ;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		temp[arr[i]].PB(i+1);
	}

	debug(temp);

	// for(int)

	int q; cin>>q;
	while(q--){

		int l,r,x; cin>>l>>r>>x;

		if(l == r){
			if(arr[l-1] == x){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
			continue;
		}

		if(sz(temp[x]) == 1){

		}
		
		int answer =(int)temp[x].size() - (lower_bound(all(temp[x]), l-1) - temp[x].begin());
		int answer1 =(int)temp[x].size() - (lower_bound(all(temp[x]), r) - temp[x].begin());


		debug(l, r, x);
		cout<< answer1 - answer <<'\n';

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
	// cin>>t;
	while(t--){
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}