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
#define MAXN 1000001
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
  //  read() ;
    Long a00,a01,a10,a11 ;
    cin>>a00>>a01>>a10>>a11 ;
    if(a00 ==0 && a01==0 && a10==0 && a11==0){
        cout<<"1" ;
        return 0 ;
    }
    Long zeros=-100 ,ones=100 ;
    rep(i,0,MAXN){
        if(i*(i-1)>2*a00) break ;
        if(i*(i-1)==2*a00){
            zeros=i ;
            break ;
        }
    }

    rep(i,0,MAXN){
        if(i*(i-1)>2*a11) break ;
        if(i*(i-1)==2*a11){
            ones=i ;
            break ;
        }
    }
    //cout<<zeros<<" "<<ones<<endl ;
    if(zeros==0){
        if(a01+a10==0){
            rep(i,0,ones) cout<<"1" ;
        }
        else cout<<"Impossible\n" ;
    }
    else if(zeros*ones==a01+a10){
        Long n = a10/zeros ;
        Long m = a10%zeros ;
        rep(i,0,n){
            cout<<"1" ;
        }
        rep(i,0,zeros-m){
            cout<<"0" ;
        }
        if(ones>1) cout<<"1" ;
        rep(i,0,m){
            cout<<"0" ;
        }
        rep(i,n,ones-1){
            cout<<"1" ;
        }
        cout<<endl ;
    }
    else{
        cout<<"Impossible\n" ;
    }
    return 0 ;
}


