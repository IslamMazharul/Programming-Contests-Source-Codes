/*
 * Mazharul Islam , BUET
 * Problem Link:http://vjudge.net/contest/135751#problem/A
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
#define MAXN 100+7
Long n ,m,arr[MAXN],DP[MAXN][MAXN][MAXN];
Long call(int cur,int i,int j){
    if(cur==m || j==n){
        if(cur==m && j==n)     {
                return 0 ;
        }
        return 1000000000000 ;
    }
    Long &ret = DP[cur][i][j] ;
    if(ret==-1)  ret=min(call(cur+1,j+1,j+1)+arr[j]-arr[i],call(cur,i,j+1)) ;
    return ret ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int testcases ,caseno=1;
    cin>>testcases ;
    while(testcases--){
        mem(DP,-1) ;
        cin>>n>>m ;
        rep(i,0,n) cin>>arr[i] ;
        sort(arr,arr+n) ;
        //rep(i,0,n) cout<<arr[i]<<endl ;
        Long res=call(0,0,0) ;
        cout<<"Case #"<<caseno++<<": " ;
        cout<<res<<endl ;
    }
    return 0 ;
}

