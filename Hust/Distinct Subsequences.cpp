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
#define maxn 100001
#define mod(x)  ( (x) %1000000007 + 1000000007 ) %1000000007

int dp[maxn] ;
int main(int argc,char *agrs[]){
    #ifdef unlucky_13
    freopen("C:\\Users\\Mazhar\\Desktop\\in.txt","r",stdin) ;
    #endif
  //ios_base::sync_with_stdio(false);cin.tie(NULL);
    int testcases ;
    scanf("%d\n",&testcases) ;
    char str[maxn] ;
    int last[27] ;
    while(testcases--){
        gets(str) ;
        memset(last,0,sizeof(last)) ;
        int Len = strlen(str) ;
        dp[0] = 1 ;
        FOR(i,1,Len){
            dp[i] = mod( dp[i-1]<<1 );

            if(last[str[i-1]-'A'] ){
                dp[i] -= dp[last[str[i-1]-'A'] - 1];
            }

            last[str[i-1]-'A'] = i;
        }

        printf("%d\n",dp[Len]) ;
    }

    return 0 ;
}

