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
#define inf (1<<62)
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
#define MAXN 400+7
Long arr[2][MAXN],DP[MAXN][207][207] ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
  //  read() ;
    Long n,m ;
    cin>>m>>n ;
    rep(i,0,2){
        rep(j,1,n+1){
            cin>>arr[i][j] ;
        }
    }

    rep(i,0,m+1){
        rep(j,0,m+1){
            DP[0][i][j]=100000000000 ;
        }
    }

    DP[0][0][0]=0 ;

    rep(i,1,n+1){
        rep(j,0,m+1){
            rep(k,0,m+1){
                DP[i][j][k]=DP[i-1][j][k] ;
                if(j-1>=0) DP[i][j][k] = min(DP[i][j][k],DP[i-1][j-1][k]+arr[0][i]) ;
                if(k-1>=0) DP[i][j][k] = min(DP[i][j][k],DP[i-1][j][k-1]+arr[1][i]) ;
            }
        }
    }
    //cout<<DP[1][1][0]<<" "<<DP[1][0][1]<<endl ;
    cout<<min(DP[n][m/2][(m-m/2)],DP[n][m-m/2][m/2])<<endl ;
    return 0 ;
}

