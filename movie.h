#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "util.h"
#include <set>
#include <string>

//Movie class, child of Product class. 
class Movie : public Product {
public:
  Movie(const std::string& name, double price, int qty, 
        const std::string& genre, const std::string& rating);

  std::set<std::string> keywords() const override;
 
  std::string displayString() const override;

  void dump(std::ostream& os) const override;

//Movie specific data
private:
    std::string genre_;
    std::string rating_;
};

#endif
