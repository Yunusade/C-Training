#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    float height;
};

int main(void) {

    struct Person person1;

    // Strlcpy
    strcpy(person1.name, "Yunze Ade");
    person1.age = 18;
    person1.height = 6.2;


    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f\n", person1.height);

    return 0;