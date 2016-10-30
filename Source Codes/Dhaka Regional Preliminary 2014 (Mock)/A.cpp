#include <bits/stdc++.h>
using namespace std ;
string s,p  ;
int Len1,Len2;
int dp[555][26] ;
const int maxn = 10000 ;
char s1[maxn],s2[maxn] ;
int call(int idx,int k){
    if(idx==Len1){
        if(k==Len2) return 1 ;
        return 0 ;
    }
    if(dp[idx][k]!=-1) return dp[idx][k] ;
    int ret = call(idx+1,k) ; // not taking
    if(k<Len2) ret +=call(idx+1,k+1) ; // taking
    dp[idx][k] = ret ;
    return ret ;
}

int main(void){
    int tc ,ct = 1;
    scanf("%d",&tc) ;
    while(tc--){
        memset(dp,-1,sizeof(dp)) ;
        scanf("%s %s",s1,s2) ;
        Len1 = strlen(s1) ;
        Len2 = strlen(s2) ;
        int res = call(0,0) ;
        cout<<res<<endl ;
        res *= (Len1-Len2) ;
     //   cout<<res<<endl ;
    }


    return 0 ;
}
