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
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
#define endl "\n"
typedef long long i64;
typedef unsigned long long ui64;
typedef string ST;
typedef vector<i64> vi;
typedef vector<ST> vs;
typedef map<i64,i64> mii;
typedef map<ST,i64> msi;
typedef set<i64> si;
typedef set<ST> ss;
typedef pair<i64,i64> pii;
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
struct ELE{
    i64 idx1,idx2,val ;
    bool operator<(const ELE&prev)const{
        if(val!=prev.val) return val<prev.val ;
        else return idx1<prev.idx1 ;
    }
};
#define MAXN 1000000
i64 arr[MAXN] ;
ELE t ;
set<i64>avail ;
set<i64>::iterator IT ;
int main(){

    ios_base::sync_with_stdio(0);
    set<ELE>Set ;
    int n ;
    ST str ;
    cin>>n>>str;
    rep(i,0,n){
        cin>>arr[i] ;
        avail.insert(i) ;
    }
    rep(i,0,n-1){
        if(str[i]!=str[i+1]){
            t.idx1=i ;
            t.idx2=i+1 ;
            t.val = abs(arr[i]-arr[i+1]) ;
            Set.insert(t) ;
        }
    }
    set<ELE>::iterator it ;
    /*
    for( it=Set.begin();it!=Set.end();it++){
        cout<<it->val<<" "<<it->idx1<<" "<<it->idx2<<endl ;
    }
    */
    while(!Set.empty()){
        it = Set.begin() ;
        t.val = it->val ;
        t.idx1 = it->idx1 ;
        t.idx2  = it->idx2 ;
        Set.erase(it) ;
        if(arr[t.idx1]!=-1 && arr[t.idx2]!=-1 && ST[t.idx1]!=){

                avail.erase(t.idx1) ;
                avail.erase(t.idx2) ;
                arr[t.idx1]=-1 ;
                arr[t.idx2]=-1 ;
                cout<<t.idx1<<" "<<t.idx2<<endl ;
                // construct the new ones
                IT = avail.upper_bound(t.idx1) ;
                if(IT!=avail.end()){
                    if(IT!=avail.begin()){
                            t.idx2 = arr[*IT] ;
                            t.idx1 = arr[*(IT-1)] ;
                            t.val = abs(arr[t.idx1]-arr[t.idx2]) ;
                    }
                    if(IT!=)
                }
        }
    }

    return 0;
}

