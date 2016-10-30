#include <bits/stdc++.h>
using namespace std ;
#define MAXN 1000007

vector<string>v[MAXN] ;
map<string,int>mp ;
map<string,int>::iterator it ;
int idx ,inrolled[MAXN];

struct COURSE{

    string original_name ;
    string course_name ;
    int id  , num ;
    bool operator <(const COURSE &prev)const{
        //if(num!=prev.num) return num < prev.num ;
        return original_name < prev.original_name ;
    }
};

vector<COURSE>vv ;
vector<COURSE>::iterator it1  ;
int getID(string course){

    it = mp.find(course) ;
    if(it==mp.end()) {

          //  cout<<course<<endl ;
        int num = 0 ;
    string s = "" ;
        for(int i=0;i<course.size();i++){
            if( isdigit(course[i]) ){
                num = num*10+course[i]-'0' ;
            }else s.push_back(course[i]) ;
        }
        COURSE tmp ;
        tmp.num = num ;
        tmp.id = idx ;
    //    cout<<s<<endl ;
        tmp.course_name = s ;
        tmp.original_name = course ;
        vv.push_back(tmp) ;
        mp[course] = idx++ ;
    }

    return mp[course] ;
}

int main(void){

    freopen("in.txt","r",stdin) ;
    string nam1,nam2,name,co ;
    int n ;
    cin>>n ;
    for(int i=0;i<n;i++){
        cin>>nam1>>nam2>>co ;
        name = nam1+"+"+nam2 ;
        int id = getID(co) ;
        v[id].push_back(name) ;
    }

    for(int i=0;i<idx;i++){
        sort(v[i].begin(),v[i].end() ) ;
    }

    for(int i=0;i<idx;i++){
        if(!v[i].empty()) inrolled[i] = 1 ;
        for(int j=1;j<v[i].size();j++){
                if(v[i][j-1]!=v[i][j]) inrolled[i]++ ;
        }
    }

    sort(vv.begin(),vv.end()) ;

    for(it1=vv.begin();it1!=vv.end();it1++){

        string ss = it1->original_name ;
        int id  = it1->id ;
        cout<<ss<<" "<<inrolled[id]<<"\n" ;
    }

    return 0 ;
}
