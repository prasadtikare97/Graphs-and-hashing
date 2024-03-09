// inclusion guards
#ifndef HANGMAN_LIB
#define HANGMAN_LIB
// header files
#include <stdio.h>
#include <stdlib.h> // for rand, srand
#include <time.h> // for time
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type
#include <string.h> // for STRING data type
// global constants
#define FRUITS_LEN 104
#define ATTEMPTS 6
#define MAX_FRUIT_SIZE 25
#define LEN_FRUITS 104
//declaring global array for fruits
extern const char* FRUITS[LEN_FRUITS];

//initializing the functions
/**
* Name: initializeRandom
* param: no parameter
* return: no value 
* Dependencies: time.h - rand
**/
void initializeRandom();

/**
* Name: getSecretWord
* param: char array
* return: length of array
* Dependencies: none
**/
int getSecretWord( char secretWord[]);

/**
* Name: buildOutputArray
* param: int size
* param: char outputArray
* return: length of array
* Dependencies: none
**/
void buildOutputArray(int size, char outputArray[]);

/**
* Name: buildAttemptArray
* param: int size
* param: no value 
* return: no value 
* Dependencies: none
**/
char* buildAttemptArray();

/**
* Name: checkGuess
* param: char guess
* param: constant char array secretWord 
* return: character array
* Dependencies: none
**/
bool checkGuess(char guess,const char* secretWord);

/**
* Name: fillOutputArray
* param: char guess
* param: constant char pointer secretWord 
* param: constant char array outputArray 
* return: boolean
* Dependencies: none
**/
bool fillOutputArray(char guess, char* secretWord,char outputArray[] );

/**
* Name: fillAttemptsArray
* param: char guess
* param: constant char pointer attempts 
* return: boolean
* Dependencies: none
**/
bool fillAttemptsArray(char guess,  char* attempts);

/**
* Name: checkVictory
* @param: char array outputArray 
* param: int size
* return: boolean
* Dependencies: none
**/
bool checkVictory(char outputArray[] ,int size);

/**
* Name: checkDefeat
* @param: char array attempts 
* return: boolean
* Dependencies: none
**/
bool checkDefeat( char* attempts);

/**
* Name: play
* @param: char pointer giveup 
* return: boolean
* Dependencies: string.h ,
**/
bool play(bool* giveup);

#endif

