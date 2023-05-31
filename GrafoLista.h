#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H

#include <iostream>
#include <vector>
#include <queue>

using std::string;
using std::vector;

struct Aresta
{
public:
    int destino;
    int peso;

    Aresta *anterior;
    Aresta *proximo;

    Aresta(int destino)
        : destino(destino), peso(1), anterior(nullptr), proximo(nullptr) {}

    Aresta(int destino, int peso)
        : destino(destino), peso(peso), anterior(nullptr), proximo(nullptr) {}
};

struct Vertice
{
    Aresta *adjacente;
    Vertice()
        : adjacente(nullptr) {}

    Vertice(Aresta *adj)
        : adjacente(adj) {}
};

class GrafoLista
{
public:
    // CONSTRUTOR
    GrafoLista(int numVertice);
    ~GrafoLista();

    // MÉTODOS
    string inserirAresta(int origem, int destino);
    string inserirAresta(int origem, int destino, int peso);
    void deletarAresta(int origem, int destino);
    void adjacencias(int vertice);
    int getVertices();
    int getArestas();

private:
    vector<Vertice> grafoLista;
};

#endif