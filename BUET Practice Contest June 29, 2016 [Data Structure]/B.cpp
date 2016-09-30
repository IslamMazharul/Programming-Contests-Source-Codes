/*
 * Mazharul Islam , BUET
 * Problem Link:http://acm.hust.edu.cn/vjudge/contest/view.action?cid=120288#problem/B
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
typedef int i64;
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
#define MAXN 100001
struct info
{
	int max1,max2;
}tree[3*MAXN];
int arr[MAXN] ;

void makeChanges(int node){

    int Right=(node<<1)+1 ;
    int Left = node<<1 ;

    if(arr[tree[Right].max1]>arr[tree[Left].max1]){
        tree[node].max1=  tree[Right].max1 ;
        tree[node].max2 = tree[Left].max1 ;
	}else{
        tree[node].max1=tree[Left].max1 ;
        tree[node].max2=tree[Right].max1 ;
	}

	if(arr[tree[Right].max2]>arr[tree[node].max2]){
        tree[node].max2=tree[Right].max2 ;
	}
	if(arr[tree[Left].max2]>arr[tree[node].max2]){
        tree[node].max2=tree[Left].max2 ;
	}
}

void init(int node,int b,int e){

   // cout<<b<<" "<<e<<endl ;
	if(b==e){
		tree[node].max1=e ;
		tree[node].max2=0 ;
	//	return;
	}
    else{
        int Left=node*2;
        int Right=node*2+1;
        int mid=(b+e)/2;
        init(Left,b,mid);
        init(Right,mid+1,e);
        makeChanges(node) ;
    }
	//cout<<b<<" "<<e<<" "<<tree[node].max1<<" "<<tree[node].max2<<endl ;
}

pii getResult(pii p1,pii p2){

    pii ret ;
    if(arr[p1.xx]>arr[p2.xx]){
        ret.xx=p1.xx ;
        ret.yy=p2.xx ;
    }
    else{
        ret.xx=p2.xx ;
        ret.yy=p1.xx ;
    }

    if(arr[ret.yy]<arr[p1.yy]){
        ret.yy=p1.yy ;
    }
    if(arr[ret.yy]<arr[p2.yy]){
        ret.yy=p2.yy ;
    }
    return ret ;
}

pii query(int node,int b,int e,int i,int j){

	if (i > e || j < b)		return mp(0,0) ;

	if(b>=i and e<=j) return mp(tree[node].max1,tree[node].max2) ;
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    pii p1 = query(Left, b,mid,i,j);
    pii p2 = query(Right, mid+1, e,i,j);
    return getResult(p1,p2) ;
}
void update(int node,int b,int e,int pos){
   // cout<<b<<" "<<e<<endl ;
	if (pos > e || pos < b)	return;
	if(b==e){
            return ;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,pos);
	update(Right,mid+1,e,pos);
	makeChanges(node) ;
}

int main(){
    read("in.txt") ;
    int n ,l,r;
    char op[3] ;
    scanf("%d",&n) ;
    arr[0]=-100000000 ;
    rep(i,1,n+1){
        scanf("%d",&arr[i]) ;
    }
    init(1,1,n) ;
    int q ;
    scanf("%d",&q) ;
    while(q--){
        scanf("%s %d %d",&op,&l,&r) ;
        if(op[0]=='Q'){
                pii res= query(1,1,n,l,r) ;
                printf("%d\n",arr[res.xx]+arr[res.yy]) ;
        }else{
            arr[l]=r ;
            update(1,1,n,l) ;
        }
    }
    return 0;
}

