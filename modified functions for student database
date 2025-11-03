 void return_book() {
    string get_ID, stud_ID, id, title, author, date, status, line;
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
        getline(ss, status);

        if (id == get_ID) {
            Copy_library << id << "," << title << "," << author << "," << date << ",available" << endl;
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

void borrow_book() {
    string get_ID, stud_ID, id, author, date, title, status, name, borrow_date, line;
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
        getline(ss, status);

        if (id == get_ID) {
            found = true;
            if (status == "available") {
                borrow_file << id << "," << title << "," << author << "," << date << "," << stud_ID << "," << borrow_date << endl;
                Copy << id << "," << title << "," << author << "," << date << ",borrowed" << endl;
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
