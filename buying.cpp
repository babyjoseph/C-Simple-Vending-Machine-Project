#include "buying.h"

namespace{
  double money = 0;
  int selection = 0;
  double price = 0, temp[100];
  int count = 0, qty = 0;
  std::string ans;
  enum buyme{
    Pause,
    Yes,
    No
  };
buyme myme = Pause;
}
extern std::vector<Product> myProduct;
void buyingMenu(){
  if(money == 0 || money < 0){
    std::cout << "Enter the Amount you have: ";
    std::cin >> money;
    std::cin.ignore();
  }
  myProduct.clear();
  readFile();
  displayProduct();
  std::cout << "\nYour Balance: " << money;
  std::cout << "\nEnter the number you want to buy: ";
  std::cin >> selection;
  std::cin.ignore();
  for(int i = 0; i < myProduct.size(); i++){
    if(i == (selection - 1)){
      price = myProduct[i].GetPrice();
      std::cout << "\nHow many " << myProduct[i].GetName() << " will you buy? ";
      std::cin >> qty;
      std::cin.ignore();
      price *= qty;
      break;
    }
  }
  if(money < price){
    std::cout << "\nYou don't have enough money" << std::endl;
    std::cout << "How much would you add? ";
    std::cin >> additional;
    std::cin.ignore();
    money+=additional;
  }
  else{
    money -= price;
  }
  std::cout << "Your remaining money: " << money << std::endl;
  price = 0;
  selection = 0;
}
void buyMenu(){
  while(true){
    switch(myme){
      case Pause:
        std::cout << "\nDo you want to buy? ";
        getline(std::cin, ans);
        if(ans == "y" ||ans == "Y"){
          myme = Yes;
        }
        else if (ans == "n" || ans == "N"){
          myme = No;
        }
        else {
          std::cout << "Unknown Input" << std::endl;
          myme = Pause;
        }
        break;
      case Yes:
        buyingMenu();
        myme = Pause;
        break;
      case No:
      myme = Pause;
        break;
    }
    if(myme == No){
      break;
    }
  }

}
