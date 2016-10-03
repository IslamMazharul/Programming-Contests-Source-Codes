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
#define MAXN 151007
ST DNA1,DNA2 ;
Long n,p ,diff[MAXN];
bool F(int Len){

    rep(i,0,n){
        Long E = i+Len ;
        Long S = i+1 ;

        if(E<=n){
            Long differencess = diff[E]-diff[S-1] ;
           // cout<<S<<" "<<E<<endl ;
            if(100*differencess<=p*Len){
                return 1 ;
            }
        }
    }
    return 0 ;

}

int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    Long low,hi,mid ;
    while(cin>>n>>p && n){
        cin>>DNA1>>DNA2 ;
        diff[0]=0 ;
        rep(i,0,n){
            if(DNA1[i]!=DNA2[i]) diff[i+1]=1 ;
            else diff[i+1]=0 ;
        }
        rep(i,1,n+1){
            diff[i]+=diff[i-1] ;
        }
        low=0 ;
        hi =1150000 ;
        /*
        rep(i,1,n+1){
            cout<<diff[i]<<" " ;
        }
        cout<<endl ;
        */
        while(low<=hi){
            mid=(low+hi)>>1 ;
            if(F(mid)) low=mid+1 ;
            else hi=mid-1 ;
        }
       // cout<<low<<" "<<mid<<" "<<hi<<endl ;
        //*/
        if(hi>0) cout<<hi<<endl ;
        else cout<<"No solution."<<endl ;
    }

}

