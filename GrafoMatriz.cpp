#include "GrafoMatriz.h"
#include <vector>

using std::cout;

GrafoMatriz::GrafoMatriz()
{
    grafoMatriz = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        grafoMatriz[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            grafoMatriz[i][j] = 0;
        }
    }
}

GrafoMatriz::GrafoMatriz(int num_vertice)
{
    this->num_vertice = num_vertice;
    grafoMatriz = new int *[num_vertice];
    for (int i = 0; i < num_vertice; i++)
    {
        grafoMatriz[i] = new int[num_vertice];
        for (int j = 0; j < num_vertice; j++)
        {
            grafoMatriz[i][j] = 0;
        }
    }
}

GrafoMatriz::~GrafoMatriz()
{
    for (int i = 0; i < num_vertice; i++)
    {
        delete[] grafoMatriz[i];
    }
    delete[] grafoMatriz;
}

string GrafoMatriz::inserirAresta(int origem, int destino)
{
    if ((origem <= 10 || origem >= 0) && (destino <= 10 || destino >= 0))
    {
        grafoMatriz[origem][destino] = 1;
        return "Aresta adicionada!";
    }
    return "Vértices não encontrados";
}

string GrafoMatriz::inserirAresta(int origem, int destino, int valor)
{
    if ((origem <= 10 || origem >= 0) && (destino <= 10 || destino >= 0))
    {
        grafoMatriz[origem][destino] = valor;
        return "Aresta adicionada!";
    }
    return "Vértices não encontrados";
}

int GrafoMatriz::adjacencias(int vertice)
{
    int adjacencia_total = 0;

    for (int i = 0; i < num_vertice; i++)
    {
        if (i == vertice)
        {
            continue;
        }

        if (grafoMatriz[i][vertice] > 0)
        {
            cout << "\nAresta: " << i << "->" << vertice;
            adjacencia_total += 1;
        }
    }

    for (int j = 0; j < num_vertice; j++)
    {
        if (grafoMatriz[vertice][j] > 0)
        {
            cout << "\nAresta: " << vertice << "->" << j;
            adjacencia_total += 1;
        }
    }

    cout << "\nVertice (" << vertice << ") tem " << adjacencia_total << " adjacencias";
    return adjacencia_total;
}

int GrafoMatriz::getVertices()
{
    return num_vertice;
}

int GrafoMatriz::getArestas()
{
    /*
     * Apenas para grafoMatriz direcionado
     */
    int aresta_total = 0;
    for (int i = 0; i < num_vertice; i++)
    {
        for (int j = 0; j < num_vertice; j++)
        {
            if (grafoMatriz[i][j] > 0)
            {
                aresta_total += 1;
            }
        }
    }
    return aresta_total;
}

void GrafoMatriz::deletarAresta(int origem, int destino)
{
    grafoMatriz[origem][destino] = 0;
    cout << "\nAresta " << origem << "->" << destino << " deletada com sucesso!";
}