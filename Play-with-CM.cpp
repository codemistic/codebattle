#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string x;
        cin>>x;
        int s=0,max=0;
        for(int i=0;i<x.length();++i){
            if(x[i]=='M'){
                s++;
            }
            else{
                s--;
            }
            if(s<0){ 
                s=0;
            }
            if(s>max){
                max=s;
            }
        }
        for(int i=0;i<x.length();++i){
            if(x[i]=='C')
                max++;
        }
        cout<<max<<endl;
    }
    return 0;
} 
