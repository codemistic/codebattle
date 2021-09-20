#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1, M = 1e9+7;
long fc[N] = {1}, ifc[N]={1};

long mod_pow(long n, long pow, unsigned m=M) {
    long r = 1;
    for(; pow; pow >>= 1) {
        if (pow & 1) r = (r*n)%m;
        n = (n*n)%m;
    }
    return r;
}

long mul(long a,long b) { return (a*b)%M; }
long cnk(long n, long k) {
    return mul(fc[n],mul(ifc[k],ifc[n-k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    
    for(int i = 1; i < N; ++i) fc[i] = (fc[i-1]*i)%M;
    ifc[N-1]=mod_pow(fc[N-1],M-2);
    for(int i = N-1; i>1; --i) ifc[i-1]=(ifc[i]*i)%M;    
    
    int t;scanf("%d",&t);
    while(t--) {
        int n,k; scanf("%d %d", &n, &k);
        int m = n/(k+1);
        long ans = cnk(n,m);
        for(int j = 0; j <m; ++j) {
            ans = (ans+M-mul(k-1,cnk(n,j)))%M;
        }
        printf("%ld\n",ans);
    }
    return 0;
}
