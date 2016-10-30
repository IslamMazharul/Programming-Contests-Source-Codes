struct node{
 bool endmark ;
 node *next[26+1] ;
 node(){
    endmrk = 0 ;
    for(int i=0;i<26;i++){
        next[i] = NULL ;
    }
 }
}*root ;

void insert(char *str,int len){
    node *curr  = root ;
    for(int i=0;i<len;i++){
        int id = str[i]-'a' ;
        if(curr->next[id]==NULL){
            curr->next[id] = new node ;
            curr = curr->next[id] ;
        }

        curr->endmark = 1 ;
    }
}
bool search(char *str,int len){
    node *cur = root ;
    for(int i=0;i<len;i++){
        int id = str[i]-'a' ;
        if(cur->next[id]==NULL) return 0 ;
        cur = cur->next[id] ;
    }
    return curr->endmark ;
}
void del(node *cur){
    for(int i=0;i<26;i++){
        if(cur->next[i]){
            del(cur->next[i]) ;
        }
    }
    delete(cur) ;
}
