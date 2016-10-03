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
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
#define endl "\n"
typedef int i64;
typedef unsigned long long ui64;
typedef string ST;
typedef vector<i64> vi;
typedef vector<ST> vs;
typedef map<i64,i64> mii;
typedef map<ST,i64> msi;
typedef set<i64> si;
typedef set<ST> ss;
typedef pair<i64,i64> pii;
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
#define MAXN 100007
vector<int>G[MAXN] ;
bool visited[MAXN] ;
int dis[MAXN],par[MAXN] ;
bool loop ;
void BFS(int source){

    queue<int>q ;
    q.push(source) ;
    visited[source]=1 ;
    dis[source]=0 ;
    par[source]=-1 ;

    while(!q.empty()){
        int t = q.front() ; q.pop() ;
        rep(i,0,sz(G[t])){
            int v = G[t][i] ;
            if(!visited[v] && v!=par[t]){
                visited[v]=1 ;
                dis[v]=dis[t]+1 ;
                q.push(v) ;
                par[v]=t ;
            }

            else if(v!=par[t] && visited[v]){
                if((dis[t]-dis[v])%2==0){
                    loop=1 ;
                    return ;
                }
            }
        }
    }
}

int main(void){
    read("in.txt") ;
    loop=0 ;
    int n,m ,u,v;
    cin>>n>>m ;
    rep(i,0,m){
        cin>>u>>v;
        G[u].pb(v) ;
        G[v].pb(u) ;
    }

    rep(i,1,n+1){
        if(!visited[i]){
            BFS(i) ;
        }
    }
    vi res1,res2 ;
    if(loop) cout<<"-1\n" ;
    else{
        rep(i,1,n+1){

            if(dis[i]%2==0) res1.pb(i) ;
            else res2.pb(i) ;
        }
        cout<<sz(res1)<<endl ;
        rep(i,0,sz(res1)) cout<<res1[i]<<" " ;
        cout<<endl ;

        cout<<sz(res2)<<endl ;
        rep(i,0,sz(res2)) cout<<res2[i]<<" " ;
    }

    return 0;
}


