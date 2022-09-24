#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *link;
struct node { 
   char nome[50]; 
   link next;
   // int peso;
};
int MAX = 1009;
//Grafo
struct graph {
   int V;
   int A;
   link *adj; 
};
//Ponteiro para o grafo
typedef struct graph *Graph;

//lista de adjacência


int hashU(char *v){
  int h, a = 31415, b = 3011;
  for(h = 0; *v != '\0'; v++){
    a = a * b % (MAX - 1);
    h = (a*h + *v)% MAX;
  }
  return h;
}

//Função que adiciona nó na lista adjacência
static link NEWnode( char w[], link next) { 
   link a = malloc( sizeof (struct node));
   strcpy(a->nome, w) ;
   a->next = next;     
   return a;                         
}

//inicializa um grafo
Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A=0;
   G->adj = malloc( V * sizeof (link));
   for (int v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

//insere aresta no grafo (entender melhor)
void GRAPHinsertArc( Graph G, char pos[], char nome[]) {
   int hash_value = hashU(pos);
   for (link a = G->adj[hash_value]; a != NULL; a = a->next) 
      if (strcmp(a->nome, pos) == 0) return;
   G->adj[hash_value] = NEWnode( nome, G->adj[hash_value]);
   G->A++;
}

void dijkstra(Graph G, char s[], char destino[]){
   int posicao = hashU(s);
   int pa[MAX], dist[MAX];
   int mature[MAX];
   for (int v  = 0; v < G->V; v++){
      pa[v] = -1, mature[posicao] = 0, dist[v] = MAX;
   }
   pa[posicao]=1, dist[posicao] = 0;
   while (1){
      int min = MAX;
      int y;
      // Substituir para Priority Queue
      for(int z=0; z<G->V; z++){
         if(mature[z])continue;
         if(dist[z]<min)
            min = dist[z], y=z;
      }

      if (min == MAX)break;
      for (link a = G->adj[y];a!=NULL; a = a->next){
         // dica: calcular o hash do nome apenas uma vez e salvar na variável para evitar TLE
         int hash_value = hashU(a->nome);
         if (mature[hash_value])continue;
         if(dist[y]+1 < dist[hash_value]){
            dist[hash_value] = dist[y]+1;
            pa[hash_value] = y; 
            }
         } 
      mature[y] = 1;
   }
  
   
   
   // printf("o caminho mais curto é %d\n", dist[hashU(destino)]);
}

int main(void){
    int  a, qntV;
    scanf("%d %d", &qntV, &a);

    char nomeOrigemBusca[50], nomeDestinoBusca[50], nomeDestinoAresta[50], nomeOrigemAresta[50];
    scanf("%s %s", nomeOrigemBusca, nomeDestinoBusca);
   //  printf("%s %s\n", nomeOrigemBusca, nomeDestinoBusca);
    
    scanf("%d %d", &qntV, &a);
    
    Graph G = GRAPHinit(qntV);

   printf("================================\n");
   printf("Nomes e suas respectivas hashs\n");
   for (int i = 0; i < qntV; i++)
    {
      scanf("%s", nomeOrigemAresta);
      printf("> %s %d\n", nomeOrigemAresta, hashU(nomeOrigemAresta));
    }
   printf("================================\n");
   
   for (int i = 0; i < a; i++){
        scanf("%s %s", nomeOrigemAresta, nomeDestinoAresta);
        GRAPHinsertArc(G, nomeOrigemAresta, nomeDestinoAresta);
    }
    
    dijkstra(G, nomeOrigemBusca, nomeDestinoBusca);

    return 0;
}