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

	vector<pair<int,int>> allpairs;

	for(int i = 0; i<n; i++){
		allpairs.PB({arr[i][0], arr[i][p-1]});
	}

	vector<vector<int>> dp(n+1, vector<int> (2,0));


	dp[0][0] = 2*allpairs[0].second - allpairs[0].first; 
	dp[0][1] = allpairs[0].second;


	for(int i = 1; i<n; i++){

		dp[i][0] = min(dp[i-1][0] + abs(allpairs[i].first - allpairs[i-1].second), dp[i-1][1] + abs(allpairs[i].second - allpairs[i-1].second));
		dp[i][1] = min(dp[i-1][0] + abs(allpairs[i].first - allpairs[i-1].first), dp[i-1][1] + abs(allpairs[i].first - allpairs[i-1].second));
		dp[i][0] += abs(allpairs[i].first - allpairs[i].second);
		dp[i][1] += abs(allpairs[i].first - allpairs[i].second);
		debug(dp);

	}

	cout<<min(dp[n-1][0], dp[n-1][1])<<'\n';
	debug(dp);

	// debug(arr);

	// int fans = INF;

	// for(int i = 0; i < (1 << n); i++){

	/*

			10010001

			11100000

			3

			10000000

			4 



	*/

	// 	//if the jth bit is on, reverse

	// 	vector<int> temp;
	// 	for(int j = 0; j<n; j++){

	// 		if((1ll << j) & i){

	// 			for(int k = p-1; k>=0; k--){
	// 				temp.PB(arr[j][k]);
	// 			}

	// 		}

	// 		else{
	// 			for(int k = 0; k<p; k++){
	// 				temp.PB(arr[j][k]);
	// 			}
	// 		}
 
	// 	}

	// 	int tsum = temp[0];
	// 	int n1 = sz(temp);

	// 	debug(temp);
	// 	for(int k = 0; k<n1-1; k++){
	// 		tsum += abs(temp[k+1] - temp[k]);
	// 	}

	// 	fans = min(fans, tsum);
	/*

		40 -> 5 +35
		5 -> 60 +55

				+ 90 + 10 ==> 100


		40 -> 60 	+20
		60 -> 5 	+55 -> 75 + 55 ==> 130


		50,60,60 	+55

		(30, 40)
		(5, 60)
		(50, 60)

		40 -> 5 or 60

		dp[i][2] => dp[i][0] -> ans if i end at 0th
				=> dp[i][1] -> ans if I end at 1st

	
		dp[0][0] = 50  -> 0 to 40 to 30
		dp[0][1] = 40  -> 0 to 30 to 40
 	
		


	*/
	// }

	// cout<<fans<<'\n';
	// if(n == 1){
	// 	cout<<
	// }

	// for(int i = n-1; i>=n-2; i--){
	// 	int men = INF;
	// 	pair<int,int> minval;

	// 	if(abs(arr[i][p-1] - arr[i-1][p-1]) < men){
	// 		men = abs(arr[i][p-1] - arr[i-1][p-1]);
	// 		minval = {0, 1};
	// 	}

	// 	if(abs(arr[i][0] - arr[i-1][p-1]) < men){
	// 		men = abs(arr[i][0] - arr[i-1][p-1]);
	// 		minval = {0, 0};
	// 	}

	// 	if(abs(arr[i][p-1] - arr[i-1][0]) < men){
	// 		men = abs(arr[i][0] - arr[i-1][p-1]);
	// 		minval = {1, 1};
	// 	}

	// 	if(abs(arr[i][0] - arr[i-1][0]) < men){
	// 		men = abs(arr[i][0] - arr[i-1][p-1]);
	// 		minval = {1, 0};
	// 	}
	// }



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