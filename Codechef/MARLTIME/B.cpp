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
	int odd = 0;
	vector<int> odds;
	vector<int> eves;

	for(int i = 0; i<n; i++){
		cin>>arr[i];
		odd += (arr[i]%2);
		
		if(arr[i]%2 == 0) eves.PB(arr[i]);
		else odds.PB(arr[i]);
	}

	if(odd < 2){
		cout<<"-1\n";
		return;
	}

	if(n%2 == 0){ 	// n is even, pairs are odd
					// even pairs must be even

					// o o o e o e e e e 
		// if(sz(eves) == 0){
		// 	for(auto v: odds){
		// 		cout<<v<<" ";
		// 	}
		// 	cout<<'\n';
		// 	return;
		// }

		if(sz(odds) % 2 == 0){
			for(auto v: odds){
				cout<<v<<' ';				
			}
			for(auto v: eves){
				cout<<v<<" ";
			}
			cout<<'\n';
			return;
		}

		else{
			for(int i = 0; i<sz(odds) - 1; i++){
				cout<<odds[i]<<" ";
			}
			cout<<eves[0]<<" ";
			cout<<odds[sz(odds) - 1]<<" ";
			for(int i = 1; i<sz(eves); i++){
				cout<<eves[i]<<" ";
			}

			cout<<'\n';

		}



		return;
	}

	//number of pairs is even
	// number of even pairs should be odd
	if(sz(eves) == 0){
		cout<<"-1\n";
		return;
	}	

	if(sz(odds) % 2 == 1){
			for(int i = 0; i<sz(odds) - 1; i++){
				cout<<odds[i]<<" ";
			}
			cout<<eves[0]<<" ";
			cout<<odds[sz(odds) - 1]<<" ";
			for(int i = 1; i<sz(eves); i++){
				cout<<eves[i]<<" ";
			}

			cout<<'\n';

	}

	else{
		for(auto v: odds){
				cout<<v<<' ';				
			}
			for(auto v: eves){
				cout<<v<<" ";
			}
			cout<<'\n';
			return;
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