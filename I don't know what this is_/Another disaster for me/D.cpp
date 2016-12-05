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
#define MAXN 100000+7
Long pass[MAXN]  ;

struct E{
    Long idx,val ;
};
E prep[MAXN];
int cmp(E e1,E e2){
    return e1.val>e2.val ;
}
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    Long n,m ;
    cin>>n>>m ;
    rep(i,0,n){
        cin>>pass[i] ;
    }
    rep(i,0,m){
        cin>>prep[i].val ;
        prep[i].idx=i+1 ;
    }
    //rep(i,)
   // cout<<prep[0]<<endl ;
    sort(prep,prep+m,cmp) ;
 //   rep(i,0,m) cout<<prep[i].val<<endl ;
    Long  countt=0 ,idx=0,res=-1;
    rep(i,0,n){
     //   cout<<countt<<prep[pass[i]-1]<<endl ;
        if(prep[idx].idx==pass[i] && prep[idx].val<=countt){
            cout<<pass[i]<<endl ;
            countt-=prep[idx].val ;
            idx++ ;
            if(idx==m){
                res=i ;
                break ;
            }
        }else if()
        else countt++ ;
    }
    cout<<res<<endl ;
    return 0 ;
}

