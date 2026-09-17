#include <stdio.h>

int sensors[3] = {10,20,30};
int *ptr = sensors;

void increase_sensor(int *ptr) {
    *ptr += 5;
}

main() {
    increase_sensor((ptr+1));
    printf("%d\n", sensors[0]);
    printf("%d\n", sensors[1]);
    printf("%d\n", sensors[2]);
}