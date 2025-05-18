#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book{
private:
    string title;
    string author;
    string isbn;    //ISBN: international standard book number
    float rating;
    int copies;

public:
    Book() = default;
    Book(const string& t, const string& a, const string& i, float r, int c)
    : title(t), author(a), isbn(i), rating(r),copies(c) {}


    //getters
    string getTitle() const { return title; };
    string getAuthor() const { return author; };
    string getIsbn() const { return isbn; };
    float getRating() const { return rating; }
    int getCopies() const { return copies; }

    //setters
    void setRating(float r) { rating = r; }
    void setCopies(int c) { copies = c; }

    //display
    void display() const {
        cout << "Title: " << title << ", Author: " << author
             << ", ISBN: " << isbn << ", Rating: " << rating
             << ", Copies: " << copies << endl;
    }
};