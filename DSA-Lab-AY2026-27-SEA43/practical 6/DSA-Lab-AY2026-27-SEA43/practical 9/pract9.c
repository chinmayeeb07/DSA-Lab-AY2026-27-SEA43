//Chinmayee Bakshi
// SEA43
//Graph Traversal
 #include <stdio.h>
 int graph[20][20], visited[20];
 int queue[20];
 int n, edges;
 void BFS(int start)
 {
 int front = 0, rear = 0, i, node;
 for (i = 0; i < n; i++)
 visited[i] = 0;
 queue[rear++] = start;
 visited[start] = 1;
 printf("\nBFS Traversal: ");
 while (front < rear)
 {
 node = queue[front++];
 printf("%d ", node);
 for (i = 0; i < n; i++)
 {
 if (graph[node][i] == 1 && !visited[i])
 {
 visited[i] = 1;
 queue[rear++] = i;
 }
 }
 }
 printf("\n");
 }
 void DFS(int node)
 {
 int i;
 visited[node] = 1;
 printf("%d ", node);
 for (i = 0; i < n; i++)
 {
 if (graph[node][i] == 1 && !visited[i])
 DFS(i);
 }
 }
 int main()
 {
 int i, u, v, start;
 printf("Enter number of buildings: ");
 scanf("%d", &n);
 if (n < 1 || n > 20)
 {
 printf("Invalid number of buidlings!\n");
 return 1;
 }
 printf("Enter number of paths: ");
 scanf("%d", &edges);
 if (edges < 0 || edges > n * (n - 1) / 2)
 {
 printf("Invalid number of paths!\n");
 return 1;
 }
 // Initialize adjacency matrix
 for (i = 0; i < n; i++)
 {
 for (int j = 0; j < n; j++)
 graph[i][j] = 0;
 }
 // Take edges from user
 printf("Enter paths (u v), buildings numbered 0 to %d:\n", n - 1);
 for (i = 0; i < edges; i++)
 {
 scanf("%d %d", &u, &v);
 if (u < 0 || u >= n || v < 0 || v >= n || u == v)
 {
 printf("Invalid path! Enter the program again.\n");
 return 1;
 }
 graph[u][v] = 1;
 graph[v][u] = 1;
 }
 // Display adjacency matrix
 printf("\nAdjacency Matrix:\n");
 for (i = 0; i < n; i++)
 {
 for (int j = 0; j < n; j++)
 printf("%d ", graph[i][j]);
 printf("\n");
 }
 printf("\nEnter starting building (0 to %d): ", n - 1);
 scanf("%d", &start);
 if (start < 0 || start >= n)
 {
 printf("Invalid starting building!\n");
 return 1;
 }
 BFS(start);
 for (i = 0; i < n; i++)
 visited[i] = 0;
 printf("DFS Traversal: ");
 DFS(start);
 printf("\n");
 printf("\nPress Enter to exit...");
 getchar();
 getchar();
 return 0;
 }
