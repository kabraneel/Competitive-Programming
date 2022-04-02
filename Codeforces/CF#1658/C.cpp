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
	vector<int> c(n);

	for(int i = 0; i<n; i++){
		cin>>c[i];
	}

	int ones = -1;
	int cones = 0;
	for(int i = 0; i<n; i++){
		if(c[i] == 1){
			cones++;
			ones = i;
			// break;
		}
	}

	if(ones == -1){
		cout<<"NO\n";;
		return;
	}

	if(cones != 1){
		cout<<"NO\n";
		return;
	}


	vector<int> temp;
	for(int i = ones; i<n; i++){
		temp.PB(c[i]);
	}

	for(int i = 0; i<ones; i++){
		temp.PB(c[i]);
	}

	debug(temp);

	// int i = 0;
	// while(i<n-1 && temp[i+1] > temp[i]){
	// 	if(temp[i] == i+1){
	// 		i++;
	// 	}
	// 	else{
	// 		cout<<"NO\n";
	// 		return;
	// 		// break;
	// 	}
	// }

	// if(temp[i]!= i+1){

	// }

	int count = 1;
	vector<vector<int>> ans;

	int i = 0;

	while(i<n-1){

		// if(count > 1000){
		// 	break;
		// }

		vector<int> temp1;

		// if(temp[i] != count){
		// 	cout<<"NO\n";
		// 	return;
		// }

		// int count1 = 0;
		while(i<n-1){

			if(temp[i+1] > temp[i]){
				temp1.PB(temp[i]);
				i++;
			}

			else{
				break;
			}

		}
		// i++;
		temp1.PB(temp[i]);
		i++;
		debug(temp1);
		count++;
		ans.PB(temp1);

	}

	if(temp[n-2] >= temp[n-1]){
		ans.PB({temp[n-1]});
	}

	sort(all(ans));
	debug(ans);


	// while(i<n){

	// 	// vector<int> temp1;

	// 	if(temp[i] != count){
	// 		cout<<"NO\n";
	// 		return;
	// 	}

	// 	int count1 = 0;
	// 	while(i<n){
	// 		if(temp[i] == (count1+count)){
	// 			i++;
	// 			count1++;
	// 		}

	// 		else{
	// 			break;
	// 		}

	// 	} 
	// 	// if(temp[i])
	// 	count++;

	// }
	int ans1 = -INF;

	for(int i = 0; i<sz(ans); i++){
		// if(ans[i][0] > ans1){
		// 	cout<<"NO\n";
		// 	return;
		// }
		for(int j = 0; j<sz(ans[i]); j++){
			if(ans[i][j] != ans[i][0]+j){
				cout<<"NO\n";
				return;
			}
		}
		// ans1 = max(ans[i].back(), ans1);
	}



	cout<<"YES\n";


	// if(i == n-1){
	// 	cout<<"YES\n";
	// 	return;
	// }

	// // i++;
	// if(temp[i] == i+1){
	// 	i++;
	// }
	// debug(i);

	// int count = 2;
	// while(i<n){
	// 	if(temp[i] == count){
	// 		i++;
	// 		count++;
	// 	}
	// 	else{
	// 		cout<<"NO\n";
	// 		return;
	// 	}
	// }
	// cout<<"YES\n";

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