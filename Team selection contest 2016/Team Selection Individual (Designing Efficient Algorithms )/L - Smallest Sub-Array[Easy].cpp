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
#define MAXN 111
Long countt[MAXN] ;
vi seq ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    Long testcases ,n,m,k,testcaseno=1;
    cin>>testcases ;
    while(testcases--){
        cin>>n>>m>>k ;
        seq.clear() ;
        seq.pb(1) ;
        seq.pb(2) ;
        seq.pb(3) ;
        rep(i,3,n){
            seq.pb((seq[i-1]+seq[i-2]+seq[i-3])%m+1) ;
        }
       // cout<<seq<<endl ;
        mem(countt,0) ;
        Long s=0 ;
        Long res=inf ;
        Long done=0 ;

        rep(i,0,sz(seq)){
            if(seq[i]<=k){
                if(countt[seq[i]]==0){
                    done++ ;
                }
            //    cout<<seq[i]<<" "<<done<<endl ;
                countt[seq[i]]++ ;
                while(s<n){
                   // cout<<countt[seq[s]]<<endl ;
                    if(seq[s]<=k) {
                        if(countt[seq[s]]<=1) break ;
                        countt[seq[s]]-- ;
                    }
                    s++ ;
                }

                if(done==k) {
                    res=min(res,i-s+1) ;
                    //cout<<i<<" "<<s<<endl ;
                }
            }
        }
        cout<<"Case "<<testcaseno++<<": " ;
        if(res==inf) cout<<"sequence nai\n" ;
        else cout<<res<<endl ;
    }
    return 0 ;
}


