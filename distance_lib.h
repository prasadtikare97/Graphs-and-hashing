// inclusion guards
#ifndef DISTANCE_LIB_H
#define DISTANCE_LIB_H

// header files
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type
#include <time.h>
#include <string.h>

// global constants
#define LENGTH 10
#define NOT_FOUND -1
#define SPECIFIER "%ld"
#define MAX_CITY_NAME_LENGTH 50
#define MAX_CITIES 100


// data type definition
typedef long int dtype;

//declaring Node
typedef struct Node {
    int citys_key;
    struct Node *next;
} Node;

//declaring City
typedef struct City {
    char name_of_city[MAX_CITY_NAME_LENGTH];
    int city_index;
    Node* neighbors[MAX_CITY_NAME_LENGTH];
} City;

//declaring Distance
typedef struct Distance {
    
    City* city1;
    City* city2;
    int key;
    double distance;
} Distance;

// Define structs queue
typedef struct Queue 
{
    int items[MAX_CITIES];
    int front;
    int rear;
} 
Queue;

/**
* @brief Inserts an edge in the adjacency list between two vertices.
* The time complexity of this algorithm is O(1) 
*
* @param  Node for adjacency list.
* @param Integer to source
* @param Integer to destination
**/
void insertEdge(Node** adjacencyList, int source, int destination);
/**
* @brief  Prints the path between two cities in the graph..
* The time complexity of this algorithm is O(1) 
*
* @param  array for parent 
* @param Integer to source
* @param Integer to destination
* @param pointer to cities
* @param Integer to distance
**/
void printPath(int parent[], int source, int destination, City* cities, Distance* table);
/**
* @brief Performs Breadth-First Search on a graph.to find a path to a destination node.
* The time complexity is O(V + E)
*
* @param Node for adjacency list representing the graph.
* @param Integer to source
* @param Integer to destination
* @param pointer to cities
* @param Integer to distance
**/
void bfs(Node *adjList[], int source, int destination, City* cities,Distance distances[]);
/**
* @brief Generates a hash key for a pair of city names based on the ASCII in two city names.
* The time complexity is O(n) 
*
* @param city1 Name of the first city.
* @param city2 Name of the second city.
* @return The calculated hash key.
**/
int hash(const char* city1,const char* city2);
/**
* @brief Finds the distance between two specified cities.
*
* The time complexity is O(1) 
*
* @param distances The array of Distance structures.
* @param cityName1 The name of the first city.
* @param cityName2 The name of the second city.
* @return The distance between the cities, or -1 if not found.
**/
double findDistance(Distance distances[], const char* city1, const char* city2);
/**
* @brief To check if teh string is equal or not
*
* The time complexity is O(n) 
*
* @param distances The array of Distance structures.
* @param str1 The name of the first city.
* @param str2 The name of the second city.
* @return boolean true or false
**/
bool areStringsEqual(const char* str1, const char* str2);

/**
* @brief Adds a distance between two cities in the distances array using hash key.
*
* Handles collisions using linear probing. The time complexity is O(1) on average, but can be worse in case of many collisions.
*
* @param distances array to store distances.
* @param char pointer to city1.
* @param char pointer to city1.
* @param double distance for calculating distances.
**/
void addDistance(Distance distances[], const char* city1, const char* city2, double distance);

/**
* @brief Creates an empty queue
*
* This function initializes and returns an empty queue
* time time complexity os O(1)
*param NA
*
* @return NA
*/
Queue* createQueue();

/**
* @brief Enqueues a node into a queue.
*
* This function enqueues a given heap node into the specified queue.
*
* @param queue The queue to enqueue the node into.
* @param node The heap node to enqueue.
*/
void enqueue(Queue* q, int value);
/**
* @brief dequeues a node from a queue.
*
* This function enqueues a given heap node from the specified queue.
*
* @param  The queue to dequeue the node into.
*/
int dequeue(Queue* q);

/**
* @brief checking if the queue is empty or not
*
* @param  pointer to the queue
*/

bool isEmpty(Queue* q);

/**
* @brief  function to get the user input y or n
*
* The time complexity of this algorithm is <O(1)>
*
* @param NA
**/
char getChoiceYN();
// end SEARCH_LIB
#endif
