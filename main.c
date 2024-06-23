#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char *choices[] = {"rock", "paper", "scissors"};
void enterChoice(char *choice)
{
    printf("Please enter your choice(rock/paper/scissors): ");
    scanf("%8s", choice);
    while (strcmp(choice, "rock") != 0 && strcmp(choice, "paper") != 0 && strcmp(choice, "scissors") != 0)
    {
        printf("Please enter valid choice(rock/paper/scissors): ");
        scanf("%8s", choice);
    }
}
void determineWinner(char *choice1, char *choice2)
{
    if ((strcmp(choice1, choice2) == 0))
    {
        printf("You drew!\n");
    }
    else if ((strcmp(choice1, "rock") == 0 && strcmp(choice2, "scissors") == 0)||
               (strcmp(choice1, "paper") == 0 && strcmp(choice2, "rock") == 0)||
               (strcmp(choice1, "scissors") == 0 && strcmp(choice2, "paper") == 0))
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
void singlePlayer()
{
    printf("You are player 1 and the computer is player 2!\n");
    char choice[9];
    enterChoice(choice);
    srand(time(NULL));
    int computerChoiceIndex = rand() % 3;
    char *computerChoice = choices[computerChoiceIndex];
    printf("The computer(Player 2) chose: %s\n", computerChoice);
    determineWinner(choice, computerChoice);
}
void playWithAFriend()
{
    printf("Player 1, ");
    char choice1[9];
    enterChoice(choice1);
    printf("\nPlayer 2, ");
    char choice2[9];
    enterChoice(choice2);
    determineWinner(choice1, choice2);
}
int main()
{
    printf("Hello and welcome to the Rock/Paper/Scissors game!\n");
    printf("would you like to play the game alone or with a friend?\n");
    printf("Alone(1)                 With a friend(2)\n");
    int choice = 0;
    scanf("%d", &choice);
    while(choice != 1 && choice != 2)
    {
        printf("Please enter valid choice option.\n");
        printf("Alone(1)                 With a friend(2)\n");
        scanf("%d", &choice);
    }
    if(choice == 1)
    {
        singlePlayer();
    }
    else
    {
        playWithAFriend();
    }
    return 0;
}
