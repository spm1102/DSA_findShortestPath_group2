#ifndef A_STAR_QUEUE_H
#define A_STAR_QUEUE_H

#include "a_star_node.h"

struct A_STAR_queue_t
{
    A_STAR_node_t *front;
    A_STAR_node_t *rear;
};

typedef struct A_STAR_queue_t A_STAR_queue_t;

A_STAR_queue_t *A_STAR_QUEUE_Create(void);
void A_STAR_QUEUE_Put(A_STAR_queue_t *p_queue, int vertex, double dist, graph_t *p_graph);
A_STAR_node_t *A_STAR_QUEUE_Get(A_STAR_queue_t *p_queue, graph_t *p_graph);
void A_STAR_QUEUE_Free(A_STAR_queue_t *p_queue);

#endif