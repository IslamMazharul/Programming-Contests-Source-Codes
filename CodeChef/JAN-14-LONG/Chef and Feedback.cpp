using namespace std ;
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define maxn 1000001
//#define inf 1110000001
char buffer[maxn] ;
int main(int argc,char** argv){

    #ifdef _unlucky_13
    freopen("C:\\Users\\Mazharul islam\\Desktop\\in.txt","r",stdin) ;
    #endif
    int testcases;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T ;
    bool good ;
    cin>>T ;
    while(T--){
        good = false ;
        cin>>buffer ;
        FOR(i,0,strlen(buffer)-2){
            if(good) break ;
            if(buffer[i]=='0' && buffer[i+1]=='1' && buffer[i+2]=='0') {
                good = true ;
            }
            if(buffer[i]=='1' && buffer[i+1]=='0' && buffer[i+2]=='1') {
                good = true ;
            }
        }
        good?cout<<"Good\n":cout<<"Bad\n" ;
    }

    return 0 ;

}

