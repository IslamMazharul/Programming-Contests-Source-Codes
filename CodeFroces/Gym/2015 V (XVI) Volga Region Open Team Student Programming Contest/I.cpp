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
#define MAXN 1000+7
vector<Long>S[200+7],SS[200+7] ;
Long arr[200+7] ;
int N ;
si keeper ;
vector<Long>::iterator IT;
/*
pii Possible(Long val){
    for(int I=0;I<sz(keeper);I++){
        Long start = keeper[I] ;
        bool res = 1 ;
        for(int i=1;i<=N;i++){
                IT = lower_bound(all(S[i]),start) ;
                bool F = 0 ;
                if(IT!=S[i].end()){
                    if(*IT<=start+val) F=1 ;
                }
                res = res & F ;
                if(res==0) break ;
        }
        if(res) return  mp(val,start);
    }
    return mp(-1,-1) ;
}
*/
int main(void){

    read() ;
    Long val ;
    scanf("%I64d",&N) ;
    for(int i=1;i<=N;i++){
        scanf("%I64d",&arr[i]) ;
    }

    Long hi = 1 ;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=arr[i];j++){
            scanf("%I64d",&val) ;
            keeper.insert(val) ;
            S[i].pb(val) ;
            hi  = max(hi,val) ;
        }
        SS[i]=S[i] ;
        sort(all(S[i])) ;
    }
   // /*
    /// BS
   // si::iterator IT  = keeper.end() ; IT-- ;
   /*
    Long lo=0 ;
  //  Long hi = *IT ;
    //cout<<hi<<endl ;
    Long Mid ;
    pii res ;
    while(lo<hi){
            //cout<<lo<<" "<<hi<<endl ;
        Mid = (lo+hi)>>1 ;
        pii ret = Possible(Mid) ;
        if(ret.first!=-1){
            hi = Mid ;
            res=ret ;
        }else{
            lo = Mid+1 ;
        }
    }
   // cout<<res.first<<" "<<res.second<<endl ;
    //*/
    //pii res= Possible(1) ;
    //cout<<res.first<<" "<<res.second<<endl ;
    /*
    printf("%I64d\n",res.first) ;
    Long s = res.second ;
    Long e = res.first+res.second ;
    //cout<<s<<" "<<e<<endl ;%I64d
    for(int i=1;i<=N;i++){
        for(int j=0;j<sz(SS[i]);j++){
            if(s<=SS[i][j] && SS[i][j]<=e){
                printf("%I64d",j+1) ;
                break ;
            }
        }
        if(i!=N) printf(" ") ;
    }
    */
    Long res=10000000000 ;
    pii res_pair ;
    foreach(it,keeper){
        Long start = *it ;
        Long Mini = start ;
        Long Maxi = start ;
        for(int i=1;i<=N;i++){
            vi::iterator it =  lower_bound(all(S[i]),start) ;
            //if(start==3) cout<<*it<<endl ;
            if(it!=S[i].end()){
         //           deb("Here") ;
           //         deb(start) ;
                Mini = min(Mini,*it) ;
                Maxi = max(Maxi,*it) ;
            }else{
                Mini = -1000000000 ;
                Maxi = 1000000000 ;
            }
        }
        if(res>Maxi-Mini){
                res=Maxi-Mini ;
                res_pair = mp(Mini,Maxi) ;
        }
    }
    cout<<res<<endl ;
    for(int i=1;i<=N;i++){
        for(int j=0;j<sz(SS[i]);j++){
            if(res_pair.first<=SS[i][j] && SS[i][j]<=res_pair.second){
                cout<<j+1 ;
                break ;
            }
        }
        if(i!=N) cout<<" " ;
    }
    return 0 ;
}
