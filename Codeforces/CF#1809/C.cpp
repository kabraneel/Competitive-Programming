// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;


#ifdef KABRANEEL
#include<sys/resource.h>
#include <sys/time.h>
#endif

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

int nC2(int i){
	return (i * (i+1))/2;
}

vector<int> fans;
int lowestNum = INF;

// int unboundedKnapsack(int W, vector<int> &wt, vector<int> &val, int idx,
//                       vector<vector<int> >& dp, int num, vector<int> &ans)
// {
 
//     if (idx == 0) {
//         return (W / wt[0]) * val[0];
//     }
 
//     if (dp[idx][W] != -1)
//         return dp[idx][W];

 
//     int notTake = 0 + unboundedKnapsack(W, wt, val, idx - 1, dp, num, ans);

//     int take = INT_MIN;
//     if (wt[idx] <= W) {
//     	ans.PB(wt[idx]);
//         take = val[idx] + unboundedKnapsack(W - wt[idx], wt, val, idx, dp, num+1, ans);
//     }
//     return dp[idx][W] = max(take, notTake);
// }

const int N = 31;
const int mex = N * 1000;

int dp[N][mex];

bool subSetSum(int S, vector<int> &vals, int ind){

	if(S == 0){
		// if(sz(ans) < lowestNum){
		// 	fans = ans;
		// 	lowestNum = sz(ans);
		// }
		// ans.pop_back();
		return true;
	}

	if(ind == -1){
		return false;
	}

	if(dp[ind][S] != -1){
		return dp[ind][S];
	}

	bool ans1 = false;
	if(vals[ind] <=  S){
		// ans.PB(vals[ind]);
		ans1 = subSetSum(S - vals[ind], vals, ind);
	}

	bool ans2 = subSetSum(S, vals, ind-1) || ans1;

	return dp[ind][S] = ans2;



}

void solve(){
	int n; int k;
	cin>>n>>k;

	vector<int> temp;
	temp.PB(1);
	for(int i = 2; i<=n; i++){
		temp.PB(nC2(i));
	}

	for(int i = 0; i<n+1; i++){
		for(int j = 0; j<k+1; j++){
			dp[i][j] = -1;
		}
	}

	// subSetSum(k, temp, n-1);


	for (int i = 1; i <= k; i++)
        dp[0][i] = false;
 
    for (int i = 1; i <= sz(temp); i++) {
        for (int j = 1; j <= k; j++) {
            if (j < temp[i - 1])
                dp[i][j] = dp[i-1][j];
            if (j >= temp[i - 1])
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - temp[i - 1]]) || dp[i][j - temp[i-1]];
        }
    }


	debug(temp);

	for(int i = 0; i<n; i++){
		for(int j = 0; j<k; j++){
			cout << dp[i][j] << ' '; 
		}
		cout << '\n';
	}

	int n1 = sz(temp);
	int i1 = k;
	debug(dp[n1][k]);
	int i2 = n1;

	// int 
	vector<int> ans;
	while((i1 >= 0) and (i2 >= 0)){
		for(int j = n1-1; j>=0; j--){
			if(i1 - temp[j] >= 0 and dp[i2][i1 - temp[j]]){
				i1 -= temp[j];
				ans.PB(j+1);
			}
		}
		i2 -= 1;
	}

	debug(ans);




}

signed main(){

	#ifdef KABRANEEL
	freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
	freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
	freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
	#endif

	#ifdef KABRANEEL
        /* setting up soft limit on resources */
        rlimit rlim , rlim_time ;
        if(getrlimit( RLIMIT_FSIZE , &rlim) || getrlimit(RLIMIT_CPU , &rlim_time) )
           return 1 ;
        // maximum file size (in bytes) that your program will be able to create ;
        rlim.rlim_cur = 1000*1000;
        // maximum allowed runtime for your program ;
        rlim_time.rlim_cur = 1;
        if(setrlimit( RLIMIT_FSIZE , &rlim ) || setrlimit(RLIMIT_CPU , &rlim_time))
           return 2 ;
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