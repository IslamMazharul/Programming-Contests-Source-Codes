
void computeLPSArray(char *pat,int M,int *lps){

	int len = 0 ;
	int i = 1 ;
	lps[0] = 0 ;
	while(i<M){

		if(pat[i] == pat[len]){
			len++ ;
			lps[i] = len ;
			i++ ;
		}
		else{
			if(len!=0) len = lps[len-1] ;
			else{
				lps[i] = 0 ;
				i++ ;
			}
		}
	}
}

void KMPSearch(char *pat,char *txt){

	int M = strlen(pat) ;
	int N = strlen(txt) ;
	int *lps = (int *)malloc(sizeof(int)*M) ;
	int j = 0 ,i=0  ;  //the two pointers
	computeLPSArray(pat,M,lps) ;
	while(i<N){
		if(pat[j] == text[i]) { i++ ; j++ ; }
		if(j==M) {  printf("MATCH FOUND\n") ; j=lps[j-1] ; }
		else if(pat[j]!=txt[i]){
			if(j==0) i++ ;
			else j = lps[j-1] ;
			// Do not match lps[0..lps[j-1]] characters,
           // they will match anyway
		}
	}
}
