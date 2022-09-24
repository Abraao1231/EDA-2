#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *link;
struct node { 
   char nome[50]; 
   link next; 
};

//Grafo
struct graph {
   link *adj; 
};
//Ponteiro para o grafo
typedef struct graph *Graph;

//lista de adjacência


int hashU(char *v){
  int h, a = 31415, b = 2803;
  for(h = 0; *v = '\0'; v++){
    a = a * b % (1009 - 1);
    h = (a*h + *v);
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
   G->adj = malloc( V * sizeof (link));
   for (int v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}



//insere aresta no grafo (entender melhor)
void GRAPHinsertArc( Graph G, char pos[], char nome[]) { 
   for (link a = G->adj[hashU(pos)]; a != NULL; a = a->next) 
      if (strcmp(a->nome, pos) == 0) return;
   G->adj[hashU(pos)] = NEWnode( nome, G->adj[hashU(pos)]);
}

int main(void){
    int  a, qntV;
    scanf("%d %d", &qntV, &a);

    char nomeOrigemBusca[50], nomeDestinoBusca[50], nomeDestinoAresta[50], nomeOrigemAresta[50];
    scanf("%s %s", nomeOrigemBusca, nomeDestinoBusca);
    scanf("%d %d", &qntV, &a);
    Graph G = GRAPHinit(qntV);

    for (int i = 0; i < qntV; i++)
    {
      scanf("%s", nomeOrigemAresta);
    }
    for (int i = 0; i < a; i++){
        scanf("%s %s", nomeOrigemAresta, nomeDestinoAresta);
        GRAPHinsertArc(G, nomeOrigemAresta, nomeDestinoAresta);
    }
    
    // Buscar

    return 0;
}