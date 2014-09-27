#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularLinkedList.h"

NodePtr insert(NodePtr lastNode, int data) 
{
    NodePtr firstNode;
    
    // Create a NodePtr called newNode
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(1);
    }
    
    // Give newNode some data
    newNode-> data = data;
    // For now, link it to itself
    newNode-> next = newNode;
    
    // Add lastNode to the beginning of the linked list
    if (lastNode == NULL)
    {                         
        lastNode = newNode;
    }
    else
    {
        // Find the node after lastNode, and assign it to first 
        firstNode = lastNode-> next;
        
        // Change the link of last node
        lastNode-> next = newNode;
        
        // Make this new node link to the firstNode
        newNode-> next = firstNode;
        
        // reassign the last node to the new node
        lastNode = newNode;
    }
    
    return lastNode;
}

NodePtr inputPlayers(void)
{
    int i, numPlayers;
    NodePtr lastNode = NULL;
    
    // Prompt user for number of players
    printf("Please enter the number of players in your game: ");
    scanf("%d", &numPlayers);

    // Creates a circular linked list of those players
    for(i = 1; i <= numPlayers; i++)
    {
        lastNode = insert(lastNode, i);
    }

    return lastNode;
}

void displayPlayers(NodePtr aNode)
{
    NodePtr firstNode;
    NodePtr curr;
    if (aNode == NULL)
        return;

    firstNode = aNode-> next;

    curr = firstNode;
    
    printf("\nRemaining players: ");

    do
    {
        printf("\tPlayer %d ", curr-> data);
        curr = curr-> next;
    }    
    while(curr != firstNode);
    
    printf("\n");

    return;
}

char** inputRhyme(void)
{    
    const int MAX_LETTERS = 10;
    int numWords; 
    int i = 0;
    char** rhyme = NULL;
    char tempWord[MAX_LETTERS];
    
    printf("\nPlease enter the number of words in your rhyme: ");
    scanf("%d", &numWords);
    
    // malloc enough space for each word
    rhyme = (char**) malloc(numWords * sizeof(char*)); 
    if (rhyme == NULL)
    {
        fprintf(stderr, "Not enough memory!\n");
        exit(1);
    }

    for (i = 0; i < numWords; i++)
    {
        rhyme[i] = (char*) malloc(sizeof(char));
        if (rhyme[i] == NULL)
        {
            fprintf(stderr, "Not enough memory!\n");
            exit(1);
        }
        
        printf("Word %d: ", i+1);
       // fgets(tempWord, MAX_LETTERS, stdin);
       // getchar(); // deal with fgets()'s newline problem
        scanf("%9s", &*tempWord); // limit to MAX_LETTERS-1 for safety
     
        strcpy(rhyme[i], tempWord);
    }
    
    rhyme[numWords] = NULL;
    
    return rhyme;
}

void displayRhyme(char** rhyme)
{
    int i = 0;
    
    printf("\nYour rhyme is: \n");
    
    for (i = 0; rhyme[i] != NULL; i++)
    {
        printf("%s ", rhyme[i]);
    }
    
    printf("\n\n");

    return;
}

void removePlayer(NodePtr prev, NodePtr curr)
{
    prev-> next = curr-> next;

    free(curr);
    
    return;
}

NodePtr sayRhyme(char** rhyme, NodePtr startingPlayer)
{
    int i = 0;
    NodePtr prev = startingPlayer;
    NodePtr curr = startingPlayer;

    printf("Player %d says %s\n", curr-> data, rhyme[i]);
    i++;

    do 
    {
        prev = curr; 
        curr = curr->next;
        printf("Player %d says %s\n", curr-> data, rhyme[i]);
        i++;
    } 
    while (rhyme[i] != NULL);

    printf("\nPlayer %d is OUT.\n", curr-> data);

    removePlayer(prev, curr);

    startingPlayer = prev-> next;
    printf("Next round will start from Player %d\n", startingPlayer-> data  ); 

    displayPlayers(prev);

    return startingPlayer;
}


