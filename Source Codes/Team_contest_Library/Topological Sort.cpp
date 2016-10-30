for each vertex u in V[G]
do color[u] ← WHITE
π[u] ← NIL ▷ π[] is parent array
time ← 0
for each vertex u in V[G]
do if color[u] ← WHITE
then DFS-Visit(u) ▷ build a new DFS-tree from u

DFS-Visit(u)

color[u] ← GRAY ▷ discover u
time ← time + 1 ▷ stopwatch
d[u] ← time
for each vertex v adjacent to u ▷ explore (u, v)
do if color[v] ← WHITE
then π[v] ← u ▷ saving parent to print path
DFS-Visit(v)
color[u] ← BLACK

f[u] ← time ▷ we are done with u
