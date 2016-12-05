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
#define MAXN 1000
int N,M ,Map[MAXN+7][MAXN+7],Map1[MAXN+7][MAXN+7];
ST Marks[MAXN+7] ;
pii joe,fire ;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
inline bool inside(int i,int j){
    if(i<0 || j<0 || i>=N || j>=M) return 0 ;
    return 1 ;
}
inline void BFS1(queue<pii> &Q){

    while(!Q.empty()){
        pii Top = Q.front() ; Q.pop() ;
        rep(i,0,4){
            int X = dir[i][0]+Top.first ;
            int  Y = dir[i][1]+Top.second ;
            if(inside(X,Y) && Map[X][Y]==-1 && Marks[X][Y]!='#'){
                Map[X][Y]=Map[Top.first][Top.second]+1 ;
                Q.push(mp(X,Y)) ;
            }
        }
    }
    return  ;
}

inline int BFS2(pii source){
    mem(Map1,-1) ;
    queue<pii>Q ;
    Q.push(source) ;
    Map1[source.first][source.second]=0 ;
    while(!Q.empty()){
        pii Top = Q.front() ; Q.pop() ;
        rep(i,0,4){
            int X = dir[i][0]+Top.first ;
            int Y = dir[i][1]+Top.second ;
            if(inside(X,Y) && Map1[X][Y]==-1 && Map[X][Y]>Map1[Top.first][Top.second]+1 && Marks[X][Y]!='#'){
               // cout<<X<<" "<<Y<<" "<<Map[X][Y]<<endl  ;
                Map1[X][Y]= Map1[Top.first][Top.second]+1 ;
                if(X==N-1 || Y==M-1) return Map1[X][Y] ;
                Q.push(mp(X,Y)) ;
            }
        }
    }
    return  -1;
}

int main(void){

    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    int testcase ;
    cin>>testcase ;
    while(testcase--){
        cin>>N>>M ;
        mem(Map,-1) ;
        queue<pii>Q ;
        rep(i,0,N) cin>>Marks[i] ;
        rep(i,0,N){
            rep(j,0,M){
                if(Marks[i][j]=='J'){
                    joe = mp(i,j) ;
                }
                else if(Marks[i][j]=='F'){
                    Q.push(mp(i,j)) ;
                    Map[i][j]=0 ;
                }
            }
        }

        BFS1(Q) ;
        Long res = BFS2(joe) ;
        if(res==-1) cout<<"IMPOSSIBLE"<<endl ;
        else cout<<res+1<<endl ;
    }
    return 0 ;
}

