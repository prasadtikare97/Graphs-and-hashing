// header files
#include "hangman_lib.h"

//main function
int main()
{
	//declaring variables
	char playAgain;
	initializeRandom(); // initialize the random number generator
	//print title
	printf("\n***************************");
	printf("\nWelcome to the Hangman Game");
	printf("\n***************************\n");
	
	do
	{
		bool giveup=true;
		if(play(&giveup) == true)
		{ // check if user won
			printf("\nYou won the round! Well done!");
		}
		else if(giveup == true)
		{ // if user type 0 to give up
			printf("\nYou gave up!");
			printf("\nCome back another time!");
			return 0;
		}
		else
		{
			printf("\nYou lost the round!"); // if user is defeated
		}
		printf("\nDo you want to play again? (y/n): "); // check to play again
        scanf(" %c", &playAgain); // input from user
        playAgain = tolower(playAgain); // lower variable
        int number =0;
        if(playAgain == 'y' || playAgain == 'n') // if any other input other than y and n
        {
        	number=0;
		}
		else{
		while(!number)
		{
        	printf("\nI didn't get that. Please use y to yes and n to no."); //print msg
        	printf("\nDo you want to play again? (y/n): ");
      		scanf(" %c", &playAgain);// input from user
        	playAgain = tolower(playAgain);// lower variable
        	if(playAgain == 'y' || playAgain == 'n')
        	{
        		number = 1;
			}
        } // condition to break the loop;
		}
		
	}while(playAgain == 'y');// condition to continue the loop
	printf("\nCome back another time!");// exit message
	return 0;
}












