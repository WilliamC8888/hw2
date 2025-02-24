#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"
#include "util.h"
#include <map>
#include <set>
#include <deque>

class MyDataStore : public DataStore {
public:
    MyDataStore();
    ~MyDataStore();
    
    //adds to prod to store
    void addProduct(Product* p) override;

    // adds user to store
    void addUser(User* u) override;

    // searches for products
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    
    
    void viewCart(std::string username);
    void addToCart(std::string username, Product* p);
    void buyCart(std::string username);
    void dump(std::ostream& ofile);

private:
    std::set<Product*> prods_; 
    std::map<std::string, User*> users_; 
    std::map<std::string,std::deque<Product*>> carts_; 
    std::map<std::string, std::set<Product*>> keywords_; 
   
    
};

#endif
