#include <stdio.h>
int battery=80;
float speed=2.5;
char status='A';
int main()
{
    scanf("%d",&battery);
    if (battery < 20) {
        printf("Low battery!\n");
    }
    else {
        printf("Battery level is sufficient.\n");
    }
    printf("%d\n",battery);
    printf("%f\n",speed);
    printf("%c\n",status);
    return 0;
}