#include <bits/stdc++.h>
using namespace std ;
int dp[22][11][166] ,n,k,s;

int call(int cur,int taken,int sum){

    if(taken<0 || sum<0) return 0 ;
    if(cur==0){
       // cout<<taken<<" "<<sum<<endl ;
        if(taken==0 && sum==0) return 1 ;
        return 0 ;
    }
    if(dp[cur][taken][sum]!=-1) return dp[cur][taken][sum] ;
    int ret = call(cur-1,taken-1,sum-cur) ;
    ret +=call(cur-1,taken,sum) ;
    dp[cur][taken][sum] = ret ;
    return ret ;
}
int main(void){

    while(scanf("%d %d %d",&n,&k,&s)==3){
        if(!n && !k && !s) break ;
        memset(dp,-1,sizeof(dp)) ;
        printf("%d\n",call(n,k,s)) ;
    }
    return 0 ;
}
