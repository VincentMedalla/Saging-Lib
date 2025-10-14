#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

    void addbook() {
        string id, title, author, date, status="available", id_check, line;
        cin.ignore();
             
        cout<<"Enter the identification code = ";
        getline(cin, id);
         
        ifstream checkfile;
        checkfile.open("library_file.txt", ios::in);
        while (getline(checkfile, line)) {
            stringstream ss(line);
            getline (ss, id_check, ',');
             
            if (id==id_check) {
                cout<<"Book already exists\n\n";
                return;
            }
        }
         
        cout<<"Enter the title = ";
        getline(cin, title);
         
        cout<<"Enter the author of the book = ";
        getline(cin, author);
         
        cout<<"Enter the publication year of the book = ";
        getline(cin, date);
         
        if (id.empty() | title.empty() | author.empty() | date.empty()) {
                cout<<"All fields are required Shutting down program\n\n";
return;
            }
             
        ofstream Myfile;
        Myfile.open("library_file.txt", ios::app);
        Myfile <<id <<"," <<author <<"," <<date <<"," <<title<< "," <<status<< endl;
        Myfile.close();
    }
   
    void booklist() {
        string id, title, author, date, status;
        cout << setw(10) << "ID" << setw(20) << "Autor" << setw(15) << "Date" << setw(30) << "Tile" << setw(20) <<"Status" << endl;
        ifstream Myfile;
            Myfile.open("library_file.txt", ios::out);
            if (!Myfile) {
                cout<<"No file was read";
            } else {
            string line;
            while (getline(Myfile,line)) {
                stringstream ss(line);
                getline(ss, id, ',');
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, date, ',');
                getline(ss, status);
                cout << setw(10) << id << setw(20) << author << setw(15) << date << setw(30) << title <<setw(20) <<status <<endl;
                            }    
            }
            cout<<endl;
        }
     
    void delete_book() {
        cin.ignore();
        string del_ID, id, author, date, title, status;
     
        cout<<"Enter the id of the bok you want to delete";
        getline(cin,del_ID);
     
        ifstream Myfile;
        Myfile.open("library_file.txt", ios::out);
        ofstream Copy;
        Copy.open("Copy_file.txt", ios::app);
     
        if (!Myfile) {
            cout<<"No file was read";
        } else {
            string line;
            while (getline(Myfile, line)) {
                stringstream ss(line);
                getline(ss, id, ',');
                getline(ss, author, ',');
                getline(ss, date, ',');
                getline(ss, title, ',');
                getline(ss, status);
                if (id==del_ID) {
                    continue;
                }
             
                Copy <<id <<"," <<author <<"," <<date <<"," <<title<< "," <<status<< endl;
                }
             
             
            }
    Myfile.close();
    Copy.close();

    remove("library_file.txt");
    rename("Copy_file.txt", "library_file.txt");
    cout<<"Book has been successfully removed";
         
        }
     
    void borrow_book() {
        int a=0;
        string get_ID, id, author, date ,title, status;
        cin.ignore();
        cout<<"Enter te book ID you want to borrow";
        getline(cin,get_ID);
     
        ifstream Myfile;
        Myfile.open("library_file.txt", ios::in);
        ofstream borrow_file;
        ofstream Copy;
        Copy.open("Copy.txt", ios::app);
        borrow_file.open("borrowed_books.txt", ios::app);
     
        string line;
        while(getline(Myfile, line)) {
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, author, ',');
            getline(ss, date, ',');
            getline(ss, title, ',');
            getline(ss, status);
            if (id==get_ID) {
                if (status!="borrowed") {
                    borrow_file <<id <<"," <<author <<"," <<date <<"," <<title <<endl;    
                    Copy <<id <<"," <<author <<"," <<date <<"," <<title <<',' << "borrowed"  <<endl;
                } else {
                    cout<<"The book has already been borrowed\n\n";
                    return;
                }
             
            } else {
                Copy <<id <<"," <<author <<"," <<date <<"," <<title <<',' << status  <<endl;
            }
         
        }
         
        cout<<"Book was succesfully borrowed";
        Myfile.close();
        Copy.close();
        remove("library_file.txt");
        rename("Copy.txt", "library_file.txt");
    }

    
    void return_book() {
    string id, author, date, title, get_ID, line, status;
    ifstream borrow_books;
    ifstream Myfile;
    Myfile.open("library_file.txt", ios::in);
    borrow_books.open("borrowed_books.txt", ios::in);
    ofstream Copy_borrow;
    ofstream Copy_library;
    Copy_borrow.open("Copy_borrow.txt", ios::app);
    Copy_library.open("Copy_library.txt", ios::app); 
    
    cout<<"Enter the id of the book you want to return";
    cin>>get_ID;
    
    while (getline(borrow_books,line)) {
        stringstream ss(line);
        getline(ss, id, '|');
        getline(ss, author, '|');
        getline(ss, date, '|');
        getline(ss, title);
        
        if (id!=get_ID) {
            Copy_borrow <<id <<"|" <<author <<"|" <<date <<"|" <<title<<endl;
        }     
        }
    while (getline(Myfile, line)) {
        stringstream ss(line);
        getline(ss, id, '|');
        getline(ss, author, '|');
        getline(ss, date, '|');
        getline(ss, title, '|');
        getline(ss, status);
        
        if (id==get_ID) {
            Copy_library <<id <<"|" <<author <<"|" <<date <<"|" <<title<<"|available" <<endl;
        } else {
            Copy_library <<id <<"|" <<author <<"|" <<date <<"|" <<title<<"|" <<status <<endl;
        }
    }
        Copy_library.close();
        Copy_borrow.close();
        borrow_books.close();
        Myfile.close();
        remove("library_file.txt");
        remove("borrowed_books.txt");
        rename("Copy_borrow.txt", "borrowed_books.txt");
        rename("Copy_library.txt", "library_file.txt");
        
        }

    void view_borrowed() {
            string id, title, author, date, status;
        cout << setw(10) << "ID" << setw(20) << "Autor" << setw(15) << "Date" << setw(30) << "Tile" << endl;
           ifstream Myfile;
            Myfile.open("borrowed_books.txt", ios::in);
               if (!Myfile) {
                   cout<<"No file was read";
               } else {
               string line;
               int a=1;
               while (getline(Myfile,line)) {
                   stringstream ss(line);
                getline(ss, id, '|');
                getline(ss, title, '|');
                getline(ss, author, '|');
                getline(ss, date);
                   cout << setw(10) << id << setw(20) << author << setw(15) << date << setw(30) << title <<endl;
                   }    
               }
               cout<<endl;
               Myfile.close();
           }
           
        
        


      int main () {
    int choice;
   
    while (true) {
    cout<<"Enter (1) if you want to add a book\n";
    cout<<"Enter (2) if you want to display the catalog\n";
    cout<<"Enter (3) if you want to delete a book\n";
    cout<<"Enter (4) if you want to borrow a book\n";
    cout<<"Enter (5) if you want to return a book\n";
    cout<<"Enter (6) if you want to view your borrowed books\n";
    cout<<"Enter (7) if you want to exit the program\n";
   
    cin>>choice;
    switch (choice) {
        case 1: addbook ();
        break;
        case 2: booklist();
        break;
        case 3: delete_book();
        break;
        case 4: borrow_book();
        break;
        case 5: return_book();
        break;
        case 6: view_borrowed();
        break;
        case 7: cout << "Thank you for choosing SAGING Library sytem!" 
<< endl;
	  default: cout<<”Invalid input”;
        return 0;

        }
    }
    return 0;
}






