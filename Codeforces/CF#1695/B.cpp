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
	vector<int> ans(n, -1);
	vector<int> arr(n);

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	for(int i = 0; i<n; i++){

		if( arr[i] < i+1){
			cout<<"-1\n";
			return;
		}

	}

	// means always possible 
	vector<pair<int,int>> temp;
	int i = 0;
	while( i < n){
		int key = arr[i];
		temp.PB({i, key});

		while(i<n && arr[i] == key){
			i++;
		}
	}

	debug(temp);

	set<int> S;
	for(auto v: temp){
		ans[v.first] = v.second;
		S.insert(v.second);
	}


	// debug(ans);
	int count1 = 1;
	for(int i = 0; i<n; i++){
		while(S.count (count1)){
			count1++;
		}
		if(ans[i] == -1){
			ans[i] = count1++;
		}

	}

	for(auto v: ans){
		cout << v << ' ';
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