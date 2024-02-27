#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char imie[50];
    float ocena;
} Student;

void sortuj_studentow(Student *students, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (students[j].ocena < students[j+1].ocena) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int main() {
    Student studenci[10] = {
        {"Jan Kowalski", 4.5},
        {"Anna Nowak", 3.75},
        {"Adam Wisniewski", 5.0},
        {"Karolina Lewandowska", 4.0},
        {"Piotr Duda", 3.25},
        {"Katarzyna Wojcik", 4.75},
        {"Mateusz Kaminski", 3.0},
        {"Aleksandra Kowalczyk", 4.25},
        {"Michal Zielinski", 2.5},
        {"Natalia Szymanska", 3.5}
    };

    sortuj_studentow(studenci, 10);

    printf("Posortowane dane studentow malejaca:\n");
    for (int i = 0; i < 10; i++) {
        printf("\n");
        printf("%s  ocena: %.2f", studenci[i].imie, studenci[i].ocena);      
    }
    return 0;
}