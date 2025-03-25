/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

// Function prototypes
void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]);
void toggleLight(int rooms, int lights[]);
void readTemperature(int rooms, int temp[]);
void checkMotion(int rooms, int motion[]);
void lockUnlockSecurity(int rooms, int locks[]);
void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    
    // Dynamically sized arrays
    int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
    initializeSystem(rooms, lights, temp, motion, locks);
    
    int choice, motionCounter = 0;
    while (1) {
        printf("\n===== Smart Home Menu =====\n");
        printf("1. Toggle Light\n");
        printf("2. Read Temperature\n");
        printf("3. Check Motion Sensor\n");
        printf("4. Lock/Unlock Security System\n");
        printf("5. House Status Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: toggleLight(rooms, lights); break;
            case 2: readTemperature(rooms, temp); break;
            case 3: checkMotion(rooms, motion); motionCounter = 0; break;
            case 4: lockUnlockSecurity(rooms, locks); break;
            case 5: houseStatus(rooms, lights, temp, motion, locks); break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
        
        // Auto-Lock Feature
        motionCounter++;
        if (motionCounter >= 5) {
            for (int i = 0; i < rooms; i++) locks[i] = 1;
            printf("Auto-Lock Activated: All doors locked due to inactivity.\n");
            motionCounter = 0;
        }
        
        // Temperature Alert
        for (int i = 0; i < rooms; i++) {
            if (temp[i] > 30) {
                printf("Warning! Room %d temperature is too high: %d°C\n", i + 1, temp[i]);
            }
        }
        
        // Energy Saving Suggestion
        int allLightsOn = 1;
        for (int i = 0; i < rooms; i++) {
            if (lights[i] == 0) {
                allLightsOn = 0;
                break;
            }
        }
        if (allLightsOn) {
            printf("Energy Saving Mode: All lights are ON. Consider turning some off.\n");
        }
    }
    return 0;
}

void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        temp[i] = 22 + (i % 3); // Simulated temp values
        motion[i] = 0;
        locks[i] = 1;
    }
    printf("System initialized: Lights OFF, Doors Locked, No motion detected.\n");
}

void toggleLight(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

void readTemperature(int rooms, int temp[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Room %d temperature: %d°C\n", room, temp[room - 1]);
}

void checkMotion(int rooms, int motion[]) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
}

void lockUnlockSecurity(int rooms, int locks[]) {
    int room;
    printf("Enter room number to toggle lock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room < 1 || room > rooms) {
        printf("Invalid room number!\n");
        return;
    }
    locks[room - 1] = !locks[room - 1];
    printf("Room %d door is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
}

void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
               i + 1, 
               lights[i] ? "ON" : "OFF", 
               temp[i], 
               motion[i] ? "Motion Detected" : "No Motion", 
               locks[i] ? "Locked" : "Unlocked");
    }
}
