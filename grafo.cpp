#include "grafo.h"

void inicializaGrafo(Grafo &G) {
    G.ordem = MAX_TAM;
    G.g = criaMatrizAdj(G.ordem);
    for(int i = 0; i < G.ordem; ++i) {
        for(int j = 0; j < G.ordem; ++j)
            G.g[i][j] = 0;
    }
}

int **criaMatrizAdj(int n) {
    int** m = new int*[n];
    for(int i = 0; i < n; ++i) {
        m[i] = new int[n];
    }
    return m;
}

void insereAresta(Grafo &G, int a, int b) {
    if(G.g[a][b] == 0)
        G.g[a][b] = 1;
}

void insereArestaPonderada(Grafo &G, int a, int b, int w) {
    if(G.g[a][b] == 0)
        G.g[a][b] = w;
}

void buscaProfundidadeRec(int **M, bool *visitado, int inicio) {
    visitado[inicio] = true;
    cout << inicio << " ";
    for(int i = 0; i < MAX_TAM; i++) {
        if(!visitado[i] && M[inicio][i] > 0)
            buscaProfundidadeRec(M, visitado, i);
    }
}

void dfs(int **M, bool *visitado, int inicio) {
    visitado[inicio] = true;
    for(int i = 0; i < MAX_TAM; i++) {
        if(!visitado[i] && M[inicio][i] > 0)
            dfs(M, visitado, i);
    }
}

void buscaProfundidade(int **M, int inicio) {
    int Pilha[MAX_TAM], status[MAX_TAM], topo = -1, v;
    for(int i = 0; i < MAX_TAM; i++) {
        status[i] = 1;
    }
    Pilha[++topo] = inicio;
    status[inicio] = 2;
    
    while(topo != -1) {
        v = Pilha[topo--];
        cout << v << setw(2);
        status[v] = 3;
        for(int j = 0; j < MAX_TAM; j++) {
            if(M[v][j] > 0) {
                if(status[j] == 1) {
                    status[j] = 2;
                    Pilha[++topo] = j;
                }
                else if(status[j] == 2) {
                    int p = 0;
                    while((p <= topo) && Pilha[p] != j) {
                        p++;
                    }
                    while(p < topo) {
                        Pilha[p] = Pilha[p+1];
                        p++;
                    }
                    topo--;
                    Pilha[++topo] = j;
                }
            }
        }
    }
}

void buscaEmLargura(int **M, int inicio) {
    return;    
}

void dijkstra(int **M, int inicio, int custo[], int rota[]) {
    int r = -1;
    bool visitado[MAX_TAM];
    
    for(int i = 0; i < MAX_TAM; i++) {
        visitado[i] = false;
    }
    
    for(int i = 0; i < MAX_TAM; i++) {
        custo[i] = INF;
        rota[i] = -1;
    }
    
    custo[inicio] = 0;
    rota[inicio] = inicio;
    
    while(true) {
        r = -1;
        for(int i = 0; i < MAX_TAM; i++) {
            if(!visitado[i] && (r < 0 || custo[i] < custo[r]))
                r = i;
        }
        if(r < 0) break;
        visitado[r] = true;
        for(int i = 0; i < MAX_TAM; i++) {
            if(M[r][i] && custo[i] > custo[r] + M[r][i]) {
                custo[i] = custo[r] + M[r][i];
                rota[i] = r;
            }
        }
    }
    
}

bool grafoConexo(Grafo G) {
    bool visitado[MAX_TAM];
    for(int i = 0; i < MAX_TAM; i++) {
       visitado[i] = false;
    }
    dfs(G.g, visitado, 2);
    int aux = 0;
    for(int i = 0; i < MAX_TAM; i++) {
        if(visitado[i])
            aux++;
    }
    return aux == MAX_TAM;    
}

int componentesConexos(Grafo G) {
    bool visitado[MAX_TAM]; 
    int cont = 0, v = 0;
    
    for(int i = 0; i < MAX_TAM; i++) {
       visitado[i] = false;
    }
    
    while(v < MAX_TAM) {
        dfs(G.g, visitado, v);
        while(v < MAX_TAM && visitado[v]) {
            v++;
        }
        cont++;
    }
    return cont;
}

void imprimeGrafo(Grafo G) {
    for(int i = 0; i < G.ordem; ++i) {
        cout << i + 1 << ":" << setw(2);
        for(int j = 0; j < G.ordem; ++j)
            if(G.g[i][j] > 0)
                cout << setw(2) << j + 1;
        cout << endl;
    }
}


/* Lista de Adjacência */
void iniciaGrafoLista(GL &G, int ordem) {
    G.ordem = ordem;
    G.adj = new No[ordem];
    for(int i = 0; i < ordem; i++) {
        G.adj[i].v = i;
        G.adj[i].prox = NULL;
    }
}

void insereArestaGL(GL &G, int a, int b) {
    No *novo = new No;
    novo->v = b;
    novo->prox = NULL;
    
    if(!G.adj[a].prox) {
        G.adj[a].prox = novo;
    } else {
        No *ant = NULL, *aux = G.adj[a].prox;
        while(aux) {
            ant = aux;
            aux = aux->prox;
        }
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}

void imprimeGrafoL(GL G) {
    No *aux;
    for(int i = 0; i < G.ordem; i++) {
        cout << i + 1 << ":";
        aux = G.adj[i].prox;
        while(aux) {
            cout << setw(2) << aux->v + 1;
            aux = aux->prox;
        }
        cout << endl;
    }
}