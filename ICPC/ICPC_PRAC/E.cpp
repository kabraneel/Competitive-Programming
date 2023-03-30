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

void solve(){
	int n, l, r, k;
	cin>>n>>l>>r>>k;

	vector<int> arr(n);

	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	vector<int> alls;
	int top = r - l;

	int count = 0;
	int curr = 1;
	for(int i = 0; i<n; i++){
		if(curr == 1){ // increasing
			if(arr[i+1] > arr[i]){
				count++;
			}
			else{
				alls.PB(count);
				curr = -1;
				count = 1;
				continue;
			}
		}
		else{
			if(arr[i+1] < arr[i]){
				count++;
			}
			else{
				alls.PB(-1 * count);
				curr = 1;
				count = 1;
				continue;
			}
		}

	}


	debug(alls);
	int n1 = sz(alls);

	// for(int i = 0; i<n1; i++){
	// 	cin>>alls[i];
	// }
	debug(alls);

	vector<int> ends(n1);
	// ends[n1 - 1] = 0;

	// for(int i = n1 - 2; i>=0; i--){
	// 	if(alls[i] > 0){
	// 		ends[i] = top - alls[i];
	// 	}
	// 	else{
	// 		ends[i] = 
	// 	}
	// }

	if(alls[n1-1] > 0){
		// to end on max
		ends[n1 - 1] = top;
		for(int i = n1 - 2; i>=0; i--){
			if(alls[i+1] > 0){
				ends[i] = (ends[i+1]) - alls[i+1];
			}
			else{
				ends[i] = ends[i+1] + alls[i+1] * -1 * k;
			}
			if(ends[i] < 0){
				ends[i] = 0;
			}
			if(ends[i] > top){
				ends[i] = top;
			}
		}

	}

	else{
		// debug("here");
		ends[n1 - 1] = 0;
		for(int i = n1 - 2; i>=0; i--){
			// debug(i, ends[i+1]);
			if(alls[i+1] < 0){
				ends[i] = (ends[i+1]) + -1 * alls[i+1];
			}
			else{
				ends[i] = ends[i+1] - alls[i+1]  * k;
			}
			if(ends[i] < 0){
				ends[i] = 0;
			}
			if(ends[i] > top){
				ends[i] = top;
			}
		}
	}


	// for(int i = 0; i<n1; i++){
	// 	if(ends[i] < 0){
	// 		ends[i] = 0;
	// 	}
	// 	if(ends[i] > top){
	// 		ends[i] = top;
	// 	}
	// }
	debug(ends);

	vector<vector<int>> ans;
	if(alls[0] > 0){
		int prev = 0;

		for(int i = 0; i<n1; i++){
			
			vector<int> temp;
			if(alls[i] > 0){
				int x = ends[i] - alls[i];
				// debug("alls[i] > 0", x);
				while(x > 0 and alls[i]){
					if(x > k){
						x -= k;
						temp.PB(k);
						alls[i]--;
					}
					else{
						temp.PB(x);
						x = 0;
						alls[i]--;
					}
				}
				for(int j = 0; j < alls[i] + 1; j++){
					temp.PB(1);
				}

				reverse(all(temp));
				vector<int> temp1;

				for(auto v : temp){
					temp1.PB(prev);
					prev += v;
				}

				debug(i, alls[i], temp1);
				temp = temp1;
			}

			else{

				int x = ends[i];

				// sum --> prev - ends[i]
				// steps --> alls[i] * -1
				int steps = alls[i] * -1;
				while((prev - ends[i] > steps) and steps){
					int x = prev - ends[i] - steps;
					debug(i, x);
					if(x > k){
						temp.PB(-1 * k);
						steps--;
						prev -= k;
					}
					else{
						temp.PB(-1 * x);
						steps--;
						prev -= x;
					}
				}

				for(int j = 0; j < steps; j++){
					temp.PB(-1);
				}
				
				reverse(all(temp));
				vector<int> temp1;

				for(auto v : temp){
					temp1.PB(prev);
					prev += v;
				}

				debug(i, alls[i], temp1);
				temp = temp1;
			}
			ans.PB(temp);
		}

	}

	debug(sz(ans));
	for(auto v : ans){
		debug(sz(v));
		for(auto u : v){
			cout << u << ' ';
		}
	}
	cout << '\n';

}

signed main(){

	 #ifdef KABRANEEL
        /* setting up soft limit on resources */
        rlimit rlim, rlim_time ;
        if(getrlimit( RLIMIT_FSIZE , &rlim) || getrlimit(RLIMIT_CPU , &rlim_time) )
           return 1 ;
        // maximum file size (in bytes) that your program will be able to create ;
        rlim.rlim_cur = 1000*1000;
        // maximum allowed runtime for your program ;
        rlim_time.rlim_cur = 1;
        if(setrlimit( RLIMIT_FSIZE , &rlim ) || setrlimit(RLIMIT_CPU , &rlim_time))
           return 2 ;
    #endif

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
	// cin>>t;

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