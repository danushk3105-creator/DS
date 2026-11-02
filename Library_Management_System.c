#include <stdio.h>
#include <string.h>
#define MAX 50
struct Book {
    int id;
    char title[30];
    char author[25];
    int issued;
    char member[20];
};
struct Book b[MAX];
int count = 0;
int find(int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (b[i].id == id)
        return i;
    }
    return -1;
}
void addBook() {
    int id;
    if (count >= MAX) {
        printf("Sorry, library is full!\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &id);
    if (find(id) != -1) {
        printf("Book ID already exists!\n");
        return;
    }
    b[count].id = id;
    printf("Enter Book Title: ");
    scanf(" %[^\n]", b[count].title);
    printf("Enter Author: ");
    scanf(" %[^\n]", b[count].author);
    b[count].issued = 0;
    strcpy(b[count].member, "-");
    printf("Book added successfully! ID: %d\n", b[count].id);
    count++;
}
void display() {
    int i;
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\n%-5s %-16s %-20s %-10s %s\n",
    "ID", "Title", "Author", "Status", "Member");
    for (i = 0; i < count; i++) {
        printf("%-5d %-16s %-20s %-10s %s\n",
        b[i].id, b[i].title, b[i].author,
        b[i].issued ? "Issued" : "Available", b[i].member);
    }
}
void searchBook() {
    int id, p;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    p = find(id);
    if (p == -1)
    printf("Book not found!\n");
    else
    printf("Found: %s by %s (%s)\n",
    b[p].title, b[p].author, b[p].issued ? "Issued" : "Available");
}
void issueBook() {
    int id, p;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    p = find(id);
    if (p == -1)
    printf("Book not found!\n");
    else if (b[p].issued)
    printf("Book is already issued to %s!\n", b[p].member);
    else {
        printf("Enter Member Name: ");
        scanf(" %[^\n]", b[p].member);
        b[p].issued = 1;
        printf("Book issued to %s successfully!\n", b[p].member);
    }
}
void returnBook() {
    int id, p;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    p = find(id);
    if (p == -1)
    printf("Book not found!\n");
    else if (!b[p].issued)
    printf("This book was not issued!\n");
    else {
        b[p].issued = 0;
        strcpy(b[p].member, "-");
        printf("Book returned successfully!\n");
    }
}
int main() {
    int ch;
    do {
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1.Add Book  2.Display  3.Search\n");
        printf("4.Issue Book  5.Return Book  6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addBook();    break;
            case 2: display();    break;
            case 3: searchBook(); break;
            case 4: issueBook();  break;
            case 5: returnBook(); break;
            case 6: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 6);
    return 0;
}
