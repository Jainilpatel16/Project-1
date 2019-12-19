//
//  main.cpp
//  project
//
//  Created by Jainil Patel on 11/18/19.
//  Copyright © 2019 Jainil Patel. All rights reserved.
//


// This is code for library to check out the different kinds of books and other items.
// Written by Jainil Patel.
// For class CSC 2110
// Instructor: Areej Salaymeh
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;


//Above is the Class of Catalog

class Catalog
{
public:
    Catalog();
    Catalog(int a,string b, string c,string d);
    void setData(int a,string b,string c,string d);
    void setID(int a);
    void setName(string b);
    void setStatus(string c);
    void setCategory(string d);
    int getID() const;
    string getName() const;
    string getStatus() const;
    string getCategory() const;
    void print() const;
    
private:
    int ID;
    string Name;
    string Status;
    string Category;
};
//---------------------------------------------------------------HEADER OF THE CLASS CATALOG.
Catalog::Catalog()
{
    setData(0 , "unknown" , "Not Available", "Category");
}

Catalog::Catalog(int a, string b, string c, string d)
{
    ID = a;
    Name = b;
    Status = c;
    Category = d;
}

void Catalog::setData(int a, string b, string c, string d)
{
    ID = a;
    Name = b;
    Status = c;
    Category = d;
}

void Catalog::setID(int a)
{
    ID = a;
}

void Catalog::setName(string b)
{
    Name = b;
}

void Catalog::setStatus(string c)
{
    Status = c;
}

void Catalog::setCategory(string d)
{
    Category = d;
}

int Catalog::getID() const
{
    return ID;
}

string Catalog::getName() const
{
    return Name;
}

string Catalog::getStatus() const
{
    return Status;
}

string Catalog::getCategory() const
{
    return Category;
}

void Catalog::print() const
{
    cout << setfill('-') << setw(30) <<"\n";
    cout << "Name: " << getName() << endl;
    cout << "Category: " << getCategory() <<endl;
    cout << "Status: " << getStatus() <<endl;
    cout << "ID: " << getID() <<endl;
}
//--------------------------------------------------------------CATALOG CLASS ENDS.
//--------------------------------------------------------------BOOKS CLASS STARTS.
class Books : public Catalog
{
public:
    Books();
    Books(int a, string b, string c, string d, string e);
    void setData(int a, string b, string c, string d, string e);
    void setAuthorName(string e);
    string getAuthorName() const;
    void print() const;
    
private:
    string AuthorName;
};
//--------------------------------------------------------------HEADER OF CLASS BOOKS.
Books::Books()
{
    setAuthorName("unknown");
}

Books::Books(int a, string b, string c, string d, string e)
      : Catalog(a, b, c, d)
{
    setAuthorName(e);
}

void Books::setData(int a, string b, string c, string d, string e)
{
    Catalog::setData(a, b, c, d);
    setAuthorName(e);
}

void Books::setAuthorName(string e)
{
    AuthorName = e;
}

string Books::getAuthorName() const
{
    return AuthorName;
}

void Books::print() const
{
    Catalog::print();
    cout << "Author Name: "<< getAuthorName() <<endl;
    cout << setfill('-') <<setw(30) << "\n";
}
//---------------------------------------------------------------BOOKS CLASS ENDS HERE.
//---------------------------------------------------------------JOURNALS CLASS START.
class Journals : public Catalog
{
public:
    Journals();
    Journals(int a, string b, string c, string d, int e);
    void setData(int a, string b, string c, string d, int e);
    void setVolume(int e);
    int getVolume() const;
    void print() const;
    
private:
    int volume;
};
//----------------------------------------------------------------HEADER OF CLASS JOURNALS.
Journals::Journals()
{
    setVolume(0);
}

Journals::Journals(int a, string b, string c, string d, int e)
         :Catalog(a, b, c, d)
{
    setVolume(e);
}

void Journals::setData(int a, string b, string c, string d, int e)
{
    Catalog::setData(a, b, c, d);
    setVolume(e);
}

void Journals::setVolume(int e)
{
    volume = e;
}

int Journals::getVolume() const
{
    return volume;
}

void Journals::print() const
{
    Catalog::print();
    cout << "Volume: " << getVolume() <<endl;
    cout << setfill('-') << setw(30) <<"\n";
}
//-------------------------------------------------------------------JOURNALS CLASS ENDS.
//-------------------------------------------------------------------MAGAZINES CLASS STARTS.
class Magazines : public Catalog
{
public:
    Magazines();
    Magazines(int a, string b, string c, string d, int e);
    void setData(int a, string b, string c, string d, int e);
    void setIssueNumber(int e);
    int getIssueNumber() const;
    void print() const;
    
private:
    int IssueNumber;
};
//--------------------------------------------------------------------HEADER OF CLASS MAGAZINES.
Magazines::Magazines()
{
    setIssueNumber(0);
}

Magazines::Magazines(int a, string b, string c, string d, int e)
          :Catalog(a,b,c,d)
{
    setIssueNumber(e);
}

void Magazines::setData(int a, string b, string c, string d, int e)
{
    Catalog::setData(a,b,c,d);
    IssueNumber = e;
}

void Magazines::setIssueNumber(int e)
{
    IssueNumber = e;
}

int Magazines::getIssueNumber() const
{
    return IssueNumber;
}

void Magazines::print() const
{
    Catalog::print();
    cout << "IssueNumber: "<< getIssueNumber() <<endl;
    cout << setfill('-') << setw(30) << "\n";
}
//--------------------------------------------------------------------END OF CLASS MAGAZINES.

//--------------------------------------------------------------------MEMU FUNCTION.

void printMenu()
{
    cout << "||-------------------Library Application------------------||" << endl;
    cout << "||--------------For Class CSC-2110 Fall 2019--------------||" << endl;
    cout << "||-----------------Professor: Areej Salaymeh--------------||" << endl;
    cout << "||------------Written by Jainil Patel (GQ6908)------------||" << endl;
    cout << endl;
    cout << "---------------------------MENU-----------------------------" << endl;
    cout << "1. SEARCH CATALOG" << endl;
    cout << "2. CHECK OUT" << endl;
    cout << "3. RETURN" << endl;
    cout << "4. ADD NEW ITEM" << endl;
    cout << "5. EXIT" << endl;
    cout << "------------------------------------------------------------" << endl;
}

//--------------------------------------------------------------------CHECK BOOK NAME FUNCTION.

bool checkBookName(string a, vector<Catalog*>& l)
{
    for(int i = 0; i < l.size(); i++)
    {
        if((*l[i]).getName() == a)
        {
            (*l[i]).print();
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------CHECK AUTHOR NAME FUNCTION.

bool checkAuthorName(string a, vector<Books*>& l)
{
    for(int i = 0; i < l.size(); i++)
    {
        if((*l[i]).getAuthorName() == a)
        {
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------------CHECK CATEGORY FUNCTION.

bool checkCategory(string a, vector<Catalog*>& l)
{
    bool x = false;
    for(int i = 0; i < l.size(); i++)
    {
        if((*l[i]).getCategory() == a)
        {
            (*l[i]).print();
            x = true;
        }
        
    }
    return x;
}

int main()                    //--------------------------------------MAIN FUNCTION.
{
    int option, addID, addVolume ;
    string bookNameSearch, bname, addName, addAuthor ;
    char addChoice, searchChoice, categoryChoice;
    
    vector<Catalog*> Catalog;
    
    Catalog.push_back(new Books(1001, "The Hobbit", "Available", "Books", "J. R. R. Tolkien"));
    Catalog.push_back(new Books(1002, "Harry Potter and the Chamber of Secrets", "Available", "Books", "J. K. Rowling"));
    Catalog.push_back(new Books(1003, "To Kill a Mockingbird", "Available", "Books", "Harper Lee"));
    Catalog.push_back(new Books(1004, "The Kite Runner", "Available", "Books", "Khaled Hosseini"));
    Catalog.push_back(new Books(1005, "A Game of Thrones", "Available", "Books", "George R. R. Martin"));
    Catalog.push_back(new Journals(1006, "Nature", "Available", "Journals", 1));
    Catalog.push_back(new Journals(1007, "Nature Communications", "Available", "Journals", 1));
    Catalog.push_back(new Journals(1008, "PLOS ONE", "Available", "Journals", 2));
    Catalog.push_back(new Journals(1009, "Science", "Available", "Journals", 3));
    Catalog.push_back(new Journals(1010, "Science Advances", "Available", "Journals", 2));
    Catalog.push_back(new Magazines(1011, "Peoples", "Available", "Magazines", 2));
    Catalog.push_back(new Magazines(1012, "Forbes", "Available", "Magazines", 1));
    Catalog.push_back(new Magazines(1013, "Men's Health", "Available", "Magazines", 4));
    Catalog.push_back(new Magazines(1014, "Detroit", "Available", "Magazines", 3));
    Catalog.push_back(new Magazines(1015, "Digital", "Available", "Magazines", 3));
    
   // cout << "-------------------Library Application-------------------"<<endl;
   // cout << "------------------Coded by Jainil Patel------------------"<<endl;
    cout << endl;
    
    do
    {                //--------------------------SELECTEING THE 1ST OPTION FROM THE MENU.
        printMenu();
        cout << endl;
        cout << "SELECTE AN OPTION: ";
        cin >> option;
        switch(option)
        {
            case 1:  //-----------------------GIVING 3 MORE OPTION FORM THE 1ST OPTION FROM MENU.
            {
                cout << "1. NAME" << endl;
                cout << "2. SEARCH BY CATEGORY" <<endl;
                cout << "3. LIST ALL THE ITEMS" <<endl;
                cout << endl;
                cout << "Please Enter your option: ";
                cin >> searchChoice;
                if(searchChoice == '1')
                {
                    cout << "Enter Name: ";
                    cin >> bookNameSearch;
                    cout << endl;
                    
                    if(checkBookName(bookNameSearch, Catalog) != true)
                    {
                        cout << "ITEM NOT FOUND"<<endl;
                        break;
                    }
                    else
                    {
                        cout << endl;
                        break;
                    }
                    break;
                    
                }
                
                else if(searchChoice == '2')
                {
                    cout << "You've selected to search by Category. \n1. Books \n2. Journals \n3. Magazines" << endl;
                    cout << "Your selection: ";
                    cin >> categoryChoice;
                    cout << endl;
                    if (categoryChoice == '1')
                    {
                        checkCategory("Books", Catalog);
                    }
                    else if (categoryChoice == '2')
                    {
                        checkCategory("Journals", Catalog);
                    }
                    else if (categoryChoice == '3')
                    {
                        checkCategory("Magazines", Catalog);
                    }
                    else
                    {
                        cout << "There is no such category." << endl;
                    }
                    break;
                }
                else if (searchChoice == '3')
                {
                    cout << "All Products: \n";
                    checkCategory("Books", Catalog);
                    checkCategory("Journals", Catalog);
                    checkCategory("Magazines", Catalog);
                }
                else
                {
                    cout << "Error: You can only search by name or category. Please try again." << endl;
                    break;
                }
                break;
            }
                
            case 2:     //--------------------------------------2ND OPTION FROM MENU CHECK OUT.
            {
                cout << "Enter the name of the item to check out: ";
                cin >> bname;
                if(checkBookName(bname, Catalog) != true)
                {
                    cout << "ITEM NOT FOUND"<<endl;
                    break;
                }
                else
                {
                    for (int i = 0; i < Catalog.size(); i++)
                    {
                        if ((*Catalog[i]).getName() == bname)
                           (*Catalog[i]).setStatus("Not Available");
                    }
                    cout << endl;
                    break;
                }
                
            }
            case 3:    //-----------------------------------3RD OPTION FORM THE MENU RETURN ITEM.
            {
               cout << "Enter the name of the item to return: ";
                cin >> bname;
                if(checkBookName(bname, Catalog) != true)
                {
                    cout << "ITEM NOT FOUND"<<endl;
                    break;
                }
                else
                {
                    for (int i = 0; i < Catalog.size(); i++)
                    {
                        if ((*Catalog[i]).getName() == bname)
                        {
                            if ((*Catalog[i]).getStatus() == "Not Available")
                            {
                                (*Catalog[i]).setStatus("Available");
                            }
                            else
                                cout << "Item was not checked out" << endl;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                cout << "Enter the ID of the the item:" <<endl;
                cin >> addID;
                
                cout << "Enter the Name of the item:" <<endl;
                cin >> addName;
                
                cout << "Is the Item a Book, a Journal, or a Magazine ?" << endl;
                cout << "1. Book" << endl;
                cout << "2. Journal" << endl;
                cout << "3. Magazine" << endl;
                cout << "Your Selected Option: ";
                cin >> addChoice;
                
                if(addChoice == '1')
                {
                    cout << "Enter the author name: ";
                    cin >> addAuthor;
                    bool checkBook = checkBookName(addName, Catalog);
                    if(checkBook == false)
                    {
                        Catalog.push_back(new Books(addID, addName, "Available", "Books", addAuthor));
                        cout << "Book list has been updated" << endl;
                    }
                    else
                    {
                        cout << "Error! This Book could not be updated. File may have been deleted." <<endl;
                        break;
                    }
                }
                else if(addChoice == '2')
                {
                    cout << "Enter the volume of Journal: ";
                    cin >> addVolume;
                    bool checkJournal = checkBookName(addName, Catalog);
                    if(checkJournal == false)
                    {
                        Catalog.push_back(new Journals(addID, addName, "Available", "Journal", addVolume));
                        cout << "Journal list has been updated" << endl;
                    }
                    else
                    {
                        cout << "Error! This Journal could not be updated. File may have been deleted." <<endl;
                        break;
                    }
                }
                else if(addChoice == '3')
                {
                    cout << "Enter the volume of Magazine: ";
                    cin >> addVolume;
                    bool checkMagazine = checkBookName(addName, Catalog);
                    if(checkMagazine == false)
                    {
                        Catalog.push_back(new Magazines(addID, addName, "Available", "Magainze", addVolume));
                        cout << "Magazine list has been updated" << endl;
                    }
                    else
                    {
                        cout << "Error! This Magazine could not be updated. File may have been deleted." <<endl;
                        break;
                    }
                }
                else
                {
                    cout << "Invalid Update Trial." << endl;
                    break;
                }
                cout << addName << " has been Updated." << endl;
                break;
            }
                
        case 5:
            cout << "Thank you for using Library Application created by JAINIL PATEL" <<endl;
            return 0;
        }
    }
    
    while (true);
    return 0;
}
    

