///             From shanto sir
#define MAXN 100007
struct info
{
	int sum[3],prop;
}tree[MAXN*3];
int arr[MAXN] ;
void init(int node,int b,int e){
	if(b==e){
		tree[node].sum[0]=1 ;
		tree[node].sum[1]=tree[node].sum[2]=0 ;
		tree[node].prop=0 ;
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);

	rep(i,0,3){
        tree[node].sum[i]=tree[Left].sum[i]+tree[Right].sum[i] ;
	}
}


void makeChanges(int node,int b,int e){

    tree[node].prop%=3 ;
    int prop = tree[node].prop ;
    if(prop==0) return ;
    int T1,T2,T0 ;
    T0 = tree[node].sum[0]  ;
    T1 = tree[node].sum[1] ;
    T2 = tree[node].sum[2] ;


    tree[node].sum[prop%3] = T0 ;
    tree[node].sum[(prop+1)%3] = T1 ;
    tree[node].sum[(prop+2)%3] = T2 ;

  //  int T = tree[node].sum[2] ;
   // tree[node].sum[2]=tree[node].sum[1] ;
   // tree[node].sum[1]=tree[node].sum[0] ;
   // tree[node].sum[0]=T ;
   // tree[node].prop-- ;


    tree[node].prop=0 ;
    int Left = node*2 ;
    int Right = node*2+1 ;
    if(b!=e){
        tree[Left].prop+=prop ;
        tree[Right].prop+=prop ;
    }
}

int query(int node,int b,int e,int i,int j){

	if (i > e || j < b)		return 0 ;
    if(tree[node].prop!=0){
                makeChanges(node,b,e) ;
    }

	if(b>=i and e<=j) {
        //    cout<<b<<" "<<e<<" "<<tree[node].sum[0]<<endl ;
            return tree[node].sum[0] ;
	}

	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

    int p1 = query(Left, b,mid,  i, j);
    int p2 = query(Right, mid+1, e, i, j);
    return  p1+p2;
}

void update(int node,int b,int e,int i,int j){

	if (i > e || j < b)	return ;
	if(tree[node].prop!=0){
        makeChanges(node,b,e) ;
    }

	if (b >= i && e <= j)
	{
            tree[node].prop++ ;
            return;
	}

	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j);
	update(Right,mid+1,e,i,j) ;
    makeChanges(Left,b,mid) ;
    makeChanges(Right,mid+1,e) ;


	rep(i,0,3){
        tree[node].sum[i]=tree[Left].sum[i]+tree[Right].sum[i] ;
	}
}
