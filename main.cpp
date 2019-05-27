/* 
 * File:   main.cpp
 * Author: ander
 *
 * Created on 26 de Maio de 2019, 09:41
 */
#include "grafo.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    int custo[MAX_TAM], rota[MAX_TAM];
    Grafo G;
    //GL GL;
    inicializaGrafo(G);
    insereArestaPonderada(G, 0, 1, 2);
    insereArestaPonderada(G, 0, 2, 9);
    insereArestaPonderada(G, 0, 3, 2);
    insereArestaPonderada(G, 0, 4, 7);
    insereArestaPonderada(G, 1, 0, 2);
    insereArestaPonderada(G, 1, 2, 6);
    insereArestaPonderada(G, 1, 5, 8);
    insereArestaPonderada(G, 1, 6, 5);
    insereArestaPonderada(G, 2, 0, 9);
    insereArestaPonderada(G, 2, 1, 6);
    insereArestaPonderada(G, 2, 4, 1);
    insereArestaPonderada(G, 2, 6, 2);
    insereArestaPonderada(G, 3, 0, 2);
    insereArestaPonderada(G, 3, 5, 2);
    insereArestaPonderada(G, 4, 0, 7);
    insereArestaPonderada(G, 4, 2, 1);
    insereArestaPonderada(G, 4, 6, 5);
    insereArestaPonderada(G, 5, 1, 8);
    insereArestaPonderada(G, 5, 3, 2);
    insereArestaPonderada(G, 5, 7, 9);
    insereArestaPonderada(G, 6, 1, 5);
    insereArestaPonderada(G, 6, 2, 2);
    insereArestaPonderada(G, 6, 4, 5);
    insereArestaPonderada(G, 6, 7, 7);
    insereArestaPonderada(G, 7, 5, 9);
    insereArestaPonderada(G, 7, 6, 7);
    dijkstra(G.g, 7, custo, rota);
    
    cout << "CUSTO:" << endl;
    
    for(int i = 0; i < MAX_TAM; i++) {
        cout << custo[i] << " ";
    }
    
    cout << "\n\nROTA:" << endl;
    
    for(int i = 0; i < MAX_TAM; i++) {
        cout << rota[i] << " ";
    }
    
    
    /*
    insereAresta(G, 0, 1);
    insereAresta(G, 1, 0);
    insereAresta(G, 1, 2);
    insereAresta(G, 1, 3);
    insereAresta(G, 1, 5);
    insereAresta(G, 2, 1);
    insereAresta(G, 2, 5);
    insereAresta(G, 2, 6);
    insereAresta(G, 3, 1);
    insereAresta(G, 3, 5);
    insereAresta(G, 4, 6);
    insereAresta(G, 5, 1);
    insereAresta(G, 5, 2);
    insereAresta(G, 5, 3);
    insereAresta(G, 5, 6);
    insereAresta(G, 5, 7);
    insereAresta(G, 6, 2);
    insereAresta(G, 6, 4);
    insereAresta(G, 6, 5);
    insereAresta(G, 7, 5);
    
    insereAresta(G, 0, 2);
    insereAresta(G, 2, 0);
    insereAresta(G, 2, 4);
    insereAresta(G, 2, 6);
    insereAresta(G, 3, 7);
    insereAresta(G, 4, 2);
    insereAresta(G, 4, 6);
    insereAresta(G, 6, 2);
    insereAresta(G, 6, 4);
    insereAresta(G, 6, 7);
    insereAresta(G, 7, 3);
    insereAresta(G, 7, 6);
    
    
    bool visitado[MAX_TAM];
    
    for(int i = 0; i < MAX_TAM; i++) {
        visitado[i] = false;
    }
    
    cout << "Busca em Profundidade Recursiva:" << endl;
    buscaProfundidadeRec(G.g, visitado, 0);
    
    cout << "\n\nBusca em Profundidade Iterativa:" << endl;
    buscaProfundidade(G.g, 0);
    //imprimeGrafo(G);
    cout << endl;
    grafoConexo(G) ? cout << "Eh conexo" : cout << "Nao eh conexo";
    cout << "\n\n";
    imprimeGrafo(G);
    cout << "\n\n";
    cout << "Total de componentes conexos eh: " << componentesConexos(G) << endl;
    
    /*
    iniciaGrafoLista(GL, 6);
    insereArestaGL(GL, 5, 3);
    insereArestaGL(GL, 0, 5);
    insereArestaGL(GL, 0, 1);
    insereArestaGL(GL, 3, 1);
    insereArestaGL(GL, 1, 5);
    insereArestaGL(GL, 2, 4);
    insereArestaGL(GL, 1, 0);
    imprimeGrafoL(GL);
    */
    return 0;
}

