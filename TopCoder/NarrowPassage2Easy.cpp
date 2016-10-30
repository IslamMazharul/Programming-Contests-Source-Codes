#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
bool dp[6][6][6][6][6][6] ;
int n,ret ;
void call(int a,int b,int c,int d,int e,int f,vector <int> &size,int &maxSizeSum){
	if(dp[a][b][c][d][e][f]) return ;
	dp[a][b][c][d][e][f] = 1 ;
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl ;
	ret++ ;
	if(size[a]+size[b]<=maxSizeSum){
		call(b,a,c,d,e,f,size,maxSizeSum) ;
	}
	if(size[b]+size[c]<=maxSizeSum){
		call(a,c,b,d,e,f,size,maxSizeSum) ;
	}
	if(size[c]+size[d]<=maxSizeSum){
		call(a,b,d,c,e,f,size,maxSizeSum) ;
	}
	if(size[d]+size[e]<=maxSizeSum){
		call(a,b,c,e,d,f,size,maxSizeSum) ;
	}
	if(size[e]+size[f]<=maxSizeSum){
		call(a,b,c,d,f,e,size,maxSizeSum) ;
	}


}
struct NarrowPassage2Easy{
int count(vector <int> size, int maxSizeSum)
{
    ret = 0 ;
    n = size.size() ;
    for(int i=n;i<6;i++){
			//cout<<"OL" ;
		size.push_back(maxSizeSum*2) ;
    }

    memset(dp,0,sizeof(dp)) ;
    call(0,1,2,3,4,5,size,maxSizeSum) ;
    return ret;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
