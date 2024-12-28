#include "a_star_queue.h"

A_STAR_queue_t *A_STAR_QUEUE_Create(void)
{
    A_STAR_queue_t *p_queue = (A_STAR_queue_t *)malloc(sizeof(A_STAR_queue_t));

    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

void A_STAR_QUEUE_Put(A_STAR_queue_t *p_queue, int vertex, double dist, graph_t *p_graph)
{
    double heuristic_dist = p_graph->vertices[vertex].heuristic_dist;
    A_STAR_node_t *p_node = A_STAR_NODE_Create(vertex, dist, heuristic_dist);
    if (p_queue->front == NULL || dist + heuristic_dist < p_queue->front->total_dist + p_queue->front->heuristic_dist)
    {
        p_node->next = p_queue->front;
        p_queue->front = p_node;
    }
    else
    {
        A_STAR_node_t *curr = p_queue->front;
        A_STAR_node_t *pre = NULL;
        while (curr != NULL && dist + heuristic_dist >= curr->total_dist + curr->heuristic_dist)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = p_node;
        p_node->next = curr;
    }
}

A_STAR_node_t *A_STAR_QUEUE_Get(A_STAR_queue_t *p_queue, graph_t *p_graph)
{
    if (p_queue->front == NULL)
    {
        return NULL;
    }
    int vertex = p_queue->front->vertexName;
    A_STAR_node_t *p_node = A_STAR_NODE_Create(vertex, p_queue->front->total_dist, p_graph->vertices[vertex].heuristic_dist);
    A_STAR_node_t *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }

    A_STAR_NODE_Free(temp);
    return p_node;
}

void A_STAR_QUEUE_Free(A_STAR_queue_t *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
    free(p_queue);
}