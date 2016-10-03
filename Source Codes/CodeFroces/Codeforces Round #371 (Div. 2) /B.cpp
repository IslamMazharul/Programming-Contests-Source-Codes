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
    freopen("in.in","r",stdin) ;
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
#define MAXN 100007
Long arr[MAXN] ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    bool res=0 ;
    int N ;
    cin>>N ;
    rep(i,0,N) cin>>arr[i] ;
    sort(arr,arr+N) ;
    Long a1 = arr[0] ;
    Long a2 = arr[N-1] ;
    if(a1==a2) res=1 ;

    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if ( (i-j)!=0 &&  abs(a2-a1) % abs(i-j)==0){
                Long x = (a2-a1)/(i-j) ;
               // cout<<val<<endl ;
               Long val = ((a2-a1)/(i-j))*i+a1 ;
               //cout<<x<<endl ;
               bool ok = 1 ;
               rep(k,1,N){
                    if(arr[k]+x!=val && arr[k]-x!=val && arr[k]!=val) ok = 0 ;
               }
               if(ok) {
                 //   cout<<val<<endl ;
                    res=1 ;
               }
            }

        }
    }
    if(res) cout<<"YES\n" ;
    else cout<<"NO\n" ;
    return 0 ;
}

