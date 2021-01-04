#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_intro();
void play_game();
void vs_mode();
void sword_attack(int *burglarHealth, int *heroHealth);
void lightning_attack(int *burglarHealth, int *heroHealth);
void fist_attack(int *burglarHealth, int *heroHealth);
int rand_burglar();
int rand_sword();
int rand_int_lightning();
int rand_int_fist();
int random_number(int min_num, int max_num);

int main()
{
    int choice;
    char name[100];

    printf("\nEnter your name: ");
    fgets(name, 10, stdin);
    printf("\nHello there litte %s", name);

    printf("\nOnce upon a time there was a young adventurer who loves to collect treasures \nand keep it at home as a souvenir.\nIn all of the times in all of his treasure hunts, he also accumulated a lot.\nHe went to various houses and places because of treasure hunting.\n");

    do{

    printf("\nDo you want to play a game 1 for yes 0 for no\n");
    scanf("%i", &choice);

    if(choice==1)
       game_intro();
    else if(choice==0)
        printf("You're no fun!\n");
    else
        printf("Please choose correctly.");

   }while(choice!=0 && choice!=1);

    return 0;
}

void game_intro()
{
    int choice;

    printf("\nOne day the adventurer heard that in an abandoned mansion deep in the woods\nwas taken care of the past owner,\neverything was all well until the owner had abandoned its house and flew to a new place.\nA treasure was left behind by the previous owner.\n");
    printf("\nThe young adventurer was excited to go into that place and look for the lost treasure.\nHe prepared all of his stuffs and travels for days.\nAfter a long journey through the woods,\nwhen you have finally arrived in front of the large gates of the abandoned mansion.\nThe entranced was locked, What will you do?\n");

    do {
        printf("1 for CLIMB \n2 for PEAK\n");
        scanf("%d", &choice);

        if(choice == 1) {
            play_game();
        }else if (choice == 2) {
            printf("Someone saw you, you died they kill you.");
        } else {
            printf("Please choose only from the options sire!\n");
        }

    }while(choice != 1 && choice !=2);
}

void play_game()
{
    int choice;

    printf("\nWELCOME LITTLE ADVENTURER!\n");
    printf("\nGet ready for a thrilling adventure! You are now at the entrance of the mansion.\nBefore entering the abandoned house, you saw an old lady dressed in a brown cloak\nand approaches you.\nOld Lady: A brave adventurer has come to take the lost treasure.\nIn front of you is a large door, where do you want to go?\n\n");

    do {
        printf("UP DOWN LEFT RIGHT\n");
        printf("1 for UP \n2 for DOWN \n3 for LEFT \n4 for RIGHT\n");
        scanf("%d", &choice);

        if(choice == 2 || choice ==3 || choice == 4) {
            printf("I think we need to enter the house. Please try again\n");
        } else if (choice < 1 || choice > 4){
            printf("Choice only in the options.\n");
        } else if(choice == 1) {
            vs_mode();
        }

    }while(choice != 1);


}

void vs_mode()
{
    int choice;
    int burglar = 60;
    int hero = 60;

    while(burglar > 0 && hero > 0) {
        printf("\nCurrent Health: %i\nAttack with what?\n 1:Sword\n 2:Lightning\n 3:Fist\n\n",hero);
        scanf("%i",&choice);

        if(choice == 1) {
            sword_attack(&burglar, &hero);
        }else if(choice == 2) {
            lightning_attack(&burglar, &hero);
        }else if(choice == 3) {
            fist_attack(&burglar, &hero);
        }else if (choice < 1 || choice > 3) {
            printf("Please choose only the 3 skills you have.\n");
        }
    }
}

void sword_attack(int *burglarHealth, int *heroHealth)
{
    int heroDmg = rand_sword();
    int burglarDmg = rand_burglar();

    printf("\nSWING!! Damage %i\n\n",heroDmg);
    *burglarHealth -= heroDmg;

    if(*burglarHealth < 0)
        *burglarHealth = 0;

    printf("The burglar life points are now %i\n\n", *burglarHealth);

    if(*burglarHealth <= 0) {
        printf("You have killed the burglar you win!\n\n");
    }else{
        printf("The burglar takes a swing BANG! Damage : %i\n", burglarDmg);
        *heroHealth -= burglarDmg;

        if(*heroHealth <= 0) {
            printf("You have been killed. You lose.\n");
        }
    }
}

void lightning_attack(int *burglarHealth, int *heroHealth)
{
    int heroDmg = rand_int_lightning();
    int burglarDmg = rand_burglar();

    printf("\nSWING!! Damage %i\n\n",heroDmg);
    *burglarHealth -= heroDmg;

    if(*burglarHealth < 0)
        *burglarHealth = 0;

    printf("The burglar life points are now %i\n\n", *burglarHealth);

    if(*burglarHealth <= 0) {
        printf("You have killed the burglar you win!\n\n");
    }else{
        printf("The burglar takes a swing BANG! Damage : %i\n", burglarDmg);
        *heroHealth -= burglarDmg;

        if(*heroHealth <= 0) {
            printf("You have been killed. You lose.\n");
        }
    }
}

void fist_attack(int *burglarHealth, int *heroHealth)
{
    int heroDmg = rand_int_fist();
    int burglarDmg = rand_burglar();

    printf("\nSWING!! Damage %i\n\n",heroDmg);
    *burglarHealth -= heroDmg;

    if(*burglarHealth < 0)
        *burglarHealth = 0;

    printf("The burglar life points are now %i\n\n", *burglarHealth);

    if(*burglarHealth <= 0) {
        printf("You have killed the burglar you win!\n\n");
    }else{
        printf("The burglar takes a swing BANG! Damage : %i\n", burglarDmg);
        *heroHealth -= burglarDmg;

        if(*heroHealth <= 0) {
            printf("You have been killed. You lose.\n");
        }
    }
}

int rand_burglar()
{
    return random_number(0,10);
}

int rand_sword ()
{
    return random_number(0,15);
}

int rand_int_lightning()
{
    return random_number(0,20);
}
int rand_int_fist()
{
    return random_number(0,5);
}


int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}










