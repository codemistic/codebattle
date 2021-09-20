#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int ans=0;
        int a[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) cin>>a[i][j];
        for(int sum=0;sum<(n+m+1)/2-1;sum++)
        { int z=0,o=0;
             for(int i=0;i<n;i++)
                 for(int j=0;j<m;j++)
                 {
                     if(i+j==sum||(n+m-2)-(i+j)==sum)
                     {
                         if(a[i][j]==0) z++;
                         else o++;
                     }
                 }
            ans+=min(z,o);
        } cout<<ans<<endl;
    }
    return 0;
}
