#include "GrafoMatriz.h"
#include "GrafoMatriz.cpp"
#include "GrafoLista.h"
#include "GrafoLista.cpp"

int main(int argc, char **argv)
{
    GrafoMatriz grafoMatriz(6);
    std::cout << "Vertices: " << grafoMatriz.getVertices();
    cout << grafoMatriz.inserirAresta(0, 1, 4);
    cout << grafoMatriz.inserirAresta(1, 2, 3);
    cout << grafoMatriz.inserirAresta(1, 3, 1);
    cout << grafoMatriz.inserirAresta(2, 0, 1);
    cout << grafoMatriz.inserirAresta(3, 2, 1);
    cout << grafoMatriz.inserirAresta(5, 3, 8);

    std::cout << "\nArestas: " << grafoMatriz.getArestas();
    grafoMatriz.getAdjacencias(1);

    // grafoMatriz.deletarAresta(1, 2);
    // grafoMatriz.deletarAresta(1, 3);

    // grafoMatriz.getAdjacencias(1);

    cout << "\n======================\n";
    // GrafoLista grafoLista(10);
    // std::cout << "\nVertices: " << grafoLista.getVertices();
    // grafoLista.inserirAresta(0, 1);
    // grafoLista.inserirAresta(1, 2);
    // grafoLista.inserirAresta(1, 3);
    // grafoLista.inserirAresta(5, 3);

    // std::cout << "\nArestas: " << grafoLista.getArestas();
    // grafoLista.adjacencias(1);

    // grafoLista.deletarAresta(1, 2);
    // grafoLista.deletarAresta(1, 3);

    // grafoLista.adjacencias(1);

    grafoMatriz.componentesConectados();
    grafoMatriz.floydWarshall();
    grafoMatriz.bellmanFord(0);
    grafoMatriz.dijkstra(0);

    // grafoMatriz.printShortestPath();
}