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
	int n; cin>>n;
	int count = 0;

	int aw = 1;
	int ab = 0;
	int bw = 0;
	int bb = 0;
	int x = 2;
	n--;
	int temp = 1;
	int dealt = 0;

	while(n > 0){
		if(count == 2){
			count = 0;
			temp = temp ^ 1;
		}
		count++;

		if(x > n){
			// int temp1 = 
			if(temp == 0){
				if(dealt % 2 == 0){
					// first card is black
					int x1 = (1 - temp) * n;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						aw += x1/2;
						ab += x1/2;
					}
					else{
						ab += x1/2 + 1;
						aw += x1/2;
					}

				}
				else{
					int x1 = (1 - temp) * n;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						ab += x1/2;
						aw += x1/2;
					}
					else{
						aw += x1/2 + 1;
						ab += x1/2;
					}
				}
			}
			else{
				// b += temp * n ;
				if(dealt % 2 == 0){
					// first card is black
					int x1 = (temp) * n;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						bw += x1/2;
						bb += x1/2;
					}
					else{
						bb += x1/2 + 1;
						bw += x1/2;
					}

				}
				else{
					int x1 = (temp) * n;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						bb += x1/2;
						bw += x1/2;
					}
					else{
						bw += x1/2 + 1;
						bb += x1/2;
					}
				}
			}
			n = 0;
		}


		else{
			if(temp == 0){
				if(dealt % 2 == 0){
					// first card is black
					int x1 = (1 - temp) * x;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						aw += x1/2;
						ab += x1/2;
					}
					else{
						ab += x1/2 + 1;
						aw += x1/2;
					}

				}
				else{
					int x1 = (1 - temp) * x;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						ab += x1/2;
						aw += x1/2;
					}
					else{
						aw += x1/2 + 1;
						ab += x1/2;
					}
				}
			}
			else{
				// b += temp * n ;
				if(dealt % 2 == 0){
					// first card is black
					int x1 = (temp) * x;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						bw += x1/2;
						bb += x1/2;
					}
					else{
						bb += x1/2 + 1;
						bw += x1/2;
					}

				}
				else{
					int x1 = (temp) * x;
					// a += (1 - temp) * n;
					if((x1 % 2) == 0){
						bb += x1/2;
						bw += x1/2;
					}
					else{
						bw += x1/2 + 1;
						bb += x1/2;
					}
				}
			}
			n -= x;
		}

		dealt += x;
		// debug(x, temp, a, b);
		x++;

	}

	cout << aw << ' ' << ab << ' ' << bw << ' ' << bb << '\n';
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