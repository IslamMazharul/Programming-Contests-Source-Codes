/*
 * Mazharul Islam , BUET
 * Problem Link:http://acm.hust.edu.cn/vjudge/contest/130740#problem/A
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
#define MAXN 10000
bool F(Long N,Long K,Long I){
    Long low=0 ;
    if(N>MAXN) return 0 ;
    Long high=N-1 ;
    Long mid ;
    while(K-->0){
        if(low>high) return 0 ;
      //  cout<<low<<" "<<high<<endl ;
        mid = (low+high)>>1 ;
        if(mid>I){
            high=mid-1 ;
        }else{
            low=mid+1 ;
        }
    }
    return mid==I ;
}
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
  //  cout<<F(13,13,0)<<endl ;
   // /*
    Long i,L ;
    vpii res ;
    Long p=-2 ;
    Long s=-2 ;
    while(cin>>i>>L){
        res.clear() ;
      //  p=-2 ;
        s=-2 ;
        rep(ii,1,10003){

            if(F(ii,L,i)){
               // cout<<ii<<endl ;
                p=ii ;
                if(s==-2){
                    s=ii ;
                }
            }
            if(p!=ii && s!=-2){
               res.pb(make_pair(s,p)) ;
                s=-2 ;
            }

        }
        cout<<sz(res)<<endl ;
        rep(i,0,sz(res)){
            cout<<res[i].ff<<" "<<res[i].ss<<endl ;
        }
    }
   // */
    return 0 ;
}

