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
bool uregistration();
void uforgot();
void flogin();
bool fregister();
void fforgot();
void menu();
void addbook();
void booklist();
void delete_book();
void borrow_book();
void return_book();
void view_borrowed();
void searchBook();
void umenu();
void amenu();
void view_student_database();
void view_student_history();

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
                cout << "Thank you for choosing BookTrack: Library Management System!" << endl;
                return 0;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
    
    }
    return 0;
};

void user(){
    int c;

    system("cls");
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
                exit(0);
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
    
    }
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
                cout << "Thank you for choosing BookTrack: Library Management System!" << endl;
                exit(0);
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
    
    }
}

void umenu(){
    int choice;

    cout<<"\n\t\t\tWelcome to BookTrack: Library Management System\t\t\t"<<endl;
    while (true) {
    cout<<"Enter (1) display the catalog\n";
    cout<<"Enter (2) borrow a book\n";
    cout<<"Enter (3) return a book\n";
    cout<<"Enter (4) view your borrowed books\n";
    cout<<"Enter (5) search for a book\n";
    cout<<"Enter (6) if you want to exit the program\n";
    cout<<"\t\t\tEnter your choice: ";
   
    if (cin >> choice) {
            switch (choice) {
                case 1: booklist();
                    break;
                case 2: borrow_book();
                    break;
                case 3: return_book();
                    break;
                case 4: view_borrowed();
                    break;
                case 5: searchBook();
                    break;
                case 6:
                    system("cls");
                    cout << "\t\t\t Thank you for choosing SAGING Library system!" << endl;
                    exit(0);
                default:
                    system("cls"); 
                    cout << "Invalid input. Please enter a number between 1 and 8." << endl;
                    
            }
        } else {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

void amenu(){
    int choice;

    cout<<"\n\t\t\tWelcome to BookTrack: Library Management System\t\t\t"<<endl;
    cout<<"\n\t\t\tAdmin\t\t\t"<<endl;
    while (true) {
    cout<<"Enter (1) add a book\n";
    cout<<"Enter (2) display the catalog\n";
    cout<<"Enter (3) display student information\n";
    cout<<"Enter (4) display student database\n";
    cout<<"Enter (5) delete a book\n";
    cout<<"Enter (6) to view as user\n";
    cout<<"Enter (7) if you want to search for a book\n";
    cout<<"Enter (8) if you want to exit the program\n";
    cout<<"\t\t\tEnter your choice: ";
   
    if (cin >> choice) {
            switch (choice) {
                case 1: addbook();
                    break;
                case 2: booklist();
                    break;
                case 3: view_student_history();
                    break;
                case 4: view_student_database();
                    break;
                case 5: delete_book();
                    break;
                case 6: umenu();
                    break;
                case 7: searchBook();
                    break;
                case 8:
                    system("cls");
                    cout << "\t\t\t Thank you for choosing SAGING Library system!" << endl;
                    exit(0);
                default:
                    system("cls"); 
                    cout << "Invalid input. Please enter a number between 1 and 8." << endl;
                    
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
    string get_ID, stud_ID, id, author, date, title, category, status, name, borrow_date, line;
    bool found = false, exist = false;
    cin.ignore();

    cout<<"Enter Student ID: ";
    getline(cin, stud_ID);

    cout<<"Enter the book ID you want to borrow: ";
    getline(cin, get_ID);

    cout<<"Enter the borrowing date (YYYY-MM-DD): ";
    getline(cin, borrow_date);

    ifstream Myfile("library_file.txt");
    ofstream Copy("Copy.txt", ios::app);
    ofstream borrow_file("borrowed_books.txt", ios::app);
    
    string histFile = stud_ID + "_history.txt";
    ofstream student_history(histFile, ios::app);

    while (getline(Myfile, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, status);

        if (id == get_ID) {
            found = true;
            if (status == "available") {
                borrow_file << id << "," << title << "," << author << "," << date << "," << category << "," << stud_ID << "," << borrow_date << endl;
                Copy << id << "," << title << "," << author << "," << date << "," << category << ",Borrowed" << endl;
                student_history << "Borrowed: " << title << " (" << id << ") on " << borrow_date << endl;
                cout << "Book was successfully borrowed.\n";
            } else {
                cout << "The book is already borrowed.\n";
                Copy << line << endl;
            }
        } else {
            Copy << line << endl;
        }
    }

    if (!found)
        cout << "Sorry, that book does not exist.\n";

    ifstream student_db_out("student_database.txt");
    ofstream student_db_in("student_database_temp.txt", ios::app);
    string sid, sname, strikes, fee;
    bool inDB = false;

    while (getline(student_db_out, line)) {
        stringstream ss(line);
        getline(ss, sid, ',');
        getline(ss, sname, ',');
        getline(ss, strikes, ',');
        getline(ss, fee, ',');

        if (sid == stud_ID) {
            inDB = true;
        }
        student_db_in << line << endl;
    }
    student_db_out.close();

    if (!inDB) {
        cout << "New student. Please enter the student's name: ";
        getline(cin, name);
        student_db_in << stud_ID << "," << name << ",0,0" << endl;
    }
    student_db_in.close();
    remove("student_database.txt");
    rename("student_database_temp.txt", "student_database.txt");

    Myfile.close();
    Copy.close();
    borrow_file.close();
    student_history.close();

    remove("library_file.txt");
    rename("Copy.txt", "library_file.txt");
}
    
void return_book() {
    string get_ID, stud_ID, id, title, author, date, status, line, category;
    string return_date, condition;
    bool found = false;

    cin.ignore();
    cout << "Enter Student ID: ";
    getline(cin, stud_ID);
    cout << "Enter the book ID you want to return: ";
    getline(cin, get_ID);
    cout << "Enter return date (YYYY-MM-DD): ";
    getline(cin, return_date);

    cout << "Condition (normal/damaged/missing/late): ";
    getline(cin, condition);

    ifstream borrow_books("borrowed_books.txt");
    ifstream Myfile("library_file.txt");
    ofstream Copy_borrow("Copy_borrow.txt", ios::app);
    ofstream Copy_library("Copy_library.txt", ios::app);
    
    string histFile = stud_ID + "_history.txt";
    ofstream student_history(histFile, ios::app);

    int feeAdd = 0, strikeAdd = 0;
    if (condition == "missing") { feeAdd = 1000; strikeAdd = 1; }
    else if (condition == "damaged") { feeAdd = 200; strikeAdd = 1; }
    else if (condition == "late") { feeAdd = 50; strikeAdd = 1; }

    while (getline(borrow_books, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        if (id != get_ID)
            Copy_borrow << line << endl;
        else
            found = true;
    }

    while (getline(Myfile, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, status);

        if (id == get_ID) {
            Copy_library << id << "," << title << "," << author << "," << date << "," << category << ",available" << endl;
            student_history << "Returned: " << title << " (" << id << ") on " << return_date 
                            << " | Condition: " << condition << endl;
        } else {
            Copy_library << line << endl;
        }
    }

    borrow_books.close();
    Myfile.close();
    Copy_borrow.close();
    Copy_library.close();

    remove("library_file.txt");
    remove("borrowed_books.txt");
    rename("Copy_library.txt", "library_file.txt");
    rename("Copy_borrow.txt", "borrowed_books.txt");

    ifstream sdb_in("student_database.txt");
    ofstream sdb_temp("student_database_temp.txt");
    string sid, name, strikes, fee;
    while (getline(sdb_in, line)) {
        stringstream ss(line);
        getline(ss, sid, ',');
        getline(ss, name, ',');
        getline(ss, strikes, ',');
        getline(ss, fee, ',');

        if (sid == stud_ID) {
            int s = stoi(strikes);
            int f = stoi(fee);
            s += strikeAdd;
            f += feeAdd;
            sdb_temp << sid << "," << name << "," << s << "," << f << endl;
        } else {
            sdb_temp << line << endl;
        }
    }
    sdb_in.close();
    sdb_temp.close();

    remove("student_database.txt");
    rename("student_database_temp.txt", "student_database.txt");

    student_history.close();
    if (found)
        cout << "Book successfully returned.\n";
    else
        cout << "Book not found in borrowed list.\n";
}
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
        umenu();
    } else {
        system("cls");
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
        ulogin();
    }
};

bool uregistration() {  // Changed to bool
    string ruserID, rpassword, rid, rpass, rname, rclass_id;
    int rschool_year;
    system("cls");

    cout << "\t\t\t Enter preferred username : ";
    cin >> ruserID;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;
    cout << "\t\t\tEnter name: ";
    cin.ignore();  // Added to handle leftover input
    getline(cin, rname);
    cout << "\t\t\tEnter school year: ";
    cin >> rschool_year;
    cin.ignore();
    cout << "\t\t\tEnter LRN (up to 12 digits): ";
    getline(cin, rclass_id);
    bool valid = true;
    if (rclass_id.length() > 12 || rclass_id.empty()) {
        valid = false;
    } else {
        for (char c : rclass_id) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
    }
    if (!valid) {
        cout << "Invalid class ID. It must consist of up to 12 digits only." << endl;
        return false;
    }
    
    
    ofstream f1("record_student.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << ' ' << rname << ' ' << rschool_year << ' ' << rclass_id << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
    user();  // Call user() instead of returning
    return true;  // Now valid
}
    
void uforgot(){
    int option;
    system("cls");
    cout<<"You forgot the password?"<<endl;
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
            cout<<"\n\n Your password is: "<<spass<<endl;
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
        amenu();
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
    }
};

bool fregister(){
    string ruserID,rpassword,rid,rpass,rname,rId;
    system("cls");
    cout<<"\t\t\t Enter Preferred username : ";
    cin>>ruserID;
    cin.ignore();
    cout<<"\t\t\t Enter Preferred password : ";
    cin>>rpassword;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, rname);
    cin.ignore();
    cout << "Enter LRN (up to 12 digits): ";
    getline(cin, rId);

    bool valid = true;
    if (rId.length() > 12 || rId.empty()) {
        valid = false;
    } else {
        for (char c : rId) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
    }
    if (!valid) {
        cout << "Invalid class ID. It must consist of up to 12 digits only." << endl;
        return false;
    }

    ofstream f1("record_staff.txt", ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successful! \n";
    main();

    return true;
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
            system("cls");
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
   void view_student_database() {
    cout << setw(15) << "Student ID" << setw(25) << "Name" << setw(10) << "Strikes" << setw(10) << "Fee" << endl;

    ifstream file("student_database.txt");
    string line, id, name, strikes, fee;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, strikes, ',');
        getline(ss, fee, ',');
        cout << setw(15) << id << setw(25) << name << setw(10) << strikes << setw(10) << fee << endl;
    }
    cout<<endl;
    file.close();
}
void view_student_history() {
    cin.ignore();
    string stud_ID, line;
    cout << "Enter Student ID: ";
    getline(cin, stud_ID);
    string histFile = stud_ID + "_history.txt";

    ifstream file(histFile);
    if (!file) {
        cout << "No history found for that student.\n";
        return;
    }
    cout << "History for " << stud_ID << ":\n";
    while (getline(file, line)) {
        cout << " - " << line << endl;
    }
    file.close();
}   
