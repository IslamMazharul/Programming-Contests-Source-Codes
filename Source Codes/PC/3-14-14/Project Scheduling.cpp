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
#define MAXN 33
int tim[MAXN],res ;
bool visited[MAXN] ;
vector<int>Graph[MAXN] ;
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
int  DFS(int u){

	int Len = Graph[u].size()-1 ;
	int ret = 0 ;
	visited[u] = 1 ;
	FOR(i,0,Len){
		int v = Graph[u][i] ;
		if(!visited[i] && tim[i]!=-1){
			DFS(v) ;
		}

		ret = max(ret,tim[v]) ;
	}

	tim[u] += ret ;

}
int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	int T,n,_tim ;
	string line;
	char ch,u,v ;
	cin>>T ;
	///////////////////////////////////////////////////////////////////
	getline(cin,line) ;
	getline(cin,line) ;
	//////////////////////////////////////////////////////////////////
	while(T--){

		FOR(i,0,MAXN){
			Graph[i].clear() ;
			tim[i] = -1 ;
		}
		memset(visited,0,sizeof(visited)) ;
		res = -  1 ;

		while(getline(cin,line)){

			stringstream buffer(line) ;
			if(line[0]=='\0') break ;

			buffer>>ch ;
			buffer>>_tim ;
			tim[ch-'A'] = _tim ;
			while(buffer>>u){
				Graph[ch-'A'].push_back(u-'A') ;
			}


		}


		FOR(i,0,MAXN){
			if(!visited[i] && tim[i]!=-1){
				DFS(i) ;
				res = max(res,tim[i]) ;
				//cout<<res<<endl ;
			}
		}

		cout<<res<<"\n" ;
		if(T) cout<<"\n" ;
	}

	return 0;
}


