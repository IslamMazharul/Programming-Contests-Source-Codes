/*
 * Mazharul Islam , BUET
 * Problem Link:
 */

using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
inline void read() {
#ifdef Mazharul
    freopen("/home/mazharul/in.in","r",stdin) ;
#endif
}

#define all(x) x.begin(),x.end()
#define sz(x) ((long long)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf 1000000000
#define ins insert
#define ff first
#define ss second
#define eps 1e-9
#define endl "\n"

typedef long long  Long ;
typedef string ST;
typedef vector<Long> vi;
typedef vector<ST> vs;
typedef map<Long,Long> mii;
typedef map<ST,Long> msi;
typedef set<Long> si;
typedef set<ST> ss;
typedef pair<Long,Long> pii;
typedef vector<pii> vpii;


/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
#define MAX_V 107
struct EDGE{
    Long v,c,speed,u;
    bool InTr ;
    EDGE(Long v,Long c,bool InTr=false){
        this->v=v ;
        this->c=c ;
        this->InTr = InTr ;
    }
    EDGE(){

    }
};
typedef vector<EDGE> VE;
Long testcases ;
EDGE edge ;
Long nV,nE,cost;                 // number of vertices and edges in initial
Long Visit[MAX_V+7],TRUE;   // used in dfs to check for visit
bool InStk[MAX_V+7];        // used in dfs to check visted vertices is in recursive call
Long Par[MAX_V+7];          // parent vertices in dfs
Long TotV;                  // to count number of vertices in dfs call
Long nG;                    // number of grp
Long Grp[MAX_V+7];          // grp in dex oa vertice used in cycle contraction in DMST

/* to set all the vertices in a cycle in same grp */

void SetGrp( Long u,Long v,Long n ){
    Grp[v] = n;
    if( u==v ) return;
    SetGrp( u,Par[v],n );
}
/* dfs to to check in graph */
void Dfs( vector< VE > &Edge , long u , bool ChkTr = true ){
    Visit[u] = TRUE;
    InStk[u] = true;
    TotV++;
    if( u==0 ) Grp[u] = nG++;
    else Grp[u] = -1;
    Long i;
    for( i=0;i<Edge[u].size();i++){
        Long v = Edge[u][i].v;
        if( ChkTr && Edge[u][i].InTr == false ) continue;
        if( InStk[v] ) SetGrp( v,u,nG++ );
        else if( Visit[v]!=TRUE ){
            Par[v] = u;
            Dfs( Edge,v,ChkTr );
        }
    }
    if( Grp[u]==-1 ) Grp[u] = nG++;
    InStk[u] = false;
}
/* this return cost of DMST
   should be call if arborescne
   is possible */
long DMST( vector< VE > &Edge ){
    Long N = Edge.size();
    //cout<<N<<" "<<testcases<<endl ;
    vector<Long> MU( N,-1 );
    vector<Long> MI( N );
    Long u,v,i,MinCost = 0;
    for( u=0;u<N;u++){
        for( i=0;i<Edge[u].size();i++){
            v = Edge[u][i].v;
            if( v==0 ) continue;
            if( MU[v]==-1 || Edge[ MU[v] ][ MI[v] ].c > Edge[u][i].c ){
                if( MU[v]!=-1 ){
                    MinCost -= Edge[ MU[v] ][ MI[v] ].c;
                    Edge[ MU[v] ][ MI[v] ].InTr = false;
                }
                MU[v] = u;
                MI[v] = i;
                MinCost += Edge[u][i].c;
                Edge[u][i].InTr = true;
            }
        }
    }
    /* termination condition */
    if( N==2 ) return Edge[ MU[1] ][ MI[1] ].c;

    TotV = 0;
    nG = 0;
    TRUE++;
    Dfs( Edge,0 );
    /* to check is any cycle created
       if all vertice can be reachable
       from root 0
    */
    if( TotV==N ) return MinCost;
    for( i=0;i<N;i++){
        if( Visit[i]==TRUE ) continue;
        Dfs( Edge,i );
    }
    /* new compressed graph is creating  */
    vector< VE > TmpE( nG );

    for(u=0;u<N;u++){
        for( i=0;i<Edge[u].size();i++){
            long v = Edge[u][i].v;
            if( v==0 ) continue;
            if( Grp[u]==Grp[v] ) continue;
            TmpE[ Grp[u]].pb( EDGE( Grp[v] , Edge[u][i].c - Edge[ MU[v] ][ MI[v] ].c ) );
        }
    }
    Edge.clear();
    return MinCost + DMST( TmpE );
}

Long F(Long min_speed,vector<EDGE>&graph){
    vector<VE>Edge(nV) ;
    rep(i,0,nE){
        edge = graph[i] ;
        if(edge.speed>=min_speed){
            Edge[edge.u].pb(EDGE(edge.v,edge.c)) ;
        }else{
           // cout<<"Not added "<<edge.u<<" "<<edge.v<<" "<<edge.c<<endl ;
        }
    }
     /* initial check for is arborescence is possible */
    TotV = 0 ;
    TRUE = 1 ;
    mem(Visit,0) ;
    mem(InStk,0) ;
    mem(Par,0) ;
    mem(Grp,0) ;
    nG=0 ;
    Dfs(Edge,0,false) ;
  //  cout<<TotV<<endl ;
    if(TotV!=nV) {
           // cout<<"Not possible to derive mst\n" ;
            return -1 ;
    }
    Long DMSTV = DMST(Edge) ;
    return DMSTV<=cost?1:-1 ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    cin>>testcases ;
    vector<EDGE>graph ;
    while(testcases--){
        cin>>nV>>nE>>cost ;
        graph.clear() ;
        rep(i,0,nE){
            cin>>edge.u>>edge.v>>edge.speed>>edge.c ;
            graph.pb(edge) ;
        }
      //  /*
        Long lo=1 ;
        Long hi=100000000 ;
        Long mid ;
        Long res=-1 ;
        while(lo<=hi){
            mid=(lo+hi)/2 ;
            Long call = F(mid,graph) ;
            if(call!=-1){
                lo=mid+1 ;
                res=mid ;
            }else{
                hi=mid-1 ;
            }
        }
        //*/
        //cout<<F(256,graph)<<endl ;
        if(res==-1) cout<<"streaming not possible."<<endl ;
        else cout<<res<<" kbps"<<endl ;
    }
    return 0 ;
}

