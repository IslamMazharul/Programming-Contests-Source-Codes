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
#define MAXN 100007
struct Data{
    Long t,w ;
    bool operator<(const Data&prev)const{
       // if(w!=prev.w)
       //     return w<prev.w ;
      if(t!=prev.t)  return t>prev.t ;
      else return w<prev.w ;
    }
};
vector<Data>ballons ;
Data me ,t;
int main(void){
    ios_base::sync_with_stdio(NULL) ; cin.tie(0);
    read() ;
    Long n ,cnt=1;
    mii disqualify ;
    mii::iterator it ;
    cin>>n>>me.t>>me.w ;
    rep(i,0,n-1){
        cin>>t.t>>t.w ;
        if(t.t>me.t){
            disqualify[t.w-t.t+1]++ ;
            cnt++ ;
        }else{
            ballons.pb(t) ;
        }
    }
    sort(all(ballons)) ;
    /*
    rep(i,0,sz(ballons)){
        cout<<ballons[i].t<<" "<<ballons[i].w<<endl ;
    }
    */
    int idx=0 ;
    Long res=cnt ;
 //   cout<<cnt<<endl ;
  //  Long tt=4 ;
    while(!disqualify.empty()){
        it = disqualify.begin() ;
    //    cout<<it->first<<endl ;
        me.t = me.t-it->first ;
        if(me.t<0) break ;
     //   if(me.t<me.w) break ; /// nije disqualify hoie zabe
        if(it->second==1){
            disqualify.erase(it) ;
        }else{
            it->second-- ;
        }
        cnt-- ;
       // cout<<me.t<<endl ;
        while(idx<sz(ballons) && ballons[idx].t>me.t){
              //  cout<<ballons[idx].w-ballons[idx].t<<endl ;
                disqualify[ballons[idx].w-ballons[idx].t+1]++ ;
                idx++ ;
                cnt++ ;
        }
        //if(idx==sz(ballons)) break ;
    //    cout<<cnt<<endl ;
   //     cout<<"-----------------"<<endl ;
        res=min(res,cnt) ;
    }
    cout<<res<<endl ;
    return 0 ;
}
