#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(){
    int n;
    string s;
    cin >> n >> s;
    s='0'+s;
    if(n%2==0){
        for(int i=2;i<=n;i+=2){
            if(s[i]%2==0) return 2;
        }
        return 1;
    }
    else{
        for(int i=1;i<=n;i+=2){
            if(s[i]%2==1) return 1;
        }
        return 2;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}
