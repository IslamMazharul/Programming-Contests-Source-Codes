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
#define MAXN
#define FOR(i,a,b) for(int i=(int) a ; i<=(int)b;i++)
struct POINT{
	double x,y ;
};

struct SEGMENTS{
	POINT s,e ;
};

SEGMENTS segments[101] ;
double ccw(POINT &Pi, POINT &Pj, POINT &Pk){

    return (Pj.x-Pi.x)*(Pk.y-Pi.y)-(Pk.x-Pi.x)*(Pj.y-Pi.y);
}
/////////////////////////////////////////////////// Rem this function///////////////////////////////////////////////////////////////////////////////
bool intersection(POINT &a,POINT &b,POINT &p,POINT &q){

    if(
	min(a.x,b.x)<=max(p.x,q.x) &&
	min(p.x,q.x)<=max(a.x,b.x) &&
	min(a.y,b.y)<=max(p.y,q.y) &&
	min(p.y,q.y)<=max(a.y,b.y) &&
	ccw(a,b,p)*ccw(a,b,q)<=0 &&
	ccw(p,q,a)*ccw(p,q,b)<=0

	)

	return 1;

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv){
	#ifdef unlucky_13
		freopen("C:\\Users\\User\\Documents\\in.txt","r",stdin) ;
	#endif
	ios_base::sync_with_stdio(false) ;
	int T ,n ;
	cin>>T ;
	while(T--){
		cin>>n ;

		FOR(i,0,n-1){
			cin>>segments[i].s.x>>segments[i].s.y>>segments[i].e.x>>segments[i].e.y ;
		}

		int res = 0 ;
		FOR(i,0,n-1){
			bool intersect = false ;
			FOR(j,0,n-1){

				if(i==j) continue ;
				intersect = intersection(segments[i].s,segments[i].e,segments[j].s,segments[j].e)  ;
				if(intersect) break ;
			}

			res += (!intersect) ;
		}

		cout<<res<<"\n" ;
	}

	return 0;
}


