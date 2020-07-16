#include "savingFile.h"

extern std::vector<Product>myProduct;
void fileSaving(){
  std::ofstream products;
  products.open("products.txt",std::ios::app);
  if(products.is_open()){
    for(auto i = myProduct.begin(); i != myProduct.end();i++){
    products << (*i).GetName()<<std::endl;
    products << (*i).GetPrice()<<std::endl;
    products << (*i).GetId()<<std::endl;
    }
  }
  else {
    std::cout << "Unable to open file" << std::endl;
  }
  products.close();
}
//37208213
//943075
