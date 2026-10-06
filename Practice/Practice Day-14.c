#include <stdio.h>

enum RobotState {
    CHARGING,
    MOVING,
    TURNING,
    STOPPED
};

struct Robot {
    int battery;
    int sensor[5];
    enum RobotState state;
};

struct Robot robot = {70, {50,40,15,60,70}, MOVING};

void show_state(struct Robot *robot) {
    switch (robot->state) {
        case CHARGING:
            printf("Robot is charging.\n");
            break;
        case MOVING:
            printf("Robot is moving.\n");
            break;
        case TURNING:
            printf("Robot is turning.\n");
            break;
        case STOPPED:
            printf("Robot is stopped.\n");
            break;
    }
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

int find_obstacle(struct Robot *robot) {

    for (int i = 0; i < 5; i++) {

        if (robot->sensor[i] < 20) {
            return i;
        }

    }

    return -1;
}

void decide(struct Robot *robot) {
    if (robot ->battery < 20) {
        robot->state = CHARGING;
    }
    else {
        int obstacle_index = find_obstacle(robot);
        if (obstacle_index == -1) {
            robot->state = MOVING;
        }
        else if (obstacle_index  == 0) {
            robot->state = TURNING;
        }
        else if (obstacle_index == 1 || obstacle_index == 2) {
            robot->state = STOPPED;
        }
        else if (obstacle_index == 3 || obstacle_index == 4) {
            robot->state = TURNING;
        }
    }
}

int main() {
    decide(&robot);
    show_state(&robot);
    perform_action(&robot);
}