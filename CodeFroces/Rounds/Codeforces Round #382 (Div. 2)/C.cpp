#include <bits/stdc++.h>
using namespace std ;
long long arr[10000000] ;
int main(void){
    //freopen("in.in","r",stdin) ;
    long long n,res=0 ;
    cin>>n ;
    long long cur=1 ;
    arr[1]=1 ;
    while(cur<n){
        cur+=(res+1) ;
        arr[res++]=cur ;
    }
   // cout<<res<<endl ;


    return 0 ;
}
