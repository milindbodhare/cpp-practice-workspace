#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include "book.hpp"

using namespace std;

class LibraryManager {
private:
    vector<Book> books;
    unordered_map<string, Book> isbnMap;
    map<string, vector<string>> authorBooks;
    set<string> bookTitles;
    multimap<string, string> authorToBooks;
    stack<string> recentBooks;
    queue<string> checkoutQueue;
    priority_queue<pair<float, string>> ratingHeap;
    list<string> recentlyViewedBooks;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        isbnMap[book.getIsbn()] = book;
        authorBooks[book.getAuthor()].push_back(book.getTitle());
        bookTitles.insert(book.getTitle());
        authorToBooks.insert({book.getAuthor(), book.getTitle()});
        recentBooks.push(book.getTitle());
        ratingHeap.push({book.getRating(), book.getTitle()});
        recentlyViewedBooks.push_back(book.getTitle());
    }

    void viewByAuthor(const string& author) {
        cout << "Books by " << author << ":\n";
        if (authorBooks.find(author) != authorBooks.end()) {
            for (const string& title : authorBooks[author])
                cout << "- " << title << endl;
        } else {
            cout << "No books found.\n";
        }
    }

    void searchByISBN(const string& isbn) {
        if (isbnMap.find(isbn) != isbnMap.end()) {
            const Book& b = isbnMap[isbn];
            b.display();
            recentlyViewedBooks.push_back(b.getTitle());
            if (recentlyViewedBooks.size() > 5)
                recentlyViewedBooks.pop_front();
        } else {
            cout << "Book not found.\n";
        }
    }

    void checkoutBook(const string& title) {
        if (bookTitles.find(title) != bookTitles.end()) {
            checkoutQueue.push(title);
            cout << title << " added to checkout queue.\n";
        } else {
            cout << "Book not available.\n";
        }
    }

    void processCheckout() {
        if (!checkoutQueue.empty()) {
            string title = checkoutQueue.front();
            checkoutQueue.pop();
            cout << "Checked out: " << title << endl;
        } else {
            cout << "No books in checkout queue.\n";
        }
    }

    void topRatedBooks(int k) {
        cout << "Top " << k << " rated books:\n";
        priority_queue<pair<float, string>> temp = ratingHeap;
        while (k-- && !temp.empty()) {
            auto top = temp.top(); temp.pop();
            cout << "- " << top.second << " (Rating: " << top.first << ")\n";
        }
    }

    void showRecentlyAdded() {
        cout << "Last added book: ";
        if (!recentBooks.empty()) {
            cout << recentBooks.top() << endl;
        } else {
            cout << "No books added yet.\n";
        }
    }

    void showRecentlyViewed() {
        cout << "Recently viewed books:\n";
        for (const auto& title : recentlyViewedBooks)
            cout << "- " << title << endl;
    }
};


int main() {
    LibraryManager lib;

    Book b1("The Alchemist", "Paulo Coelho", "ISBN001", 4.6, 3);
    Book b2("Clean Code", "Robert Martin", "ISBN002", 4.8, 2);
    Book b3("Atomic Habits", "James Clear", "ISBN003", 4.7, 5);

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.viewByAuthor("James Clear");
    lib.searchByISBN("ISBN002");
    lib.showRecentlyViewed();

    lib.checkoutBook("Clean Code");
    lib.processCheckout();

    lib.topRatedBooks(2);
    lib.showRecentlyAdded();

    return 0;
}
