using namespace std ;
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define maxn 101
//#define inf 1110000001
vector<int>Graph[maxn] ;
bool G[maxn][maxn] ;
int n,m ,matchL[maxn],matchR[maxn];
int main(int argc,char** argv){

    #ifdef _unlucky_13
    freopen("C:\\Users\\Mazharul islam\\Desktop\\in.txt","r",stdin) ;
    #endif
    int testcases;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T ,u,v;
    cin>>T ;
    while(T--){
        memset(G,0,sizeof(G)) ;
        cin>>n>>m ;
        FOR(i,0,n){
            cin>>u>>v ;
            if(!G[u][v]){
                Graph[u].push_back(maxn+v) ;
                Graph[v].push_back(maxn+u) ;
            }
        }
    }
    return 0 ;

}

