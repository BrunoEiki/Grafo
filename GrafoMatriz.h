#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include <iostream>
#include <vector>
#include <queue>

using std::greater;
using std::priority_queue;
using std::string;
using std::vector;

struct VerticeMatriz
{
    int etiqueta;
    int estimativa;

    VerticeMatriz(int etiqueta, int estimativa)
        : etiqueta(etiqueta), estimativa(estimativa) {}

    bool operator>(const VerticeMatriz &other) const
    {
        return this->estimativa > other.estimativa;
    }
};

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
    int countAdjacencias(int vertice);
    vector<int> getAdjacencias(int vertice);
    int getVertices();
    int getArestas();
    void relaxar();

    // void printShortestPath();
    void printPath(VerticeMatriz *);
    void printPath(const vector<int> &predecessor, int vertice);

    // ALGORITMOS
    void bellmanFord(int origem);
    void floydWarshall();
    void dijkstra(int fonte);
    void componentesConectados();
    void DFS(int vertice);

private:
    int num_vertice;
    int **grafoMatriz;

    vector<VerticeMatriz *> vertices;
    vector<bool> visitados;
};
#endif