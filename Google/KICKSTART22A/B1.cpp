#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    int x=1;
    while(x<=t)
    {
        string expp;
        string out;
        cin>>expp;
        cin>>out;
        int n = expp.size();
        int m = out.size();
        sort(expp.begin(),expp.end());
        sort(out.begin(),out.end());
        unordered_map<char,int>m1;
         unordered_map<char,int>m2;
         int i,j;
         for(i=0;i<n;i++)
         {
             m1[expp[i]]++;
         }
          for(i=0;i<m;i++)
         {
             m2[out[i]]++;
         }
         int temp=0;
         for(i=0;i<n;i++)
         {
             if(m2[expp[i]]>=m1[expp[i]])
             {
                 temp=0;
             }
             else{
                 temp=1;
                 break;
             }
         }
         
        
        cout<<"Case #"<<"";
        cout<<x<<"";
        cout<<":"<<" ";
        if(n>m)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        
        else{
            if(temp==0)
            {
                cout<<m-n<<endl;
            }
            else{
                cout<<"IMPOSSIBLE"<<endl;
            }
        }
        x++;
        
    }
    return 0;
}