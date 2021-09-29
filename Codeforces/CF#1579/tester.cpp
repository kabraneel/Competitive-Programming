#include <bits/stdc++.h>
#include <chrono>

using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)

ll lim=1e9+7;

ll power(ll a,ll b,ll lim)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%lim;
        a=(a*a)%lim;
        b/=2;
    }
    return res;
}

void solve()
{
    ll i,n,x;
    // cin>>n;
    n = (int) 10;
    vi a;
    rep(i,0,n)
    {
        // cin>>x;
        x = n - i;
        if(a.size()>0 && x<a.front())
            a.insert(a.begin(),x);
        else
            a.pb(x);
    }
    rep(i,0,n)
    cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
   fast;

   auto start = chrono::high_resolution_clock::now();


   ll t=1;
   // cin>>t;
   while(t--)
   {
       solve();
   }


   auto end = chrono::high_resolution_clock::now();
   double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

   time_taken *= 1e-9;

   cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
   return 0;
}
