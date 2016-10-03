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
#define inf 100000000000
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
#define MAXN 1007
double Length[MAXN],Width[MAXN] ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int nx,ny ;
    bool res ;
    double w ;
    while(cin>>nx>>ny>>w){
        if(!nx && !ny && !w) break ;
        res=1 ;
        rep(i,0,nx){
            cin>>Length[i] ;
        }
        sort(Length,Length+nx) ;
        /*
        rep(i,0,nx){
            cout<<Length[i]<<" " ;
        }
        cout<<endl ;
        */
        rep(i,1,nx){
            if(Length[i]-Length[i-1]>w) res=0 ;
        }
        if(Length[0]-w/2>0) res=0 ;
        if(Length[nx-1]+w/2<75) res=0 ;
        Width[0]=0 ;
        rep(i,0,ny){
            cin>>Width[i] ;
        }
        sort(Width,Width+ny) ;
        /*
        rep(i,0,ny){
            cout<<Width[i]<<" " ;
        }
        cout<<endl ;
        */
        rep(i,1,ny){
            if(Width[i]-Width[i-1]>w) res=0 ;
        }
        if(Width[0]-w/2>0) res=0 ;
        if(Width[ny-1]+w/2<100) res=0 ;
        if(res) cout<<"YES\n" ;
        else cout<<"NO\n" ;
    }
    return 0 ;
}


