#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int m =21;
    int u,c;
    srand(time(0));
    printf("Welcome to the Matchstick Game!\n");
    printf("Rules: Pick 1, 2, 3, or 4 matchsticks each turn.\n");
    printf("Whoever is forced to pick the last matchstick loses.\n\n");
    printf("Number of matchsticks: %d\n", m);
    while( m>1 ){
        // printf("Number of matchsticks left: %d\n", m);
        printf("Your turn!,Pick 1, 2, 3, or 4 matchsticks\n");
        scanf("%d",&u);
        printf("Number of matchsticks left: %d\n", m);
        if(u<1||u>4){
            printf("Invalid input. Please try again.\n");
            continue;
        }
        m -= u;
        if (m == 1) {
            printf("Only one matchstick left. Computer is forced to pick it up.\n");
            printf("Congratulations! You Win!\n");
            break;
        }
        // c= m>4?((rand()%4) + 1):((rand()%m) + 1);  // Random number between 1 and 4
        c = 5 - u; //for computer to always win!
        printf("Computer's turn.\nComputer picked ...%d matchsticks.\n", c);
        m -= c;
        printf("Number of matchsticks left: %d\n\n", m);
        if (m == 1) {
            printf("Only one matchstick left. You are forced to pick it up.\n");
            printf("You Lose!\n");
            break;
        }
        else if(m<1){
            printf("Congratulations! You Win!\n");
            break;
        }
    }
    return 0;
}