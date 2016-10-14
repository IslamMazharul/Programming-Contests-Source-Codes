/*
 * Mazharul Islam
 * BUET
 */

using namespace std;
#include <bits/stdc++.h>

#define rep(i,a,n) for(int i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define INF (1LL<<62)
#define ins insert
#define xxx first
#define yyy second
#define eps 1e-9
#define endl "\n"

typedef long long Long;
typedef unsigned long long Ulong;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<Long,Long> pii;
typedef vector<pii> vpii;

#define MAXN 100000+7

/*
        Debug Extensions
*/

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
/* Debug
*/
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
 
priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAXN];
Long D[MAXN];
bool F[MAXN];
int n,m,k ;
inline Long Dijkstra(int starting,int destination){
		// initialize distance vector
    for(int i=0; i<=n+1; i++) D[i] = INF;
    D[starting] = 0;
    Q.push(pii(starting, 0));
 
    // dijkstra
    while(!Q.empty()) {
        
        int u = Q.top().first;
      //  cout<<u<<endl ;
        Q.pop();
        if(F[u]) continue;
        int sz = G[u].size();
        for(int i=0; i<sz; i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if(!F[v] && D[u]+w < D[v]) {
                D[v] = D[u] + w;
                Q.push(pii(v, D[v]));
            }
        }
        F[u] = 1; // done with u
    }
	return D[destination] ;
    // result
    //for(i=1; i<=nodes; i++) printf("Node %d, min weight = %d\n", i, D[i]);
}
Long u,v,cost ;
bool storage[MAXN] ;
int main(void) {
    ios_base::sync_with_stdio(0);
	cin>>n>>m>>k ;
	rep(i,0,m){
		cin>>u>>v>>cost ;
		G[u].pb(pii(v,cost)) ;
		G[v].pb(pii(u,cost)) ;
	}
	rep(i,0,k){
		cin>>u ;
		storage[u]=1 ;
	}
	rep(i,1,n+1){
		if(storage[i]) G[i].pb(pii(n+1,0)) ;
		else G[0].pb(pii(i,0)) ;
	}
	
	Long res=Dijkstra(0,n+1) ;
	if(res==INF) cout<<"-1\n" ;
	else cout<<res<<endl ;	
	return 0;
}

