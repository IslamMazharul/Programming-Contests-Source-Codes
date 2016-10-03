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
#define sz(x) ((i64)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define FF first
#define SS second
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
#define MAXN 2007
bool F[MAXN][MAXN] ;
double DP[MAXN][MAXN] ;
pii points[MAXN] ;
int n ;
double euclidian_distance(int I,int J){
    return hypot(points[I].FF-points[J].FF,points[I].SS-points[J].SS) ;
}
double call(int L,int R){

    int next=max(L,R)+1 ;
    if(next==n-1){
        return euclidian_distance(L,n-1)+euclidian_distance(R,n-1) ;
    }
    if(F[L][R]) return DP[L][R] ;
    double ret=1e100 ;
    F[L][R]=1 ;
    ret = min(ret,call(next,R)+euclidian_distance(L,next)) ;
    ret = min(ret,call(L,next)+euclidian_distance(R,next)) ;
    DP[L][R]=ret ;
    return ret ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;

    while(cin>>n){
        mem(F,0) ;
        rep(i,0,n){
            cin>>points[i].FF>>points[i].SS ;
        }

        double res = call(0,0) ;
        cout<<fixed<<setprecision(2)<<res+eps<<endl ;
    }
}
