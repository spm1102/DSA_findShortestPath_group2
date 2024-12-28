#ifndef DIJKSTRA_NODE_H
#define DIJSKTRA_NODE_H

#include "GRAPH_GEN.h"

struct DIJKSTRA_node_t {
    int vertex;
    int total_dist;
    struct DIJKSTRA_node_t* next;
};

typedef struct DIJKSTRA_node_t DIJKSTRA_node_t;

DIJKSTRA_node_t* DIJKSTRA_NODE_Create(int vertex, int dist);
void DIJKSTRA_NODE_Free(DIJKSTRA_node_t* p_node);

#endif