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

string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(start, end - start + 1);
}
bool isNumeric(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

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
void checkBook();
void umenu();
void amenu();
void view_student_database();
void view_student_history();
void payfee();
void searchBook();

int main () {
    int c;

    system("cls");
        cout << "*************************************\n";
        cout << "Welcome to the Login page\n";
        cout << "*************************************\n";
        cout << "Press (1) for Student\n";
        cout << "Press (2) to Faculty Member\n";
        cout << "Press (3) to EXIT\n";
        cout << "*************************************\n";
        cout << "Please enter your choice: ";


    switch(c){
        case 1:
            user();
            break;
        case 2:
            faculty();
            break;
        case 3:
                system("cls");
                cout << "Thank you for choosing SAGING Library system!" << endl;
                return 0;
            default:
                system("cls");
                cout << "Please select from the options given above \n" << endl;
    
    }
    return 0;
};

void user() {
    int c;
    while (true) {
        system("cls");
    cout<<"*************************************\n";
    cout<<"Welcome to the Login page\n";
    cout<<"*************************************\n";
    cout<<"(1) to LOGIN"<<endl;
    cout<<"(2) to REGISTER"<<endl;
    cout<<"(3) if you FORGOT your PASSWORD"<<endl;
    cout<<"(4) to EXIT"<<endl;
    cout<<"*************************************\n";
    cout<<"Please enter your choice: ";
    cin>>c;
    cout<<endl;
        switch (c) {
            case 1:
                ulogin();
                return;
            case 2:
                uregistration();
                break;
            case 3:
                uforgot();
                break;
            case 4:
                system("cls");
                cout << "Thank you for choosing SAGING Library system!" << endl;
                exit(0);
            default:
                system("cls");
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please select from the options given above \n" << endl;
                break;
        }
    }
}
void faculty() {
    int c;
    while (true) {
    	system("cls");
  	cout<<"*************************************\n";
    cout<<"Welcome to the admin page\n";
    cout<<"*************************************\n";
    cout<<"(1) to LOGIN"<<endl;
    cout<<"(2) to REGISTER"<<endl;
    cout<<"(3) if you FORGOT your PASSWORD"<<endl;
    cout<<"(4) to EXIT"<<endl;
    cout<<"*************************************\n";
    cout<<"Please enter your choice: ";
        cin >> c;
        cout << endl;
        switch (c) {
            case 1:
                flogin();
                return;
            case 2:
                fregister();
                break;
            case 3:
                fforgot();
                break;
            case 4:
                system("cls");
                cout << "Thank you for choosing SAGING Library system!" << endl;
                exit(0);
            default:
                system("cls");
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please select from the options given above \n" << endl;
                break;
        }
    }
}

void umenu(){
    int choice;

    cout<<"******************************************************\n";
    cout<<"Welcome to BookTrack: Library Management System"<<endl;
    cout<<"******************************************************\n";
    while (true) {
    cout<<"Enter (1) display the catalog\n";
    cout<<"Enter (2) view your borrowed books\n";
    cout<<"Enter (3) search for a book\n";
    cout<<"Enter (4) if you want to exit the program\n";
    cout<<"******************************************************\n";
    cout<<"Enter your choice: ";
   
    if (cin >> choice) {
            switch (choice) {
                case 1: booklist();
                    break;
                case 2: view_borrowed();
                    break;
                case 3: checkBook();
                    break;
                case 4:
                    system("cls");
                    cout << "Thank you for choosing SAGING Library system!" << endl;
                    exit(0);
                default:
                    system("cls"); 
                    cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                    
            }
        } else {
            system("cls");
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

void amenu(){
    int choice;

    cout<<"*****************************************************\n";
    cout<<"Welcome to BookTrack: Library Management System"<<endl;
    cout<<"*****************************************************\n";
    cout<<"Admin"<<endl;
    while (true) {
    cout<<"Enter (1)  add a book\n";
    cout<<"Enter (2)  delete a book\n";
    cout<<"Enter (3)  display the catalog\n";
    cout<<"Enter (4)  display student information\n";
    cout<<"Enter (5)  display student database\n";
    cout<<"Enter (6)  if you want to borrow a book\n";
    cout<<"Enter (7)  if you want to return a book\n";
    cout<<"Enter (8)  if you want to pay a student's fee\n";
    cout<<"Enter (9)  to view as user\n";
    cout<<"Enter (10) if you want to search for a book\n";
    cout<<"Enter (11) if you want to exit the program\n";
       cout<<"*****************************************************\n";
    cout<<"Enter your choice: ";
   
    if (cin >> choice) {
            switch (choice) {
                case 1: addbook();
                    break;
                case 2: delete_book();
                    break;
                case 3: booklist();
                    break;
                case 4: view_student_history();
                    break;
                case 5: view_student_database();
                    break;
                case 6: borrow_book();
                    break;
                case 7: return_book();
                    break;
                case 8: payfee();
                    break;
                case 9: umenu();
                    break;
                case 10: searchBook();
                    break;
                case 11:
                    system("cls");
                    cout << "Thank you for choosing SAGING Library system!" << endl;
                    exit(0);
                default:
                    system("cls"); 
                    cout << "Invalid input. Please enter a number between 1 and 11." << endl;
                    
            }
        } else {
            cout << "Invalid input. Please enter a number between 1 and 11." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


void addbook() {
    string id, title, author, date, category, status = "Available", id_check, line;
    cin.ignore();
    
    cout << "Enter the identification code = ";
    getline(cin, id);
    id = trim(id);
    if (id.empty() || !isNumeric(id)) {
        system("cls");
        cout << "ID must be integers only and cannot be empty." << endl;
        return;
    }
    
    ifstream checkfile("library_file.txt");
    if (!checkfile) {
        system("cls");
        cout << "Error opening file for checking." << endl;
        return;
    }
    bool exists = false;
    while (getline(checkfile, line)) {
        stringstream ss(line);
        getline(ss, id_check, ',');
        id_check = trim(id_check);
        if (id == id_check) {
            exists = true;
            break;
        }
    }
    checkfile.close();
    if (exists) {
        system("cls");
        cout << "Book already exists." << endl;
        return;
    }
    
    cout << "Enter the title = ";
    getline(cin, title);
    title = trim(title);
    
    cout << "Enter the author of the book = ";
    getline(cin, author);
    author = trim(author);
    
    cout << "Enter the publication year of the book = ";
    getline(cin, date);
    date = trim(date);

    cout<<"Enter the category of the book = ";
    getline(cin, category);
    category = trim(category);

    
    if (id.empty() || title.empty() || author.empty() || date.empty()  || category.empty()) {
        system("cls");
        cout << "All fields are required. Shutting down program." << endl;
        return;
    }
    
    ofstream Myfile("library_file.txt", ios::app);
    if (!Myfile) {
        system("cls");
        cout << "Error opening file for writing." << endl;
        return;
    }
    Myfile << id << "," << title << "," << author << "," << date << "," << category << ","  << status << endl;
    Myfile.close();
    system("cls");
    cout << "Book added successfully." << endl;
}

void booklist() {
    string id, title, author, date, category, status;
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(10) << "ID"
         << "| " << left << setw(25) << "Author"
         << "| " << left << setw(15) << "Date"
         << "| " << left << setw(30) << "Title"
         << "| " << left << setw(15) << "Category"
         << "| " << left << setw(15) << "Status"
         << "|\n";
    cout << "----------------------------------------------------------------------------------------------------------------------\n";

    ifstream Myfile("library_file.txt");
    if (!Myfile) {
        system("cls");
        cout << "No file was read" << endl;
        return;
    }
    string line;
    while (getline(Myfile, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, status, ',' );
         cout << "| " << left << setw(10) << id
             << "| " << left << setw(25) << author
             << "| " << left << setw(15) << date
             << "| " << left << setw(30) << title
             << "| " << left << setw(15) << category
             << "| " << left << setw(15) << status
             << "|\n";
    }

    cout << "----------------------------------------------------------------------------------------------------------------------\n\n";
    cout << endl;
    Myfile.close();
}


void delete_book() {
    cin.ignore();
    string del_ID, id, title, author, date, category, status;
    
    cout << "Enter the id of the book you want to delete: ";
    getline(cin, del_ID);
    del_ID = trim(del_ID);
    
    ifstream Myfile("library_file.txt");
    ofstream Copy("Copy_file.txt");
    
    if (!Myfile) {
        system("cls");
        cout << "No file was read" << endl;
        return;
    }
    string line;
    bool found = false;
    while (getline(Myfile, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, status);
        if (trim(id) == del_ID) {
            found = true;
            continue;  // Skip this book
        }
        Copy <<id <<"," << title <<"," << author <<"," << date << "," << category << "," <<status<< endl;
    }
    Myfile.close();
    Copy.close();
    
    remove("library_file.txt");
    rename("Copy_file.txt", "library_file.txt");
    if (found) {
        system("cls");
        cout << "Book has been successfully removed." << endl;
    } else {
        system("cls");
        cout << "Book not found." << endl;
    }
}
   
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

void borrow_book() {
    string studID, bookID, borrowDate, line;
    cin.ignore();
    cout << "Enter Student ID: ";
    getline(cin, studID);
    studID = trim(studID);
    if (studID.empty()) {
        cout << "Student ID cannot be empty.\n";
        return;
    }
    cout << "Enter the book ID you want to borrow: ";
    getline(cin, bookID);
    bookID = trim(bookID);
    if (bookID.empty()) {
        cout << "Book ID cannot be empty.\n";
        return;
    }
    cout << "Enter the borrowing date (YYYY-MM-DD): ";
    getline(cin, borrowDate);
    borrowDate = trim(borrowDate);
    if (borrowDate.empty()) {
        system("cls");
        cout << "Borrowing date cannot be empty.\n";
        return;
    }
    ifstream libraryFile("library_file.txt");
    if (!libraryFile) {
        system("cls");
        cout << "Error: Could not open library file.\n";
        return;
    }
    ofstream tempLibrary("temp_library.txt");
    ofstream borrowFile("borrowed_books.txt", ios::app);
    string histFile = studID + "_history.txt";
    ofstream studentHistory(histFile, ios::app);
    bool bookFound = false;
    while (getline(libraryFile, line)) {
        stringstream ss(line);
        string id, title, author, date,category, status;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, status);
        if (trim(id) == bookID) {
            bookFound = true;
            if (trim(status) == "Available") {
                borrowFile << bookID << "," << title << "," << author << "," << date << "," << category << "," << studID << "," << borrowDate << endl;
                tempLibrary << bookID << "," << title << "," << author << "," << date << "," << category << ",Borrowed" << endl;
                studentHistory << "Borrowed: " << title << " (" << bookID << ") on " << borrowDate << endl;
                system("cls");
                cout << "Book was successfully Borrowed.\n";
            } else {
                system("cls");
                cout << "The book is already Borrowed.\n";
                tempLibrary << line << endl;
            }
        } else {
            tempLibrary << line << endl;
        }
    }
    libraryFile.close();
    tempLibrary.close();
    borrowFile.close();
    studentHistory.close();
    if (!bookFound) {
            system("cls");
            cout << "Sorry, that book does not exist.\n";
        remove("temp_library.txt");
        return;
    }
    ifstream studentDB("student_database.txt");
    ofstream tempStudentDB("temp_student_db.txt");
    bool studentInDB = false;
    while (getline(studentDB, line)) {
        stringstream ss(line);
        string sid, name, strikes, fee;
        getline(ss, sid, ',');
        getline(ss, name, ',');
        getline(ss, strikes, ',');
        getline(ss, fee, ',');
        if (trim(sid) == studID) {
            studentInDB = true;
        }
        tempStudentDB << line << endl;
    }
    studentDB.close();
    if (!studentInDB) {
        string name;
        cout << "New student. Please enter the student's name: ";
        getline(cin, name);
        name = trim(name);
        tempStudentDB << studID << "," << name << ",0,0" << endl;
    }
    tempStudentDB.close();
    remove("student_database.txt");
    rename("temp_student_db.txt", "student_database.txt");
    remove("library_file.txt");
    rename("temp_library.txt", "library_file.txt");
}

void return_book() {
    string studID, bookID, returnDate, condition, line;
    cin.ignore();
    cout << "Enter Student ID: ";
    getline(cin, studID);
    studID = trim(studID);
    if (studID.empty()) {
        cout << "Student ID cannot be empty.\n";
        return;
    }
    cout << "Enter the book ID you want to return: ";
    getline(cin, bookID);
    bookID = trim(bookID);
    if (bookID.empty()) {
        cout << "Book ID cannot be empty.\n";
        return;
    }
    cout << "Enter return date (YYYY-MM-DD): ";
    getline(cin, returnDate);
    returnDate = trim(returnDate);
    if (returnDate.empty()) {
        cout << "Return date cannot be empty.\n";
        return;
    }
    cout << "Condition (normal/damaged/missing/late): ";
    getline(cin, condition);
    condition = trim(condition);
    if (condition.empty()) {
        cout << "Condition cannot be empty.\n";
        return;
    }
    int feeAdd = 0, strikeAdd = 0;
    if (condition == "missing") { feeAdd = 1000; strikeAdd = 1; }
    else if (condition == "damaged") { feeAdd = 200; strikeAdd = 1; }
    else if (condition == "late") { feeAdd = 50; strikeAdd = 1; }
    ifstream borrowFile("borrowed_books.txt");
    ifstream libraryFile("library_file.txt");
    if (!borrowFile || !libraryFile) {
        cout << "Error: Could not open required files.\n";
        return;
    }
    ofstream tempBorrow("temp_borrow.txt");
    ofstream tempLibrary("temp_library.txt");
    string histFile = studID + "_history.txt";
    ofstream studentHistory(histFile, ios::app);
    bool bookFound = false;
    while (getline(borrowFile, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ',');
        if (trim(id) != bookID) {
            tempBorrow << line << endl;
        } else {
            bookFound = true;
        }
    }
    borrowFile.close();
    while (getline(libraryFile, line)) {
        stringstream ss(line);
        string id, title, author, date, category, status;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, status);
        if (trim(id) == bookID) {
            tempLibrary << bookID << "," << title << "," << author << "," << date << "," << category << ",Available" << endl;
            studentHistory << "Returned: " << title << " (" << bookID << ") on " << returnDate << " | Condition: " << condition << endl;
        } else {
            tempLibrary << line << endl;
        }
    }
    libraryFile.close();
    tempBorrow.close();
    tempLibrary.close();
    studentHistory.close();
    remove("borrowed_books.txt");
    rename("temp_borrow.txt", "borrowed_books.txt");
    remove("library_file.txt");
    rename("temp_library.txt", "library_file.txt");
    if (bookFound) {
        ifstream studentDB("student_database.txt");
        ofstream tempStudentDB("temp_student_db.txt");
        while (getline(studentDB, line)) {
            stringstream ss(line);
            string sid, name, strikes, fee;
            getline(ss, sid, ',');
            getline(ss, name, ',');
            getline(ss, strikes, ',');
            getline(ss, fee, ',');
            if (trim(sid) == studID) {
                int s = stoi(strikes);
                int f = stoi(fee);
                s += strikeAdd;
                f += feeAdd;
                tempStudentDB << sid << "," << name << "," << s << "," << f << endl;
            } else {
                tempStudentDB << line << endl;
            }
        }
        studentDB.close();
        tempStudentDB.close();
        remove("student_database.txt");
        rename("temp_student_db.txt", "student_database.txt");
        cout << "Book successfully returned.\n";
    } else {
        cout << "Book not found in borrowed list.\n";
    }
}

void view_student_database() {
    system("cls");
    cout << "------------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Student ID"
         << "| " << left << setw(25) << "Name"
         << "| " << left << setw(10) << "Strikes"
         << "| " << left << setw(10) << "Fee"
         << "|\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";

    ifstream file("student_database.txt");
    if (!file) {
        cout << "Error: Could not open student database file.\n";
        return;
    }

    string line, id, name, strikes, fee;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, strikes, ',');
        getline(ss, fee, ',');

        cout << "| " << left << setw(15) << trim(id)
             << "| " << left << setw(25) << trim(name)
             << "| " << left << setw(10) << trim(strikes)
             << "| " << left << setw(10) << trim(fee)
             << "|\n";
    }

    cout << "------------------------------------------------------------------------------------------------------------------\n";
    file.close();

    cout << "\nPress Enter to return...";
    cin.ignore();
    cin.get();
}


void view_student_history() {
    system("cls");
    string studID;
    cin.ignore();
    cout << "Enter Student ID: ";
    getline(cin, studID);
    studID = trim(studID);
    if (studID.empty()) {
        cout << "Student ID cannot be empty.\n";
        return;
    }

    string histFile = studID + "_history.txt";
    ifstream file(histFile);
    if (!file) {
        cout << "No history found for that student.\n";
        return;
    }

    cout << "\n------------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(60) << ("History for " + studID) << "|\n";
    cout << "------------------------------------------------------------------------------------------------------------------\n";

    string line;
    int count = 1;
    while (getline(file, line)) {
        cout << "| " << left << setw(5) << count++
             << "| " << left << setw(90) << trim(line)
             << "|\n";
    }

    cout << "------------------------------------------------------------------------------------------------------------------\n";
    file.close();

    cout << "\nPress Enter to return...";
    cin.get();
}


void view_borrowed() {
    system("cls");
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(10) << "Book ID"
         << "| " << left << setw(30) << "Title"
         << "| " << left << setw(25) << "Author"
         << "| " << left << setw(15) << "Date"
         << "| " << left << setw(15) << "Category"
         << "| " << left << setw(15) << "Borrower ID"
         << "|\n";
    cout << "----------------------------------------------------------------------------------------------------------------------\n";

    ifstream file("borrowed_books.txt");
    if (!file) {
        cout << "Error: Could not open borrowed books file.\n";
        return;
    }

    string line, id, title, author, date, category, studID, borrowDate;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, category, ',');
        getline(ss, studID, ',');
        getline(ss, borrowDate, ',');

        cout << "| " << left << setw(10) << trim(id)
             << "| " << left << setw(30) << trim(title)
             << "| " << left << setw(25) << trim(author)
             << "| " << left << setw(15) << trim(date)
             << "| " << left << setw(15) << trim(category)
             << "| " << left << setw(15) << trim(studID)
             << "|\n";
    }

    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    file.close();

    cout << "\nPress Enter to return...";
    cin.ignore();
    cin.get();
}
void checkBook() {
    string usrSearch, lcTitle, lcAuthor, lcCategory;
    string id, title, author, date,category, status;
    bool found = false;
    int resultNo = 0;
    cout << "Search: ";
    cin >> usrSearch;
    usrSearch = trim(usrSearch);    
    transform(usrSearch.begin(), usrSearch.end(), usrSearch.begin(), ::tolower);
    if (usrSearch.length() < 1) {
        cout << "Invalid Search." << endl;
    return;
}
cout << setw(10) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "Date" << setw(15) << "Category"<< setw(20) << "Status" << endl;
ifstream iFile("library_file.txt");
if (!iFile) {
    cout << "Error opening library file." << endl;
    return;
}
string line;
while (getline(iFile, line)) {
    stringstream ss(line);
    getline(ss, id, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, date, ',');
    getline(ss, category, ',');
    getline(ss, status);
    lcTitle = trim(title);
    lcAuthor = trim(author);
    lcCategory = trim(category);

    transform(lcTitle.begin(), lcTitle.end(), lcTitle.begin(), ::tolower);
    transform(lcAuthor.begin(), lcAuthor.end(), lcAuthor.begin(), ::tolower);
    transform(lcCategory.begin(),lcCategory.end(),lcCategory.begin(),::tolower);

    // Substring search: check if usrSearch is in title or author
    if (lcTitle.find(usrSearch) != string::npos || lcAuthor.find(usrSearch) != string::npos  || lcCategory.find(usrSearch) != string::npos) {
        cout << setw(10) << trim(id) << setw(30) << trim(title) << setw(20) << trim(author) << setw(15) << trim(date) << setw(20)  << setw(15) << category << trim(status) << endl;
        resultNo++;
        found = true;
    }
}   iFile.close();
if (!found) {
    cout << "No results found." << endl;
}
}

void ulogin() {
    int count = 0;
    string userID, password, id, pass;
    system("cls");
    cout << "Please enter username and password: " << endl;
    cout << "******************************************************";
    cout << "USERNAME: ";
    cin >> userID;
    cout << "\nPASSWORD: ";
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
        ulogin();  // Recurse for retry (consider loop for better UX)
    }
}

bool uregistration() {
    string ruserID, rpassword, rname, rclass_id;
    int rschool_year;
    system("cls");
    cout << "Enter preferred username : ";
    cin >> ruserID;
    cout << "Enter the password : ";
    cin >> rpassword;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, rname);
    cout << "Enter school year: ";
    cin >> rschool_year;
    cin.ignore();
    cout << "Enter LRN (up to 12 digits): ";
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
        cout << "Invalid LRN. It must consist of up to 12 digits only." << endl;
        return false;
    }
    ofstream f1("record_student.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << ' ' << rname << ' ' << rschool_year << ' ' << rclass_id << endl;
    system("cls");
    cout << "\nRegistration is successful! \n";
    user();
    return true;
}


    
void uforgot() {
    int option;
    system("cls");
    cout << "You forgot the password?" << endl;
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "Enter your choice: ";
    cin >> option;
    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\t\t\t Enter the username: ";
            cin >> suserId;
            ifstream f2("record_student.txt");
            while (f2 >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();
            if (count == 1) {
                cout << "Your account is found! \n";
                cout << "Your password is: " << spass << endl;
                user();  // Go back to user menu
            } else {
                                cout << "\nYour account is not found" << endl;
                uforgot();
            }
            break;
        }
        case 2:
            user();
            break;
        default:
            cout << "\t\t\t Please try again" << endl;
            uforgot();
    }
}
void flogin() {
    int count = 0;
    string userID, password, id, pass;
    system("cls");
    cout << "Please enter username and password: " << endl;
    cout << "******************************************************";
    cout << "USERNAME: ";
    cin >> userID;
    cout << "PASSWORD: ";
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
        flogin();  // Recurse for retry
    }
}

bool fregister() {
    string ruserID, rpassword, rname, rId;
    system("cls");
    cout << "nter Preferred username : ";
    cin >> ruserID;
    cin.ignore();
    cout << "Enter Preferred password : ";
    getline(cin, rpassword);
    cout << "Enter name: ";
    getline(cin, rname);
    ofstream f1("record_staff.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << endl;
    system("cls");
    cout << "Registration is successful! \n";
    faculty();
    return true;
}


void fforgot() {
    int option;
    system("cls");
    cout << "You forgot the password?\n";
    cout << "******************************************************";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "******************************************************";
    cout << "Enter your choice: ";
    cin >> option;
    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "Enter the username: ";
            cin >> suserId;
            ifstream f2("record_staff.txt");
            while (f2 >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();
            if (count == 1) {
                system("cls");
                cout << "Your account is found!\n";
                cout << "Your password is: " << spass << endl;
                faculty();  //Go back to faculty menu
            } else {
                cout << "Your account is not found" << endl;
                fforgot();
            }
            break;
        }
        case 2:
            faculty();
            break;
        default:
            cout << "Please try again" << endl;
            fforgot();
    }
}


void payfee() {
    int s,f, feeAdd;    
    string sid, name, strikes, feek, line, stud_ID, fee;
    cin.ignore();
    cout<<"Enter the students id;";

    getline(cin,stud_ID);
    cout<<"Enter the payment";
    cin>>feeAdd;
    
    
    ifstream sdb_in("student_database.txt");
    ofstream sdb_temp("student_database_temp.txt", ios::app);
    while (getline(sdb_in, line)) {
        stringstream ss(line);
        getline(ss, sid, ',');
        getline(ss, name, ',');
        getline(ss, strikes, ',');
        getline(ss, fee, ',');

        if (sid == stud_ID) {
            int s = stoi(strikes);
            int f = stoi(fee);
            f -= feeAdd;
            sdb_temp << sid << "," << name << "," << s << "," << f << endl;
        } else {
            sdb_temp << line << endl;
        }
    }
    sdb_in.close();
    sdb_temp.close();
    
    remove("student_database.txt");
    rename("student_database_temp.txt", "student_database.txt");

}

