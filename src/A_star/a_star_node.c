#include "a_star_node.h"

A_STAR_node_t *A_STAR_NODE_Create(int vertex, double dist, double heuristic_dist)
{
    A_STAR_node_t *p_node_heap = (A_STAR_node_t *)malloc(sizeof(A_STAR_node_t));
    if (!p_node_heap)
    {
        return NULL;
    }
    p_node_heap->vertexName = vertex;
    p_node_heap->real_dist = dist;
    p_node_heap->heuristic_dist = heuristic_dist;
    p_node_heap->total_dist = dist;
    p_node_heap->next = NULL;

    return p_node_heap;
}

void A_STAR_NODE_Free(A_STAR_node_t *p_node_heap)
{
    free(p_node_heap);
}