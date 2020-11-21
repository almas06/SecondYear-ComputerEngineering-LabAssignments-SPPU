/*Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which
adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and
displays the data members. If an exception is caught, replace all the data member values with
zero values.*/


#include <iostream>
using namespace std;

class Publication{
    public:
    string title;
    float price;
    
};


class Book:public Publication{
    public: 
    int page_count;
    void book_accept();
    void book_display();
};

void Book :: book_accept(){
    cout<<"\n------------------------\n";
    cout<<"  Getting Book Details";
     cout<<"\n-----------------------\n\n";

    cout<<"Enter the name of book :=> ";
    cin>>title;

    cout<<"Enter the price of the book :=>";
    cin>>price;

    cout<<"Enter the page count :=>";
    cin>>page_count;
    cout<<"\n";
}
void Book :: book_display(){
    cout<<"\n----------------------------\n";
    cout<<"        Book Details";
    cout<<"\n----------------------------\n\n";

     cout<<"Title of the book :=>"<<title<<endl;
     cout<<"Price of the book is :=> "<<price<<" Rs."<<endl;
     cout<<"Book Page count :=> "<<page_count<<" pages"<<endl<<endl;
}



class Tape : public Publication{
    public:
    float playing_time;

    void tape_accept();
    void tape_display();

    
};
void Tape :: tape_accept(){
    cout<<"\n--------------------------\n";
    cout<<"   Getting Tape Details";
    cout<<"\n--------------------------\n";
    cout<<"Enter the name of book :=> ";
    cin>>title;

    cout<<"Enter the price of the book :=>";
    cin>>price;

    cout<<"Enter the playing time(in mins) :=>";
    cin>>playing_time;
    cout<<"\n";

}
void Tape :: tape_display(){
    cout<<"\n------------------------------\n";
    cout<<"         Tape Details ";
    cout<<"\n------------------------------\n\n";
     cout<<"Title of the book :=> "<<title<<endl;
     cout<<"Price of the book is:=> "<<price<<" Rs."<<endl;
     cout<<"Book Playing Time :=> "<<playing_time<<" mins"<<endl<<endl;
}

int main(){
     Tape t;
     Book b;
    int c;
    char ans;
    cout<<"--------ASSIGNMENT-1-----------\n";
    while(c!=3)
     {
    cout<<" \n 1. Read a book \n 2. Tape a book \n 3. Exit \n Enter your choice :";
    cin>>c;
    
    switch(c)
    {
        case 1:
        {
            b.book_accept();
            b.book_display();
            break;
        }
        case 2:
        {
            t.tape_accept();
            t.tape_display();
            break;
        }
        
        case 3:
        {
            cout<<"\n===========Exit===========\n\n";
            break;
        }
        default:
            cout<<"Error :  Enter a valid input!\n\n";
    }
    
    }
    

    return 0;
}

