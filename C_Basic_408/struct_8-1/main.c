#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int num;
    char name[20];
    char sex;
}stu, *p_stu;

typedef int YYZ;

int main(void) {
    struct student s = {1, "yyz", 'M'};
    struct student *p;
    p = &s;
    printf("%d\n", p->num);
    printf("%d\n", (*p).num); // *p 必须加括号 *的优先级没有.高

    struct student *p2;
    p2 = (struct student *)malloc(sizeof(struct student));
    p2->num = 2;
    p2->name[0] = 'w';
    p2->name[1] = '7';
    p2->name[2] = 'f';

    p2->sex = 's';
    printf("%s\n", p2->name);

    YYZ ia = 0;
    return 0;
}