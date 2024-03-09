#include "distance_lib.h"

int main()
{
//declaring teh cities with keys	
	 City cities[MAX_CITY_NAME_LENGTH] = 
	 {
        {"Flagstaff", 0},
        {"Williams", 1},
        {"Rimrock", 2},
        {"Camp Verde", 3},
        {"Spring Valley", 4},
        {"Bumble Bee", 5},
        {"Glendale", 6},
        {"Rock Springs", 7},
        {"Anthem", 8},
        {"Glendale", 9},
        {"Phoenix", 10}
    };
	//declaring variables
	char choice;
	Node* adjList[MAX_CITY_NAME_LENGTH] = {NULL};
	Distance distances[MAX_CITY_NAME_LENGTH];
	//inserting the edge and adding the distance
	insertEdge(adjList,cities[0].city_index,cities[1].city_index);
	addDistance(distances,cities[0].name_of_city,cities[1].name_of_city,100.5);
	insertEdge(adjList,cities[1].city_index,cities[2].city_index);
	addDistance(distances,cities[1].name_of_city,cities[2].name_of_city,50.2);
	
	insertEdge(adjList,cities[2].city_index,cities[3].city_index);
	addDistance(distances,cities[2].name_of_city,cities[3].name_of_city,75.5);
	
	insertEdge(adjList,cities[3].city_index,cities[4].city_index);
	addDistance(distances,cities[3].name_of_city,cities[4].name_of_city,120.1);
	
	insertEdge(adjList,cities[4].city_index,cities[5].city_index);
	addDistance(distances,cities[4].name_of_city,cities[5].name_of_city,75.0);
	
	insertEdge(adjList,cities[5].city_index,cities[6].city_index);
	addDistance(distances,cities[5].name_of_city,cities[6].name_of_city,60.5);
	
	insertEdge(adjList,cities[6].city_index,cities[7].city_index);
	addDistance(distances,cities[6].name_of_city,cities[7].name_of_city,50.5);
	
	insertEdge(adjList,cities[7].city_index,cities[8].city_index);
	addDistance(distances,cities[7].name_of_city,cities[8].name_of_city,40.0);
	
	insertEdge(adjList,cities[8].city_index,cities[9].city_index);
	addDistance(distances,cities[8].name_of_city,cities[9].name_of_city,35.5);	
	
	insertEdge(adjList,cities[9].city_index,cities[10].city_index);
	addDistance(distances,cities[9].name_of_city,cities[10].name_of_city,20.8);
	//printing the list of cities
	 printf("\nList of Cities:\n");
	 int i;
        for ( i = 0; i <= 10; i++) 
        {
            printf("%d: %s\n", i, cities[i].name_of_city);
        }
        
	int source ;
    int destination;
    
    do
	{
		//getting the source and destination from user
		printf("\nEnter the index for source city: ");
        while (scanf("%d", &source) != 1 || source < 0 || source >= 10) 
        {
        	//checking is invalid input
            printf("Invalid input. Please enter a valid index between 0 and 9: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        
        printf("Enter the index for destination city: ");
        while (scanf("%d", &destination) != 1 || destination < 0 || destination > 10) 
        {
        	//checking is invalid input
            printf("Invalid input. Please enter a valid index between 0 and 10: ");
            while (getchar() != '\n'); // Clear input buffer
        }
		// Print the distance between two cities
	printf("Finding the path between %s and %s...\n", cities[source].name_of_city, cities[destination].name_of_city);
    
    //Breadth-First Search algorithm to traverse an adjacency list graph, from source node to a destination node
	bfs(adjList, source, destination,cities,distances);
	//finding the distance of source and destination city
    double distance = findDistance(distances, cities[source].name_of_city, cities[destination].name_of_city);
    	// Ask the user if they want to calculate another path
        printf("\nDo you want to calculate another path? (y/n): ");
        choice = getChoiceYN();
	}while (choice == 'y' || choice == 'Y');
    
	return 0;
}

