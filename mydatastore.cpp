#include "mydatastore.h"
#include <iostream>

using namespace std;

MyDataStore::MyDataStore(){
}

MyDataStore::~MyDataStore() {
    //Need to clear carts before deleting users to not segfault
    for (auto& cart : carts_) {
        cart.second.clear(); 
    }

    // Deletes producst
    for (set<Product*>::iterator x = prods_.begin(); x != prods_.end(); ++x) {
        delete *x;
    }

    // Deletes users
    for (map<string, User*>::iterator x = users_.begin(); x != users_.end(); ++x) {
        delete x->second;
    }
}

void MyDataStore::addProduct(Product* product){
    prods_.insert(product);
    set<string> keywords = product->keywords();
    for(set<string>::iterator x = keywords.begin(); x != keywords.end(); ++x){
        keywords_[*x].insert(product);
    }
}

void MyDataStore::addUser(User* user){
    users_[convToLower(user->getName())] = user;
}

// Searches given vector of search terms
vector<Product*> MyDataStore::search(vector<string>& terms,int type){
    vector<Product*> prodlist;
    if(terms.empty()){
        return prodlist;
    }
    set<Product*> intSet;
    bool found = false;

    for (size_t i = 0; i<terms.size(); i++){
        string j = convToLower(terms[i]);
        if(keywords_.find(j) != keywords_.end()){
            if(i == 0){
                intSet=keywords_[j];
            }
            else{
                if(type == 0){
                    intSet = setIntersection(intSet,keywords_[j]);
                }
                else{
                    intSet = setUnion(intSet,keywords_[j]);
                }
            }
            found = true;
        }
        else if(type == 0){
            return{}; 
        }
    }
    if (!found) {
        return {};
    }

    prodlist.assign(intSet.begin(),intSet.end());
    return prodlist;
}


void MyDataStore::viewCart(string username) {
    username = convToLower(username);
    if (users_.find(username) == users_.end()) {
        cout << "Invalid username" << endl;
        return;
    }

    if (carts_.find(username) == carts_.end() || carts_[username].empty()) {
        cout << "Cart is empty" << endl;
        return;
    }

    int index = 1;
    for (Product* p : carts_[username]) {
        cout << "Item " << index << ":\n" << p->displayString();
        if (index < carts_[username].size()) { 
            cout << "\n";
        }
        index++;
    }
}

void MyDataStore::addToCart(string username, Product* p){
    username = convToLower(username);
    if (users_.find(username) == users_.end()){
        cout << "Invalid user" << endl;
        return;
    }

    if (p == nullptr) {
        cout << "Invalid" << endl;
        return;
    }
    carts_[username].push_back(p);
}


void MyDataStore::buyCart(string username) {
    username = convToLower(username);
    if (users_.find(username) == users_.end()) {
        cout << "Invalid user" << endl;
        return;
    }
    User* user = users_[username];
    if (carts_.find(username) == carts_.end() || carts_[username].empty()) {
        cout << "Cart is empty" << endl;
        return;
    }

    deque<Product*>& cart = carts_[username];
    deque<Product*> cancelled; 

    while (!cart.empty()) {
        Product* p = cart.front();
        cart.pop_front();

        if (p->getQty() > 0 && user->getBalance() >= p->getPrice()) {
            p->subtractQty(1);
            user->deductAmount(p->getPrice());
        } else {
            cancelled.push_back(p); 
        }
    }

    cart.swap(cancelled);
}


// Puts all in output stream
void MyDataStore::dump(ostream& ofile){
    ofile<<"<products>"<<endl;
    for(set<Product*>::iterator x = prods_.begin(); x != prods_.end(); ++x){
        (*x)->dump(ofile);
    
    }
    ofile<<"</products>"<<endl;
    ofile<<"<users>"<<endl;

    for(map<string, User*>::iterator x = users_.begin(); x != users_.end(); ++x){
        x->second->dump(ofile);
    }
    ofile<<"</users>"<<endl;

}
