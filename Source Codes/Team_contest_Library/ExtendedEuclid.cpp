
typedef pair<int,int>pii ;
pii extendedEuclid(int a,int b){

    if(b==0) return pii(1,0) ;
    else{
        pii d = extendedEuclid(b,a%b) ;
        return pii(d.second , d.first-d.second*(a/b)) ;
    }
}
