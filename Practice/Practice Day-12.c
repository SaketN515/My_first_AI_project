#include <stdio.h>
#include <string.h>

struct Robot {
    int battery;
    int sensor[5];
};

struct Robot robot = {70, {50, 40, 15, 60, 70}};

int found = 0;

void show_battery(struct Robot robot) {
    printf("battery: %d\n", robot.battery);
}

void drain_battery(struct Robot *robot) {
    robot->battery -= 10;
}

void scan_sensors(struct Robot *robot) {
    for (int i = 0; i < 5; i++) {
        if (robot->sensor[i] < 20) {
            printf("Obstacle detected at sensor %d\n", i);
            found = 1;
        } else {
            printf("Path Clear at sensor %d\n", i);
        }
    }
}

void decide(struct Robot *robot) {
    drain_battery(robot);
    show_battery(*robot);
    if (robot->battery < 20) {
        printf("Battery low, please recharge\n");
    }
    else {
        scan_sensors(robot);
        if (found) {
            printf("Turning.\n");
        } else {
            printf("Moving forward.\n");
        }
    }
}

int main() {
    decide(&robot);
    return 0;
}