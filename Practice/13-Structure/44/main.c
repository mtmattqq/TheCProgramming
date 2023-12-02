#include <stdio.h>
#include "book.h"
#include "date.h"
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned);
 
int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17U
    };
    struct Date date_borrowed = {2007, 11, 14}, 
        date_returned = {2007, 12, 3};
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}