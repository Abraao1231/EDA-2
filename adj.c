#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node *link;
struct node { 
   char nome[50]; 
   link next;
   int c;
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



int fakehash[1010];
int deshash[1010];
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
   a->c = 1;
   return a;                         
}

//inicializa um grafo
Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V;
   G->A=0;
   G->adj = malloc( 20000 * sizeof (link));
   for (int v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

//insere aresta no grafo (entender melhor)
void GRAPHinsertArc( Graph G, char pos[], char nome[]) {

   for (link a = G->adj[hashU(pos)]; a != NULL; a = a->next) 
      if (strcmp(a->nome, pos) == 0) return;
    G->adj[hashU(pos)] = NEWnode( nome, G->adj[hashU(pos)]);
    G->adj[hashU(nome)] = NEWnode( pos, G->adj[hashU(nome)]);
    G->A++;
}
int VALOR_ALTO = 999999;

int pa[1009]; int dist[1009];
void dijkstra(Graph G, int s ,int * pa, int *dist){

    bool mature [MAX];
    
    for(int v = 0; v < G->V;v++){pa[v] = -1; mature[v] = false; dist[v] = VALOR_ALTO;}
    pa[fakehash[s]] = s; dist[fakehash[s]] = 0;
    while(true){
        int y;
        int min = VALOR_ALTO;
        
        // Implementação sem Priority 
        for(int z = 0; z < G->V; z++){
            if(mature[z]) continue;
            if(dist[z] < min){
                min = dist[z];y=deshash[z];
            }
        }      
        
          
        if (min == VALOR_ALTO) break;
        for(link a = G->adj[y]; a != NULL; a = a->next){
            int hashv = hashU(a->nome);
            if(mature[fakehash[hashv]]) continue;
            if(dist[y] + a->c < dist[fakehash[hashv]]){
                dist[fakehash[hashv]] = dist[fakehash[y]] + a->c;
                
                pa[fakehash[hashv]] = fakehash[y];
            }
        } 

        mature[fakehash[y]] = true;
    }    
 }


int main(void){
    int  a, qntV;
    scanf("%d %d", &qntV, &a);

    char nomeOrigemBusca[50], nomeDestinoBusca[50], nomeDestinoAresta[50], nomeOrigemAresta[50];
    scanf("%s %s", nomeOrigemBusca, nomeDestinoBusca);
    for (int i = 0; i < 1010; i++) fakehash[i] = -1;
    scanf("%d %d", &qntV, &a);
    
    Graph G = GRAPHinit(qntV);

   int vertice = 0;
   for (int i = 0; i < qntV; i++)
    {
        scanf("%s", nomeOrigemAresta);
        deshash[vertice] = hashU(nomeOrigemAresta);
        fakehash[hashU(nomeOrigemAresta)] = vertice++;

    }
   
   for (int i = 0; i < a; i++){
        scanf("%s %s", nomeOrigemAresta, nomeDestinoAresta);
        GRAPHinsertArc(G, nomeOrigemAresta, nomeDestinoAresta);
    }
   
    dijkstra(G, hashU(nomeOrigemBusca), pa, dist);
    int resultado = dist[fakehash[hashU(nomeDestinoBusca)]];
    
    if(resultado == VALOR_ALTO)
        printf("%d\n", -1);
    else
        printf("%d\n", resultado);
    
    return 0;
}