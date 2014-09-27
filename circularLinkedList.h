#define NAMELENGTH 15

typedef struct node 
{
    int data;
    struct node *next;
} Node, *NodePtr;   

//Precondition: User has entered the number of players
//Postcondition: Inserts a new player into the linked list of players
NodePtr insert(NodePtr firstNode, int data);

// Precondition: None
// Postcondition: User has inputted number of players
NodePtr inputPlayers(void);

// Precondition: (1) User has specified number of players, 
//               (2) Each player has been inserted to the linked list as a node
// Postcondition: Displays all data in the linked list starting from the first node
void displayPlayers(NodePtr firstNode);

//Precondition: None
//Postcondition: Player has inputted a rhyme for the players to say
char** inputRhyme(void);

// Precondition: User has inputted rhyme
// Postcondition: Displays all the words in the rhyme
void displayRhyme(char** rhyme);

// Precondition: List of players has been created
// Postcondition: Removes a player from the circ. linked list, if there are 2+ players
void removePlayer(NodePtr prev, NodePtr curr);

// Precondition: The number of players and the rhyme have been specified
// Postcondition: One round of the rhyme is printed to the screen
NodePtr sayRhyme(char** rhyme, NodePtr startingPlayer);

