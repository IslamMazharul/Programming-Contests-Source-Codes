/*
 * Mazharul Islam , BUET
 * Problem Link:http://acm.hust.edu.cn/vjudge/contest/view.action?cid=120288#problem/I
 */
using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define endl "\n"
typedef long long  i64;
typedef unsigned long long uint;
typedef string ST;
typedef vector<int> vi;
typedef vector<ST> vs;
typedef map<int,int> mii;
typedef map<ST,int> msi;
typedef set<int> si;
typedef set<ST> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define deb(x) cerr << #x << " = " << x << endl;
#define MAXN 1000007
struct Element
{
	int Lsum,Rsum,Tsum,Msum,LLsum,RRsum ;
};

Element tree[MAXN*3];
int arr[MAXN] ;

void init(int node,int b,int e){
	if(b==e){
		tree[node].Lsum=tree[node].Rsum=tree[node].Msum=tree[node].Tsum=arr[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);

    tree[node].Lsum=max(tree[Left].Lsum,tree[Left].Tsum+tree[Right].Lsum) ;
    tree[node].Rsum=max(tree[Right].Rsum,tree[Right].Msum+tree[Left].Rsum) ;
    tree[node].Tsum = tree[Left].Tsum+tree[Right].Tsum ;
    tree[node].Msum = max(max(tree[Right].Msum,tree[Left].Msum),tree[node].Tsum) ;
}
Element query(int node,int b,int e,int i,int j){
	if(i<=b && e<=j) {
    //       cout<<b<<" "<<e<<" "<<tree[node].Msum<<endl ;
            return tree[node] ;
	}

	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    Element ret ;
    if(j<=mid){
            ret = query(Left,b, mid,i, j) ;
    }
    else if(i>mid){
            ret = query(Right,mid+1,e,i,j) ;
    }
    else{
        Element p1 = query(Left, b,mid,  i, j);
        Element p2 = query(Right, mid+1, e, i, j);
        ret.Lsum=max(p1.Lsum,p1.Tsum+p2.Lsum) ;
        ret.Rsum=max(p2.Rsum,p2.Msum+p1.Rsum) ;
        ret.Tsum = p1.Tsum+p2.Tsum ;
        ret.Msum = max(max(p2.Msum,p1.Msum),p1.Tsum+p1.Tsum) ;
    }
   // cout<<b<<" "<<e<<" "<<ret.Msum<<endl ;
    return ret ;
}

void update(int node,int b,int e,int i,int j,int val){

	if (i > e || j < b)	return ;
	if (b >= i && e <= j)
	{

            tree[node].Lsum=tree[node].Rsum=tree[node].Msum=tree[node].Tsum=val ;
          //  cout<<b<<" "<<e<<" "<<tree[node].Msum<<endl ;
            return;
	}

	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j,val);
	update(Right,mid+1,e,i,j,val) ;
    tree[node].Lsum=max(tree[Left].Lsum,tree[Left].Tsum+tree[Right].Lsum) ;
    tree[node].Rsum=max(tree[Right].Rsum,tree[Right].Msum+tree[Left].Rsum) ;
    tree[node].Tsum = tree[Left].Tsum+tree[Right].Tsum ;
    tree[node].Msum = max(max(tree[Right].Msum,tree[Left].Msum),tree[node].Tsum) ;
 //   cout<<b<<" "<<e<<" "<<tree[node].Msum<<endl ;
}

int main(){
    read("in.txt") ;
    int N,M ,op,l,r;
    scanf("%lld",&N) ;
    rep(i,1,N+1){
        scanf("%lld",&arr[i]) ;
    }
    scanf("%lld",&M) ;
    init(1,1,N) ;

    while(M--){
        scanf("%d%d%d",&op,&l,&r) ;
        if(op==0){
            //cout<<r-arr[l]<<endl ;
            arr[l]=r ;
            update(1,1,N,l,l,arr[l]) ;
            //arr[l]=r ;
        }
        else{
            Element res=query(1,1,N,l,r) ;
            printf("%d\n",res.Msum) ;
        }
    }
    return 0;
}




