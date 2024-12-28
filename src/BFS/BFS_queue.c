#include "BFS_queue.h"

BFS_queue_t* BFS_QUEUE_Create(void){
    BFS_queue_t* p_queue = (BFS_queue_t*)malloc(sizeof(BFS_queue_t));
    p_queue->front = NULL;
    p_queue->rear = NULL;
    return p_queue;
}
// Put element to queue
void BFS_QUEUE_Put(BFS_queue_t* p_queue, int vertex){
    BFS_node_t* p_node = BFS_NODE_Create(vertex);
    if(p_queue->rear == NULL){
        p_queue->front = p_node;
        p_queue->rear = p_node;
    }
    else{
        p_queue->rear->next = p_node;
        p_queue->rear = p_node;
    }
}

// Get element from queue
BFS_node_t* BFS_QUEUE_Get(BFS_queue_t* p_queue){
    if(p_queue->front == NULL){
        return NULL;
    }
    BFS_node_t* p_node = BFS_NODE_Create(p_queue->front->vertex);
    BFS_node_t* temp = p_queue->front;
    p_queue->front = p_queue->front->next;

    if(p_queue->front == NULL){
        p_queue->rear = NULL;
    }

    BFS_NODE_Free(temp);
    return p_node;
}

void BFS_QUEUE_Free(BFS_queue_t* p_queue){
    p_queue->front = NULL;
    p_queue->rear =NULL;
    free(p_queue);
}