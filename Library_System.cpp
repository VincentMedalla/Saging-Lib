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
                system("cls");
                cout << "Thank you for choosing SAGING Library system!" << endl;
                return 0;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;
    
    }
    return 0;
};

void user() {
    int c;
    while (true) {
        system("cls");
        cout << "Welcome to the Login page\n";
        cout << "Press (1) to LOGIN" << endl;
        cout << "Press (2) to REGISTER" << endl;
        cout << "Press (3) if you FORGOT your PASSWORD" << endl;
        cout << "Press (4) to EXIT" << endl;
        cout << "Please enter your choice: ";
        cin >> c;
        cout << endl;
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
                cout << "\t\t\t Please select from the options given above \n" << endl;
                break;
        }
    }
}
void faculty() {
    int c;
    while (true) {
        system("cls");
        cout << "Welcome to the admin page\n";
        cout << "Press (1) to LOGIN" << endl;
        cout << "Press (2) to REGISTER" << endl;
        cout << "Press (3) if you FORGOT your PASSWORD" << endl;
        cout << "Press (4) to EXIT" << endl;
        cout << "Please enter your choice: ";
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
                cout << "\t\t\t Please select from the options given above \n" << endl;
                break;
        }
    }
}

void umenu(){
    int choice;

    cout<<"\n\t\t\tWelcome to Saging Library System\t\t\t"<<endl;
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
                case 5: checkBook();
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
            system("cls");
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};

void amenu() {
    int choice;
    cout << "\n\t\t\tWelcome to Saging Library System\t\t\t" << endl;
    cout << "\n\t\t\tAdmin\t\t\t" << endl;
    while (true) {
        cout << "Enter (1) add a book\n";
        cout << "Enter (2) display the catalog\n";
        cout << "Enter (3) display student information\n";
        cout << "Enter (4) display student history\n";
        cout << "Enter (5) delete a book\n";
        cout << "Enter (6) to view as user\n";
        cout << "Enter (7) to search for a book\n";
        cout << "Enter (8) to exit the program\n";
        cout << "\t\t\tEnter your choice: ";
        if (cin >> choice) {
            switch (choice) {
                case 1: addbook(); break;
                case 2: booklist(); break;
                case 3: view_student_database(); break;
                case 4: view_student_history(); break;
                case 5: delete_book(); break;
                case 6: umenu(); break;
                case 7: checkBook(); break;
                case 8:system("cls");
                    cout << "\t\t\t Thank you for choosing SAGING Library system!" << endl;
                    exit(0);
                default:
                    system("cls");
                    cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            }
        } else {
            system("cls");
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void addbook() {
    string id, title, author, date, status = "available", id_check, line;
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
    
    if (id.empty() || title.empty() || author.empty() || date.empty()) {
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
    Myfile << id << "," << title << "," << author << "," << date << "," << status << endl;
    Myfile.close();
    system("cls");
    cout << "Book added successfully." << endl;
}

void booklist() {
    string id, title, author, date, status;
    cout << setw(10) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "Date" << setw(20) << "Status" << endl;
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
        getline(ss, status);
        cout << setw(10) << trim(id) << setw(30) << trim(title) << setw(20) << trim(author) << setw(15) << trim(date) << setw(20) << trim(status) << endl;
    }
    cout << endl;
    Myfile.close();
}

void delete_book() {
    cin.ignore();
    string del_ID, id, title, author, date, status;
    
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
        getline(ss, status);
        if (trim(id) == del_ID) {
            found = true;
            continue;  // Skip this book
        }
        Copy << id << "," << title << "," << author << "," << date << "," << status << endl;
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
        string id, title, author, date, status;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, status);
        if (trim(id) == bookID) {
            bookFound = true;
            if (trim(status) == "available") {
                borrowFile << bookID << "," << title << "," << author << "," << date << "," << studID << "," << borrowDate << endl;
                tempLibrary << bookID << "," << title << "," << author << "," << date << ",borrowed" << endl;
                studentHistory << "Borrowed: " << title << " (" << bookID << ") on " << borrowDate << endl;
                system("cls");
                cout << "Book was successfully borrowed.\n";
            } else {
                system("cls");
                cout << "The book is already borrowed.\n";
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
        string id, title, author, date, status;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, status);
        if (trim(id) == bookID) {
            tempLibrary << bookID << "," << title << "," << author << "," << date << ",available" << endl;
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
    cout << setw(15) << "Student ID" << setw(25) << "Name" << setw(10) << "Strikes" << setw(10) << "Fee" << endl;
    cout << string(60, '-') << endl;
    ifstream file("student_database.txt");
    if (!file) {
        cout << "Error: Could not open student database file.\n";
        return;
    }
    string line, id, name, strikes, fee;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, strikes, ',');
        getline(ss, fee, ',');
        cout << setw(15) << trim(id) << setw(25) << trim(name) << setw(10) << trim(strikes) << setw(10) << trim(fee) << endl;
    }
    cout << endl;
    file.close();
}

void view_student_history() {
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
    cout << "History for " << studID << ":\n";
    string line;
    while (getline(file, line)) {
        cout << " - " << line << endl;
    }
    file.close();
}

void view_borrowed() {
    cout << setw(10) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "Date" << endl;
    cout << string(75, '-') << endl;
    ifstream file("borrowed_books.txt");
    if (!file) {
        cout << "Error: Could not open borrowed books file.\n";
        return;
    }
    string line, id, title, author, date, studID, borrowDate;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, date, ',');
        getline(ss, studID, ',');
        getline(ss, borrowDate, ',');
        cout << setw(10) << trim(id) << setw(30) << trim(title) << setw(20) << trim(author) << setw(15) << trim(date) << endl;
    }
    cout << endl;
    file.close();
}

void checkBook() {
    string usrSearch, lcTitle, lcAuthor;
    string id, title, author, date, status;
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
cout << setw(10) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "Date" << setw(20) << "Status" << endl;
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
    getline(ss, status);
    lcTitle = trim(title);
    lcAuthor = trim(author);
    transform(lcTitle.begin(), lcTitle.end(), lcTitle.begin(), ::tolower);
    transform(lcAuthor.begin(), lcAuthor.end(), lcAuthor.begin(), ::tolower);
    // Substring search: check if usrSearch is in title or author
    if (lcTitle.find(usrSearch) != string::npos || lcAuthor.find(usrSearch) != string::npos) {
        cout << setw(10) << trim(id) << setw(30) << trim(title) << setw(20) << trim(author) << setw(15) << trim(date) << setw(20) << trim(status) << endl;
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
        ulogin();  // Recurse for retry (consider loop for better UX)
    }
}

bool uregistration() {
    string ruserID, rpassword, rname, rclass_id;
    int rschool_year;
    system("cls");
    cout << "\t\t\t Enter preferred username : ";
    cin >> ruserID;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;
    cout << "\t\t\tEnter name: ";
    cin.ignore();
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
        cout << "Invalid LRN. It must consist of up to 12 digits only." << endl;
        return false;
    }
    ofstream f1("record_student.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << ' ' << rname << ' ' << rschool_year << ' ' << rclass_id << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
    user();
    return true;
}


    
void uforgot() {
    int option;
    system("cls");
    cout << "You forgot the password?" << endl;
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t Enter your choice: ";
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
                cout << "\n\n Your account is found! \n";
                cout << "\n\n Your password is: " << spass << endl;
                user();  // Go back to user menu
            } else {
                                cout << "\n\tYour account is not found" << endl;
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
        flogin();  // Recurse for retry
    }
}

bool fregister() {
    string ruserID, rpassword, rname, rId;
    system("cls");
    cout << "\t\t\t Enter Preferred username : ";
    cin >> ruserID;
    cin.ignore();
    cout << "\t\t\t Enter Preferred password : ";
    getline(cin, rpassword);
    cout << "Enter name: ";
    getline(cin, rname);
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
        cout << "Invalid LRN. It must consist of up to 12 digits only." << endl;
        return false;
    }
    ofstream f1("record_staff.txt", ios::app);
    f1 << ruserID << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
    faculty();
    return true;
}


void fforgot() {
    int option;
    system("cls");
    cout << "You forgot the password?\n";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;
    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\t\t\t Enter the username: ";
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
                cout << "\n Your account is found!\n";
                cout << "\t\t Your password is: " << spass << endl;
                faculty();  // Go back to faculty menu
            } else {
                cout << "\n\tYour account is not found" << endl;
                fforgot();
            }
            break;
        }
        case 2:
            faculty();
            break;
        default:
            cout << "\t\t\t Please try again" << endl;
            fforgot();
    }
}
