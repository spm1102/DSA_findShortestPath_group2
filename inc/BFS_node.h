#ifndef BFS_NODE_H
#define BFS_NODE_H

#include"GRAPH_GEN.h"

struct BFS_node_t {
    int vertex;
    struct BFS_node_t* next;
};

typedef struct BFS_node_t BFS_node_t;


BFS_node_t* BFS_NODE_Create(int ver);
void BFS_NODE_Free(BFS_node_t* p_node);

#endif