#include "readingFile.h"
extern std::vector<Product>myProduct;

void readFile(){
  std::ifstream infile;
  infile.open("products.txt");
  if(infile.is_open()){
    std::cout << "file is open!" << std::endl;
    while(infile.peek() != std::ifstream::traits_type::eof()){
      Product temp;
      std::string name;
      double price;
      int id;
      getline(infile, name);
      //std::cout << name;
      infile >> price;
      infile.ignore();
      //std::cout << price;
      infile>> id;
      infile.ignore();
      //std::cout << id;
      temp.SetName(name);
      temp.SetPrice(price);
      temp.SetId(id);
      myProduct.push_back(temp);
    }
  }
  else {
    std::cout << "unable to open file!" << std::endl;
  }
  infile.close();
}
