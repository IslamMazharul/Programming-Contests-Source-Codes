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
#define MAXN 150007
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    Long arr[3] ;
    rep(i,0,3) cin>>arr[i] ;
    Long maxi = max(max(arr[0],arr[1]),arr[2]) ;
    Long res=maxi+maxi+maxi ;
    rep(i,0,3){
        rep(j,0,3){
            if(i<=j){ // on the same day
                Long temp=0  ;
                rep(k,0,3){
                    if(i<=k && k<=j) temp+=maxi-arr[k] ;
                    else if(maxi-arr[k]-1>=0) temp +=(maxi-arr[k]-1) ;
                    else temp+=maxi+maxi+maxi ;
                }
                //if(j==2 && i==2) cout<<temp<<endl ;
                res=min(res,temp) ;
            }
            else{

                Long temp=0  ;
                rep(k,0,3){
                    if(j<k && k<i) {
                            if(maxi-arr[k]-1>=0) { temp+=maxi-arr[k]-1 ; //cout<<temp<<endl ;
                            }
                            else temp+=maxi+maxi+maxi ;
                    }
                    else temp +=(maxi-arr[k]) ;

                    //if(i==2 && j==0) cout<<temp<<endl ;
                }
                res=min(res,temp) ;

            }
        }

    }
    cout<<res<<endl ;
    return 0 ;
}

