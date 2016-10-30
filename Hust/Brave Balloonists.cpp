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
#define maxn 100000+10
bool is_prime[maxn] ;
int cnt,primeList[maxn] ;
//#define mod
#define LL long long
void sieve(){

    for(int i=2;i<maxn;i++){

        if(!is_prime[i]){
            primeList[cnt++] = i ;
            for(int j=i+i;j<maxn;j+=i) is_prime[j] = true ;
        }
    }
    /*
    for(int i=0;i<cnt;i++) cout<<primeList[i]<<" " ;
    cout<<cnt<<endl ;
    */
}
int main(int argc,char *agrs[]){
    #ifdef unlucky_13
    freopen("C:\\Users\\Mazhar\\Desktop\\in.txt","r",stdin) ;
    #endif

    sieve() ;
    LL n,mul ;
    while(cin>>mul){
        for(int i=1;i<10;i++){
            cin>>n ;
            mul *=n ;
            //cout<<mul<<" " ;
        }
        LL res = 1 ;
        for(int i=0;i<cnt;i++){
                if(sqrt(mul)+1<primeList[i]) break ;
                LL Count = 1 ;
                while(mul%primeList[i]==0){
                    Count++ ;
                    mul /=primeList[i] ;
                }
                res *=Count ;

        }

        if(mul!=1) res*=2 ;
        cout<<res%10<<"\n" ;
    }



    return 0 ;
}

