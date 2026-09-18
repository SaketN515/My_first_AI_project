#include <stdio.h>
int distance[3] = {100,40,200};
int battery = 70;
char robot_name[] = "Robo";
char status[] = "Ready";
char objects[][10] = {"chair", "person", "bottle"};

struct Robot {
    int battery;
    float speed;
    char status[20];
};
struct Robot Robo = {80, 2.5, "Ready"};
int side() {
    printf("Robot Name: %s\n", robot_name);
    printf("Status: %s\n", status);
    if (strcmp(status, "Ready") == 0) {
        printf("Robot is Ready!\n");
    }
    else {
        printf("Robot is Not Ready!\n");
    }
    int *ptr = distance;
    if (*(ptr + 1) < 50) {
        printf("Obstacle Ahead!\n");
    }
    else {
        printf("Path is Clear!\n");
    }
    int found = 0;
    for (int i = 0 ; i < sizeof((objects)) / sizeof((objects[0])); i++) {
        if (strcmp(objects[i], "person") == 0) {
        found = 1;
        }
        else {}
    }   
    if (found == 1) {
        printf("Person Detected");
     }
    else {
        printf("Person not Detected");
    }   
    
    return 0;
    }
int found =0;
    int main() {
        if (battery < 20) {
            printf("Go charge!!\n");
        }
        else {
                for (int i = 0 ; i < sizeof((objects)) / sizeof((objects[0])); i++) {
        if (strcmp(objects[i], "person") == 0) {
        found = 1;
        }
        else {}
    }   
    if (found == 1) {
        printf("Person Detected");
     }
    else {
        printf("Keep Scanning !!!");
    } 
        }
    printf("%d\n", Robo.battery);
    printf("%f\n", Robo.speed);
    printf("%s\n", Robo.status);
    }
