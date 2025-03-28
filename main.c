#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 5 //  max number of rooms

// Function prototypes
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();
void exitSystem();

int main()
{
    int rooms;
    printf("\nEnter the number of rooms: ");
    scanf("%d", &rooms);
    initializeSystem();
    return 0;
}

void initializeSystem()
{
    printf("\nInitializing system...\n");
    displayMenu();
}

void displayMenu()
{
    int choice;
    printf("\n===== Smart Home Menu =====\n\t1.Toggle Light\n\t2.Read Temperature\n\t3.Check Motion Sensor\n\t4.Lock/Unlock Security System\n\t5.House Status Summary\n\t6.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        controlLights();
        break;

    case 2:
        readTemperature();
        break;

    case 3:
        detectMotion();
        break;

    case 4:
        securitySystem();
        break;

    case 5:
        analyzeHouseStatus();
        break;

    case 6:
        exitSystem();
        break;

    default:
        printf("\n\tChoice input exceeded...................\n");
        break;
    }
}
void controlLights()
{
    int room_number;
    char energy[50];
    printf("Enter room number to toggle light (1-3): ");
    scanf("%d", &room_number);
    if (room_number == 1)
    {
        printf("\nLight in room 1 is OFF\n");
    }
    else if (room_number == 2)
    {
        printf("\nLight in room 2 is now ON\n");
    }
    else if (room_number == 3)
    {
        printf("\nLight in room 3 is OFF\n");
    }
    printf("\nDo you want to enter Energy Saving mode?\n");
    scanf("%s", energy);
    if (strcmp(energy, "yes") == 0 || strcmp(energy, "YES") == 0 || strcmp(energy, "ok") == 0 || strcmp(energy, "okay") == 0)
    {
        printf("\nAll lights are now switched off");
    }
    else
    {
        printf("\nLights remain turned ON");
    }
    displayMenu();
}
void readTemperature()
{
    int room_number, room_temp, rooms[] = {22, 25, 24};
    printf("Enter the room number to check for its temperature(1-3): ");
    scanf("%d", &room_number);
    if (room_number == 1)
    {
        printf("The Temperature in Room 1 is %d°C\n", rooms[0]);
    }
    else if (room_number == 2)
    {
        printf("The Temperature in Room 2 is %d°C\n", rooms[1]);
    }
    else if (room_number == 3)
    {
        printf("The Temperature in Room 3 is %d°C\n", rooms[2]);
    }
    if (rooms[0] > 30)
    {
        printf("\nWARNING: THE TEMPERATURE OF THE ROOM IS GREATER THAN 30°C.");
    }
    else if (rooms[1] > 30)
    {
        printf("\nWARNING: THE TEMPERATURE OF THE ROOM IS GREATER THAN 30°C.");
    }
    else if (rooms[2] > 30)
    {
        printf("\nWARNING: THE TEMPERATURE OF THE ROOM IS GREATER THAN 30°C.");
    }

    displayMenu();
}
void detectMotion()
{
    int room_number;
    printf("Enter the room number to detect any motion(1-3): ");
    scanf("%d", &room_number);
    if (room_number == 1)
    {
        printf("\nNo motion detected in Room 1\n");
    }
    else if (room_number == 2)
    {
        printf("\nMotion detected in Room 2\n");
    }
    else if (room_number == 3)
    {
        printf("\nNo motion detected in Room 3\n");
    }

    displayMenu();
}
void securitySystem()
{
    int room_number;
    printf("Enter the room number to check for its Security System(1-3): ");
    scanf("%d", &room_number);
    if (room_number == 1)
    {
        printf("\nRoom 1 is Locked\n");
    }
    else if (room_number == 2)
    {
        printf("\nRoom 2 is Locked\n");
    }
    else if (room_number == 3)
    {
        printf("\nRoom 3 is unlocked\n");
    }

    displayMenu();
}
void analyzeHouseStatus()
{
    printf("House Status: ");
    printf("\n\tRoom 1: Light OFF, Temp 22°C, No Motion, Locked\n");
    printf("\n\tRoom 2: Light ON, Temp 25°C, Motion Detected, Locked\n");
    printf("\n\tRoom 3: Light OFF, Temp 24°C, No Motion, Unlocked\n");
    displayMenu();
}
void exitSystem()
{
    printf("\nExiting...\n");
}
