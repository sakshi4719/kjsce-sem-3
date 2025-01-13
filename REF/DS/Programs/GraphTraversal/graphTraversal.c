#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int items[50];
  int front;
  int rear;
};

struct node
{
  int vertex;
  struct node* next;
};

struct Graph
{
  int numVertices;
  struct node** adjLists;
  int* visited;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
struct node* createNode(int);

void dfs(struct Graph* graph, int vertex)
{
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("%d ", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0)
    {
      dfs(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

void bfs(struct Graph* graph, int startVertex)
{
  struct queue* q = createQueue();
  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q))
  {
    int currentVertex = dequeue(q);
    printf("%d ", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp)
    {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0)
      {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

struct node* createNode(int v)
{
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices)
{
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++)
  {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

struct queue* createQueue()
{
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(struct queue* q, int value)
{
  if (q->rear == 50 - 1)
    printf("\nQueue is Full!!");
  else
  {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

int dequeue(struct queue* q)
{
  int item;
  if (isEmpty(q))
  {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
      //printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

int main()
{
  struct Graph* graphDFS = createGraph(6);
  addEdge(graphDFS, 0, 1);
  addEdge(graphDFS, 0, 2);
  addEdge(graphDFS, 1, 2);
  addEdge(graphDFS, 1, 4);
  addEdge(graphDFS, 1, 3);
  addEdge(graphDFS, 2, 4);
  addEdge(graphDFS, 3, 4);

  printf("Depth First Search: \n");
  dfs(graphDFS, 0);

  struct Graph* graphBFS = createGraph(6);
  addEdge(graphBFS, 0, 1);
  addEdge(graphBFS, 0, 2);
  addEdge(graphBFS, 1, 2);
  addEdge(graphBFS, 1, 4);
  addEdge(graphBFS, 1, 3);
  addEdge(graphBFS, 2, 4);
  addEdge(graphBFS, 3, 4);

  printf("\nBreadth First Search: \n");
  bfs(graphBFS, 0);

  return 0;
}
