#include<stdio.h>
#include<stdlib.h>
#define MAX 6

struct graphNode {
    int data;
    struct graphNode *next;	
};

int degree[MAX];
int vertex_list[MAX] = {1, 2, 3, 4, 5,6};  // Vertices
struct graphNode *arr[MAX];  // Adjacency list
int visited_list[MAX];  // Keeps track of visited vertices
int queue[MAX];
int front = -1;
int rear = -1;

struct graphNode *createList(int vertex) {
    struct graphNode *r;
    int data;
    printf("Vertex %d connected to (-1 to stop): ", vertex);
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    r = (struct graphNode *)malloc(sizeof(struct graphNode));
    r->data = data;
    r->next = createList(vertex);
    return r;
}

void addq(int data) {
    if (rear == MAX-1) {
        printf("Queue is full.\n");
        return;
    }
    rear++;
    queue[rear] = data;
    if (front == -1) {
        front++;
    }
}

void delq() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    queue[front] = 0;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

int find_index(int cwv) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (vertex_list[i] == cwv) {
            return i;
        }
    }
    return -1;
}

void BFS(int cwv) {
    int vli = 0;
    visited_list[vli] = cwv;
    addq(cwv);
    int index = find_index(cwv);
    struct graphNode *adjacent = arr[index];
    
    while (front != -1) {
        while (adjacent != NULL) {
            int i, flag = 0;
            for (i = 0; i < MAX; i++) {
                if (visited_list[i] == adjacent->data) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                vli++;
                visited_list[vli] = adjacent->data;
                addq(adjacent->data);
            }
            adjacent = adjacent->next;
        }
        delq();
        if (front != -1) {
            cwv = queue[front];
            index = find_index(cwv);
            adjacent = arr[index];
        }
    }
}
int find_degree(int vertex) // 1
{
    int index = find_index(vertex); // 0
    struct graphNode* adjacent = arr[index]; // 1001
    int degree = 0;
    while(adjacent != NULL)
    {
        degree++; // 3
        adjacent = adjacent->next; // NULL
    }
    return degree;
}

int isConnected() {
    for (int i = 0; i < MAX; i++) {
        visited_list[i] = 0;  // Initialize visited list
    }
    
    BFS(vertex_list[0]);  // Perform BFS from the first vertex

    for (int i = 0; i < MAX; i++) {
        if (visited_list[i] == 0) {
            return 0;  // If any vertex is not visited, the graph is not connected
        }
    }
    return 1;  // All vertices visited, graph is connected
}

int main() {
    // Creating the graph using linked lists
    for (int i = 0; i < MAX; i++) {
        arr[i] = createList(vertex_list[i]);
    }

    // Displaying the adjacency list
    for (int i = 0; i < MAX; i++) {
        printf("\n Adjacent of %d: ", vertex_list[i]);
        struct graphNode *temp = arr[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    // Checking if the graph is connected
    if (isConnected()) {
        printf("\nThe graph is connected.\n");
    } else {
        printf("\nThe graph is not connected.\n");
    }
    
    // Step 1: find degrees of all vertices
    int i;
    for(i=0; i<MAX; i++)
    {
        degree[i] = find_degree(vertex_list[i]); // 1  // 3
    }
    // step 2: display all degrees and calculate sum of degrees
    for(i=0;i<MAX;i++)
    {
        printf("\n degree(%d) = %d",vertex_list[i], degree[i]);
    }

    for(i=0;i<MAX; i++)
    {
        if(degree[i]%2 != 0)
        {
            printf("\n not a Eular Graph");
            return 0;
        }
    }
    printf("\n Graph is Eular");
    return 0;
}
