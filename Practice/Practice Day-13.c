#include <stdio.h>

struct Robot {
    int battery;
    int sensor[5];
};

struct Robot robot = {70, {50, 40, 15, 60, 70}};

int find_obstacle(struct Robot *robot) {

    for (int i = 0; i < 5; i++) {

        if (robot->sensor[i] < 20) {
            return i;
        }

    }

    return -1;
}

void show_battery(struct Robot robot) {
    printf("battery: %d\n", robot.battery);
}

void drain_battery(struct Robot *robot) {
    robot->battery -= 10;
}


void decide(struct Robot *robot) {
    drain_battery(robot);
    show_battery(*robot);
    if (robot->battery < 20) {
        printf("Battery low, please recharge\n");
    }
    else {
    int obstacle_sensor = find_obstacle(robot);
    if (obstacle_sensor == -1) {
        printf("Moving forward.\n");
    }
    else if (obstacle_sensor == 0) {
        printf("Turning right.\n");
    }
    else if (obstacle_sensor == 1 || obstacle_sensor == 2) {
        printf("Stopping.\n");
    }
    else if (obstacle_sensor == 3 || obstacle_sensor == 4) {
        printf("Turning left.\n");
    }
}
}

int main() {
    decide(&robot);
    return 0;
}