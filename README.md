1.Implement a C program that uses graphs and heaps.

Suppose you are given a list of cities and the distance from each other, represented as an undirected graph. You need to find if there is a path between two given cities.

To optimize the search for a path, you decide to implement a hash table to store the distance between two cities. 
The hash table should take the form of a dictionary, where the keys are represented as the pair of cities (e.g., (Flagstaff, Sedona)) and the values are the distances between them.




2. The hangman game is a guessing game where the user guesses letters until they figure out what the secret word is. In most versions of the game, the user has 6 chances to guess the correct word. For each incorrect guess, a part of the hangman is drawn. If the user fails 6 times, the hangman is complete, and the user loses. If the user knows the secret word, they keep guessing the correct letters until the word is complete, which results in a win.
The goal of this assignment is to simulate the hangman game. Because we don’t want to draw the hangman, we will just use textual messages to communicate the user of their status in the game. Follow the items below to complete your game step-by-step.
extra_hangman.c hangman_lib.h hangman_lib.c
