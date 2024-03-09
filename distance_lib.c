#include "distance_lib.h"

//inserting the edge between vertices source and destination
void insertEdge(Node** adjacencyList, int source, int destination)
{
	//declaring the newnode
	Node* new_node= (Node*)malloc(sizeof(Node));
	if(new_node == NULL)
	{
		return;
	}
	 // Initializing the new node
	new_node->citys_key = destination;
	new_node->next = adjacencyList[source];
	//head of the linked list updated to new node.
	adjacencyList[source] =  new_node;
}

//prints the path between two cities in a graph 
void printPath(int parent[], int source, int destination, City* cities, Distance table[]) 
{
	//if no path exists
    if (parent[destination] == -1) 
	{
        printf("\n No path exists between %s and %s.", cities[source].name_of_city, cities[destination].name_of_city);
        return;
    }
	//declaring variables
    int path_index = 0;
    int current = destination;
    int path[MAX_CITY_NAME_LENGTH];

    while (current != source) 
	{
		//adding the current path
        path[path_index] = current;
        path_index++;
        current = parent[current];
    }
    //adding source path 
    path[path_index] = source;

    double total_distance = 0.0;
    int i;
    //getting the city path and finding the distance and adding it 
    for (i = 0; i < path_index; i++)
	{
        int city1 = path[i];
        int city2 = path[i + 1];
        double distance = findDistance(table, cities[city1].name_of_city, cities[city2].name_of_city);
        addDistance(table, cities[city1].name_of_city, cities[city2].name_of_city, distance);
        total_distance += distance;
    }
	//printing the path
    printf("\nPath between %s and %s :", cities[source].name_of_city, cities[destination].name_of_city, total_distance);
    for (i = path_index; i >= 0; i--) 
	{
        printf("%s", cities[path[i]].name_of_city);
        if ( path_index+1 > i) 
		{
            printf(",");
        }
    }
    // printing distance
    printf("\nThe distance is (%0.2lf):", total_distance);
	printf("\n");
}

//Breadth-First Search algorithm to traverse list graph,
void bfs(Node *adjList[], int source, int destination, City* cities,Distance distances[]) 
{
	//declaring the variables
    bool visited[MAX_CITIES] = {false};
    int parent[MAX_CITIES],i;
	for ( i = 0; i < MAX_CITIES; i++)
     {
        parent[i] = -1; // Initialize all parent indices to -1 (indicating no parent)
    }
    visited[source] = true;

    int queue[MAX_CITY_NAME_LENGTH];
    //create queue
        Queue* q = createQueue();
        visited[source] = true;
	//enqueue
    enqueue(q, source);
	 // searching while there are cities in the queue
    while (!isEmpty(q)) 
    {
        // Dequeue a city from the queue
        int current = dequeue(q);
		//adding adjacent list o node
        Node* temp = adjList[current];

        //Traverse the list
        while (temp != NULL) 
        {
            int adjCity = temp->citys_key; 

            // If the adjacent city hasn't been visited yet
            if (!visited[adjCity]) 
            {
            	// Marking it as visited and enqueuing it
                visited[adjCity] = true; 
                parent[adjCity] = current;
                enqueue(q, adjCity); 

                // If the destination city is reached
                if (adjCity == destination) 
                {
                    // Print the path from source to destination
                    printPath(parent, source, destination, cities, distances);
                    free(q); // Free the queue memory
                    return; 
                }
            }
            temp = temp->next; // Move to the next node
        }
    }

    // Free the queue memory
    free(q);
	  // If the destination city is not found, print path
    printPath(parent, source, destination, cities, distances);
}
//hashing and calculates a key by aggregating the ASCII characters
int hash(const char* city1,const char* city2)
{
	int key=0;
	int i;
	//getting the keys from the city
	for(i=0;i<strlen(city1) && i< strlen(city2); i++)
	{
		key += city1[i] + city2[i];
	}
		for(i=strlen(city1); i< strlen(city2); i++)
	{
		key += city2[i];
	}
	//returns the calculated key
	return key % MAX_CITIES;
	
}
//function for finding the distances
double findDistance(Distance distances[], const char* city1, const char* city2) {
	//getting the calculated key
    int key = hash(city1, city2);
	int current_key = key;
	while (true) 
    {
        // If the distance is not found

        if (distances[key].key == -1) 
        {
            return -1;
        } 
        else if (distances[key].key == key)      
        {
            // Check if the city names match
            if (areStringsEqual(distances[key].city1->name_of_city, city1) == 0 &&
                areStringsEqual(distances[key].city2->name_of_city, city2) == 0) 
			{
                return distances[key].distance;
            }
        }
        // Move to the next 
        key = (key + 1) % MAX_CITIES;
        // Check if we have searched the entire array
        if (key == current_key) 
		{
            return -1;
        }
    }
}
//function to check if both strings for citys are equal
bool areStringsEqual(const char* str1, const char* str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') 
	{
        if (str1[i] != str2[i]) 
		{
            return false;
        }
        i++;
    }
    return str1[i] == str2[i]; // Check if both strings have ended
}

//function to add teh distances
void addDistance(Distance distances[], const char* city1, const char* city2, double distance) 
{
	//getting the calculated key
    int key = hash(city1, city2);

     while (distances[key].key != 0) 
    { 
        key = (key + 1) % MAX_CITIES; 
    }

    // Add the distance to the array at the probed position
    distances[key].key = key;
    distances[key].distance = distance;
    distances[key].city1 = malloc(sizeof(City));
    distances[key].city2 = malloc(sizeof(City));
    strcpy(distances[key].city1->name_of_city, city1);
    strcpy(distances[key].city2->name_of_city, city2);
}


// Function to create and initialize a new queue
Queue* createQueue() 
{
    // Dynamically allocate memory
    Queue* q = (Queue*)malloc(sizeof(Queue));
    // Initialize the front and rear as empty queue
    q->front = -1;
    q->rear = -1;

    return q;
}

// Function to add a value to the rear of the queue
void enqueue(Queue* q, int value) 
{
    // Check if the queue is full 
    if (q->rear == MAX_CITIES - 1) 
    {
        // Print a message queue is full
        printf("\nQueue is Full!!");
    } 
    else 
    {
        // Check if the queue is currently empty
        if (q->front == -1)
            q->front = 0;
        // adding to next rear index
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove queue
int dequeue(Queue* q) 
{
    int item;
    // Check if the queue is empty
    if (isEmpty(q)) 
    {
        // Print a message queue is empty
        printf("Queue is empty");
        item = -1;
    } 
    else 
    {
        // getting the element from front of the queue
        item = q->items[q->front];
        q->front++;
        // Check if the queue has become empty after dequeue
        if (q->front > q->rear) 
        {
            q->front = q->rear = -1;
        }
    }
    // Return the dequeued item
    return item;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) 
{
    // Return true if the front index is empty queue
    return q->front == -1;
}

char getChoiceYN()
{
//declaring a variable
char choice;
char lowerChoice;
while (1)
{
//initializing
	scanf(" %c", &choice);
	//making it lower case
	lowerChoice = tolower(choice);
	//checking if it has yes or no
	if (lowerChoice == 'y' || lowerChoice == 'n')
	{
		return lowerChoice;
	}
	else
	{
		printf("Invalid option. Please type 'y' to restart or 'n' to exit:\n");
	}
}
}
