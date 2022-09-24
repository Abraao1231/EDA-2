


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <sys/types.h>

// #include <iostream.h>
// #include <iomanip.h>
#include <time.h> // por segundos()

#define MaxDim 100
#define Rand_Max 100000

// Protótipos

int encontrar(int);
void funion(int, int);
void seedRandom(unsigned int );
double randomn(void);
segundos duplos(void);

void gera_grafo(int , double);
void gera_grafo_sim(int , double);
void print_grafo(int);
void print_listas(int);
void constroi_lista(int);
void alcance(int, int);
void print_alcance(void);
void init_buscaP(void);
void buscaP(int);
void print_alc_buscaP(int);
void FordBellman(int);
void Prim(int);
void Dijkstra(int);
void Kruskal(void);
void Boruvka(int);

void AGM_buscaP(int, int);
void print_listas_AGM_B(int, int, int*);

// Variáveis ​​Globais

int MAdj[MaxDim][MaxDim];
int Dist[MaxDim][MaxDim];

int LisAdjP[MaxDim][MaxDim];
int LisAdjN[MaxDim][MaxDim];
int CardP[MaxDim];
int CardN[MaxDim];

int M_arcos; // Número de Arcos no Grafo
int I_arco[MaxDim*MaxDim]; // I_arco[k] Inicio(Origem) do Arco k
int J_arco[MaxDim*MaxDim]; // J_arco[k] Fim(Destino) do Arco k

int Hq, Tq;
int Dim;

int Q[MaxDim];
marca int[MaxDim];

int DistInfinita;

int AGM_LisAdjP[MaxDim][MaxDim];
int AGM_CardP[MaxDim];

// Programa Principal

int main()
{
	int v,a;
	flutuar falso;
	antros duplos;

	printf(" Digite o numero de vértices no grafo: ");
	scanf("%d", &Dim);

	printf(" Digite a densidade do grafo: ");
	scanf("%f", &faux);

	antros = falso;


	// Geração do Gráfico

	gera_grafo(Dim, dens);

	constroi_lista (Dim);

	// Gráfico Imprime

	print_grafo(Dim);


	printf("Tecle <enter>");
	obter();

	print_listas(Dim);


// printf("Digite o numero do vertice para saber seu alcance: ");
// scanf("%d",&v);
// printf("Digite o numero maximo de arestas: ");
// scanf("%d",&a);

// printf(" Alcance (Busca em Largura) \n");
// alcance(v, Dim);

	printf("Tecle <enter>");
	obter();

	printf("Boruvka \n");
    Boruvka(Dim);

	printf("Tecle <enter>");
	obter();


// printf(" CMC de %d aos demais vértices via ALg. Ford & Belman \n", v);
// FordBellman(v);
// printf("Tecle <enter>");
// pega();  

// Kruskal();
// Dijkstra(v);
// printf("Tecle <enter>");
// pega();  
//Prim(v);

// printf("Tecle <enter>");
// pega();

// init_buscaP();
// buscaP(v);

	printf("Tecle <enter>");
	obter();



/*
    v = 1;
	printf(" Kruskal \n");

	Kruskal();
	printf("Primeiro\n");

	Prim(v);
	obter();

    v = 1;
    init_buscaP();
	buscaP(v);
	print_alc_buscaP(v);

	alcance(v,Dim);
	print_alcance();
*/
	retorno(0);
}


// Algoritmo de Dijkstra para caminho mais curto de
// sa todos os outros.
//
// Só funciona se Dist[i][j] >= 0 para qualquer (i,j)


void Boruvka(int n)
{
     int i, j, p, ii, jj, iter, n_grupos;
     int grupo[MaxDim], minDist[MaxDim], minArco[MaxDim];
     int arco_usado[MaxDim*MaxDim];
     
     
     printf("\n Boruvka \nn=%d M_arcos=%d \n", n, M_arcos);
     for(i=1; i<=n; i++)
     {
       grupo[i] = i;
       AGM_CardP[i] = 0;
     }
     for(i=1; i<=M_arcos; i++)
     {
       arco_usado[i] = 0;
     }
     n_grupos = n;

     iter = 0;
     print_listas_AGM_B(n, iter, grupo);
     printf("Tecle <enter>");
	 obter();

     
     Faz
     {
       iter++;
                            
       // Inicializa Distancias Minimas para cada grupo
       for(i=1; i<=n_grupos; i++)
       {
         minDist[i]=DistInfinita;
       }
       
       // Encontrar o grupo mais próximo de cada grupo
       // a são correspondentes e distantes associadas
       for(j=1; j<=M_arcos; j++)
       {
          ii = I_arco[j]; jj = J_arco[j];
          if (grupo[ii] != grupo[jj])
          {
             if ( Dist[ii][jj] < minDist[grupo[ii]])
             {
                  minDist[grupo[ii]] = Dist[ii][jj];
                  minArco[grupo[ii]] = j;
             }
             if ( Dist[ii][jj] < minDist[grupo[jj]])
             {
                  minDist[grupo[jj]] = Dist[ii][jj];
                  minArco[grupo[jj]] = j;
             }
          }
       }
       // Insere as aresta nas arvore geradora minima AGM
       para (ii=1; ii<=n_grupos; ii++)
       {
           jj = minArco[ii];
           if (arco_usado[jj] == 0) // Se o arco nao foi usado
           {
            arco_usado[jj] = 1;
            
            i = I_arco[jj]; j = J_arco[jj];
			p = AGM_CardP[i] + 1;
			AGM_LisAdjP[i][p] = j;
			AGM_CardP[i] = p;
			p = AGM_CardP[j] + 1;
            AGM_LisAdjP[j][p] = i;
			AGM_CardP[j] = p;
           }
       }
       
       
       // Determina os grupos (componentes conexos) da AGM
       // (parcial), Se for um soh, um AGM foi feito.
              
       para (i=1; i<=n; i++)
       {
           marca[i] = 0;
       }
       
       n_grupos = 0;
       para (i=1; i<=n; i++)
       {
           if (marca[i] == 0)
           {
               n_grupos++;
               AGM_buscaP(i, n_grupos);
           }
       }       
       
       para (i=1; i<=n; i++)
       {
           grupo[i] = marca[i];
       }

       print_listas_AGM_B(n, iter, grupo);
	   printf("Tecle <enter>");
	   obter();
       
     }
     enquanto (n_grupos > 1);
}


//
// Busca em Profundidade na Floresta Construida
// ao longo do Algoritmo de Boruvka
//

void AGM_buscaP( int v, int rotulo)
{
     int cartão, w, i;
     
     cartão = AGM_CardP[v];
     para (i=1; i<=cartão; i++)
     {
		 w = AGM_LisAdjP[v][i];
         if (marca[w] == 0)
         {
             marca[w] = rotulo;
             AGM_buscaP(w, rotulo);
         }
     }
}

// Imprime listas AGM Boruvka

void print_listas_AGM_B(int n, int iter, int grupo[])
{
	int i,j,p;
	printf("\n Boruvka - Floresta Iter %d - Listas de Adjacências\n", iter);
	for(i=1; i<=n; i++)
	{
		printf("%d | Grupo %d | %d Arcos Saindo : ", i, grupo[i], AGM_CardP[i]);
		p = AGM_CardP[i];
		for(j=1; j<=p; j++)
		{
			printf("%d",AGM_LisAdjP[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}




//
// Caminho-mais-curto com custos não negativos
// Algoritmo de Dijkstra
//

void Dijkstra(int s)
{
	int v,w,k,l, vmin, dmin;
	int d_temp[MaxDim];
	int pred[MaxDim];
	int pos_prox[MaxDim];


    // Inicialização: d_temp contemcao um estimativa pessimista
	// da distância de salvamento

	for (v=1; v<=Dim; v++)
	{
		d_temp[v] = DistInfinita;
		pos_prox[v] = 0;
		pred[v] = -1;
	}

    // Caso Base - conhece-se o vértice mais próximo de s
	// (ele mesmo).

	d_temp[s] = 0;
	pred[s] = 0;

	k = 1;
	pos_prox[s] = k;


	// Agora pode-se atualizado como estimativas pessimistas
	// das distancias.

	for(l=1; l<=CardP[s]; l++)
	{
		v = LisAdjP[s][l];
		if (d_temp[v] > d_temp[s]+Dist[s][v])
		{
           d_temp[v] = d_temp[s]+Dist[s][v];
		   pred[v] = s;
		}
	}


    // Passo Indutivo
	// Conhece-se os k vértices mais próximos de s
	// Então conhece-se os k+1 vértices mais próximos de s

    // O k+1-ésimo mais próximo é o que possui o menor d_temp

    para (k=2; k<=Dim; k++)
	{
       // Encontra o k-ésimo vértice mais próximo de s

	   vmin = 0;
	   dmin = DistInfinita;
       for (v=1; v<=Dim; v++)
	   {
		   if ((d_temp[v] < dmin) && (pos_prox[v] == 0))
		   {
               vmin = v;
               dmin = d_temp[v];
		   }
	   }


       printf(" Vmin: %d DistMin: %d\n", vmin, dmin);

	   pos_prox[vmin] = k;


	  // Atualiza-se as estimativas dos pessimistas
	  // das distancias.

   	  for(l=1; l<=CardP[vmin]; l++)
	  {
	 	 v = LisAdjP[vmin][l];
		 if ( (pos_prox[v] == 0) && (d_temp[v] > d_temp[vmin] + Dist[vmin][v])) //d_temp[vmin]+Dist[s][v])
		 {
            d_temp[v] = d_temp[vmin] + Dist[vmin][v]; //d_temp[vmin]+Dist[s][v];
		    pred[v] = vmin;
		 }
	  }

	}

	// Distancias e caminhos mais curtos

	printf(" DIJKSTRA -- CMC a partir de %d \n",s);
	for (v=1; v<=Dim; v++)
	{
		printf(" %d D=%d %d-esimo mais proximo Caminho: ",
			v, d_temp[v], pos_prox[v]);
		w = v;
		enquanto (pred[w] > 0)
		{
			printf("%d",pred[w]);
			w = pred[w];
		}
		printf("\n");
	}

	for (v=1; v<=Dim; v++)
	{
			printf("Aresta: %d %d %d\n",v ,pred[v], Dist[v][pred[v]]);
    }

}

//================================================ ====





void Prim(int s)
{
	int v,w,k,l, vmin, dmin;
	int d_temp[MaxDim];
	int pred[MaxDim];
	int pos_prox[MaxDim];


    // Inicialização: d_temp contemcao um estimativa pessimista
	// da distância de salvamento

	for (v=1; v<=Dim; v++)
	{
		d_temp[v] = DistInfinita;
		pos_prox[v] = 0;
		pred[v] = -1;
	}


	d_temp[s] = 0;
	pred[s] = s;

	k = 1;
	pos_prox[s] = k;


	// Agora pode-se atualizado como estimativas pessimistas
	// das distancias.

	for(l=1; l<=CardP[s]; l++)
	{
		v = LisAdjP[s][l];
		if (d_temp[v] > Dist[s][v]) // d_temp[s]+Dist[s][v])
		{
           d_temp[v] = Dist[s][v];//d_temp[s]+Dist[s][v];
		   pred[v] = s;
		}
	}


    para (k=2; k<=Dim; k++)
	{

	   vmin = 0;
	   dmin = DistInfinita;
       for (v=1; v<=Dim; v++)
	   {
		   if ((d_temp[v] < dmin) && (pos_prox[v] == 0))
		   {
               vmin = v;
               dmin = d_temp[v];
		   }
	   }


       printf(" Vmin: %d DistMin: %d\n", vmin, dmin);

	   pos_prox[vmin] = k;


	  // Atualiza-se as estimativas dos pessimistas
	  // das distancias.

   	  for(l=1; l<=CardP[vmin]; l++)
	  {
	 	 v = LisAdjP[vmin][l];
		 if ( (pos_prox[v] == 0) && (d_temp[v] > Dist[vmin][v])) //d_temp[vmin]+Dist[s][v])
		 {
            d_temp[v] = Dist[vmin][v]; //d_temp[vmin]+Dist[s][v];
		    pred[v] = vmin;
		 }
	  }

	}

	// Distancias e caminhos mais curtos
/*
	printf(" PRIM - vértice inicial: %d\n",s);
	for (v=1; v<=Dim; v++)
	{
		printf(" %d D=%d %d-esimo mais proximo Caminho: ",
			v, d_temp[v], pos_prox[v]);
		w = v;
		enquanto (pred[w] > 0)
		{
			printf("%d",pred[w]);
			w = pred[w];
		}
		printf("\n");
	}
*/
	for (v=1; v<=Dim; v++)
	{
			printf("Aresta: %d %d %d\n",v ,pred[v], Dist[v][pred[v]]);
    }

}

//================================================ ====

int pont[MaxDim];
int rank[MaxDim];

int encontrar(int v)
{
    if (pont[v] != v)
    {
         return( find(pont[v]));
    }
    retorno(v);
}

void funion(int c1, int c2)
{
   if (classe[c1] <classe[c2])
   {
       pont[c1] = c2;
   }
   senão
   {
       pont[c2] = c1;
       if ( posto[c1] == posto[c2] )
       {
            posto[c1]++;
       }
   }
}


void Kruskal()
{
	int v,w,k,ll;
	int v1, v2, w1, w2, c1, c2;
	temperatura interna;
	int pred[MaxDim];
	int ind_sort[MaxDim*MaxDim];

    //izacao: Caso Base - Conhecendo o CMC de s
	// a todos os outros vértices usando no minimo ZERO
	// arcos.

	printf(" Kruskal MST 01 \n");

    // Init Union e Find ponteiros e ranks

	for (v=1; v<=Dim; v++)
	{
		pont[v] = v;
		posto[v] = 0;
	}

    // Encontra ordem crescente das arestas
	printf(" Kruskal MST 02 \n");

    para (k=1; k<=M_arcos; k++)
	{
        ind_sort[k] = k;
    }
    for (ll=1; ll<=M_arcos; ll++)
	{
		for(k=1; k<=M_arcos-1; k++)
		{
            v1 = I_arco[ind_sort[k]];
            w1 = J_arco[ind_sort[k]];
            v2 = I_arco[ind_sort[k+1]];
            w2 = J_arco[ind_sort[k+1]];
			if( Dist[v1][w1] > Dist[v2][w2])
			{
                temp = ind_sort[k];
                ind_sort[k] = ind_sort[k+1];
                ind_sort[k+1] = temp;
			}
		}
	}

	// Distancias e caminhos mais curtos
	printf("MST Kruskal \n");

    para (k=1; k<=M_arcos - 1; k++)
	{
         v = I_arco[ind_sort[k]];
         w = J_arco[ind_sort[k]];
         printf(" A %d %d %d\n", v, w, Dist[v][w]);


         c1 = encontrar(v);
         c2 = encontrar(w);

         se (c1 != c2)
         {
                printf(" Aresta %d %d %d\n", v, w, Dist[v][w]);
                funion(c1,c2);
         }
     }

}

// Algoritmo de FordBellman para caminho mais curto

void FordBellman(int s)
{
	int v,w,k,ll;
	int d_temp[MaxDim];
	int pred[MaxDim];
	int circ_neg;

	circ_neg = 0;

    //izacao: Caso Base - Conhecendo o CMC de s
	// a todos os outros vértices usando no minimo ZERO
	// arcos.

	for (v=1; v<=Dim; v++)
	{
		d_temp[v] = DistInfinita;
		pred[v] = -1;
	}

	d_temp[s] = 0;
	pred[s] = 0;


    // Passo Indutivo
	// Conhece-se o caminho mais curto de um vértice q usando
	// sem arcos maximo k-1.
	// Para obter o cmc de saq usando no maximo k arcos,
	// testa-se para cada arco no gráfico (v,w) se d_temp(v) + Dist[v][w]
	// e' menor que d_temp[w], em caso afirmativo o atual cmc de
	// viu nao e' um cmc e portanto atualizamos d_temp[w] e pred[w]

    para (k=1; k<=Dim - 1; k++)
	{

		for(ll=1; ll<=M_arcos; ll++)
		{
			v = I_arco[ll];
			w = J_arco[ll];
			if( d_temp[ v ] + Dist[v][w] < d_temp[w] )
			{
				d_temp[w] = d_temp[ v ] + Dist[v][w];
				pred[w] = v;
			}
		}

        /* Tempos de dist. Imprime atualizados */
	    for (v=1; v<=Dim; v++)
        {
		   printf(" %d D=%d Caminho: ",v, d_temp[v]);
		   w = v;
/* Faz
		   {
			  printf(" %d | %d ||", d_temp[w], pred[w]);
			  w = pred[w];
	       }
		   while ((w != v)&&(pred[w] > 0)); */
	       printf("\n");
        }
        obter();


	}

        obter();

	// Testa se existe circuito negativo

	for(ll=1; ll<=M_arcos; ll++)
	{
			v = I_arco[ll];
			w = J_arco[ll];
			if( d_temp[ v ] + Dist[v][w] < d_temp[w] )
			{
				d_temp[w] = d_temp[ v ] + Dist[v][w];
				pred[w] = v;
				printf("CIRCUITO NEGATIVO DETECTADO\n");
				circ_neg=1;
				w=v;
				Faz{
                    printf("ant v=%dw=%d\n",v,w);
					printf("%d",w);
					w = pred[w];
                    printf("dep v=%dw=%d\n",v,w);
                    obter();
				}
				while(w != v);
				printf("\n\n");

			}
	}

	
	// Distancias e caminhos mais curtos


    if(circ_neg == 0)
	{
	printf(" Ford Bellman -- CMC a partir de %d \n",s);
	for (v=1; v<=Dim; v++)
	{
		printf(" %d D=%d Caminho: ",v, d_temp[v]);
		w = v;
		enquanto (pred[w] > 0)
		{
			printf("%d",pred[w]);
			w = pred[w];
		}
		printf("\n");
	}
	}

}

// Imprime Alcance via busca em profundidade

void print_alc_buscaP(int v)
{
	int;
		printf("\n Vertices alcancaveis a partir de %d \n",v);

		for (i=1;i<=Dim;i++)
		{
			if( marca[i] == 1)
			{
				printf("%d",i);
			}
		}
		printf("\n");
}

// INicializa busca em profundidade

void init_buscaP()
{
	int;
		for (i=1;i<=Dim;i++)
		{
			marca[i] = 0;
		}

		printf("\n Busca em Prof INICIALIZADA \n");

}

// Busca em Profundidade a partir da Origem do Alcance

void buscaP(int v)
{
	int w,i;

    printf("%d\n",v);

	if (marca[v] == 0)
	{
		marca[v] = 1;
		for (i=1;i<=CartãoP[v];i++)
		{
			w=LisAdjP[v][i];
            printf("(%d,%d)",v,w);
			buscaP(w);
		}
	}
}


// Imprime Alcance

void print_alcance(void){
	int;
	printf("Os vértices atingidos são:\n");
	for(i=1;i<=Tq;i++){
		printf("%d", Q[i]);
	}
	printf("\n");
}

// Alcance: Busca em Largura (BFS- Breadth First Search)

void alcance(int v, int n){
	int u,i,k,j,w,I,F;

    // Inicializacao: Nenhum vertice foi alcancado (visitado) mark[w]=-1
    //
    // ao final, mark[w] contém a distância de vaw
    //
	for(i=1;i<=n;i++) marca[i]=-1;

    //
    // Teorema (K): Conhece-se todos os vértices a uma distancia K
    // do vértice v (distancia em numero de arestas)
    //


    //
    // Base do Caso: K=0
    //
    // O unico vértice eh o proprio vértice v
    //
	Q[1]=v;
	Hq=1;
	Tq=1;
	marca[v]=0;


	for(k=1;k<=n;k++){

        // Passo indutivo: Se Teo(K-1) eh verdade, ou seja, conhece-se todos a dist k-1
        // Entao Teo(K) eh verdade
        //
        //


        //
        // Prova para cada vértice com dist k-1 determinar
        // seus vizinhos que ainda não foram visitados: serao todos
        // os vértices a dist k.

        printf("Dist: %d %d\n",k,n);

		I=Hq;
		F=Tq; // Q[j] para j de I a F contem todos os vértices a dist k-1
		for (j=I;j<=F;j++){
		            //
			w=Q[j]; // nós um vértice a dist k-1 de v
			        //
			for (i=1;i<=CardP[w];i++){
				u=LisAdjP[w][i]; // u eh um vizinho de w, ou seja (w,u) estah em E
				if (marca[u]==-1){
					marca[u]=k;

					printf("%d",u);

					Q[++Tq]=u;
				}
			}
		}
		Hq=F+1;

        printf("\n");


	}
}

// Gera Grafo

void gera_grafo(int n, double dens)
{
	int i,j;

	M_arcos = 0;
	DistInfinita = 1;
	printf("\n\n Gerando Grafo Aleatório de Densidade: %f #Vértices: %d\n\n",dens,n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
		  if(i!=j)
		  {
            if(randomn() < dens)
			{
				M_arcos++;
				I_arco[M_arcos] = i;
				J_arco[M_arcos] = j;
				MAdj[i][j]=1;
				Dist[i][j]= 600 - (int)(randomn() * 1000.);
		        DistInfinita += Dist[i][j];
			}
			senão
			{
				MAdj[i][j]=0;
			}
          }
          senão
          {
			MAdj[i][j]=0;
          }
		}
	}

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(MAdj[i][j]==0)
			{
				Dist[i][j]=DistInfinita;
			}
		}
	}

}


// Gera Grafo Simetrico

void gera_grafo_sim(int n, double dens)
{
	int i,j;

	M_arcos = 0;
	DistInfinita = 1;
	printf("\n\n Gerando Grafo Aleatório de Densidade: %f #Vértices: %d\n\n",dens,n);
	for(i=1; i<=n; i++)
	{
		for(j=i; j<=n; j++)
		{
            if(i!=j)
            {
			    if(randomn() < dens)
			    {
				   M_arcos++;
				   I_arco[M_arcos] = i;
				   J_arco[M_arcos] = j;
				   MAdj[i][j]=1;
				   MAdj[j][i]=1;

				   Dist[i][j]= (int)(randomn() * 1000.);
				   Dist[j][i]= Dist[i][j];

				   DistInfinita += Dist[i][j];
                 }
				 senão
			     {
				   MAdj[i][j]=0;
				   MAdj[j][i]=0;
			     }
              }
              senão
			  {
				 MAdj[i][j]=0;
				 MAdj[j][i]=0;
			  }
        }
    }


	for(i=1; i<=n; i++)
	{
		for(j=i; j<=n; j++)
		{
			if(MAdj[i][j]==0)
			{
				Dist[i][j]=DistInfinita;
				Dist[j][i]=DistInfinita;
			}
		}
	}

}


// Imprime gráfico

void print_grafo(int n)
{
	int i,j;
	printf("\n GRAFO: Matriz de Adjacência\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d:%d %d ",i,j,MAdj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d:%d %d ",i,j,Dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//Constroi Lista de Adjacências

void constroi_lista(int n)
{
	int i,j,p;

	para (i=1; i<=n; i++)
	{
		CardP[i] = 0;
		CartãoN[i] = 0;
	}

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if (MAdj[i][j] == 1)
			{
				p = CardP[i] + 1;
				LisAdjP[i][p] = j;
				CardP[i] = p;

				p = CardN[j] + 1;
				LisAdjN[j][p] = i;
				CartãoN[j] = p;
			}
		}
	}

}


// Imprime listas

void print_listas(int n)
{
	int i,j, p, soma;
	soma = 0;
	printf("\n GRAFO: Listas de Adjacência\n");
	printf("\n Listas de Saida de Arcos \n");
	for(i=1; i<=n; i++)
	{
		printf("%d | %d Arcos Saindo : ", i, CardP[i]);
		p = CartãoP[i];
		for(j=1; j<=p; j++)
		{
			printf("%d",LisAdjP[i][j]);
		}
		printf("\n");
	}
	printf("\n Listas de Entrada de Arcos \n");
	for(i=1; i<=n; i++)
	{
		printf("%d | %d Arcos Chegando : ", i, CardN[i]);
		p = CartãoN[i];
		for(j=1; j<=p; j++)
		{
			printf("%d",LisAdjN[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


// Rotinas dependentes do sistema
// Arquivo: system.cpp


void seedRandom(unsigned int seed)
// semente para gerador de números aleatórios.
{
  srand(semente);
  Retorna;
}

double randomn(void)
// número aleatório entre 0,0 e 1,0 (não incluído).
{
  duplo rr;

  rrr = (duplo) rand() / (duplo) RAND_MAX;
  retorna rr;
}

segundos duplos()
// tempo de CPU em segundos desde o início da execução.
{
  segundos duplos;

  segundos = (double)(clock() / 1000,0);
  retorno(s);
}
