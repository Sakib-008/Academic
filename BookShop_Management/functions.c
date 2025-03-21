#include<stdio.h>
#include"header.h"


int addBook(Book *books,int i)
{
    printf("Enter the name of the book: ");
    fflush(stdin);
    gets(books[i].name);
    printf("Enter the author's name: ");
    gets(books[i].author);
    printf("Enter total page numbers: ");
    scanf("%d",&books[i].page);
    printf("Enter the price: ");
    scanf("%f",&books[i].price);
    printf("Book has been added successfully.\n");
    return i+1;
}

void viewRecord(Book *books,int i)
{
    if(i==0)
        printf("No books in the record.\n");
    else
    {
        printf("Record of books:\n");
        for(int j=0;j<i;j++)
        {
            printf("Name:%s\tAuthor:%s\tPages:%d\tPrice:%.3f\n",books[j].name,books[j].author,books[j].page,books[j].price);
        }
    }
}
void savetoFile(Book *books,int i)
{
    FILE *file=fopen("records.txt","w");
    if(file==NULL)
    {
        printf("File could not open.\n");
        return;
    }
    else
        printf("Saving records to file...\n");
    for(int j=0;j<i;j++)
    {
        fprintf(file,"Name:%s\tAuthor:%s\tPages:%d\tPrice:%.3f\n",books[j].name,books[j].author,books[j].page,books[j].price);
    }
    fclose(file);
    printf("The existing records has been saved to file successfully.\n");
}
void searchBook(Book *books,int i)
{
    char s[50];
    printf("Enter the book name for search: ");
    fflush(stdin);
    gets(s);
    int j,search=0;
    for(j=0;j<i;j++)
    {
        if(strcmp(s,books[j].name)==0)
        {
            search=1;
            break;
        }
    }
    if(search)
    {
        printf("Book found.Here is the details:\n");
        printf("Name:%s\tAuthor:%s\tPages:%d\tPrice:%.3f\n",books[j].name,books[j].author,books[j].page,books[j].price);
    }
    else
        printf("Book was not found in the records!\n");
}
void editBook(Book *books,int i)
{
    char s[50];
    printf("Enter the name of book you want to edit: ");
    fflush(stdin);
    gets(s);
    int j,search=0;
    for(j=0;j<i;++j)
    {
        if(strcmp(s,books[j].name)==0)
        {
            search=1;
            break;
        }
    }
    if(search)
    {
        printf("Book found.Here is the previous details:\n");
        printf("Name:%s\tAuthor:%s\tPages:%d\tPrice:%.3f\n\n",books[j].name,books[j].author,books[j].page,books[j].price);
        printf("Please enter the new details:\n");
        printf("Enter the name of the book: ");
        fflush(stdin);
        gets(books[j].name);
        printf("Enter the author's name: ");
        gets(books[j].author);
        printf("Enter total page numbers: ");
        scanf("%d",&books[j].page);
        printf("Enter the price: ");
        scanf("%f",&books[j].price);
        printf("Book information edited successfully.\n");
    }
    else
        printf("Sorry!Book not found.\n");
}
void totalPrice(Book *books,int i)
{
    struct totalPrice
    {
        char name[50];
    }b[100];
    float total;
    int j,k,count;
    printf("Enter the number of books: ");
    scanf("%d",&count);
    printf("Enter the name of the books :\n");
    for(j=0;j<count;j++)
    {
        fflush(stdin);
        gets(b[j].name);
    }
    for(j=0;j<i;j++)
    {
        for(k=0;k<count;k++)
        {
            if(strcmp(b[k].name,books[j].name)==0)
                total+=books[j].price;
        }
    }
    printf("The total price of these books = %.3f\n",total);
}
