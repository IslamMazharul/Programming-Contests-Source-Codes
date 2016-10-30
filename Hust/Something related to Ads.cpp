/*
TASK:
*/
using namespace std ;
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<fstream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
#define maxn 30000+10
//#define mod
struct ADDS{
    int s,e,cost ;
    bool operator<(const ADDS &p)const{
        return e<p.e ;
    }
};
ADDS adds[maxn] ;
int N,dp[maxn] ;
int main(int argc,char *agrs[]){
    #ifdef unlucky_13
    freopen("C:\\Users\\Mazhar\\Desktop\\in.txt","r",stdin) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,CT=1;
    cin>>T ;
    while(T--){
        cin>>N ;
        FOR(i,0,N-1){
            cin>>adds[i].s>>adds[i].e>>adds[i].cost ;
            adds[i].e+=adds[i].s ;
        }
        sort(adds,adds+N) ;
       // FOR(i,0,N-1) cout<<adds[i].e<<"\n";
        dp[adds[0].e]  = adds[0].cost ;
        int height = adds[0].e+1 ;
        int cur = 1 ;
        while(cur<N){
            dp[height] = max(dp[height-1],dp[height-adds[cur].e-1]+adds[cur].cost) ;
            if(adds[cur].e>=height) cur++ ;
            height++ ;
          //  cout<<adds[cur].e<<" "<<cur<<" "<<height<<"\n" ;
        }
        cout<<dp[height]<<"\n" ;
    }




    return 0 ;
}

