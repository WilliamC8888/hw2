#include "clothing.h"
#include <sstream>
#include <iomanip>

using namespace std;


Clothing::Clothing(const string& name, double price, int qty, const string& size, const string& brand)
    : Product("clothing", name, price, qty), size_(size), brand_(brand) {}

// Creates set of words allowing movie to be searched for
set<string> Clothing::keywords() const {
    set<string> keywords = parseStringToWords(convToLower(name_)); 
    set<string> brandKeywords = parseStringToWords(convToLower(brand_));
    keywords.insert(brandKeywords.begin(), brandKeywords.end());
    return keywords;
}

// String displaying book info
string Clothing::displayString() const {
    stringstream ss;
    ss << name_ << "\n"
       << "Size: " << size_ << " Brand: " << brand_ << "\n"
       << price_ << " " << qty_ << " left.";
    return ss.str();
}

// Sends details to output
void Clothing::dump(std::ostream& os) const {
    Product::dump(os);
    os << size_ << "\n" << brand_ << endl;
}
