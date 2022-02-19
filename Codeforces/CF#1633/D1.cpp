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

const int N = 1e3 + 5;
int n, k;

int solver(int n1, int k1, vector<int> &temp, vector<int> &c){
	if(n1 == 0){
		return 0;
	}
	if(k1 == 0){
		return 0;
	}

	int ans = 0;
	// for(int i = 0; i<17; i++){
	if(k1 >= temp[n1 - 1]){
		ans = max(ans,max(solver(n1-1, k, temp),  c[n1-1]+ solver(n1-1, k1-temp[i], temp)));
	}
	ans = max(ans, solver(n1-1, k, temp));
		// else
	// }
	return ans;
}

void solve(){
	cin>>n>>k;
	vector<pair<int,int>> arr(n);

	for(int i = 0; i<n; i++){
		cin>>arr[i].first;
	}

	for(int i = 0; i<n; i++){
		cin>>arr[i].second;
	}

	sort(all(arr));
	vector<int> temp(18);

	// debug(arr);

	for(int i = 0; i<n; i++){
		int temp1 = arr[i].first;
		int ind = -1;
		for(int i = 20; i>=0; i--){
			if(((1ll<<i) & temp1) > 0){
				// temp[(1ll<<i)] = ;
				ind = i;
				break;
			}
		}
		debug(ind);

		if((1ll<<ind) == temp1){
			temp[ind] = max(temp[ind], arr[i].second);
		}

		temp[ind+1] = max(temp[ind+1], arr[i].second);

		// for(int i = 0;)
	}

	for(auto v: temp){
		cout<<v<<' ';
	}
	cout<<'\n';


	for(int i = 1; i<=17; i++){
		temp[i] = max(temp[i], temp[i-1]);
	}

	cout<<solver(n, k, temp)<<'\n';

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