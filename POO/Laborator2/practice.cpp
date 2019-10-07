#include <iostream>
using namespace std;
class Book
{
    char title[20],
        author[20],
        edit[20];
    unsigned int year;

public:
    //class constructor signature
    Book(char book_title[20], char book_author[20], char book_edit[20], int book_year);
    //class destructor signature
    ~Book();
    //display function
    void showOff()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Edit: " << edit << endl;
        cout << "Year: " << year << endl;
    }
};
//constructor
Book::Book(char book_title[20], char book_author[20], char book_edit[20], int book_year)
{
    strcpy(title, book_title);
    strcpy(author, book_author);
    strcpy(edit, book_edit);
    year = book_year;
    cout << "\nConstructor said: record created" << endl;
}
//destructor
Book::~Book()
{
    cout << "\nDestructor said: memory for " << title << " was freed up" << endl;
}

int main()
{
    Book book1("Book1", "Author1", "Edit1", 1);
    book1.showOff();
    Book book2("Book2", "Author2", "Edit2", 2);
    book2.showOff();
    return 0;
}