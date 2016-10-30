#include <bits/stdc++.h>
using namespace std;

struct SquareFreeString{
string isSquareFree(string s)
{
    string ret;
   // cout<<s<<endl ;
    bool res= 0 ;
    for(int sz=1;sz<=s.length();sz++){
		for(int st=0;st<s.length();st++){

            //check
            string temp = "" ;
            for(int k=0;k<sz;k++){
				if(st+k<s.length()){
					temp.push_back(s[st+k]) ;
				}
            }
          //  cout<<temp<<endl ;
            temp = temp+temp ;
            if(temp.length()>1 && s.find(temp)!=std::string::npos){
				//cout<<temp<<endl ;
				res=1 ;
            }
		}
    }
    if(res) return "not square-free" ;
		else return "square-free" ;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
