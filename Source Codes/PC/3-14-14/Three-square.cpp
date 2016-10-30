#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

#include <cmath>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
using namespace std ;
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
#define MAXN 50000+10
struct PRE{
	int a,b,c ;
};
PRE pre[MAXN] ;
bool visited[MAXN] ;
int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	int T,N ;
	for(int a=0;a<sqrt(MAXN) ;a++){
		for(int b=a;b<sqrt(MAXN);b++){
			for(int c=b;c<sqrt(MAXN);c++){
				if(a*a+b*b+c*c>MAXN) break ;
				if(visited[a*a+b*b+c*c]) continue ;
				pre[a*a+b*b+c*c].a = a ;
				pre[a*a+b*b+c*c].b = b ;
				pre[a*a+b*b+c*c].c = c ;
				visited[a*a+b*b+c*c] = 1 ;
			}
		}
	}
	cin>>T ;
	while(T--){
		cin>>N ;
		visited[N]?cout<<pre[N].a<<" "<<pre[N].b<<" "<<pre[N].c:cout<<"-1" ;
		cout<<"\n";
	}

	return 0;
}

