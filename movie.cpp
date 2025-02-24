#include "movie.h"
#include <sstream>
#include <iomanip>

using namespace std;

Movie::Movie(const string& name, double price, int qty, const string& genre, const string& rating)
    : Product("movie", name, price, qty), genre_(genre), rating_(rating) {}

// Creates set of words allowing movie to be searched for
set<string> Movie::keywords() const {
    set<string> keywords = parseStringToWords(convToLower(name_));
    set<string> genreKeywords = parseStringToWords(convToLower(genre_));
    keywords.insert(genreKeywords.begin(), genreKeywords.end());
    return keywords;
}

// String displaying movie info
string Movie::displayString() const {
    stringstream ss;
    ss << name_ << "\nGenre: " << genre_ << " Rating: " << rating_<< "\n" 
    << fixed << setprecision(2) << price_ << " " << qty_ << " left.";
    return ss.str();
}

// Sends details to output
void Movie::dump(std::ostream& os) const {
    Product::dump(os);
    os << genre_ << "\n" << rating_ << endl;
}
