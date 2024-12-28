#define RAYGUI_IMPLEMENTATION
#include "gui.h"

void CELL_Draw(cell_t cell)
{
    if (cell.IS_source)
    {
        DrawRectangle(cell.x * cellWidth, cell.y * cellHeight, cellWidth, cellHeight, RED);
    }
    else if (cell.IS_dest)
    {
        DrawRectangle(cell.x * cellWidth, cell.y * cellHeight, cellWidth, cellHeight, BLUE);
    }

    DrawRectangleLines(cell.x * cellWidth, cell.y * cellHeight, cellWidth, cellHeight, BLACK);
}

bool INDEX_IsValid(int x, int y)
{
    return x >= 0 && x < COLS && y >= 0 && y < ROWS;
}

void GUI_displayError(void)
{
    BeginDrawing();
    DrawRectangleRec((Rectangle){180, 190, 110, 50}, GRAY);
    DrawText("Find no path", 195, 195, 14, BLACK);
    EndDrawing();
}

void GUI_displayPath(graph_t *p_graph, cell_t **grid)
{
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (p_graph->vertices[COLS * i + j].visited == true && grid[i][j].IS_source == false && grid[i][j].IS_dest == false)
            {
                BeginDrawing();
                DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight, GREEN);
                DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLACK);
                EndDrawing();
            }
        }
    }
    BeginDrawing();
}

void GUI_findShortestPath(cell_t **grid, bool *isAlgorithmRunning)
{
    graph_t *p_graph = GEN_GRAPH_Create((const cell_t **)grid);
    int source = TAKE_source((const cell_t **)grid);
    int dest = TAKE_dest((const cell_t **)grid);
    // if (IsKeyDown(KEY_ONE))
    // {
    //     *isAlgorithmRunning = true;
    //     BFS(p_graph, grid, source, dest, &GUI_displayPath);
    // }

    bool IS_Reset = false;
    // foward
    if (IsKeyDown(KEY_TWO))
    {
        *isAlgorithmRunning = true;
        dijkstra(p_graph, grid, source, dest, &GUI_displayPath);
    }
    else if (IsKeyDown(KEY_THREE))
    {
        *isAlgorithmRunning = true;
        a_star_queue(p_graph, grid, source, dest, &GUI_displayPath);
    }
    else if (IsKeyDown(KEY_R))
    {
        GRID_Reset(grid);
        IS_Reset = true;
    }

    // track the found shortest path

    int currentVertex = dest;
    // check if the dest node is not found
    // if not found
    if (p_graph->vertices[currentVertex].preVertex == -1 && *isAlgorithmRunning == true)
    {
        while (!WindowShouldClose())
        {
            GUI_displayError();
        }
        BeginDrawing();
        return;
    }
    // if found
    int pathLength = 0;
    int path[MAX_PATH_LENGTH];
    while (currentVertex != source && p_graph->vertices[currentVertex].preVertex != -1) // preVertex of source = -1
    {   
        path[pathLength++] = currentVertex;
        currentVertex = p_graph->vertices[currentVertex].preVertex;
        int j = currentVertex % 10;
        int i = (currentVertex - j) / 10;
        grid[i][j].IS_inPath = true;
    }

    int* grid_idx = (int*)malloc(NUM_LOCATIONS * sizeof(int));
    if(!grid_idx){
        return;
    }
    grid_idx[0] = 34;
    grid_idx[1] = 79;
    grid_idx[2] = 10;
    grid_idx[3] = 37;
    grid_idx[4] = 71;
    grid_idx[5] = 32;
    grid_idx[6] = 4;
    grid_idx[7] = 95;
    grid_idx[8] = 65;
    grid_idx[9] = 39;

    if(!IS_Reset){
        printf("\nShortest path from vertex (%d) to (%d): ", grid_2_symbol(grid_idx, source), grid_2_symbol(grid_idx, dest));
        printf("(%d) ", grid_2_symbol(grid_idx, source));
        for(int i = pathLength - 1; i >= 0; i--){
            printf("(%d) ", grid_2_symbol(grid_idx, path[i]));
        }
        printf("\n");
        double sum_dis = p_graph->vertices[dest].total_dist;
        printf("Sum of distance: %.1lf km\n", sum_dis);
    }
    else printf("The grid is reset!");
    free(grid_idx);
    GRAPH_Free(p_graph);
}

void DrawGradientLine(int srcX, int srcY, int destX, int destY)
{
    int numSegments = 10;
    float dx = (destX - srcX) / (float)numSegments;
    float dy = (destY - srcY) / (float)numSegments;

    for (int i = 0; i < numSegments; i++)
    {
        int x1 = srcX + (int)(dx * i);
        int y1 = srcY + (int)(dy * i);
        int x2 = srcX + (int)(dx * (i + 1));
        int y2 = srcY + (int)(dy * (i + 1));

        int color = 200 * i / numSegments;
        DrawLine(x1, y1, x2, y2, (Color){color, color, color, 255});
    }
}

void GUI_INIT(cell_t **grid)
{
    InitWindow(screenWidth, screenHeight, "Algorithm");

    bool isDrawingWalls = false;
    bool hasSource = false;
    bool hasDest = false;
    int sourceX = -1;
    int sourceY = -1;
    int destX = -1;
    int destY = -1;

    bool isAlgorithmRunning = false;

    while (!WindowShouldClose())
    {
        // Choose src and dest
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            Vector2 mPos2 = GetMousePosition();
            int inX = (int)mPos2.x / cellWidth;
            int inY = (int)mPos2.y / cellHeight;

            if (INDEX_IsValid(inX, inY))
            {
                if (!hasSource)
                {
                    hasSource = true;
                    sourceX = inX;
                    sourceY = inY;
                    grid[inX][inY].IS_source = true;
                }
                else if (!hasDest)
                {
                    hasDest = true;
                    destX = inX;
                    destY = inY;
                    grid[inX][inY].IS_dest = true;
                }
                else
                {
                    // Clear previous source and destination
                    grid[sourceX][sourceY].IS_source = false;
                    grid[destX][destY].IS_dest = false;
                    hasSource = false;
                    hasDest = false;
                }
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < COLS; i++)
        {
            for (int j = 0; j < ROWS; j++)
            {
                if (grid[i][j].IS_activated)
                {
                    DrawRectangle(grid[i][j].x * cellWidth, grid[i][j].y * cellHeight, cellWidth, cellHeight, BROWN);
                    CELL_Draw(grid[i][j]);
                }
            }
        }
        // Draw ways between nodes, gray for 2-ways, black for 1 way
        // 34-37: (3,4)-(3,7)
        DrawLine(3 * cellWidth, 4 * cellHeight, 3 * cellWidth, 7 * cellHeight, GREEN);

        // 34-32: (3,4)-(3,2)
        DrawLine(3 * cellWidth, 4 * cellHeight, 3 * cellWidth, 2 * cellHeight, GREEN);

        // 34-65: (3,4)-(6,5)
        DrawLine(3 * cellWidth, 4 * cellHeight, 6 * cellWidth, 5 * cellHeight, GREEN);

        // 79-37: (7,9)-(3,7)
        DrawLine(7 * cellWidth, 9 * cellHeight, 3 * cellWidth, 7 * cellHeight, GREEN);

        // 79-95: (7,9)-(9,5)
        DrawLine(7 * cellWidth, 9 * cellHeight, 9 * cellWidth, 5 * cellHeight, GREEN);

        // 79-65: (7,9)-(6,5)
        DrawLine(7 * cellWidth, 9 * cellHeight, 6 * cellWidth, 5 * cellHeight, GREEN);

        // 10-71: (1,0)-(7,1)
        DrawLine(1 * cellWidth, 0 * cellHeight, 7 * cellWidth, 1 * cellHeight, GREEN);

        // 10-32: (1,0)-(3,2)
        DrawLine(1 * cellWidth, 0 * cellHeight, 3 * cellWidth, 2 * cellHeight, GREEN);

        // 10-4: (1,0)-(0,4)
        DrawLine(1 * cellWidth, 0 * cellHeight, 0 * cellWidth, 4 * cellHeight, GREEN);

        // 37-65: (3,7)-(6,5)
        DrawLine(3 * cellWidth, 7 * cellHeight, 6 * cellWidth, 5 * cellHeight, GREEN);

        // 71-32: (7,1)-(3,2)
        DrawLine(7 * cellWidth, 1 * cellHeight, 3 * cellWidth, 2 * cellHeight, GREEN);

        // 71-95: (7,1)-(9,5)
        DrawLine(7 * cellWidth, 1 * cellHeight, 9 * cellWidth, 5 * cellHeight, GREEN);

        // 32-4: (3,2)-(0,4)
        DrawLine(3 * cellWidth, 2 * cellHeight, 0 * cellWidth, 4 * cellHeight, GREEN);

        // 4-34: src=4 (0,4) dest=34 (3,4)
        DrawGradientLine(0 * cellWidth, 4 * cellHeight, 3 * cellWidth, 4 * cellHeight);

        // 79-39: src=79 (7,9) dest=39 (3,9)
        DrawGradientLine(7 * cellWidth, 9 * cellHeight, 3 * cellWidth, 9 * cellHeight);

        // 37-4: src=37 (3,7) dest=4 (0,4)
        DrawGradientLine(3 * cellWidth, 7 * cellHeight, 0 * cellWidth, 4 * cellHeight);

        // 37-95: src=37 (3,7) dest=95 (9,5)
        DrawGradientLine(3 * cellWidth, 7 * cellHeight, 9 * cellWidth, 5 * cellHeight);

        // 37-39: src=37 (3,7) dest=39 (3,9)
        DrawGradientLine(3 * cellWidth, 7 * cellHeight, 3 * cellWidth, 9 * cellHeight);

        // 39-4: src=39 (3,9) dest=4 (0,4)
        DrawGradientLine(3 * cellWidth, 9 * cellHeight, 0 * cellWidth, 4 * cellHeight);

        // 95-65: src=95 (9,5) dest=65 (6,5)
        DrawGradientLine(9 * cellWidth, 5 * cellHeight, 6 * cellWidth, 5 * cellHeight);

        if (IsKeyPressed(KEY_ENTER) && sourceX != -1 && sourceY != -1 && destX != -1 && destY != -1)
        {
            isAlgorithmRunning = false;
            GUI_findShortestPath(grid, &isAlgorithmRunning);
        }

        if (isAlgorithmRunning)
        {
            for (int i = 0; i < COLS; i++)
            {
                for (int j = 0; j < ROWS; j++)
                {
                    if (grid[i][j].IS_inPath && grid[i][j].IS_source == false)
                    {
                        DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight, YELLOW);
                        DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLACK);
                    }
                }
            }
        }
        if (IsKeyPressed(KEY_DELETE))
        {
            GRID_PATH_Reset(grid);
        }
        EndDrawing();
    }

    CloseWindow();
}