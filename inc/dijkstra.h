#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Dijkstra_queue.h"

void dijkstra(graph_t *p_graph, cell_t **grid, int startVertex, int destination, void (*GUI_displayPath)(graph_t *p_graph, cell_t **grid));
#endif