#ifndef GUI_H
#define GUI_H

#include <time.h>
#include "a_star.h"
#include "dijkstra.h"
#include "BFS.h"
#include "raylib.h"
#include "raygui.h"

#define MAX_PATH_LENGTH 100

void CELL_Draw(cell_t cell);
bool INDEX_IsValid(int x, int y);
void GUI_displayError(void);
void GUI_displayPath(graph_t *p_graph, cell_t** grid);
void GUI_findShortestPath(cell_t** grid, bool* isAlgorithmRunning);
void DrawGradientLine(int srcX, int srcY, int destX, int destY);
void GUI_INIT(cell_t** grid);

#endif