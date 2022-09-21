#include <stdio.h>
#include <stdlib.h>
/*
    N -> Número de pessoas
    A -> Número de apertos
*/

//Grafo
struct graph {
   int V; 
   int A; 
   link *adj; 
};
//Ponteiro para o grafo
typedef struct graph *Graph;

//lista de adjacência
typedef struct node *link;
struct node { 
   int w; 
   link next; 
};

//Função que adiciona nó na lista adjacência
static link NEWnode( int w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

//inicializa um grafo
Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (int v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

//insere aresta no grafo (entender melhor)
void GRAPHinsertArc( Graph G, int v, int w) { 
   for (link a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

int main(void){
    int n, a, qntV, qntA;
    scanf("%d %d", &n, &a);

    int nomeOrigem[50], nomeDestino[50];
    scanf("%s %s", nomeOrigem, nomeDestino);
    for (int i = 0; i < n; i++)
    {
        // Ler e inserir Vertice
        qntV = i+1;
    }
    for (int i = 0; i < a; i++){
        // Ler e inserir aresta
        qntA = i+1;
    }
    
    // Buscar

    return 0;
}