#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_intro();
void play_game();
void story_mode();
void vs_mode(char enemy_name[], int *hero_health);
int potion(int *player_health);
void sword_attack(int *burglarHealth, int *heroHealth, char enemyName[]);
void lightning_attack(int *burglarHealth, int *heroHealth, char enemyName[]);
void fist_attack(int *burglarHealth, int *heroHealth, char enemyName[]);
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
    fgets(name, 99, stdin);
    printf("\nHello there litte %s", name);

    printf("\nOnce upon a time there was a young adventurer who loves to collect treasures \nand keep it at home as a souvenir.\nIn all of the times in all of his treasure hunts, he also accumulated a lot.\nHe went to various houses and places because of treasure hunting.\n");

    do{

    printf("\nDo you want to play a game?\n[1] for yes\n[0] for no\n>> ");
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

    printf("\nOne day the adventurer heard that in an abandoned mansion deep in the woods\nwas taken care of the past owner,everything was all well until the owner\nhad abandoned its house and flew to a new place.\nA treasure was left behind by the previous owner.\n");
    printf("\nGet ready for a thrilling adventure!\nYou are now at the entrance of the mansion.\nBefore entering the abandoned house, you saw an old ladydressed in a brown cloak and approaches you.\n\nOld Lady: A brave adventurer has come to take the lost treasure. Please take remember these for your safety'N,N,E,E,W'\n");
    printf("\nThe young adventurer was excited to go into that place and look for the lost treasure.\nHe prepared all of his stuffs and travels for days.\nAfter a long journey through the woods.\n\nWhen you have finally arrived in front of the large gates of the abandoned mansion.\nThe entranced was locked, What will you do?\n");

    do {
        printf("[1] for CLIMB \n[2] for PEAK\n>> ");
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
        printf("[1] for UP \n[2] for DOWN \n[3] for LEFT \n[4] for RIGHT\n>> ");
        scanf("%d", &choice);

        if(choice == 2 || choice ==3 || choice == 4) {
            printf("I think we need to enter the house. Please try again\n");
        } else if (choice < 1 || choice > 4){
            printf("Choice only in the options.\n");
        } else if ( choice == 1) {
            story_mode();
        }
    }while(choice != 1);
}


void story_mode()
{
    int choice;
    char burglar[] = "Burglar";
    char spy[] = "Spy";
    char ninja[] = "Ninja";

    int hero = 35;

    printf("You entered the abandoned house, and there's NO going back.\n");
    printf("Wow, it is DARK in here. Where to now?\n");
    do
    {
        printf("[1] for UP \n[2] for DOWN \n[3] for LEFT \n[4] for RIGHT\n>> ");
        scanf("%d",&choice);

        if(choice == 2 || choice == 4 || choice == 3){
            printf("Sadly, there is no going back\nGame Over.");
            return;
        } else if(choice == 1){
            vs_mode(burglar, &hero);
        }
    }while(choice != 1);

    if(hero == 0)
        return;

    printf("Where to next?\n");
    printf("Wow, it is DARK in here. Where to now?\n");

    do {
        printf("[1] for UP \n[2] for DOWN \n[3] for LEFT \n[4] for RIGHT\n>> ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You fell into stairs, sprained yourself cannot climb up again.\nGame Over\n");
            return;
        }else if (choice == 2) {
            printf("You stepped onto a trap and got caught by a spike.\nGame Over\n");
            return;
        }else if (choice == 3) {
            printf("You felt chill down your spine. The next thing you know you got stabbed at the back.\nGame Over\n");
            return;
        }else if (choice < 1 || choice > 4){
            printf("Choice only in the options.\n");
        } else if ( choice == 4) {
            vs_mode(spy, &hero);
        }
    }while(choice != 4);

    if(hero == 0)
        return;

    printf("Where to next?\n");
    printf("Wow, it is DARK in here. Where to now?\n");

    do {
        printf("[1] for UP \n[2] for DOWN \n[3] for LEFT \n[4] for RIGHT\n>> ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You fell into stairs, sprained yourself cannot climb up again.\nGame Over\n");
            return;
        }else if (choice == 2) {
            printf("You stepped onto a trap and got caught by a spike.\nGame Over\n");
            return;
        }else if (choice == 3) {
            printf("You felt chill down your spine. The next thing you know you got stabbed at the back.\nGame Over\n");
            return;
        }else if (choice < 1 || choice > 4){
            printf("Choice only in the options.\n");
        } else if ( choice == 4) {
            vs_mode(ninja, &hero);
        }
    }while(choice != 4);

    if(hero == 0)
        return;

    printf("Adventurer: I can see a room shining. I should probably head there, HAHAHA!\n");
    printf("I feel much closer to my treasure. The next direction will definitely be a lot closer.\n");
    printf("Where to now?\n");

    do {
        printf("[1] for UP \n[2] for DOWN \n[3] for LEFT \n[4] for RIGHT\n>> ");
        scanf("%i", &choice);

        if(choice == 1) {

        } else if(choice == 2) {

        } else if(choice == 4) {

        } else if(choice == 3) {

        }
    }while(choice != 3);



}

void vs_mode (char enemy_name[], int *hero_health)
{
    int choice;
    int enemy_health = 25;

    while(enemy_health > 0 && *hero_health > 0) {
        printf("\nAdventurer's Current Health: %i\nEnemy name: %s\nEnemy health: %i\n\nAttack with what?\n [1] Sword\n [2] Lightning\n [3] Fist\n\n>> ",*hero_health ,enemy_name,enemy_health);
        scanf("%i",&choice);

        if(choice == 1) {
            sword_attack(&enemy_health, hero_health, enemy_name);
        }else if(choice == 2) {
            lightning_attack(&enemy_health, hero_health, enemy_name);
        }else if(choice == 3) {
            fist_attack(&enemy_health, hero_health, enemy_name);
        }else if (choice < 1 || choice > 3) {
            printf("Please choose only the 3 skills you have.\n");
        }

        if(*hero_health <= 10 && *hero_health >= 1) {
            printf("Your current health is now  : %i\nDo you want to use your potion?\n[1]Yes\n[2]No\n>> ", *hero_health );
            scanf("%i", &choice);

            if(choice == 1) {
                *hero_health = potion(hero_health);
            }
        }
}
}

void sword_attack(int *enemyHealth, int *heroHealth, char enemyName[])
{
    int heroDmg = rand_sword();
    int enemyDmg = rand_burglar();

    printf("\nSWING!! Sword attack!\nDamage : %i\n",heroDmg);
    *enemyHealth -= heroDmg;

    if(*enemyHealth < 0)
        *enemyHealth = 0;

    printf("The %s life points are now %i\n\n", enemyName, *enemyHealth);

    if(*enemyHealth <= 0) {
        printf("You have killed the %s you win!\n\n", enemyName);
    }else{
        printf("The %s takes a swing BANGGG!\nDamage done to you: %i\n",enemyName, enemyDmg);
        *heroHealth -= enemyDmg;

        if (*heroHealth < 0)
        *heroHealth = 0;

        if(*heroHealth <= 0) {
            printf("You have been killed. You lose.\n");
        }
    }
}

void lightning_attack(int *enemyHealth, int *heroHealth, char enemyName[])
{
    int heroDmg = rand_int_lightning();
    int enemyDmg = rand_burglar();

    printf("\nSWING!! Lightning Strike!\nDamage : %i\n",heroDmg);
    *enemyHealth -= heroDmg;

    if(*enemyHealth < 0)
        *enemyHealth = 0;

    printf("The %s life points are now %i\n\n",enemyName, *enemyHealth);

    if(*enemyHealth <= 0) {
        printf("You have killed the %s you win!\n\n", enemyName);
    }else{
        printf("The %s takes a swing BANGGG!\n Damage done to you: %i\n",enemyName, enemyDmg);
        *heroHealth -= enemyDmg;

        if (*heroHealth < 0)
        *heroHealth = 0;

        if(*heroHealth <= 0) {
            printf("You have been killed. You lose.\n");
        }
    }
}

void fist_attack(int *enemyHealth, int *heroHealth, char enemyName[])
{
    int heroDmg = rand_int_fist();
    int enemyDmg = rand_burglar();

    printf("\nSWING!! Fist attack!\nDamage : %i\n",heroDmg);
    *enemyHealth -= heroDmg;

    if(*enemyHealth < 0)
        *enemyHealth = 0;

    printf("The %s life points are now %i\n\n",enemyName, *enemyHealth);

    if(*enemyHealth <= 0) {
        printf("You have killed the %s you win!\n\n", enemyName);
    }else{
        printf("The %s takes a swing BANGGG!\n Damage done to you: %i\n",enemyName, enemyDmg);
        *heroHealth -= enemyDmg;

        if (*heroHealth < 0)
        *heroHealth = 0;

        if(*heroHealth <= 0) {
            printf("You have been killed. You lose.\n");
        }
    }
}

int potion(int *player_health)
{
    int potion = 10;

    return *player_health += potion;
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










