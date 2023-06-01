#include "GrafoMatriz.h"

#include <vector>
#include <iomanip>

#define INFINITO INT_MAX

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
        VerticeMatriz *v = new VerticeMatriz(i, 0);
        vertices.push_back(v);
        visitados.push_back(false);
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
        VerticeMatriz *v = new VerticeMatriz(i, 0);
        vertices.push_back(v);
        visitados.push_back(false);
    }
}

GrafoMatriz::~GrafoMatriz()
{
    for (int i = 0; i < num_vertice; i++)
    {
        delete[] vertices[i];
        delete[] grafoMatriz[i];
    }
    delete[] grafoMatriz;
}

string GrafoMatriz::inserirAresta(int origem, int destino)
{
    if ((origem <= 10 || origem >= 0) && (destino <= 10 || destino >= 0))
    {
        grafoMatriz[origem][destino] = 1;
        return "\nAresta adicionada!";
    }
    return "\nVértices não encontrados";
}

string GrafoMatriz::inserirAresta(int origem, int destino, int valor)
{
    if ((origem <= 10 || origem >= 0) && (destino <= 10 || destino >= 0))
    {
        grafoMatriz[origem][destino] = valor;
        return "\nAresta ponderada adicionada!";
    }
    return "\nVértices não encontrados";
}

vector<int> GrafoMatriz::getAdjacencias(int vertice)
{
    vector<int> adjacentes;

    // // INDO DOS OUTROS VERTICES ATE O VERTICE ESCOLHIDO
    // for (int i = 0; i < num_vertice; i++)
    // {
    //     if (i == vertice)
    //         continue;

    //     if (grafoMatriz[i][vertice] > 0)
    //         adjacentes.push_back(i);
    // }

    // DO VERTICE ESCOLHIDO ATE OS OUTROS VERTICES
    for (int j = 0; j < num_vertice; j++)
    {
        if (grafoMatriz[vertice][j] > 0)
        {
            adjacentes.push_back(j);
        }
    }

    return adjacentes;
}

int GrafoMatriz::countAdjacencias(int vertice)
{
    int adjacencia_total = 0;

    // for (int i = 0; i < num_vertice; i++)
    // {
    //     if (i == vertice)
    //         continue;

    //     if (grafoMatriz[i][vertice] > 0)
    //     {
    //         cout << "\nAresta: " << i << "->" << vertice;
    //         adjacencia_total += 1;
    //     }
    // }

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

void GrafoMatriz::relaxar()
{
}

// void GrafoMatriz::printShortestPath()
// {
//     for (VerticeMatriz *u : vertices)
//     {
//         printf("\n\nDistancia: %d", u->estimativa);
//         printPath(u);
//     }
// }

void GrafoMatriz::deletarAresta(int origem, int destino)
{
    grafoMatriz[origem][destino] = 0;
    cout << "\nAresta " << origem << "->" << destino << " deletada com sucesso!";
}

void GrafoMatriz::dijkstra(int origem)
{
    std::vector<int> predecessor(num_vertice, -1);
    std::vector<int> dist(num_vertice, INFINITO);
    dist[origem] = 0;

    cout << "\n**** DIJKSTRA ****\n";

    std::priority_queue<VerticeMatriz, std::vector<VerticeMatriz>, std::greater<VerticeMatriz>> filaPrioridade;
    filaPrioridade.push(VerticeMatriz(origem, 0));

    while (!filaPrioridade.empty())
    {
        VerticeMatriz verticeAtual = filaPrioridade.top();
        filaPrioridade.pop();

        int u = verticeAtual.etiqueta;

        for (int v = 0; v < num_vertice; ++v)
        {
            int peso = grafoMatriz[u][v];
            if (peso > 0 && dist[u] != INFINITO && dist[u] + peso < dist[v])
            {
                dist[v] = dist[u] + peso;
                predecessor[v] = u;
                filaPrioridade.push(VerticeMatriz(v, dist[v]));
            }
        }
    }

    for (int i = 0; i < num_vertice; ++i)
    {
        std::cout << "Vertice: " << i << ", Caminho Mínimo: ";
        if (dist[i] == INFINITO)
        {
            std::cout << "IMPOSSIVEL CHEGAR";
        }
        else
        {
            std::cout << dist[i];
        }

        std::cout << "\n     ";
        printPath(predecessor, i);
        std::cout << std::endl;
    }
}

void GrafoMatriz::printPath(const vector<int> &predecessor, int vertice)
{
    if (predecessor[vertice] == -1)
    {
        std::cout << vertice << " ";
        return;
    }

    printPath(predecessor, predecessor[vertice]);
    std::cout << "-> " << vertice << " ";
}

void GrafoMatriz::componentesConectados()
{
    cout << "\n**** COMPONENTES CONECTADOS ****\n";

    visitados.assign(num_vertice, false); // Inicializa todos os vértices como não visitados

    for (int v = 0; v < num_vertice; ++v)
    {
        if (!visitados[v])
        {
            std::cout << "Componente Conectado: ";
            DFS(v);
            std::cout << std::endl;
        }
    }
}

void GrafoMatriz::DFS(int vertice)
{
    visitados[vertice] = true; // Marca o vértice como visitado
    std::cout << vertice << " ";

    // Explora os vértices adjacentes não visitados
    for (int adjacente = 0; adjacente < num_vertice; ++adjacente)
    {
        if (grafoMatriz[vertice][adjacente] != 0 && !visitados[adjacente])
        {
            DFS(adjacente);
        }
    }
}

void GrafoMatriz::floydWarshall()
{
    cout << "\n**** FLOYD-WARSHALL ****\n";
    int dist[num_vertice][num_vertice];

    // Inicializa a matriz de distâncias com os pesos das arestas existentes
    for (int i = 0; i < num_vertice; ++i)
    {
        for (int j = 0; j < num_vertice; ++j)
        {
            if (grafoMatriz[i][j] != 0)
            {
                dist[i][j] = grafoMatriz[i][j];
            }
            else
            {
                dist[i][j] = INFINITO;
            }
        }
    }

    // Encontra os menores caminhos entre todos os pares de vértices
    for (int k = 0; k < num_vertice; ++k)
    {
        for (int i = 0; i < num_vertice; ++i)
        {
            for (int j = 0; j < num_vertice; ++j)
            {
                // Se passar pelo vértice k reduz a distância entre i e j, atualiza a distância
                if (dist[i][k] != INFINITO && dist[k][j] != INFINITO && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Imprime as distâncias mínimas entre todos os pares de vértices
    for (int i = 0; i < num_vertice; ++i)
    {
        for (int j = 0; j < num_vertice; ++j)
        {
            if (dist[i][j] == INFINITO)
            {
                std::cout << std::setw(4) << "INF ";
            }
            else
            {
                std::cout << std::setw(4) << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}

void GrafoMatriz::bellmanFord(int origem)
{
    cout << "\n**** BELLMAN-FORD ****\n";

    vector<int> dist(num_vertice, INFINITO);
    vector<int> predecessor(num_vertice, -1);
    dist[origem] = 0;

    // Relaxar as arestas repetidamente
    for (int i = 0; i < num_vertice - 1; ++i)
    {
        // Percorrer todas as arestas do grafo
        for (int u = 0; u < num_vertice; ++u)
        {
            for (int v = 0; v < num_vertice; ++v)
            {
                int peso = grafoMatriz[u][v];
                if (peso != 0 && dist[u] != INFINITO && dist[u] + peso < dist[v])
                {
                    dist[v] = dist[u] + peso;
                    predecessor[v] = u;
                }
            }
        }
    }

    // Verificar se há ciclo de peso negativo
    for (int u = 0; u < num_vertice; ++u)
    {
        for (int v = 0; v < num_vertice; ++v)
        {
            int peso = grafoMatriz[u][v];
            if (peso != 0 && dist[u] != INFINITO && dist[u] + peso < dist[v])
            {
                std::cout << "O grafo contém um ciclo de peso negativo." << std::endl;
                return;
            }
        }
    }

    // Imprimir as distâncias mínimas e os caminhos
    for (int i = 0; i < num_vertice; ++i)
    {
        std::cout << "Vertice: " << i << ", Distancia minima: ";
        if (dist[i] == INFINITO)
        {
            std::cout << "IMPOSSIVEL CHEGAR";
        }
        else
        {
            std::cout << dist[i];
        }

        std::cout << ", Caminho: ";
        printPath(predecessor, i);
        std::cout << std::endl;
    }
}
