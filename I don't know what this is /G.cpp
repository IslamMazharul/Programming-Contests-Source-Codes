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
#define MAXN 150007
struct Interval{
    Long  s,e ;
};
vector<Interval>interval ;
bool F(Long s,Long e){
    bool okay=1 ;
    rep(j,0,sz(interval)){
            if(interval[j].e<s || interval[j].s>e){
            }
            else{
                okay=0 ;
                break ;
            }
        }
        return okay ;
}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
 //   read() ;
    Long n ,s,e,ss,ee;
    cin>>n ;
    Interval I ;
    rep(i,0,n){
        cin>>s>>e ;
        I.s = 100000000000 ;
        if(F(s,s+e-1)){
            I.s = s ;
            I.e = s+e-1 ;
        }
        else{

            if(F(1,e)){
                I.s = 1 ;
                I.e = e ;
            }
                rep(j,0,sz(interval)){
                    if(F(interval[j].e+1,interval[j].e+e)){
                        if(interval[j].e+1<I.s){
                                I.s = interval[j].e+1 ;
                                I.e = interval[j].e+e ;
                        }
                    }
                }
        }


        interval.pb(I) ;
        cout<<I.s<<" "<<I.e<<endl ;
    }
    return 0 ;
}

