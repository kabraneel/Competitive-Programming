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
	int n; int q; cin>>n>>q;
	vector<int> arr(n);

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	// debug(arr);

	vector<vector<int>> temp;
	set<pair<int,int>> S;

	// vector<vector<int>> ans;

	int i = 0;

	while(i<n-1){

		int j = i;
		vector<int> temp1;
		while(i<n-1){

			if(arr[i+1] <= arr[i]){
				temp1.PB(arr[i]);
				i++;
			}

			else{
				break;
			}

		}
		// i++;
		temp1.PB(arr[i]);
		i++;
		S.insert({j, i-1});
		// debug(temp1);
		temp.PB(temp1);

	}

	// debug(temp);
	// debug(S);

	while(q--){
		// cout<<"Here\n";
		int type;
		cin>>type;

		if(type == 1){
			int ind;
			cin >> ind;

			int x; cin>>x;
			arr[ind-1] = x;


			// debug(arr[ind - 2], ind, x);
			if(ind - 2 >= 0 && arr[ind-2] <= x){
				// cout<<"im hereee1\n";
				debug("im hereee1\n");
				auto it = S.lower_bound(MP(ind, INF));
				it--;

				// cout<<"Pair found is : "<< it-> first <<" "<<it -> second<<'\n';
				int tf = it -> first;
				int ts = it -> second;

				debug(tf, ts);


				// if its the end, then we should merge 
				if(tf == ind - 1){ // its an edge
					it--;

					// int temp = ts;
					// if(it != S.end())
					// // if(it !=)
					int temp = it -> first;

					S.erase(it);
					S.erase({tf, ts});

					S.insert({temp, ts});

				}

				else{
					S.erase(it);

					S.insert({tf, ind -2});
					S.insert({ind - 1, ts});

				}


				debug(S);

			}

			else if (ind < n && arr[ind] > x){

				debug("IM hereeee2\n");
				auto it = S.lower_bound(MP(ind, INF));
				it--;

				// cout<<"Pair found is : "<< it-> first <<" "<<it -> second<<'\n';
				int tf = it -> first;
				int ts = it -> second;

				if(tf == ind -1){ // its an edge
					it++;

					int temp = it -> second;

					S.erase(it);
					S.erase({tf, ts});

					S.insert({tf, temp});

				}

				else{
					S.erase(it);

					// arr[ind-1] = x;
					S.insert({tf, ind - 1});
					S.insert({ind , ts});

				}

				// debug(S);

			}

			debug(arr);
			debug(S);

		}

		else{
			int a,b; cin>>a>>b;
			auto it1 = S.lower_bound({a-1, INF});
			it1--;

			auto it2 = S.lower_bound({b-1, INF});
			it2--;
			// int numsegs = 0;

			debug(it1 -> first, it1 -> second, it2 -> first, it2 -> second);
			
			if(it1 -> first  == it2 -> first ){

				cout<<"0\n";
				continue;

			}	

			if(it1 -> second + 1 == it2 -> first){

				// int k1 = 
				// int 
				int l1 = 0;
				int l2 = 0;

				int r1 = 0;
				int r2 = 0;


				cout<<arr[it2 -> first] - arr[it1 -> second]<<'\n';
			}
			
			else{
				cout<<"-1\n";
				continue;
			}

		}
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
	// cin>>t;
	while(t--){
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}