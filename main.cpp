#include "GrafoMatriz.h"
#include "GrafoMatriz.cpp"
#include "GrafoLista.h"
#include "GrafoLista.cpp"

int main(int argc, char **argv)
{
    GrafoMatriz grafoMatriz(10);
    std::cout << "Vertices: " << grafoMatriz.getVertices();
    grafoMatriz.inserirAresta(0, 1, 1);
    grafoMatriz.inserirAresta(1, 2, 2);
    grafoMatriz.inserirAresta(1, 3, 1);
    grafoMatriz.inserirAresta(5, 3, 1);

    std::cout << "\nArestas: " << grafoMatriz.getArestas();
    grafoMatriz.adjacencias(1);

    grafoMatriz.deletarAresta(1, 2);
    grafoMatriz.deletarAresta(1, 3);

    grafoMatriz.adjacencias(1);

    cout << "\n======================";
    GrafoLista grafoLista(10);
    std::cout << "\nVertices: " << grafoLista.getVertices();
    grafoLista.inserirAresta(0, 1);
    grafoLista.inserirAresta(1, 2);
    grafoLista.inserirAresta(1, 3);
    grafoLista.inserirAresta(5, 3);

    std::cout << "\nArestas: " << grafoLista.getArestas();
    grafoLista.adjacencias(1);

    grafoLista.deletarAresta(1, 2);
    grafoLista.deletarAresta(1, 3);

    grafoLista.adjacencias(1);
}