#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char imie[50];
    char nazwisko[50];
    char telefon[50];
} Contact;

void dodaj(Contact *kontakty, Contact *newContact, int dlugoscKsiazki){
    for(int i = 0; i < dlugoscKsiazki; i++){
        if(strlen(kontakty[i].nazwisko) == 0){
            strcpy(kontakty[i].imie, newContact->imie);
            strcpy(kontakty[i].nazwisko, newContact->nazwisko);
            strcpy(kontakty[i].telefon, newContact->telefon);
            break;
        }
    }
}

void usun(Contact *kontakty, char nazwisko[50], int dlugoscKsiazki){
    for(int i = 0; i < dlugoscKsiazki - 1; i++){
        if(strcmp(kontakty[i].nazwisko, nazwisko) == 0){
            strcpy(kontakty[i].imie, "");
            strcpy(kontakty[i].nazwisko, "");
            strcpy(kontakty[i].telefon, "");
            break;
        }
    }
}

void wypiszKontakty(Contact *kontakty, int dlugoscKsiazki) {
    printf("All contacts:\n");
    for (int i = 0; i < dlugoscKsiazki; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Imie: %s\n", kontakty[i].imie);
        printf("Nazwisko: %s\n", kontakty[i].nazwisko);
        printf("Telefon: %s\n", kontakty[i].telefon);
        printf("\n");
    }
}

Contact znajdz(Contact *kontakty, char nazwisko[50], int dlugoscKsiazki){
    for(int i = 0; i < dlugoscKsiazki - 1; i++){
        if(strcmp(kontakty[i].nazwisko, nazwisko) == 0){
            return kontakty[i];
        }
    }
}

int main() {
    Contact kontakty[50] = {
        {"Jan", "Kowalski", "123456789"},
        {"Anna", "Nowak", "987654321"},
        {"Adam", "Wisniewski", "111222333"},
        {"Karolina", "Lewandowska", "444555666"},
        {"Piotr", "Duda", "777888999"},
        {"Katarzyna", "Wojcik", "000999888"},
        {"Mateusz", "Kaminski", "333444555"},
        {"Aleksandra", "Kowalczyk", "666777888"},
        {"Michal", "Zielinski", "111000222"},
        {"Natalia", "Szymanska", "444777111"}
    };

    Contact nowy = {"Tomek", "Baryla", "123456789"};
    dodaj(kontakty, &nowy, 50);
    usun(kontakty, "Nowak", 50);

    wypiszKontakty(kontakty, 50);

    Contact znaleziony = znajdz(kontakty, "Duda", 50);
    printf("%s", znaleziony.imie);
    return 0;
}