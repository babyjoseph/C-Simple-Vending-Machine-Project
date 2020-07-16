#include "product_data.h"

std::string Product::GetName(){return _name;}
double Product::GetPrice() {return _price;}
int Product::GetId() {return _id;}
void Product::SetName(std::string name){_name = name;}
void Product::SetPrice(double price){_price = price;}
void Product::SetId(int id) {_id = id;}
