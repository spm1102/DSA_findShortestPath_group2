#ifndef A_STAR_H
#define A_STAR_H

#include "a_star_queue.h"

void a_star_queue(graph_t *p_graph, cell_t** grid, int startVertex, int destination, void (*GUI_displaypPath)(graph_t *p_graph, cell_t** grid));

#endif