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
	set<int> S;

	for(int i = 0; i<n; i++){
		cin>>arr[i];
		S.insert(arr[i]);
	}

	int mex = 0;



	for(auto v: S){
		if(S.count(v+1) == 0){
			mex = v+1;
			break;
		}
	}

	// if(*)

	if(*S.begin() != 0){
		// cout<<"0\n";
		cout << *S.begin() - 1 <<'\n';
		return;
	}

	if(mex == 1){
		cout<<"-1\n";
		return;
	}

	vector<int> temp;
	for(auto v: S){
		temp.PB(v);
	}

	debug(mex, temp);

	int n1 = sz(temp);
	int ans = 0;

	for(int i = 0; (i + mex - 1) < n1; i++){
		// debug(temp[i+mex-1], temp[i]);
		if((temp[i+mex-2] - temp[i] + 1) == mex - 1 && (temp[i+mex - 1] - temp[i]+1) != mex){
			debug(temp[i]);
			ans++;
		}
	}

	if(temp[n1 - 1] - temp[(n1 - 1) - (mex - 2)] + 1 == mex - 1){
		ans++;
	}

	cout<<ans-1<<'\n';





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