#include<bits/stdc++.h>
using namespace std;
#define Long long long
#define MAX 5000+7
#define pii pair< Long, Long >
#define pb(x) push_back(x)
#define sz(x) ((long long)x.size())
inline void read() {
#ifdef Mazharul
    freopen("in.in","r",stdin) ;
#endif
}
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];
int DP[MAX][MAX] ;
int Dir[MAX][MAX] ;
int par[MAX] ;
int i, u, v, w, sz, nodes, edges, starting,Cost;
int DFS(int u,int parr,Long cost){
    if(cost<0) return -1000000 ;
    if(u==nodes) return 1 ;
    Long maxi=-100000000 ;
  //  if(DP[par][u]!=-1) return DP[par][u] ;
    int nxt=-1 ;
    rep(i,0,sz(G[u])){
        int v = G[u][i].first ;
        Long ret = DFS(v,u,cost-G[u][i].second) ;
      //  cout<<u<<" "<<v<<" "<<cost-G[u][i].second<<" "<<ret<<endl ;
       if(ret>maxi){
            nxt = v ;
            maxi=ret ;
       }
       // maxi=max(ret,maxi) ;
    }
  //  DP[par][u]=maxi+1 ;
  //  Dir[par][u]=nxt ;
  //  cout<<u<<" "<<nxt<<endl ;
    par[u]=nxt ;
    return maxi+1 ;
}

int main() {
    read() ;
    // create graph
  //  memset(DP,-1,sizeof(DP)) ;
    cin>>nodes>>edges>>Cost ;
    for(i=0; i<edges; i++) {
        cin>>u>>v>>w ;
        G[u].pb(pii(v, w));
       // G[v].pb(pii(u, w)); // for undirected
    }
   // cout<<DFS(1,Cost)<<endl ;
   DFS(1,0,Cost) ;
   vector<int>res ;
   u=1 ;
   while(1){
        res.pb(u) ;
     //   cout<<u<<endl ;
     //   if(u==0) break ;
        if(u==nodes) break ;
        u=par[u] ;
   }
   cout<<sz(res)<<endl ;
   rep(i,0,sz(res)){
    cout<<res[i]<<" " ;
   }
    return 0;
}
