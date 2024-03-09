// header files
#include "hangman_lib.h"

//declaring the array of secret words
const char* FRUITS[104] = {"abiu",  "acai", "acerola", "akebi", "ackee", 
    "apple", "apricot", "araza", "avocado", "banana", "bilberry", "blackberry",
    "blackcurrant", "blueberry", "boysenberry", "breadfruit", "canistel",
    "cashew", "cempedak", "cherimoya", "cherry", "cloudberry", "coconut",
    "cranberry", "currant", "damson", "date", "dragonfruit", "pitaya", "durian",
    "elderberry", "feijoa", "fig", "gooseberry", "grape", "raisin",
    "grapefruit", "guava", "honeyberry", "huckleberry", "jabuticaba", "plinia",
    "jackfruit", "jambul", "jostaberry", "jujube", "kiwano", "kiwifruit",
    "kumquat", "lemon", "lime", "loganberry", "longan", "loquat", "lulo",
    "lychee", "mango", "mangosteen", "marionberry", "melon", "cantaloupe",
    "galia", "melon", "honeydew", "watermelon", "mulberry", "nance",
    "nectarine", "orange", "clementine", "mandarine", "tangerine", "papaya",
    "passionfruit", "pawpaw", "peach", "pear", "persimmon", "plantain", "plum", 
    "prune", "pineapple", "pineberry", "plumcot", "pluot", "pomegranate",
    "pomelo", "quince", "raspberry", "salmonberry", "rambutan", "redcurrant",
    "salak", "sapodilla", "sapote", "satsuma", "soursop", "strawberry",
    "tamarillo", "tamarind", "tangelo", "tayberry", "ximenia", "yuzu"};

void initializeRandom()
{
	//seeding for the random number to get generated at the given time
	srand(time(0)); // Using current time for each execution

}
int getSecretWord(char secretWord[])
{
	int index =  rand() % FRUITS_LEN +1; //getting the secret word index
	const char* new_word = FRUITS[index]; // adding it word from fruits to new character
	strcpy(secretWord, new_word);// copying the word
    
    // getting the length of the secret word
    int length= strlen(new_word); // 
	return length; // rteurning length
}

void buildOutputArray(int size, char outputArray[]) 
{
	int i;
	for ( i = 0; i < size; i++)
	{
        outputArray[i] = '_'; // Filling the output array with underscores
    }
}

char* buildAttemptArray()
{
	char* array= (char*)malloc(7 * sizeof(char));
	int i;
	for(i=0;i<6;i++)
	{
		array[i] = '*'; // Filling the attempt array with stars
	}
		array[6] = '\0'; // last element is null
return array;
}

bool checkGuess(char guess, const char* secretWord)
{
	int j;
	for(j=0;secretWord[j] !='\0';j++)
	{
		if(guess == secretWord[j])
		{ //guessing the word is present in secret word or not	
		return true;
		}
	}
	return false;	
}

bool fillOutputArray(char guess, char* secretWord,char outputArray[] )
{
	int i;
	bool fill_All = false;
		for(i=0;secretWord[i] !='\0';i++)
		{
		//	printf("\nfillOutputArray");
		if(secretWord[i] == guess){ //checking if the array has secret word and underscore 
			if(outputArray[i] == '_')
			{
				outputArray[i] = guess; // add thet word to output array
				fill_All =true;
			}
			else{
				return false;
			}
		}
	}
	return fill_All;
}

bool fillAttemptsArray(char guess,char* attempts)
{
	int i;
		for(i=0;attempts[i] !='\0';i++)
		{
		if(attempts[i] == '*'){ // checking if the array has stars
		attempts[i] = guess; // adding incorrect word to attempts array
		return true;
		}
		else if (attempts[i] == guess) // if the attempts word already has the guess word
		{
            return false;
		}
		}
	return false;
}

bool checkVictory(char outputArray[] ,int size)
{
		int i;
		for(i=0;i <size;i++){
			if(outputArray[i] == '_')
			{ // checking if the output array is having any underscore
				return false;
			}		
		}
		return true; // victory
}

bool checkDefeat( char* attempts){
		int i;
		for(i=0;attempts[i] !='\0';i++)
		{
			if(attempts[i] == '*')
			{ // checking if the attempts array is having any stars
				return false;
			}	
		}
		return true;// defeat
}

bool play(bool* giveup)
{
	//declaring variables and arrays
	char secret_word[MAX_FRUIT_SIZE];
	int size;
	size=getSecretWord(secret_word); //get secret word
	char* attempts = buildAttemptArray(); // build array '*'
	//printf("attempt array : %s",attempts);
	char outputArray[MAX_FRUIT_SIZE];
	buildOutputArray(size,outputArray); // build output array '_'
	//printf("\n%s",secret_word);
	int total_attempts =6;
	while(total_attempts > 0)
	{
	
	char guess;
	printf("\n\nWhich letter? (0 to exit the game): \n"); // user input for getting guess
    scanf(" %c", &guess);
    if(guess == '0'){ // if 0 then leave the game
    *giveup=true;
	return false;	
	}
	
	if (checkGuess(guess, secret_word) == true)
	{ // guessing the word
		if(fillOutputArray(guess,secret_word,outputArray))
		{ // filling the word in array
			printf("%s",outputArray); // print the array
			if (checkVictory(outputArray, size))
			{ //checking victory
                *giveup = false;
                return true;
            }
		}
		else 
		{
            printf("Repeated guess. Try another letter!\n"); // if guess is repeated then  print msg
        }
	}
	else
	{
		printf("\nThe letter doesn't exist in the word.");// print message
		fillAttemptsArray(guess,attempts);// fill incorrect guess in attempt array
		printf("\nMistakes: %s",attempts);// print array
		
		if (checkDefeat(attempts)) 
		{ //check defeat if attempt array is full
            *giveup = false;
            printf("\nThe secret word was: %s",secret_word);
            return false;
        }
        total_attempts--;
    }

}
free(attempts);
return false;
}
