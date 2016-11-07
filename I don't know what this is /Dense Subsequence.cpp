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
int m ;
ST str ;
vi pos ;
int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
  //  read() ;
    si res ;
    cin>>m>>str ;
    for(char ch='a';ch<='z';ch++){
        rep(i,0,sz(str)){
            if(str[i]==ch){
                pos.pb(i) ;
            }
        }
            /// check if OK
            bool ok=1 ;
            int last=0 ;
            sort(all(pos)) ;
         //   cout<<pos<<endl ;
            rep(j,0,sz(pos)){
                if(j){
                    if(pos[j]-pos[j-1]>m) ok=0 ;
                }else{
                    if (pos[j]>m) ok=0 ;
                }
            }
            if(sz(str)-pos[sz(pos)-1]>m) ok=0 ; // for the last element
           // cout<<ok<<endl ;
            if(ok){
                /// we have found a solution
             //   cout<<"OK"<<endl ;
                rep(k,0,sz(pos)){
                    if(str[pos[k]]!=ch){
                        res.insert(pos[k]) ;
                    }

                }
           //     cout<<res<<endl ;
            //    cout<<pos<<endl ;
                si::iterator it ;
                int lo,hi ;
                rep(l,0,sz(pos)){
                    if(str[pos[l]]==ch){
                    //    cout<<pos[l]<<endl ;
                        it =  res.lower_bound(pos[l]-1) ;
                        lo = *it ;
                        if(abs(pos[l]-lo+1)>=m || res.empty()){
                            res.insert(pos[l]) ;
                        }

                    }
                }

                break ;
            }

        }
    ST res_str="" ;
    //cout<<res<<endl ;
    foreach(it,res){
        res_str.pb(str[*it]) ;
    }
    sort(all(res_str)) ;
    cout<<res_str ;
    return 0 ;
}

