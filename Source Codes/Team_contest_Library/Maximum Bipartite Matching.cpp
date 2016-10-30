//========================================================Maximum Bipartite Matching (From igor) =================================//
//still n oac :(
// define M and N to be the maximum sizes of the left and right set respectively
bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int m, n;
bool bpm( int u ) {
    for( int v = 0; v < n; v++ ) if( graph[u][v] ) {
        if( seen[v] ) continue;
        seen[v] = true;
        if( matchR[v] < 0 || bpm( matchR[v] ) ) {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int main() {
    // Read input and populate graph[][]
    // Set m to be the size of L, n to be the size of RCPSC 490
Graph Theory: Network Flows and Matching
    memset( matchL, ­1, sizeof( matchL ) );
    memset( matchR, ­1, sizeof( matchR ) );
    int cnt = 0;
    for( int i = 0; i < m; i++ )
    {
        memset( seen, 0, sizeof( seen ) );
        if( bpm( i ) ) cnt++;
    }
    // cnt contains the size of the matching
    // matchL[i] is what left vertex i is matched to (or ­1 if unmatched)
    // matchR[j] is what right vertex j is matched to (or ­1 if unmatched)
    return 0;
}
