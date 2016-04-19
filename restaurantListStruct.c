//  Yuya Oguchi
//  COEN11L     Lab3
//  10/10/2014
//  restaurantwaitlist Structure
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct customer
{
    int number;
    char name[10];
};

void stats(struct customer wait_list[10], int counter)
{
    int j = 0;

    printf("Current wait list:\n");
    while (j < counter) {
        printf("Name: %s\t # of people: %d",wait_list[j].name, wait_list[j].number);
        printf("\n");
        j+= 1;
    }
    j = 0;
    return;
}

void add( struct customer wait_list[10], int *counter)
{
    int x;
    int result;
    char tempname[10];//name to add to list


                    printf("Please specify your name\n");
                    scanf("%s",tempname); //read in new entry

    for (x = 0; x < *counter; x ++)
    {
        result =  strcmp(wait_list[x].name, tempname);//check for duplicate name and blocl if there is one
        if (result == 0)
        {
            printf("Duplicate name, please retry!");
            return;
        }

    }

                    printf("\nPlease specify your group size\n");
                    scanf("%d", &wait_list[*counter].number); //read in new entry


                    strcpy(wait_list[*counter].name,tempname);//add in the actual name in array
    (*counter)++;
                    return;
}

void substract(struct customer wait_list[10], int *counter){
    int i;
    //int temp2;
    int temp;
    //char *ntemp2 = NULL;
    //char ntemp;
    int k;


    int seatsize;//seatsize available
    int seatfound = 0;//0 unless seat found 1 seatnot found 2
    struct customer wait_list2[10];


    printf("What is the open seat size?\n");
    scanf("%d", &seatsize);

    for (i = 0; i < *counter; i ++)//check all list
    {

        if (seatfound == 0){//if seat is still not found


            if (wait_list[i].number <= seatsize)
            {
                /*For Number*/
                for(k = i;k < *counter - 1; k++){
                    //temp2 = wait_list[counter - 1].number;//keep what is going to be thrown out
                    temp = wait_list[k + 1].number;//temp keep next number
                    wait_list[k].number = wait_list[k+1].number;//swap the order with next one
                    wait_list[k + 1].number = temp;
                }
                //wait_list[i].number = temp2;

                /*For Name*/
                for(k = i;k < *counter - 1; k++){
                    //ntemp2 = wait_list[0].name;//keep what is going to be thrown out
                    strcpy(wait_list2[k+1].name,wait_list[k+1].name);
                    //ntemp = wait_list[k].name;//temp keep next number
                    strcpy(wait_list[k].name,wait_list[k+1].name);//swap the order with next one
                    strcpy(wait_list[k + 1].name,wait_list2[k + 1].name);
                }

                //strcpy(wait_list[0].name,ntemp2);
                seatfound = 1;
                printf("Seat found!");
            }
        }
    }

    if (seatfound == 0){
        printf("No waitlist matches table size");
    }
    seatfound = 0;
    return;

}


int main()
{
    int flag = 0; //To decide when to quit the application
    int command;//response on what user wants to do
    int counter; //size of array

    struct customer wait_list[10];

    wait_list[0].number = 2;
    strcpy(wait_list[0].name,"Nick");


    wait_list[1].number = 4;
    strcpy(wait_list[1].name,"Matt");

    wait_list[2].number = 1;
    strcpy(wait_list[2].name,"Sean");

    printf("Welcome to Yuya's Restaurant what would you like to do?\n\n");
    printf("Type 1 to add waitlist\n");
    printf("Type 2 to eliminate an entry that fits the table\n");
    printf("Type 3 to show all Waitlist\n");
    printf("Type 4 to quit\n");
    printf("----------------------------\n\n\n");

    counter = 3;//take number of array in the group

    while (flag == 0) {


    scanf("%d", &command); // read in the user input

        if (command == 1)//add one entry
        {

            if (counter < 10){//run while under 10 list
                add(wait_list, &counter);

            }
            else if (counter >= 10)
            {
                printf("Que for waitlist is full."); // if the que is up to 10, do not add to list
            }
            printf("\n\nWhat would you like to do?\n");
        }




        else if (command == 2)//delete one of the list
        {
            substract(wait_list, &counter);
            counter -= 1;
            printf("\n\nWhat would you like to do?\n");
        }


        else if (command == 3)//show all array
        {
            stats(wait_list, counter);

        printf("\n\nWhat would you like to do?\n");
        }

        else if (command == 4){ //quit
        flag = 1;
        }

    }
    return 0;

}
