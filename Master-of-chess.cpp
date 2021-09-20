#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    
    while(T--)
    {
        int N;
        cin>>N;
        int x[N],y[N];
        for(int i=0;i<N;i++)
            cin>>x[i]>>y[i];
        int A,B;
        cin>>A>>B;
        bool ans=true;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(i==0 && j==0)
                    continue;
                int a=A+i,b=B+j;
                bool check=false;
                for(int i=0;i<N;i++)
                    if((abs(a-x[i])==2 && abs(b-y[i])==1) || (abs(a-x[i])==1 && abs(b-y[i])==2))
                    {
                        check=true;
                        break;
                    }
                if(check==false)
                    ans=false;
        }
    }
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
