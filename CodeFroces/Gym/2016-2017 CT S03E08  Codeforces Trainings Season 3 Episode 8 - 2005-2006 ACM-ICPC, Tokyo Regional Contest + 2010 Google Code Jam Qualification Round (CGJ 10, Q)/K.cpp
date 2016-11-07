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
Long arr[5] ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int n ;
    Long val=0,maxi=-1 ,res=-1;
    cin>>n ;
    rep(i,0,n){
        cin>>arr[i];
    }
    sort(arr,arr+n) ;
    for(int i=1;i<n;i++){
        val+=(arr[i]-arr[0]) ;
    }
  //  cout<<arr[0]<<endl ;
   // cout<<val<<endl ;
   Long limit = sqrt(val)+0.5 ;
    rep(i,1,limit+1){
        Long I  = val/i ;
        if(val%i==0){
            Long cur= 1;
            while(cur*i<arr[n-1]) cur++ ;
            Long K = i*cur-arr[n-1] ;
            bool ok=1 ;
           // cout<<K<<" "<<i<<" "<<cur<<endl ;
            rep(j,0,n){
                if((arr[j]+K)%i!=0) ok=0 ;
            }
            if(ok){
                res=max(res,K) ;
            }

        }
        if(val%I==0){
            Long cur= 1;
            while(cur*I<arr[n-1]) cur++ ;
            Long K = I*cur-arr[n-1] ;
            bool ok=1 ;
           // cout<<K<<" "<<i<<" "<<cur<<endl ;
            rep(j,0,n){
                if((arr[j]+K)%I!=0) ok=0 ;
            }
            if(ok){
                res=max(res,K) ;
            }

        }

    }
    cout<<res<<endl ;
    //cout<<val<<endl ;
    return 0 ;
}

