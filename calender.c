#include<stdio.h>

struct Week {
    char day[100];
    int date;
    char actdisp[100];
};

struct Week day[7];

void read() {
    for (int i = 0; i < 7; i++) {
        printf("Enter the date of Day %d:\n", i + 1);
        scanf("%d", &day[i].date);
        
        printf("Enter the name of Day %d:\n", i + 1);
        scanf(" %s", day[i].day); 
        
        printf("Enter the activity description of Day %d:\n", i + 1);
        scanf(" %99[^\n]", day[i].actdisp); 
    }
}

void display() {
    printf("------------Calendar---------\n");

    for (int i = 0; i < 7; i++) {
        printf("Day %d - Date: %d, Day: %s, Activity Description: %s\n", i + 1, day[i].date, day[i].day, day[i].actdisp);
    }
}

int main() {
    read();
    display();

    return 0;
}
