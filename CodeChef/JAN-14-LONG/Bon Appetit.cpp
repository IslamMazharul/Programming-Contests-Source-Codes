#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define maxn 100001
#define inf 1110000001
using namespace std ;
struct data{
    int s,e,p ;
    bool operator<(const data &prev)const{
        if(p!=prev.p) return p<prev.p ;
        else if(e!=prev.e) return e<prev.e ;
		return s>prev.s ;
    }
};

data d[maxn] ;
int n,k,I[maxn+100] ;

int LisNlogk(int s,int e){
	//cout<<s<<" "<<e<<"\n" ;
	I[s] = -inf ;

	FOR(i,s+1,e+10) I[i] = inf ;
	int LisLength = s,lo,mid,hi ;
	FOR(i,s,e+1){
		lo = s ;
		hi = LisLength ;
		while(lo<=hi){
			//cout<<lo<<" "<<hi<<"\n" ;
			mid = (lo+hi)/2 ;
			if(I[mid]<d[i].s) lo = mid+1 ;
			else hi = mid-1 ;
		}
		if(lo<=LisLength) I[lo] = min(I[lo],d[i].e-1) ;
		else {
				I[lo] = d[i].e-1 ;
				LisLength = lo ;
		}
		//cout<<I[lo]<<" "<<lo<<"\n" ;
	}
   // cout<<LisLength-s-1<<"\n" ;
	//FOR(i,s,LisLength+1) cout<<I[i]<<" " ;
	//cout<<"\n" ;
	return LisLength ;
}

int main(int argc,char** argv){

    #ifdef _unlucky_13
    freopen("C:\\Users\\Mazharul islam\\Desktop\\in.txt","r",stdin) ;
    #endif
    int testcases;
	ios_base::sync_with_stdio(false);
	cin>>testcases ;
    while(testcases--){
        cin>>n>>k ;
        FOR(i,0,n){
			cin>>d[i].s>>d[i].e>>d[i].p ;
        }
        sort(d,d+n) ;
       // FOR(i,0,n) cout<<d[i].s<<" "<<d[i].e<<" "<<d[i].p<<"\n" ;
        int res = 0 ,j,i=0;
        //memset(flag,0,sizeof(flag)) ;
        while(i<n){
          j = i ;
		  while((j+1)<n && d[j+1].p==d[i].p) j++ ;
		  int lis = (LisNlogk(i,j)-i) ;
		  res +=lis ;
		  i = j+1 ;
        }

        cout<<res<<"\n" ;
    }

    return 0 ;

}
