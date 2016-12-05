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
#define maxn 100+7
bool seen[maxn] ;
int deg[maxn] ,match[maxn] ,g[maxn][maxn] ;
int N ;
//////////////////////////////////////////GEO//////////////////////////////////////////////////////////////

double INF = 1e100;
double EPS = 1e-12;

struct PT {
  int x, y;
  PT() {}
  PT(int x, int y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b-a, c-d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

PT Pos[2*maxn+7] ;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool OK(int u,int v){

    PT a = Pos[u] ;
    PT b = Pos[v] ;
    rep(i,N,2*N){
        if(match[i]==-1) continue ;
        if(i==u || i==u || match[i]==u||match[i]==v) continue ;
        PT c = Pos[i] ;
        PT d = Pos[match[i]] ;
        if(SegmentsIntersect(a,b,c,d)) {
            //    cout<<"intersec"<<endl ;
                return 0 ;
        }
    }
    return 1 ;
}

bool bpm(int u){

  rep(i,0,deg[u]){
      int v=g[u][i] ;
      if(seen[v]) continue ;
      seen[v]=true ;
      /*
      rep(i,N,2*N){
        cout<<match[i]<<" " ;
      }
      cout<<endl ;
      */
      //cout<<"Trying to match "<<u<<" with "<<v<<endl ;
      if(match[v]==-1 || bpm(match[v])){
          if(!OK(u,v)) continue ;
          match[v] = u ;
          return 1 ;
      }
  }
  return 0 ;
}


int main(void){
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    read() ;
    while(cin>>N){
        mem(deg,0) ;
        rep(i,0,2*N){
            cin>>Pos[i].x>>Pos[i].y ;
        }
        rep(i,0,N){
            rep(j,0,N){
                g[i][deg[i]++] = j+N ;
                g[j+N][deg[j+N]++] = i ;
            }
        }
        mem(match,-1) ;
        rep(i,0,N){
            mem(seen,0) ;
            bpm(i) ;
        }
        rep(i,0,2*N) cout<<match[i]+1<<endl ;
    }
    return 0 ;
}

