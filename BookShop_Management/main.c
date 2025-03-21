//It is a project on bookshop management...
#include <stdio.h>
#include <stdlib.h>
#include"header.h"

int main()
{
    int choice;
    static int i=0;
    do
    {
        printf("\nDisplay Menu of Bookshop management:\n");
        printf("1.Add book.\n");
        printf("2.View existing record.\n");
        printf("3.Save records to file.\n");
        printf("4.Search for a book.\n");
        printf("5.Edit book information.\n");
        printf("6.Count total price.\n");
        printf("7.Exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            i=addBook(books,i);
            break;
        case 2:
            viewRecord(books,i);
            break;
        case 3:
            savetoFile(books,i);
            break;
        case 4:
            searchBook(books,i);
            break;
        case 5:
            editBook(books,i);
            break;
        case 6:
            totalPrice(books,i);
            break;
        case 7:
            break;
        default:
            printf("\nInvalid choice!Try again.\n");
        }
    }while(choice!=7);
    printf("\nExiting the program...\n");
    return 0;
}
