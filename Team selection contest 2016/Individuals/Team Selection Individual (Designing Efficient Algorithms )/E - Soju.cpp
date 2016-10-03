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
    freopen("/home/mazharul/in.txt","r",stdin) ;
#endif
}

#define all(x) x.begin(),x.end()
#define sz(x) ((long long)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf 100000000000
#define ins insert
#define ff first
#define ss second
#define eps 1e-9
#define endl "\n"

typedef long long  Long ;
typedef unsigned long long ULong;
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
#define MAXN 2*100007
struct Point{
    Long x,y,type;
} ;

Point points ;
vector<Point>p ;
int compare(Point p, Point q) {
    return p.y < q.y;
}
int main(void) {
	ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int testcases,n,m ;
    cin>>testcases;
    while (testcases--) {
        p.clear() ;
        cin>>n ;
        rep(i,0,n){
            cin>>points.x>>points.y ;
            points.type=1 ;
            p.pb(points) ;
        }
        cin>>m ;
        rep(i,0,m){
            cin>>points.x>>points.y ;
            points.type=0 ;
            p.pb(points) ;
        }

        sort(all(p),compare) ;

        Long res=inf ;
        Long delta = inf ;

        rep(i,0,sz(p)){
            if(!p[i].type){
                res=min(res,p[i].x+p[i].y+delta) ;
            }else{
                delta=min(delta,-p[i].x-p[i].y) ;
            }
        }

        delta = inf;
        reverse(all(p)) ;

        rep(i,0,sz(p)){
            if(!p[i].type){
                res=min(res,p[i].x-p[i].y+delta) ;
            }else{
                delta=min(delta,-p[i].x+p[i].y) ;
            }
        }
        //*/
        cout<<res<<endl ;
    }
    return 0;
}

