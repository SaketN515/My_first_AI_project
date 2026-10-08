#include <stdio.h>

typedef enum {
    CHARGING,
    MOVING,
    TURNING,
    STOPPED
} RobotState;

struct Robot {
    int battery;
    int sensor[5];
    RobotState state;
};

struct Robot robot = {80, {50,40,60,70,90}, MOVING};

int find_obstacle(struct Robot *robot) {

    for (int i = 0; i < 5; i++) {

        if (robot->sensor[i] < 20) {
            return i;
        }

    }

    return -1;
}

RobotState decide_state(struct Robot *robot) {
    if (robot->battery < 20) {
        return CHARGING;
    }

    int obstacle_index = find_obstacle(robot);

    if (obstacle_index == -1) {
        return MOVING;
    }

    if (obstacle_index == 0 ||
        obstacle_index == 3 ||
        obstacle_index == 4) {
        return TURNING;
    }

    return STOPPED;
}

void set_state(struct Robot *robot, RobotState new_state) {
    robot->state = new_state;
}

void perform_action(struct Robot *robot) {
    switch (robot->state) {
        case CHARGING:
            printf("Charging.....\n");
            break;
        case MOVING:
            printf("Moving Forward.....\n");
            break;
        case TURNING:
            printf("Turning.....\n");
            break;
        case STOPPED:
            printf("Stopping.....\n");
            break;
    }
}



int main() {
    RobotState new_state = decide_state(&robot);
    set_state(&robot, new_state);
    perform_action(&robot);
    return 0;
}