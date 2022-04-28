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

	for(int i = 0; i<n; i++) cin>>arr[i];

	vector<int> odds;
	vector<int> eves;

	for(int i = 0; i<n; i++){
		if(arr[i] % 2 == 0){
			eves.PB(i);
		}
		else{
			odds.PB(i);
		}
	}
	debug(eves);
	debug(odds);

	int ans = INF;
	// int temp = arr[0]%2;


	for(int i = 0; i<n; i++){ // use operation at position i
		//min taken to reach here from 1
		if(arr[i] % 2  == arr[0] % 2){ // its possible to reach here, so lets reach here and switch
			if(arr[i] % 2 == 0){
				// int temp = upper_bound(all(eves), i) - eves.begin();
				// debug(arr[i], temp);
				// temp += lower_bound(all(odds), i) - odds.begin() ;
				// ans = min(ans, temp);
				int j = 0;
				int count = 0;
				while(j <= i && j<sz(eves)){
					count++;
					j++;
				}

				if(j == sz(eves)){
					// debug("hereee");
					debug(j, count);
					ans = min(ans, count);
					debug(ans);
					continue;
				}

				if(arr[odds[sz(odds) - 1]] != n-1){
					continue;
				}

				int x = sz(odds);
				while(x >= 0 && x >= eves[j]){
					x--;
					count++;
				}
				// debug(count, arr[i]);
				// debug(arr[i], j);
				debug(count);
				if( x < eves[j])
					ans  = min(ans, count);
				debug(ans);

			}
			else{
				// int temp = upper_bound(all(eves), i) - eves.begin();
				// debug(arr[i], temp);
				// temp += lower_bound(all(odds), i) - odds.begin() ;
				// ans = min(ans, temp);
				int j = 0;
				int count = 0;
				while(j <= i && j < sz(odds)){
					count++;
					j++;
				}

				if(j == sz(odds)){
					debug("pls be here");
					debug(j, count);
					ans = min(ans, count);
					debug(ans);
					continue;
				}

				if(arr[eves[sz(eves) - 1]] != n-1){
					continue;
				}

				int x = sz(eves);

				while(x >= 0 && x >= odds[j]){
					x--;
					count++;
				}
				// debug(count, arr[i]);
				// debug(arr[i], j);
				debug(count);
				if(x < odds[j])
					ans  = min(ans, count);
				debug(ans);
			}
		}
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