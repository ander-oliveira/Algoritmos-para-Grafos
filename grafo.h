/* 
 * File:   grafo.h
 * Author: ander
 *
 * Created on 26 de Maio de 2019, 09:44
 */

#ifndef GRAFO_H
#define GRAFO_H

#include <iomanip>
#include<iostream>
#define MAX_TAM 8
#define INF 9999

using namespace std;

struct grafo {
    int **g;
    int ordem;
};
typedef grafo Grafo;



/*Implementação para Matriz de Adjacência*/
void inicializaGrafo(Grafo &G);
int **criaMatrizAdj(int n);
void insereAresta(Grafo &G, int a, int b);
void insereArestaPonderada(Grafo &G, int a, int b, int w);
void buscaProfundidadeRec(int **G, bool *visitado, int inicio);
void dfs(int **M, bool *visitado, int inicio);
void buscaProfundidade(int **M, int inicio);
void buscaEmLargura(Grafo G, int inicio);
void dijkstra(int **M, int inicio, int custo[], int rota[]);
bool grafoConexo(Grafo G);
int componentesConexos(Grafo G);
void imprimeGrafo(Grafo G);
/* END */


/*Implementação para Lista de Adjacência*/
struct No {
    int v;
    No *prox;
};

struct grafoLista {
    No *adj;
    int ordem;
};

typedef grafoLista GL;

void iniciaGrafoLista(GL &G, int ordem);
void insereArestaGL(GL &G, int a, int b);
void imprimeGrafoL(GL G);
/* END */


#endif /* GRAFO_H */

