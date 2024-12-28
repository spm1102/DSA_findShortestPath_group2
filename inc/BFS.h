#ifndef BFS_H
#define BFS_H

#include"BFS_queue.h"

void BFS(graph_t* p_graph, cell_t** grid,int startVertex, int destination, void (*GUI_displayPath)(graph_t* p_graph, cell_t **grid));

#endif