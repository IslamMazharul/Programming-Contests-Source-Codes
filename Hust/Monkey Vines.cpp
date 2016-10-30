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
#define maxn 150+10
#define LL long long
 //#define mod
 char line[maxn] ;
 int cur  ;
 LL call(){

    LL ret = 1 ;
    while(cur<strlen(line)){
        cur++ ;
        if(line[cur]=='['){

            ret = max( ret, call() ) ;
            cout<<ret<<endl ;
        }
        else {
            return 2*ret ;
        }
    }
}

int main(int argc,char *agrs[]){
    #ifdef unlucky_13
    freopen("C:\\Users\\Mazhar\\Desktop\\in.txt","r",stdin) ;
    #endif
   //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int testcases,caseno=1 ;
    LL res ;
    scanf("%d\n",&testcases) ;

    while(testcases--){
        cur = 0 ;
        gets(line) ;
        if(line[0]=='\0') {
            res = 1 ;
        }
        else{
            res = call() ;
        }

        cout<<caseno++<<" "<<res<<endl ;
    }




    return 0 ;
}

