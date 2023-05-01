#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class GrafoMatriz
{
public:
    // CONSTRUTOR
    GrafoMatriz();
    GrafoMatriz(int num_vertice);
    ~GrafoMatriz();

    // MÉTODOS
    string inserirAresta(int origem, int destino);
    string inserirAresta(int origem, int destino, int valor);
    
    void deletarAresta(int origem, int destino);
    int adjacencias(int vertice);
    int getVertices();
    int getArestas();

private:
    int num_vertice;
    int **grafoMatriz;
};

#endif