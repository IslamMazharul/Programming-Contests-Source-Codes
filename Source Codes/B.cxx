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
#define MAXN 101
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
#define LL long long
#define pp pair<int,int>
char array[1000][2000] ;
int main(int argc, char **argv){
	memset(array,-1,sizeof(array)) ;
	int n ,a[MAXN];
	cin>>n ;
	FOR(i,0,n-1) cin>>a[i] ;
	vector<pp>points ;
	int X = 0 , Y =  0 ;
	points.push_back(pp(X,Y)) ;
	int mini = 10000000 ;
	int maxi = -1000000 ;
	FOR(i,0,n-1){
		X +=a[i] ;
		if(i%2==0) Y+=a[i] ;
		else Y-=a[i] ;
		mini = min(Y,mini) ;
		maxi  = max(maxi,Y) ;
		points.push_back(pp(X,Y)) ;
	}

	//FOR(i,0,n) cout<<points[i].first<<" "<<points[i].second<<endl ;
	FOR(i,0,n-1){
		char c ;
		if(points[i].second>points[i+1].second) c = '\\' ;
		else c = '/' ;
		int Y =  points[i].second ;
		FOR(j,points[i].first,points[i+1].first){
			array[j][Y+10000] = c ;
			Y++ ;
		}
	}

	FOR(i,0,points[n].first){
		FOR(j,mini+10000,maxi+10000){
			if(array[i][j]!=-1) cout<<array[i][j]<<" " ;
		}
	}


	return 0;
}

