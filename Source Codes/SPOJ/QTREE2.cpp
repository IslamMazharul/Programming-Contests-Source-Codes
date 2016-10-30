#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std ;
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
#define LL long long
#define MAXN 10002
int L[MAXN];
LL dis[MAXN] ; // the distance from root
int P[MAXN][22];
int T[MAXN];
struct EDGE{
    int v,cost ;
} ;
vector<EDGE>graph[MAXN];
void dfs(int from,int u,int dep,int weight){

    T[u]=from;
    L[u]=dep ;
    dis[u] = dis[from] + weight ;
    int siz = graph[u].size()-1 ;
    FOR(i,0,siz){

        int v=graph[u][i].v ;
        int cost = graph[u][i].cost ;
        if(v==from) continue;
        dfs(u,v,dep+1,cost);
    }
}

void lca_init(int N){

      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }

int lca_query(int p, int q,int N){


      if (L[p] < L[q])
          swap(p,q) ;

      int log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

      for (int i = log; i >= 0; i--){
          if (L[p] - (1 << i) >= L[q]){
              p = P[p][i];
          }
      }

      if (p == q)
          return p;

        for (int i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
}
bool check(int N,int i){ return (bool)(N & (1<<i)) ; }

int Find(int u,int k){
    //cout<<"The "<<k<<"-th node from  "<<u<<" is " ;
    k-- ;
    for(int i=31;i>=0;i--){
        if(check(k,i)){
            u = P[u][i] ;
            k = k/2 ;
        }
    }
    //cout<<u<<endl ;
    return u ;
}

int main(int argc, char **argv){
    #ifdef unlucky_13
        freopen("C:\\Users\\Mazharul Islam\\Documents\\in.txt","r",stdin) ;
    #endif
    int testcases ,u,v,k,N;
    cin>>testcases ;
    EDGE edg ;
    while(testcases--){
        FOR(i,0,MAXN){
            graph[i].clear() ;
        }
        cin>>N ;
        FOR(i,0,N-2){
            cin>>u>>edg.v>>edg.cost ;
            edg.v-- ;
            graph[u-1].push_back(edg) ;
        }

        dfs(0,0,0,0) ;
        lca_init(N) ;
        
        //cout<<P[5][0]<<"\n" ;
       // cout<<Find(4,0)<<"\n" ;
        string in ;
        while(1){
            cin>>in ;
            if(in[1]=='O') break ;
            else if(in[0]=='D'){
                    cin>>u>>v ;
                    u-- ;
                    v-- ;
                    int LCA = lca_query(u,v,N) ;
                  //  cout<<dis[u]<<" "<<dis[v]<<endl ;
                    int res ;
                    if(LCA==u || LCA==v) res = dis[u]+dis[v]-2*dis[LCA]+1 ;
                    else res = dis[u]+dis[v]-2*dis[LCA] ;
                    cout<<res<<"\n" ;
            }
            else{
                cin>>u>>v>>k ;
                u-- ;
                v-- ;
                int LCA = lca_query(u,v,N) ;
                int res ;
                //cout<<L[u]-L[LCA]<<"\n" ;
                if(L[u]-L[LCA]>=k){
                    res = Find(u,k) ;
                }

                else{
                    //k-- ;
                    //cout<<L[v]+L[u]-2*L[LCA]<<"\n" ;
                    //if(LCA==u || LCA==v) k = L[v]+L[u]-2*L[LCA]- k+2 ;
                   // else
                    k = L[v]+L[u]-2*L[LCA]-k+2 ;
                    //k -= (L[v]-L[LCA]) ;
                   // cout<<k<<"---\n" ;
                    //k = (L[v]-L[LCA]-k) ;
                    cout<<k<<endl ;
                    res = Find(v,k) ;
                }
                
                cout<<res+1<<"\n" ;
            }
       }
    }

	return 0 ;
}
