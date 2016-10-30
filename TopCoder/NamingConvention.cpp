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

struct NamingConvention{
string toCamelCase(string variableName)
{
    string ret="";
    int space = 1 ;
    for(int i=0;i<variableName.size();i++){
		if(variableName[i]=='_'){
			space++ ;
		}else{
			if(space==2){
				ret.push_back(variableName[i]+'A'-'a') ;
				space = 1 ;
			}else{
				ret.push_back(variableName[i]) ;
			}
		}
    }

    return ret;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
