#ifndef ENDORSED_GRAPH_H
#define ENDORSED_GRAPH_H

#include <limits.h>
#include <math.h>
#include "cell.h"

#define MAX_VERTICES 100

struct edge_t
{
    int src;               // the source node
    int dest;              // the destination node
    double weight;
    struct edge_t *next;
};

typedef struct edge_t edge_t;

struct vertex_t
{
    int x, y;               //coordinate of node
    int visited;
    double heuristic_dist;  // heuristic dist to the destination
    double total_dist;      //distance to the source
    int preVertex;          //the previous node
    edge_t *edge;
};
typedef struct vertex_t vertex_t;

struct graph_t
{
    int numVertices;        //the number of nodes
    vertex_t vertices[MAX_VERTICES];
};

typedef struct graph_t graph_t;

graph_t* GRAPH_Create(const cell_t** grid);
void GRAPH_Free(graph_t *p_graph);
void EDGE_Add(graph_t *p_graph, int src, int dest, double weight);
void EDGE_Add_oneWay(graph_t *p_graph, int src, int dest, double weight);
void EDGE_Free(edge_t *p_edge);
double distance_measure(graph_t *p_graph, int source, int dest);

#endif