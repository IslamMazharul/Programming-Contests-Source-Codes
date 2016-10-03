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
#define MAXN 1000
ST passwords[MAXN] ;
int main(void){
    ios_base::sync_with_stdio(NULL) ;
    read() ;
    int n,k ,tim=0,best,worst;
    best=worst=INT_MAX ;
    cin>>n>>k ;
    ST actual_pass ;
    rep(i,0,n) cin>>passwords[i] ;
    rep(i,1,n){
        rep(j,0,n-i){
            if(passwords[j].length()>passwords[j+1].length()){
                swap(passwords[j],passwords[j+1]) ;
            }
        }
    }
    cin>>actual_pass ;
    rep(i,0,n){
       // cout<<passwords[i]<<endl ;
        tim++ ;
        //cout<<actual_pass.length()<<" "<<passwords[i].length()<<" "<<tim<<endl ;
        if(actual_pass.length()==passwords[i].length()){
            best=min(best,tim) ;
        }
        if(i==n-1 || actual_pass.length()<passwords[i+1].length()){
            worst = min(worst,tim) ;
        }
        if((i+1)%k==0) tim+=5 ;
    }

    cout<<best<<" "<<worst<<endl ;
    return 0 ;
}
