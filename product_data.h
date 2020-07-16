#ifndef PRODUCT_DATA_H
#define PRODUCT_DATA_H

#include <string>
class Product{
  std::string _name;
  double _price;
  int _id;
public:
  std::string GetName();
  double GetPrice();
  int GetId();
  void SetName(std::string name);
  void SetPrice(double price);
  void SetId(int id);
};

#endif
