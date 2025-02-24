#include "book.h"
#include <sstream>
#include <iomanip>

using namespace std;

Book::Book(const string& name, double price, int qty, const string& isbn, const string& author)
    : Product("book", name, price, qty), isbn_(isbn), author_(author) {}

// Creates set of words allowing movie to be searched for
set<string> Book::keywords() const {
    set<string> keywords = parseStringToWords(name_); 
    set<string> authorKeywords = parseStringToWords(author_); 
    keywords.insert(authorKeywords.begin(), authorKeywords.end()); 
    keywords.insert(isbn_); 
    return keywords;
}

// String displaying book info
string Book::displayString() const {
    stringstream ss;
    ss << name_ << "\nAuthor: " << author_ << " ISBN: " << isbn_
       << "\n" << fixed << setprecision(2) << price_ << " " << qty_ << " left.";
    return ss.str();
}
// Sends details to output
void Book::dump(std::ostream& os) const {
    Product::dump(os); 
    os << isbn_ << "\n" << author_ << endl;
}
