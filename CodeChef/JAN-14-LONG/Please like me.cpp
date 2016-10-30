using namespace std ;
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;i++)
//#define maxn 100001
//#define inf 1110000001
#define ll long long
#define eps 1e-6
int main(int argc,char** argv){

    #ifdef _unlucky_13
    freopen("C:\\Users\\Mazharul islam\\Desktop\\in.txt","r",stdin) ;
    #endif
    int testcases;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll L,D,S,C ;
    int T ;

    cin>>T ;
    while(T--){

        cin>>L>>D>>S>>C ;
        double Right = log10(L) ;
        double Left = log10(S)+(D-1)*log10(1+C) ;
        //cout<<Right<<" "<<Left<<"\n" ;
        if(Left-Right>=0) cout<<"ALIVE AND KICKING\n" ;
        else cout<<"DEAD AND ROTTING\n" ;
    }

    return 0 ;

}

