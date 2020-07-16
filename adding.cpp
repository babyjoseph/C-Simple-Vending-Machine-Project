#include "adding.h"
namespace{
  Product product;
}
std::vector<Product> myProduct;
Product AddProduct(){
  Product temp;
  std::string name;
  double price;
  int id;
      std::cout << "=============== Product ===============" << std::endl;
      std::cout << "Enter Product Name: ";
      getline(std::cin, name);
      std::cout << "Enter Product Price: ";
      std::cin >> price;
      std::cin.ignore();
      std::cout << "Enter Product Id: ";
      std::cin >> id;
      std::cin.ignore();
      temp.SetName(name);
      temp.SetPrice(price);
      temp.SetId(id);
      return temp;
}

void Adding(){
    product = AddProduct();
    myProduct.push_back(product);
}

enum Decision{
  Pause,
  Yes,
  No
};
Decision myDecision = Pause;

void MenuAdd(){
  std::string ans;
  bool babye = true;
  myProduct.clear();
  Adding();
  while(babye){
    switch(myDecision){
      case Pause:
        std::cout << "Enter another? ";
        getline(std::cin, ans);
        if(ans == "y" || ans == "Y"){
          myDecision = Yes;
        }
        else if (ans == "n" || ans == "N"){
          myDecision = No;
        }
        else{
          std::cout << "Input Error!" << std::endl;
          myDecision = Pause;
        }
        break;
      case Yes:
        Adding();
        myDecision = Pause;
        break;
      case No:
        //babye = false;
        myDecision = Pause;
        break;
    }
    if (myDecision == No){
      break;
    }
  }
  fileSaving();
}
