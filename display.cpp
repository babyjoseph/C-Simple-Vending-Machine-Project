#include "display.h"

namespace {
  enum menuState{
    Mainmenu,
    Admin,
    Customer,
    Exit
  };
  int index = 0;
}
extern std::vector<Product> myProduct;

void displayMenu(){
  bool exit = true;
  menuState myMain = Mainmenu;
  std::string ans;
  while(exit){
    system("clear");
    switch(myMain){
      case Mainmenu:
        std::cout << "[admin]" << std::endl;
        std::cout << "[customer]" << std::endl;
        std::cout << "[exit]" << std::endl;
        std::cout << "Input: ";
        getline(std::cin,ans);
        if(ans == "admin")
        {
          myMain = Admin;
        }
        else if (ans == "customer")
        {
          myMain = Customer;
        }
        else if (ans == "exit")
        {
          myMain = Exit;
        }
        else
        {
          std::cout << "Input ERROR!" << std::endl;
          myMain = Mainmenu;
        }
          break;
      case Admin:
        system("clear");
        MenuAdd();
        myMain = Mainmenu;
        break;
      case Customer:
        buyingMenu();
        buyMenu();
        myMain = Mainmenu;
        break;
      case Exit:
        exit = false;
        break;
      default:
      std::cout << "Input Error!" << std::endl;
      break;
    }
  }
}

void displayProduct(){
  for(auto i = myProduct.begin(); i != myProduct.end(); i++){
    std::cout << "=============== Product " << ++index << " ===============" << std::endl;
    std::cout << "Product Name: " << (*i).GetName() << std::endl;
    std::cout << "Product Price: " << (*i).GetPrice() << std::endl;
    std::cout << "Product Id: " << (*i).GetId() << std::endl;
  }
  index = 0;
}
