#include <stdio.h>
#include <string.h>

int turn = 0;
struct Robot {
    int battery;
    int sensor[5];
};
struct Robot robot = {70, {50, 40, 15, 60, 70}};
int closest;

int previous() {
    closest = robot.sensor[0];

    for (int i = 0; i < 5; i++) {
        if (robot.sensor[i] < 20) {
            printf("Obstacle detected at sensor %d\n", i);
            turn = 1;
        } else {
            printf("No obstacle at sensor %d\n", i);
        }

        if (turn == 1) {
            printf("Turning to avoid obstacle\n");
        } else {
            printf("Moving forward\n");
        }
        if (robot.sensor[i] < closest) {
            closest = robot.sensor[i];
        }
    }

    printf("Closest obstacle: %d\n", closest);
    return 0;
}
int main() {
    previous();
    return 0;
}