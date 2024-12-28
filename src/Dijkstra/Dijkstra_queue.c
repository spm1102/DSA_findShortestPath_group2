#include "Dijkstra_queue.h"
DIJKSTRA_queue_t *DIJKSTRA_QUEUE_Create(void)
{
    DIJKSTRA_queue_t *p_queue = (DIJKSTRA_queue_t *)malloc(sizeof(DIJKSTRA_queue_t));

    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}

void DIJKSTRA_QUEUE_Put(DIJKSTRA_queue_t *p_queue, int vertex, int dist)
{
    DIJKSTRA_node_t *p_node = DIJKSTRA_NODE_Create(vertex, dist);
    if (p_queue->front == NULL || dist < p_queue->front->total_dist)
    {
        p_node->next = p_queue->front;
        p_queue->front = p_node;
    }
    else
    {
        DIJKSTRA_node_t *curr = p_queue->front;
        DIJKSTRA_node_t *pre = NULL;
        while (curr != NULL && dist >= curr->total_dist)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = p_node;
        p_node->next = curr;
    }
}

DIJKSTRA_node_t *DIJKSTRA_QUEUE_Get(DIJKSTRA_queue_t *p_queue)
{
    if (p_queue->front == NULL)
    {
        return NULL;
    }
    DIJKSTRA_node_t *p_node = DIJKSTRA_NODE_Create(p_queue->front->vertex, p_queue->front->total_dist);
    DIJKSTRA_node_t *temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if (p_queue->front == NULL)
    {
        p_queue->rear = NULL;
    }
    DIJKSTRA_NODE_Free(temp);
    return p_node;
}

void DIJKSTRA_QUEUE_Free(DIJKSTRA_queue_t *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
    free(p_queue);
}