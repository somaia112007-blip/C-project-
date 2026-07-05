#include <iostream>
#include <string>
using namespace std; 

const int MAX_BOOKS = 100; 

// Arrays to store book data
string titles[MAX_BOOKS];
string authors[MAX_BOOKS];
bool isAvailable[MAX_BOOKS]; 

int bookCount = 0; 

// Function declarations
void addBook();
void searchBook();
void borrowBook();
void returnBook();
void displayBooks();
void showMenu(); 

int main() {
    int choice; 

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: displayBooks(); break;
            case 6: cout << "Exiting program... Goodbye!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        } 
    } while (choice != 6); 

    return 0;
} 

// Show menu
void showMenu() {
    cout << "\n===== Library Management System =====\n";
    cout << "1. Add new book\n";
    cout << "2. Search for a book\n";
    cout << "3. Borrow a book\n";
    cout << "4. Return a book\n";
    cout << "5. Display all books\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
} 

// Add book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!\n";
        return;
    } 

    cout << "Enter book title: ";
    getline(cin, titles[bookCount]); 

    cout << "Enter author name: ";
    getline(cin, authors[bookCount]); 

    isAvailable[bookCount] = true;
    bookCount++; 

    cout << "Book added successfully!\n";
} 

// Search book
void searchBook() {
    string key;
    cout << "Enter title to search: ";
    getline(cin, key); 

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (titles[i].find(key) != string::npos) {
            cout << "Book Found!\n";
            cout << "Title: " << titles[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Status: " << (isAvailable[i] ? "Available" : "Borrowed") << endl;
            found = true;
        }
    } 
    if (!found)
        cout << "Book not found!\n";
} 
// Borrow book
void borrowBook() {
    string name;
    cout << "Enter book title to borrow: ";
    getline(cin, name); 

    for (int i = 0; i < bookCount; i++) {
        if (titles[i] == name) {
            if (isAvailable[i]) {
                isAvailable[i] = false;
                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Book is already borrowed!\n";
            }
            return;
        }
    } 

    cout << "Book not found!\n";
} 

// Return book
void returnBook() {
    string name;
    cout << "Enter book title to return: ";
    getline(cin, name); 

    for (int i = 0; i < bookCount; i++) {
        if (titles[i] == name) {
            if (!isAvailable[i]) {
                isAvailable[i] = true;
                cout << "Book returned successfully!\n";
            } else {
                cout << "Book was not borrowed!\n";
            }
            return;
        }
    } 

    cout << "Book not found!\n";
} 

// Display all books
void displayBooks() {
    if (bookCount == 0) {
        cout << "No books in library.\n";
        return;
    } 

    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i + 1 << ". " << titles[i]
             << " | Author: " << authors[i]
             << " | Status: " << (isAvailable[i] ? "Available" : "Borrowed") << endl;
    }
}
