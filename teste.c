
int dijkstra(int s, int d, int MAX) {  
   int min, at, proc[MAX], prev[MAX], dist[MAX], g[MAX][MAX], vert;       

   

   for (int i=1; i<=vert;i++) {
       prev[i]=-1;
       dist[i]=MAX;
       proc[i]=0;
   }

   dist[s] = 0;
   vert = s;

   while (at != d) {
       for (int i=1; i<=vert;  i++) {
           if (dist[i] > dist[at] + g[at][i]) {
               dist[i] = dist[at] + g[at][i];
           }
       }
       min = MAX;
       proc[vert]=1;
       for (int i=1; i<=vert; i++) {
           if ((dist[i]<min) && (!proc[i])) {
               min = dist[i];
               at = i;
           }
       }
       if (min == MAX) {
      	 return MAX;
       }
   }
   return dist[d];
}