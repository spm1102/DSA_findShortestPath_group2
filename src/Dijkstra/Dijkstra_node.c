#include "Dijkstra_node.h"

DIJKSTRA_node_t* DIJKSTRA_NODE_Create(int vertex, int dist) {
    DIJKSTRA_node_t* p_node = (DIJKSTRA_node_t*)malloc(sizeof(DIJKSTRA_node_t));
    p_node->vertex = vertex;
    p_node->total_dist = dist;
    p_node->next = NULL;

    return p_node;
}

void DIJKSTRA_NODE_Free(DIJKSTRA_node_t* p_node) {
    free(p_node);
}