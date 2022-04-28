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

	int p; cin>>p;

	vector<vector<int>> arr(n, vector<int> (p, 0));



	for(int i = 0; i<n; i++){
		for(int j = 0; j<p; j++){
			cin>>arr[i][j];
		}
	}

	for(int i = 0; i<n; i++){
		sort(all(arr[i]));
	}

	debug(arr);

	int fans = INF;

	for(int i = 0; i < (1 << n); i++){

		//if the jth bit is on, reverse

		vector<int> temp;
		for(int j = 0; j<n; j++){

			if((1ll << j) & i){

				for(int k = p-1; k>=0; k--){
					temp.PB(arr[j][k]);
				}

			}

			else{
				for(int k = 0; k<p; k++){
					temp.PB(arr[j][k]);
				}
			}
 
		}

		int tsum = temp[0];
		int n1 = sz(temp);

		debug(temp);
		for(int k = 0; k<n1-1; k++){
			tsum += abs(temp[k+1] - temp[k]);
		}

		fans = min(fans, tsum);

	}

	cout<<fans<<'\n';


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
	int count = 1;
	while(t--){
	  cout << "Case #" << count++ <<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}