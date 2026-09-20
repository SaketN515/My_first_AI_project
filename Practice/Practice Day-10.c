#include <stdio.h>
#include <string.h>


struct Robot {
    int battery;
    float speed;
    char status[20];
    int person_detected;
};
struct Robot robot = {70, 2.5, "Ready", 1};

void decide(struct Robot *robot) {
    if (robot->battery < 20) {
        strcpy(robot->status, "Charging");
    }
    else if (robot->person_detected == 1) {
        strcpy(robot->status, "Following");
    }
    else {
        strcpy(robot->status, "Working");
    }
}

void drain_battery(struct Robot *robot) {
    robot->battery -= 20;
    if (robot->battery < 0) {
        robot->battery = 0;
    }
}

void show_status(struct Robot robot) {
    printf("%d\n", robot.battery);
    printf("%.2f\n", robot.speed);
    printf("%s\n", robot.status);
    printf("%d\n", robot.person_detected);
}

int main() {
    show_status(robot);
    decide(&robot);
    drain_battery(&robot);
    printf("Battery after draining: %d\n", robot.battery);
    show_status(robot);
    return 0;
}