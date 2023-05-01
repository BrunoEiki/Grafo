#include "GrafoLista.h"
#include <vector>

using std::cout;

GrafoLista::GrafoLista(int numVertice)
{
    grafoLista.reserve(numVertice);
    for (int i = 0; i < numVertice; i++)
    {
        Vertice v;
        grafoLista.push_back(v);
    }
}

GrafoLista::~GrafoLista()
{
    for (Vertice v : grafoLista)
    {
        Aresta *aresta = v.adjacente;
        Aresta *temp = aresta;

        while (temp != nullptr)
        {
            temp = aresta->proximo;
            delete (aresta);
            aresta = temp;
        }
    }
}

string GrafoLista::inserirAresta(int origem, int destino)
{
    Aresta *aresta = new Aresta(destino);

    if (grafoLista[origem].adjacente == nullptr)
    {
        grafoLista[origem].adjacente = aresta;
    }
    else
    {
        Aresta *temp = grafoLista[origem].adjacente;

        while (temp->proximo != nullptr)
        {
            temp = temp->proximo;
        }
        aresta->anterior = temp;
        temp->proximo = aresta;
    }
    return "Aresta adicionada!";
}

void GrafoLista::adjacencias(int vertice)
{
    int total = 0;
    Aresta *aresta;
    for (int i = 0; i < grafoLista.size(); i++)
    {
        aresta = grafoLista[i].adjacente;
        while (aresta != nullptr)
        {
            //
            if (aresta->destino == vertice)
            {
                cout << "\nAresta: " << i << "->" << vertice;
                total += 1;
            }

            if (i == vertice)
            {
                cout << "\nAresta: " << i << "->" << aresta->destino;
                total += 1;
            }
            aresta = aresta->proximo;
        }
    }
    cout << "\nVertice (" << vertice << ") tem " << total << " adjacencias";
}

int GrafoLista::getVertices()
{
    return grafoLista.size();
}

int GrafoLista::getArestas()
{
    /*
     * Apenas para grafoLista direcionado
     */
    int aresta_total = 0;
    for (Vertice v : grafoLista)
    {

        Aresta *aresta = v.adjacente;
        while (aresta != nullptr)
        {
            aresta_total += 1;
            aresta = aresta->proximo;
        }
    }
    return aresta_total;
}

void GrafoLista::deletarAresta(int origem, int destino)
{
    Aresta *aresta = grafoLista[origem].adjacente;
    if (aresta != nullptr && aresta->destino == destino)
    {
        grafoLista[origem].adjacente = aresta->proximo;
        delete aresta;
        cout << "\nAresta " << origem << "->" << destino << " deletada com sucesso!";
        return;
    }
    while (aresta != nullptr)
    {
        if (aresta->destino == destino)
        {
            aresta->anterior->proximo = aresta->proximo;
            delete aresta;
            cout << "\nAresta " << origem << "->" << destino << " deletada com sucesso!";
            return;
        }
        aresta = aresta->proximo;
    }
    cout << "\nAresta " << origem << "->" << destino << " nao encontrada!";
}
