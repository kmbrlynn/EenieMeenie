#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularLinkedList.h"

int main(int argc, char* argv[])
{
    NodePtr lastNode = NULL;
    NodePtr startingPlayer = NULL;
    
    char ** rhyme;
    
    lastNode = inputPlayers();

    displayPlayers(lastNode);
    
    rhyme = inputRhyme();
    
    displayRhyme(rhyme);

    startingPlayer = lastNode-> next;
     
    while (startingPlayer-> next != startingPlayer)
    {
        startingPlayer = sayRhyme(rhyme, startingPlayer);
    }
 
    printf("*** Player %d WINS! ***\n", startingPlayer-> data);

    return 0; 
}