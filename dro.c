#include <stdio.h>
#include <limits.h>

#define V 22
#define INF INT_MAX

const char* shop[V] = {
    "Home",               
    "Cafe Mocha",         
    "Tech Hub Electronics", 
    "Sunshine Pharmacy",  
    "Book Nook",          
    "Tasty Bites Diner",
    "Fashion Forward",    
    "City Cycles",        
    "Fresh Mart",          
    "Gadget Galaxy",      
    "Bella's Bakery",     
    "Quick Fix Auto",     
    "Gourmet Delights",   
    "Fit & Fine Gym",     
    "Pet Paradise",       
    "Starlight Café",     
    "Home Essentials",    
    "Chill Zone",         
    "Eco-Friendly Goods", 
    "Veggie World",       
    "Craft Corner",       
    "Zen Spa"             
};

void printPath(int p[], int j) {
    if (p[j] == -1) {
        printf("%s", shop[j]);
        return;
    }
    printPath(p, p[j]);
    printf(" -> %s", shop[j]);
}

void dijkstra(int graph[V][V], int src, int dist[], int p[]) {
    int visit[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visit[i] = 0;
        p[i] = -1;
    }
    dist[src] = 0;
    for (int cnt = 0; cnt < V - 1; cnt++) {
        int min = INF, mindex;
        for (int v = 0; v < V; v++) {
            if (!visit[v] && dist[v] <= min) {
                min = dist[v];
                mindex = v;
            }
        }
        int u = mindex;
        visit[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visit[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                p[v] = u;
            }
        }
    }
}

int main() {
    int graph[V][V] = {{0, 2, 0, 4, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0},
        {2, 0, 5, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 3, 0, 0, 0, 0, 0},
        {0, 5, 0, 6, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4, 0, 0, 0, 0},
        {4, 7, 6, 0, 0, 5, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 0, 0, 0, 6, 3, 0, 0, 7, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0},
        {0, 0, 0, 5, 6, 0, 0, 4, 9, 0, 7, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 2, 0, 3, 0, 0, 5, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 5, 0, 0, 0, 6, 7, 0, 8, 0, 0, 0, 0, 0, 9, 0, 0},
        {0, 0, 0, 8, 0, 9, 0, 0, 0, 3, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 9, 7, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 7, 0, 8, 0, 0, 0, 0, 4, 5, 6, 0, 0, 0, 9, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 6, 7, 0, 0, 0, 0, 0, 4, 0, 0, 0, 6, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 7, 0, 7, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 6, 0, 5, 6},
        {6, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 7, 0, 8, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 6, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 6, 0, 9, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0, 0, 7, 0, 0, 0}};

    int nShops, intershop[20]; 
    int dist[V], p[V];
    int src = 0; 
    float velo;
    float t;
    
    
    printf("Available Shops:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: %s\n", i, shop[i]);
    }


    
    printf("Enter the number of shops to visit (excluding starting point 0): ");
    scanf("%d", &nShops);

    printf("Enter the indices of the shops to visit (between 1 and %d):\n", V-1);
    for (int i = 0; i < nShops; i++) {
        scanf("%d", &intershop[i]);
    }
    
    printf("Enter your speed of your mode of transportation in kmph\n");
    scanf("%f", &velo);

    
    int totalShops = nShops + 2;
    int path[totalShops];
    path[0] = 0; 
    for (int i = 0; i < nShops; i++) {
        path[i + 1] = intershop[i];
    }
    path[totalShops - 1] = 0; 

    int totaldist = 0;
    printf("\nRoute and distances:\n");
    for (int i = 0; i < totalShops - 1; i++) {
        int srcNode = path[i];
        int fnode = path[i + 1];

        dijkstra(graph, srcNode, dist, p);
        
        printf("Shortest path from %s to %s:\n", shop[srcNode], shop[fnode]);
        printf("Path: ");
        printPath(p, fnode);
        printf("\nTotal distance in Kilometers: %d\n", dist[fnode]);

        totaldist = totaldist + dist[fnode];
    }

    printf("\nTotal distance for the complete route: %d\n", totaldist);
    
    t = totaldist/velo;
    
    printf("TIme taken to cover the route is %f hours", t);

    return 0;
}
