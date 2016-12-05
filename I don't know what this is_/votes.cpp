#include<bits/stdc++.h>
using namespace std ;
#define Long unsigned long long
#define MAXN 2000+7
long double DP[MAXN+MAXN][MAXN+MAXN] ,ncr[MAXN+MAXN][MAXN+MAXN];
int main(void){
    freopen("A-large-practice.in","r",stdin) ;
    freopen("A-large-practice.out","w",stdout) ;
    Long testcases ;
    cin>>testcases ;

    /*
    for(int i=1;i<20;i++){
        for(int j=1;j<20;j++){
            cout<<DP[i][j]<<" " ;
        }
        cout<<endl ;
    }
    */
    for(int i=0;i<MAXN+MAXN;i++){
            ncr[i][0]=1 ;
        for(int j=1;j<=i;j++){
            ncr[i][j] = ncr[i-1][j-1]+ncr[i-1][j] ;
        }
    }
    for(int i=1;i<=MAXN;i++) DP[i][0]=1 ;

            for(int i=1;i<=MAXN;i++){
                for(int j=1;j<=MAXN;j++){
                    DP[i][j]=0 ;
                    if(i-1>j) DP[i][j] += DP[i-1][j] ;
                    if(i>j-1) DP[i][j] += DP[i][j-1] ;
                }
            }
   // cout<<ncr[5][3]<<endl ;
    ///*
    int n,m ,caseno=1;
    while(testcases--){
            cin>>n>>m ;
            //memset(DP,0,sizeof(DP)) ;
         //   cout<<DP[n][m]<<endl ;
         cout<<"Case #"<<caseno++<<": ";
            cout<<fixed<<setprecision(12)<<DP[n][m]/ncr[n+m][n]<<endl  ;
    }
    //*/
}
