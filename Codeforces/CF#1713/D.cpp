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
	int N = 1ll << n;
	vector<int> arr(N);
	// set<int> S;

	for(int i = 0; i< N; i++){
		// S.insert(i);
		arr[i] = i+1;
	}

	while(sz(arr) >= 4){

		vector<int> temp;
		
		for(int i = 0; i<sz(arr); i+=4){
			cout<<"? " << arr[i] << " " << arr[i+2] << endl;
			int c; cin>>c;
			if(c == 0){
				cout<<"? " << arr[i+1] << " " << arr[i+3] << endl;
				int y; cin>>y;
				if(y == 1){
					temp.PB(arr[i+1]);
				}
				else{
					temp.PB(arr[i+3]);
				}
			}
			else if(c == 1){
				cout<<"? " << arr[i] << " " << arr[i+3] << endl;
				int y; cin>>y;
				if(y == 1){
					temp.PB(arr[i]);
				}
				else{
					temp.PB(arr[i+3]);
				}
			}
			else{
				cout<<"? " << arr[i+2] << " " << arr[i+1] << endl;
				int y; cin>>y;
				if(y == 1){
					temp.PB(arr[i+2]);
				}
				else{
					temp.PB(arr[i+1]);
				}
			}
		}

		// cout<<"TEMP:\n";
		// for(auto v: temp){
		// 	cout << v << " ";
		// }
		// cout<<'\n';
		arr = temp;
	}

	if(sz(arr) == 2){
		cout<<"? " <<arr[0] << " " << arr[1] << '\n';
		int y; cin>>y;
		vector<int> temp;
		if(y == 1){
			temp.PB(arr[0]);
		}
		else{
			temp.PB(arr[1]);
		}
		arr = temp;
	}

	cout<<"! "<<arr[0]<<endl;



}

signed main(){

	// #ifdef KABRANEEL
	// freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
	// freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
	// freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
	// #endif

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
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