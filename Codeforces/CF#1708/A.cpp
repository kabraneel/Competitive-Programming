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
		
	int n, l, r; cin>>n>>l>>r;
	vector<int> ans(n+1);
	vector<int> X(n);

	for(int i = 0; i<n; i++){
		X[i] = i+1;
	}
	debug(X);
	// set<int> S;

	for(int i = n; i>=1; i--){
		// smallest number to add to l s.t.
		// (l + num)%i = 0;
		int x =  (r % i);
		if( (r%i) == 0 ){
			x = 0;
		}
		debug(i, x);
		int temp = r - x;

		debug(temp);
		if(temp < l){
			cout<<"NO\n";
			return;
		}

		ans[i] = temp;

	}
	// int j = 0;

	// while(j < n){
	// 	int temp = l;
	// 	while(temp <= r){
	// 		if((temp % X[j]) == 0 ){
	// 			ans[j] = temp;
	// 			j++;
	// 			break;
	// 		}
	// 		temp++;
	// 	}
	// 	if( temp > r){
	// 		cout<<"NO\n";
	// 		return;
	// 	}
	// }

	// if(j == n){

		cout<<"YES\n";
		for(int i = 1; i<=n; i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
//	}

//	else{
//		cout<<"NO\n";
//	}

	debug(ans);

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