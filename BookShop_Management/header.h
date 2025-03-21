#include<string.h>

typedef struct
{
    char name[50];
    char author[50];
    int page;
    float price;
}Book;
Book books[100];

int addBook(Book *books,int i);
void viewRecord(Book *books,int i);
void savetoFile(Book *books,int i);
void searchBook(Book *books,int i);
void editBook(Book *books,int i);
void totalPrice(Book *books,int i);
