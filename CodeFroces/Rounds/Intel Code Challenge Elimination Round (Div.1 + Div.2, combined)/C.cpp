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
#define MAXN 100000+7
Long arr[MAXN] ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    Long n ;
    cin>>n;
    rep(i,1,n+1){
        cin>>arr[i] ;
        arr[i]+=arr[i-1] ;
    }
    multiset<Long>ms ;
    multiset<Long>values ;
    multiset<Long>::iterator it2 ;
    multiset<Long>::iterator it1 ;
    ms.insert(0) ;
    ms.insert(n+1) ;
    Long prev ;
    Long nxt  ,idx;
    Long v ;
    values.insert(arr[n]) ;
    rep(i,0,n){
        cin>>idx ;
      //  foreach(it,values) cout<<*it<<" " ;
        //cout<<endl ;
        it1=ms.upper_bound(idx) ;
        it1-- ;
        prev=*it1 ;
        it1=ms.upper_bound(idx) ;
        nxt = *it1 ;
       // cout<<prev<<" "<<nxt<<endl ;
        ms.insert(idx) ;

       if(prev+1<=nxt-1){
            Long v = arr[nxt-1]-arr[prev] ;
            //cout<<v<<endl ;

            it2 = values.find(v) ;
            if(it2!=values.end()){
           //         cout<<v<<" is erased"<<endl ;
                    values.erase(it2) ;
            }
       }

       if(idx-1>=prev+1){
            v= arr[idx-1]-arr[prev] ;
         //   cout<<v<<" inserted"<<endl ;
            values.insert(v) ;
       }
       if(nxt-1>=idx+1){
            v = arr[nxt-1]-arr[idx] ;
           // cout<<v<<" inserted "<<endl ;
            values.insert(v) ;
       }
       //*/

        ms.insert(prev) ;
        ms.insert(nxt) ;
        Long res=0 ;
        if(!values.empty()){
            it2=values.end(); it2-- ;
            res=*it2 ;
        }else res=0 ;

        cout<<res<<endl ;
        //*/
    }
    return 0 ;

}

