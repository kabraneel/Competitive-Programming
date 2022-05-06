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
	int n,k; cin>>n>>k;
	string s; cin>>s;

	vector<int> arr;
	for(int i = 0; i<n; i++){
		arr.PB(s[i] - 'a');
	}

	k = min(k, 26ll);

	debug(arr);
	int done = 0;

	int count = 0;

	while(k>0){
		count++;
		if(count > 100){
			break;
		}
		int x = -1;
		int tt = 0;
		for(int j = done; j<n; j++){
			if(arr[j] > k){
				x = j;
				break;
			}
			tt = max(tt, arr[j]);
		}

		debug(k, x, tt);

		if(x == -1){
			for(int i = 0; i<n; i++){
				arr[i] = 0;
			}
			break;
		}

		//till j-1, I can make everything 'a'
		if(x == done){
			//ez case
			debug("here");
			// int tt = arr[done];
			// char tt = arr[done];
			int tttmp = arr[x];
			debug(x);
			for(int i = done; i<n; i++){
				if(arr[i] >= tttmp - k && arr[i] <= tttmp){
					debug("IM HERE");
					arr[i] = min(arr[i], max(0ll, tttmp - k));
				}
			}
			// arr[done] = arr[done] - k;
			break;
		}

		// int tt = arr[x-1];

		for(int i = done; i<n; i++){
			// arr[i] =;
				// debug("here1", arr[i], arr[x-1]);
			if(arr[i] <= tt){
				arr[i] = min(arr[i], max(0ll, tt - k));
			}

		}

		k -= tt;
		done = x;
		debug(arr);


	}

	// debug("ans", arr);
	for(auto v: arr){
		char tt = 'a' + v;
		cout<< tt;
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