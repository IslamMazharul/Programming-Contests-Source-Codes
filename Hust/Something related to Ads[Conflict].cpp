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
#define maxn 100
//#define mod
int A[maxn],B[maxn],C[maxn],N,dp[maxn] ;
int main(int argc,char *agrs[]){
    #ifdef _unlucky_13
    freopen("C:\\Users\\Mazharul islam\\Desktop\\in.txt","r",stdin) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,CT=1 ,H;
    cin>>T ;
    while(T--){
        H = 0 ;
        cin>>N ;
        FOR(i,0,N){
            cin>>A[i]>>B[i]>>C[i] ;
            B[i]+=A[i] ;
            H = max(H,B[i]) ;
        }
        memset(dp,0,sizeof(dp)) ;
       // cout<<H<<"\n"
       FOR(i,0,N-1){
            REP(j,H,B[i]){
                dp[j] = max(dp[j-1],dp[j-A[i]-1]+C[i]) ;
            }
        }

        cout<<dp[H]<<"\n" ;
    }




    return 0 ;
}

