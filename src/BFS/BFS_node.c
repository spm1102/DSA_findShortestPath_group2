#include "BFS_node.h"

BFS_node_t *BFS_NODE_Create(int ver)
{
    BFS_node_t *p_node = (BFS_node_t *)malloc(sizeof(BFS_node_t));
    p_node->vertex = ver;
    p_node->next = NULL;
    return p_node;
}

void BFS_NODE_Free(BFS_node_t *p_node)
{
    free(p_node);
}