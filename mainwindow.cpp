#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDialog>

//add book function
void MainWindow::onAddBookClicked() {
    bool ok = false;
    const QString id = QInputDialog::getText(this, "Add Book", "Enter the identification code:", QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok) return;

    // check if the written ID already exist
    QFile checkFile("library_file.txt");
    if (checkFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&checkFile);
        while (!in.atEnd()) {
            const QString line = in.readLine();
            const QStringList parts = line.split(',');
            if (!parts.isEmpty() && parts[0].trimmed() == id) {
                QMessageBox::information(this, "Book Exists", "Book already exists.");
                checkFile.close();
                return;
            }
        }
        checkFile.close();
    }

    const QString title = QInputDialog::getText(this, "Add Book", "Enter the title:", QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok) return;
    const QString author = QInputDialog::getText(this, "Add Book", "Enter the author of the book:", QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok) return;
    const QString date = QInputDialog::getText(this, "Add Book", "Enter the publication year of the book:", QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok) return;

    if (id.isEmpty() || title.isEmpty() || author.isEmpty() || date.isEmpty()) {
        QMessageBox::warning(this, "Missing Fields", "All fields are required.");
        return;
    }

    const QString status = "available";
    QFile outFile("library_file.txt");
    if (!outFile.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "File Error", "Unable to open library_file.txt for writing.");
        return;
    }
    QTextStream out(&outFile);
    out << id << "," << title << "," << author << "," << date << "," << status << "\n";
    outFile.close();

    QMessageBox::information(this, "Success", "Book added successfully.");
}


//view book catalog function
void MainWindow::onBookListButtonClicked()
{
    QFile file("library_file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Catalog", "library_file.txt not found or cannot be opened.");
        return;
    }

    QTextStream in(&file);
    QString output;

    output += QString("%1 %2 %3 %4 %5\n")
                  .arg("ID", -8)
                  .arg("Title", -30)
                  .arg("Author", -20)
                  .arg("Date", -6)
                  .arg("Status", -10);
    output += QString(80, '-') + '\n';

    while (!in.atEnd()) {
        const QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        const QStringList parts = line.split(',', Qt::KeepEmptyParts); // expected id,title,author,date,status
        const QString id    = parts.value(0).trimmed();
        const QString title = parts.value(1).trimmed();
        const QString auth  = parts.value(2).trimmed();
        const QString date  = parts.value(3).trimmed();
        const QString stat  = parts.value(4).trimmed();
        output += QString("%1 %2 %3 %4 %5\n")
                      .arg(id, -8)
                      .arg(title.left(30), -30)
                      .arg(auth.left(20), -20)
                      .arg(date, -6)
                      .arg(stat, -10);
    }
    file.close();


    QDialog dlg(this);
    dlg.setWindowTitle("Library Catalog");
    QVBoxLayout *lay = new QVBoxLayout(&dlg);
    QTextEdit *text = new QTextEdit(&dlg);
    text->setReadOnly(true);
    text->setPlainText(output);
    lay->addWidget(text);
    QPushButton *closeBtn = new QPushButton("Close", &dlg);
    connect(closeBtn, &QPushButton::clicked, &dlg, &QDialog::accept);
    lay->addWidget(closeBtn);
    dlg.resize(800, 400);
    dlg.exec();
}

// function for deleting book
void MainWindow::onDeleteBookClicked()
{
    bool ok = false;
    const QString delId = QInputDialog::getText(this, "Delete Book",
                                                "Enter the ID of the book to delete:",
                                                QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok || delId.isEmpty()) return;

    QFile inFile("library_file.txt");
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Delete Book", "library_file.txt not found or cannot be opened.");
        return;
    }

    QFile outFile("Copy_file.txt");
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        inFile.close();
        QMessageBox::critical(this, "Delete Book", "Cannot create temporary file.");
        return;
    }

    QTextStream in(&inFile);
    QTextStream out(&outFile);
    bool found = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) continue;
        const QStringList parts = line.split(',', Qt::KeepEmptyParts);
        const QString id = parts.value(0).trimmed();
        if (id == delId) {
            found = true;
            continue; // skip this record
        }
        out << line << '\n';
    }

    inFile.close();
    outFile.close();

    if (!found) {
        QFile::remove("Copy_file.txt");
        QMessageBox::information(this, "Delete Book", "Book ID not found.");
        return;
    }

    // Replace original file with the copy
    if (!QFile::remove("library_file.txt") || !QFile::rename("Copy_file.txt", "library_file.txt")) {
        QMessageBox::critical(this, "Delete Book", "Failed to update library file after deletion.");
        return;
    }

    QMessageBox::information(this, "Delete Book", "Book has been successfully removed.");
}

//function for borrowing book
void MainWindow::onBorrowBookClicked()
{
    bool ok = false;
    const QString borrowId = QInputDialog::getText(this, "Borrow Book",
                                                   "Enter the ID of the book to borrow:",
                                                   QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok || borrowId.isEmpty()) return;

    QFile inFile("library_file.txt");
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Borrow Book", "library_file.txt not found or cannot be opened.");
        return;
    }

    QFile outFile("Copy_file.txt");
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        inFile.close();
        QMessageBox::critical(this, "Borrow Book", "Cannot create temporary file.");
        return;
    }

    QFile borrowLog("borrowed_books.txt");
    if (!borrowLog.open(QIODevice::Append | QIODevice::Text)) {
        inFile.close();
        outFile.close();
        QMessageBox::critical(this, "Borrow Book", "Cannot open borrowed_books.txt.");
        return;
    }

    QTextStream in(&inFile);
    QTextStream out(&outFile);
    QTextStream log(&borrowLog);
    bool found = false;
    bool alreadyBorrowed = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.trimmed().isEmpty()) continue;
        QStringList parts = line.split(',', Qt::KeepEmptyParts);
        if (parts.size() < 5) continue;

        QString id     = parts.value(0).trimmed();
        QString title  = parts.value(1).trimmed();
        QString author = parts.value(2).trimmed();
        QString date   = parts.value(3).trimmed();
        QString status = parts.value(4).trimmed();

        if (id == borrowId) {
            found = true;
            if (status.toLower() == "borrowed") {
                alreadyBorrowed = true;
                out << line << '\n'; // keep original line
            } else {
                out << id << "," << title << "," << author << "," << date << "," << "borrowed" << '\n';
                log << id << "," << title << "," << author << "," << date << '\n';
            }
        } else {
            out << line << '\n';
        }
    }

    inFile.close();
    outFile.close();
    borrowLog.close();

    if (!found) {
        QFile::remove("Copy_file.txt");
        QMessageBox::information(this, "Borrow Book", "Book ID not found.");
        return;
    }

    if (alreadyBorrowed) {
        QFile::remove("Copy_file.txt");
        QMessageBox::information(this, "Borrow Book", "The book has already been borrowed.");
        return;
    }

    if (!QFile::remove("library_file.txt") || !QFile::rename("Copy_file.txt", "library_file.txt")) {
        QMessageBox::critical(this, "Borrow Book", "Failed to update library file after borrowing.");
        return;
    }

    QMessageBox::information(this, "Borrow Book", "Book has been successfully borrowed.");
}

//function for returning borrowed books
void MainWindow::onReturnBookClicked(){
    bool ok = false;
    const QString returnId = QInputDialog::getText(this, "Return Book",
                                                   "Enter the ID of the book to return:",
                                                   QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok || returnId.isEmpty()) return;

    QFile borrowedFile("borrowed_books.txt");
    QFile libraryFile("library_file.txt");
    QFile tempBorrowed("Copy_borrow.txt");
    QFile tempLibrary("Copy_library.txt");

    if (!borrowedFile.open(QIODevice::ReadOnly | QIODevice::Text) ||
        !libraryFile.open(QIODevice::ReadOnly | QIODevice::Text) ||
        !tempBorrowed.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate) ||
        !tempLibrary.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Return Book", "Failed to open one or more files.");
        return;
    }

    QTextStream inBorrowed(&borrowedFile);
    QTextStream inLibrary(&libraryFile);
    QTextStream outBorrowed(&tempBorrowed);
    QTextStream outLibrary(&tempLibrary);

    bool found = false;

    // Remove book from borrowed_books.txt
    while (!inBorrowed.atEnd()) {
        QString line = inBorrowed.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList parts = line.split(',', Qt::KeepEmptyParts);
        QString id = parts.value(0).trimmed();

        if (id != returnId) {
            outBorrowed << line << '\n';
        } else {
            found = true;
        }
    }

    // Update status in library_file.txt
    while (!inLibrary.atEnd()) {
        QString line = inLibrary.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList parts = line.split(',', Qt::KeepEmptyParts);
        if (parts.size() < 5) continue;

        QString id     = parts.value(0).trimmed();
        QString title  = parts.value(1).trimmed();
        QString author = parts.value(2).trimmed();
        QString date   = parts.value(3).trimmed();
        QString status = parts.value(4).trimmed();

        if (id == returnId) {
            outLibrary << id << "," << title << "," << author << "," << date << ",available" << '\n';
        } else {
            outLibrary << line << '\n';
        }
    }

    borrowedFile.close();
    libraryFile.close();
    tempBorrowed.close();
    tempLibrary.close();

    // Replace original files
    QFile::remove("borrowed_books.txt");
    QFile::rename("Copy_borrow.txt", "borrowed_books.txt");
    QFile::remove("library_file.txt");
    QFile::rename("Copy_library.txt", "library_file.txt");

    if (found) {
        QMessageBox::information(this, "Return Book", "Book successfully returned.");
    } else {
        QMessageBox::warning(this, "Return Book", "Book ID not found in borrowed list.");
    }
}


//function for checking borrowed book list
void MainWindow::onViewBorrowedClicked(){
    QFile file("borrowed_books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Borrowed Books", "borrowed_books.txt not found or cannot be opened.");
        return;
    }

    QTextStream in(&file);
    QString output;

    output += QString("%1 %2 %3 %4\n")
                  .arg("ID", -10)
                  .arg("Author", -20)
                  .arg("Date", -15)
                  .arg("Title", -30);
    output += QString(75, '-') + '\n';

    while (!in.atEnd()) {
        const QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        const QStringList parts = line.split(',', Qt::KeepEmptyParts); // expected id,title,author,date
        const QString id     = parts.value(0).trimmed();
        const QString title  = parts.value(1).trimmed();
        const QString author = parts.value(2).trimmed();
        const QString date   = parts.value(3).trimmed();

        output += QString("%1 %2 %3 %4\n")
                      .arg(id, -10)
                      .arg(author.left(20), -20)
                      .arg(date, -15)
                      .arg(title.left(30), -30);
    }
    file.close();

    QDialog dlg(this);
    dlg.setWindowTitle("Borrowed Books");
    QVBoxLayout *layout = new QVBoxLayout(&dlg);
    QTextEdit *text = new QTextEdit(&dlg);
    text->setReadOnly(true);
    text->setPlainText(output);
    layout->addWidget(text);
    QPushButton *closeBtn = new QPushButton("Close", &dlg);
    connect(closeBtn, &QPushButton::clicked, &dlg, &QDialog::accept);
    layout->addWidget(closeBtn);
    dlg.resize(800, 400);
    dlg.exec();
}

//function for searching for books
void MainWindow::onCheckBookClicked() {
    bool ok = false;
    QString usrSearch = QInputDialog::getText(this, "Search Book",
                                              "Enter title or author to search:",
                                              QLineEdit::Normal, QString(), &ok).trimmed();
    if (!ok || usrSearch.isEmpty()) {
        QMessageBox::warning(this, "Search Book", "Search term cannot be empty.");
        return;
    }

    usrSearch = usrSearch.toLower();
    QFile file("library_file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Search Book", "library_file.txt not found or cannot be opened.");
        return;
    }

    QTextStream in(&file);
    QString output;
    int resultCount = 0;

    output += QString("%1 %2 %3 %4 %5\n")
                  .arg("ID", -10)
                  .arg("Title", -30)
                  .arg("Author", -20)
                  .arg("Date", -10)
                  .arg("Status", -10);
    output += QString(90, '-') + '\n';

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList parts = line.split(',', Qt::KeepEmptyParts);
        if (parts.size() < 5) continue;

        QString id     = parts.value(0).trimmed();
        QString title  = parts.value(1).trimmed();
        QString author = parts.value(2).trimmed();
        QString date   = parts.value(3).trimmed();
        QString status = parts.value(4).trimmed();

        QString lcTitle = title.toLower();
        QString lcAuthor = author.toLower();

        if (lcTitle.contains(usrSearch) || lcAuthor.contains(usrSearch)) {
            output += QString("%1 %2 %3 %4 %5\n")
            .arg(id, -10)
                .arg(title.left(30), -30)
                .arg(author.left(20), -20)
                .arg(date, -10)
                .arg(status, -10);
            resultCount++;
        }
    }

    file.close();

    if (resultCount == 0) {
        output += "\nNo results found.";
    }

    QDialog dlg(this);
    dlg.setWindowTitle("Search Results");
    QVBoxLayout *layout = new QVBoxLayout(&dlg);
    QTextEdit *text = new QTextEdit(&dlg);
    text->setReadOnly(true);
    text->setPlainText(output);
    layout->addWidget(text);
    QPushButton *closeBtn = new QPushButton("Close", &dlg);
    connect(closeBtn, &QPushButton::clicked, &dlg, &QDialog::accept);
    layout->addWidget(closeBtn);
    dlg.resize(800, 400);
    dlg.exec();
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addBookButton, &QPushButton::clicked, this, &MainWindow::onAddBookClicked);
    connect(ui->bookListButton, &QPushButton::clicked, this, &MainWindow::onBookListButtonClicked);
    connect(ui->deleteBookButton, &QPushButton::clicked, this, &MainWindow::onDeleteBookClicked);
    connect(ui->borrowBookButton, &QPushButton::clicked, this, &MainWindow::onBorrowBookClicked);
    connect(ui->returnBookButton, &QPushButton::clicked, this, &MainWindow::onReturnBookClicked);
    connect(ui->viewBorrowedButton, &QPushButton::clicked, this, &MainWindow::onViewBorrowedClicked);
    connect(ui->checkBookButton, &QPushButton::clicked, this, &MainWindow::onCheckBookClicked);
}


MainWindow::~MainWindow()
{
    delete ui;
}
