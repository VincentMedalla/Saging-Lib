#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include <cctype>
#include <algorithm>
#include <limits>
#include <cstdlib> 

using namespace std;
void user();
void faculty();
void ulogin();
void uregistration();
void uforgot();
void flogin();
void fregister();
void fforgot();
void menu();
void addbook();
void booklist();
void delete_book();
void borrow_book();
void return_book();
void view_borrowed();
void searchBook();

int main () {
    int c;

    cout<<"\t\t\tWelcome to the Login page\t\t\t\n";
    cout<<"\t\tPress (1) for Student"<<endl;
    cout<<"\t\tPress (2) to Faculty Member"<<endl;
    cout<<"\t\tPress (3) to EXIT"<<endl;
    cout<<"\t\tPlease enter your choice: ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            user();
            break;
        case 2:
            faculty();
            break;
        case 3:
                cout << "Thank you for choosing SAGING Library system!" << endl;
                return 0;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
    
    }
    return 0;
};

void user(){
    int c;

    cout<<"Welcome to the Login page\n";
    cout<<"Press (1) to LOGIN"<<endl;
    cout<<"Press (2) to REGISTER"<<endl;
    cout<<"Press (3) if you FORGOT your PASSWORD"<<endl;
    cout<<"Press (4) to EXIT"<<endl;
    cout<<"Please enter your choice: ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            ulogin();
            break;
        case 2:
            uregistration();
            break;
        case 3:
            uforgot();
            break;
        case 4:
                cout << "Thank you for choosing SAGING Library system!" << endl;
                return;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
    
    }
    return;
}

void faculty(){
    int c;
    
    cout<<"Welcome to the admin page\n";
    cout<<"Press (1) to LOGIN"<<endl;
    cout<<"Press (2) to REGISTER"<<endl;
    cout<<"Press (3) if you FORGOT your PASSWORD"<<endl;
    cout<<"Press (4) to EXIT"<<endl;
    cout<<"Please enter your choice: ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            flogin();
            break;
        case 2:
            fregister();
            break;
        case 3:
            fforgot();
            break;
        case 4:
                cout << "Thank you for choosing SAGING Library system!" << endl;
                return;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
    
    }
    return;
}

void menu(){
    int choice;

    cout<<"\n\t\t\tWelcome to Saging Library System\t\t\t";
    while (true) {
    cout<<endl;
    cout<<"Enter (1) if you want to add a book\n";
    cout<<"Enter (2) if you want to display the catalog\n";
    cout<<"Enter (3) if you want to delete a book\n";
    cout<<"Enter (4) if you want to borrow a book\n";
    cout<<"Enter (5) if you want to return a book\n";
    cout<<"Enter (6) if you want to view your borrowed books\n";
    cout<<"Enter (7) if you want to search for a book\n";
    cout<<"Enter (8) if you want to exit the program\n";
   
    if (cin >> choice) {
            switch (choice) {
                case 1: addbook();
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
                case 7: searchBook();
                    break;
                case 8:
                    cout << "Thank you for choosing SAGING Library system!" << endl;
                    return;
                default: cout << "Invalid input. Please enter a number between 1 and 8." << endl;
                    exit(0);
            }
        } else {
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

    void addbook() {
        string id, title, author, date, category, status="Available", id_check, line, cont = "Y";
        cin.ignore();
        while(cont == "Y" | cont == "y"){
            cout<<"Enter the identification code = ";
            getline(cin, id);
            for (char ch : id) {
                if (!std::isdigit(ch)) {
                    cout<<"I.D. must onl be integers."<<endl;
                    return;
                }
            }
            
            ifstream checkfile;
            checkfile.open("library_file.txt", ios::in);
            while (getline(checkfile, line)) {
                stringstream ss(line);
                getline (ss, id_check, ',');
                
                if (id==id_check) {
                    cout<<"Book already exists\n\n";
                    checkfile.close();
                    return;
                }
            }
            
            cout<<"Enter the title = ";
            getline(cin, title);
            
            cout<<"Enter the author of the book = ";
            getline(cin, author);
            
            cout<<"Enter the publication year of the book = ";
            getline(cin, date);
            cout<<"Enter the category of the book = ";
            getline(cin, category);
            
            if (id.empty() | title.empty() | author.empty() | date.empty() | category.empty()) {
                    cout<<"All fields are required. Try again? (Y/n): ";
                    cin>>cont;
                    continue;
            }
            break;
        }
        ofstream Myfile;
        Myfile.open("library_file.txt", ios::out | ios::app);
        Myfile <<id <<"," <<title <<"," <<author <<"," <<date<< "," << category << "," <<status<<endl;
        Myfile.close();
    }
   
    void booklist() {
        string id, title, author, date, category, status;
        cout << setw(10) << "ID" << setw(20) << "Author" << setw(15) << "Date" << setw(30) << "Title" << setw(15) << "Category" << setw(20) <<"Status" << endl;
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
                getline(ss, category, ',');
                getline(ss, status);
                cout << setw(10) << id << setw(20) << author << setw(15) << date << setw(30) << title << setw(15) << category << setw(20) <<status <<endl;
                            }    
            }
            cout<<endl;
    };
     
    void delete_book() {
        cin.ignore();
        string del_ID, id, author, date, title, status, category;
     
        cout<<"Enter the id of the book you want to delete: ";
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
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, date, ',');
                getline(ss, category, ',');
                getline(ss, status);
                if (id==del_ID) {
                    continue;
                }
             
                Copy <<id <<"," << title <<"," << author <<"," << date << "," << category << "," <<status<< endl;
                }
             
             
            }
    Myfile.close();
    Copy.close();

    remove("library_file.txt");
    rename("Copy_file.txt", "library_file.txt");
    cout<<"Book has been successfully removed." << endl;
         
        };
     
    void borrow_book() {
        int a=0;
        string get_ID, id, author, date ,title, status, category;
        cin.ignore();
        cout<<"Enter the book ID you want to borrow: ";
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
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, date, ',');
            getline(ss, category, ',');
            getline(ss, status);
            if (id==get_ID) {
                if (status!="Borrowed") {
                    borrow_file <<id <<"," << title <<"," << author <<"," << date << "," << category <<endl;    
                    Copy <<id <<"," << title <<"," << author <<"," << date << "," << category <<"," << "Borrowed"  <<endl;
                } else {
                    cout<<"The book has already been borrowed\n\n";
                    return;
                }
             
            } else {
                Copy <<id <<"," << title <<"," << author <<"," << date << "," << category <<',' << status  <<endl;
            }
         
        }
         
        cout<<"Book was succesfully borrowed";
        Myfile.close();
        Copy.close();
        remove("library_file.txt");
        rename("Copy.txt", "library_file.txt");
    };

    
    void return_book() {
    string id, author, date, title, get_ID, line, status, category;
    ifstream borrow_books;
    ifstream Myfile;
    Myfile.open("library_file.txt", ios::in);
    borrow_books.open("borrowed_books.txt", ios::in);
    ofstream Copy_borrow;
    ofstream Copy_library;
    Copy_borrow.open("Copy_borrow.txt", ios::app);
    Copy_library.open("Copy_library.txt", ios::app); 
    
    cout<<"Enter the id of the book you want to return: ";
    cin>>get_ID;
    
    while (getline(borrow_books,line)) {
        stringstream ss(line);
                getline(ss, id, ',');
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, date, ',');
                getline(ss, category);
        if (id!=get_ID) {
            Copy_borrow <<id <<"," << title <<"," << author <<"," << date << "," << category <<endl;
        }     
        }
    while (getline(Myfile, line)) {
        stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, date, ',');
            getline(ss, category, ',');
            getline(ss, status);        
        if (id==get_ID) {
            Copy_library <<id <<"," << title <<"," << author <<"," << date <<"," << category << "," << "Available" <<endl;
        } else {
            Copy_library <<id <<"," << title <<"," << author <<"," << date << "," << category <<"," <<status <<endl;
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
        
        };

    void view_borrowed() {
            string id, title, author, date, category, status;
        cout << setw(10) << "ID" << setw(20) << "Author" << setw(15) << "Date" << setw(30) << "Title" << setw(15) << "Category" << endl;
           ifstream Myfile;
            Myfile.open("borrowed_books.txt", ios::in);
               if (!Myfile) {
                   cout<<"No file was read";
               } else {
               string line;
               int a=1;
               while (getline(Myfile,line)) {
                   stringstream ss(line);
                getline(ss, id, ',');
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, date, ',');
                getline(ss, category);
                   cout << setw(10) << id << setw(20) << author << setw(15) << date << setw(30) << title << setw(15) << category <<endl;
                   }    
               }
               cout<<endl;
               Myfile.close();
           };
           
void searchBook(){     
    string usrSearch, lcTitle, lcAuthor, lcCategory;
    string id, title, author, date, category, status;
    bool searchStatus=false;
    int resultNo=0;
    cout<<"Search: ";
    cin>>usrSearch;
    transform(usrSearch.begin(),usrSearch.end(),usrSearch.begin(),::tolower); //turn usrSearch to lowercase
    if(usrSearch.length()<1){
        cout<<"Invalid Search."<<endl; //check for usrSearch length
        return;
    }
    cout << setw(10) << "ID" << setw(20) << "Author" << setw(15) << "Date" << setw(30) << "Title" << setw(15) << "Category" << setw(20) <<"Status" << endl;
    ifstream iFile;
    string line = "";
    int location;
    iFile.open("library_file.txt");
    while(getline(iFile, line)){
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, status);
        lcTitle = title, lcAuthor = author, lcCategory = category;
        transform(lcTitle.begin(),lcTitle.end(),lcTitle.begin(),::tolower);
        transform(lcAuthor.begin(),lcAuthor.end(),lcAuthor.begin(),::tolower); //turn title and author to lowercase
        transform(lcCategory.begin(),lcCategory.end(),lcCategory.begin(),::tolower); //turn title and author to lowercase

        // for(int i = 0;i<usrSearch.length();i++){
        //     if(usrSearch[i] == lcTitle[i] || usrSearch[i] == lcAuthor[i] || usrSearch[i] == id[i] || usrSearch[i] == category [i]){
        //         searchStatus = true;
        //     }
        //     else{
        //         searchStatus = false;
        //         continue;
        //     }
        // }
        if(lcTitle.find(usrSearch) != string::npos || lcAuthor.find(usrSearch) != string::npos || id.find(usrSearch) != string::npos || lcCategory.find(usrSearch) != string::npos){
            cout << setw(10) << id << setw(20) << author << setw(15) << date << setw(30) << title << setw(15) << category <<setw(20) <<status <<endl;
            resultNo++;
        }
        
    }
    if(resultNo<1){
        cout << setw(10) << "No results"<<endl;
    }
    iFile.close();
};

void ulogin() {
    int count = 0;
    string userID, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userID;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;
    ifstream input("record_student.txt");
    while (input >> id >> pass) {
        if (id == userID && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();
    if (count == 1) {
        system("cls");
        cout << userID << "\n Your LOGIN is successful" << endl;
        menu();
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
    }
};


void uregistration(){
    string ruserID,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserID;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f1("record_student.txt", ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful! \n";
    main();
};
    
void uforgot(){
    int option;
    system("cls");
    cout<<"You forgot the password?";
    cout<<"Press 1 to search your id by username"<<endl;
    cout<<"Press 2 to go back to the main menu"<<endl;
    cout<<"\t\t\t Enter your choice: ";
    cin>>option;
    switch (option)
    {
    case 1 : {
        int count=0;
        string suserId,sId,spass;
        cout<<"\n\t\t\t Enter the username: ";
        cin>>suserId;

        ifstream f2("record_student.txt");
        while(f2>>sId>>spass){
            if(sId==suserId){
                count=1;
            }
        }
        f2.close();
        if(count==1){
            cout<<"\n\n Your account is found! \n";
            cout<<"\n\n Your password is: "<<spass;
            main();
        }else{
            cout<<"\n\tYour account is not found";
            main();
        }
        break;
    }
    case 2:
        {
            main();
        }
    default:
        cout<<"\t\t\t Please try again"<<endl;
        uforgot();
    }
};

void flogin() {
    int count = 0;
    string userID, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userID;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;
    ifstream input("record_staff.txt");
    while (input >> id >> pass) {
        if (id == userID && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();
    if (count == 1) {
        system("cls");
        cout << userID << "\n Your LOGIN is successful" << endl;
        menu();
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
    }
};

void fregister(){
    string ruserID,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserID;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f1("record_staff.txt", ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful! \n";
    main();
};

void fforgot(){
    int option;
    system("cls");
    cout<<"You forgot the password?";
    cout<<"Press 1 to search your id by username"<<endl;
    cout<<"Press 2 to go back to the main menu"<<endl;
    cout<<"\t\t\t Enter your choice: ";
    cin>>option;
    switch (option)
    {
    case 1 : {
        int count=0;
        string suserId,sId,spass;
        cout<<"\n\t\t\t Enter the username: ";
        cin>>suserId;

        ifstream f2("record_staff.txt");
        while(f2>>sId>>spass){
            if(sId==suserId){
                count=1;
            }
        }
        f2.close();
        if(count==1){
            cout<<"\n\n Your account is found! \n";
            cout<<"\n\n Your password is: "<<spass;
            main();
        }else{
            cout<<"\n\tYour account is not found";
            main();
        }
        break;
    }
    case 2:
        {
            main();
        }
    default:
        cout<<"\t\t\t Please try again"<<endl;
        fforgot();
    }
};