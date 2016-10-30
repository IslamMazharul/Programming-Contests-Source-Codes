/* Millar-Rabin primality test  iteration signifies the accuracy of the test */
bool Millar(LL p,LL iteration){
	
	if(p<2 || p%2==0) return 0 ;	
	
	LL s = p-1 ;
	while(s%2) s /=2 ;
	for(int i=0;i<iteration;i++){
	   
	   LL a = rand()%(p-1)+1 ,temp = s ;
	   LL mod = BigMod(a,s,p) ;
	   while(mod!=1 && mod!=p-1 && temp!=p-1){    
		    mod = mulmod(mod,mod,p) ;
		    temp *=2 ;
		}
		if(mod!=p-1 && temp%2==0) return false ; 	
	}
	
	return true ;
	
}
