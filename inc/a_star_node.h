#ifndef A_STAR_NODE__H
#define A_STAR_NODE__H

#include "GRAPH_GEN.h"

struct A_STAR_node_t
{
    int vertexName;
    double real_dist;
    double heuristic_dist;
    double total_dist;
    struct A_STAR_node_t *next;
};

typedef struct A_STAR_node_t A_STAR_node_t;

A_STAR_node_t *A_STAR_NODE_Create(int vertex, double dist, double heuristic_dist);
void A_STAR_NODE_Free(A_STAR_node_t *p_node_heap);

#endif