#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define int  long long int

signed main(){

    int tc;
    cin>>tc;

    while (tc--)
    {
        int n,k,i;
        cin>>n>>k;

        // if(n==1){
        //     cout<<0<<endl;
        //     continue;
        // }

        map<int,vector<int>>adj;
        vector<int>degree(n+1,0);
        vector<int>vis(n+1,0);

        for(i=0;i<n-1;i++){

            int u,v;
            cin>>u>>v;

            degree[u]+=1;
            degree[v]+=1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;


        for(int node=1; node<=n; node++){

            if(degree[node]<=1){
                q.push(node);
                vis[node]=1;
            }
        }

        int ans = n;

        //  watch(q.size());

        while(!q.empty() and k-- and ans>0){

            ans = ans - q.size();

            for(i=0;i<q.size();i++){

                int node = q.front();
                q.pop();

                for(auto nbr:adj[node]){

                    degree[nbr] -=1;

                    if(degree[nbr]==1 and vis[nbr]==0){
                        q.push(nbr);
                        vis[nbr]=1;

                    }
                }
            }
        }

        ans = max(ans, (int)0);

        cout<<ans<<endl;




   }

}
