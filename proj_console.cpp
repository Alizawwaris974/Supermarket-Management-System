#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using std::cout , std::cin , std::endl, std::vector, std::string, std::setw, std::fstream, std::istringstream;

class Product {
public:
   int price;
   string brand;
   int quantity;
public:
 Product () {};
 Product (int p , string b, int q) {
    price = p;
    brand = b;
    quantity = q;
 }

 virtual void Display() const{
    cout<< setw(15) << brand << setw(10) <<" -Price: Rs "<<  price << setw(10) << " -Quantity: " << quantity <<endl;
 }

};

class Shampoo : public Product {
private:
  vector<Product> shampoo;
public:
  Shampoo () {};
  Shampoo (int p,string b,int q) : Product(p,b,q) {};
 
  vector<Product> getshampoo() {
    return shampoo;  
  }

  void Brand(string brand, int price , int quantity) { // segregates items of file into shampoo category
    if ((brand == "Sunsilk") || (brand == "Pantene") || (brand == "PertPlus") || (brand == "Head&Shoulders")) {
      shampoo.push_back(Product(price,brand,quantity));
    }
  }

   void Display() const{   // prints out items stored in shampoo vector
    cout << "Available brands in Shampoo category: "<<endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:shampoo) {
      product.Display();
    }
  }
};

class Detergents : public Product {
private:
  vector<Product> detergents;
public:
  Detergents() {};
  Detergents (int p,string b, int q) : Product(p,b,q) {};
  
  vector<Product> getdetergents() {
    return detergents; 
  }

  void Brand (string brand, int price,int quantity) {
    if ((brand == "SurfExcel-(1kg)") || (brand == "Brite-(1kg)") || (brand == "Bounus-(1kg)") || (brand == "Safeguard(White)") || (brand == "Safeguard(Pink)") || (brand == "Dettol(Menthol)") || (brand == "Dettol(Protect)") ){
      detergents.push_back(Product(price, brand, quantity));
    }
  }

  void Display() const {
    cout << "Available brands in Soaps & Detergents category: "<<endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:detergents) {
      product.Display();
    }
  }
};

class Mobilephones : public Product {
private:
   vector<Product> mobilephones;
public:
  Mobilephones () {};
  Mobilephones (int p,string b,int q) : Product(p,b,q) {};

  vector<Product> getmobilephones() {
    return mobilephones;  
  }

  void Brand (string brand, int price, int quantity) {
    if ((brand == "Samsung(A-32)") || (brand == "Samsung(A-30)") || (brand == "Samsung(S-24)") || (brand == "Redmi(A-3)") || (brand == "Redmi(Note-12)") || (brand == "Redmi(12)") || (brand == "Oppo(A-77)") || (brand == "Oppo(A-17)") || (brand == "Oppo(A-18)")) {
      mobilephones.push_back(Product(price, brand, quantity));
    }
  }

  void Display() const{
    cout<< "Available brands in Mobilephone category:  "<< endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:mobilephones){
    product.Display();
    }
  }
};

class Laptops : public Product {
private:
  vector<Product> laptop;
public:
  Laptops () {} ;
  Laptops (int p,string b,int q) : Product(p,b,q) {};

  vector<Product> getlaptop() {
    return laptop;  
  }

  void Brand (string brand, int price, int quantity) {
    if ((brand == "HP(Victus-15)") || (brand == "HP(250)") || (brand == "HP(Spectre)") || (brand == "Lenovo(Thinkbook-14)") || (brand == "Lenovo(Thinkbook-17)") || (brand == "Lenovo(Thinkbook-16)")) {
      laptop.push_back(Product(price, brand, quantity));
    }
  }

  void Display() const{
    cout<< "Available brands in Laptop category:  "<< endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:laptop){
    product.Display();
    }
  }
};

class Beverages : public Product {
private:
  vector<Product> beverages;
public:
  Beverages () {};
  Beverages (int p,string b,int q) : Product(p,b,q) {};

  vector<Product> getbeverages() {
    return beverages; 
  }

  void Brand (string brand, int price, int quantity) {
    if ((brand == "NestleFruitaVitals-(Chausa)") || (brand == "NestleFruitaVitals-(Guava)") || (brand == "NestleFruitaVitals-(Grape)") || (brand == "Pepsi-(50ml)") || (brand == "Sprite-(50ml)") || (brand == "CocalCola-(50ml)") || (brand == "RoohAfza-(100ml)") || (brand == "Olpers-(1lit)") || (brand == "MilkPak-(1lit)") || (brand == "Haleeb-(1lit)")) {
      beverages.push_back(Product(price, brand, quantity));
    }
  }

  void Display() const{
    cout<< "Available brands in Beverages category:  "<< endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:beverages){
    product.Display();
    }
  }
};

class Chocolates : public Product {
private:
  vector<Product> chocolates;
public:
  Chocolates () {};
  Chocolates (int p,string b,int q) : Product(p,b,q) {};

  vector<Product> getchocolates() {
    return chocolates;  
  }
 
 void Brand (string brand, int price, int quantity) {
    if ((brand == "CadburyDairymilk") || (brand == "FeraroRoacher") || (brand == "Lindit-(Dark)") || (brand == "Lindit-(Milk)") || (brand == "Bounty") || (brand == "Kitkat")) {
      chocolates.push_back(Product(price, brand, quantity));
    }
  }

  void Display() const{
    cout<< "Available brands in Chocolate category:  "<< endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:chocolates){
    product.Display();
    }
  }
};

class Chips : public Product {
private:
  vector<Product> chips;
public:
  Chips() {};
  Chips (int p,string b, int q) : Product(p,b,q) {};

  vector<Product> getchips() {
    return chips; 
  }

  void Brand (string brand, int price, int quantity) {
    if ((brand == "Lays-Masala") || (brand == "Lays-FrenchChese") || (brand == "Lays-Salted") || (brand == "Lays-WavyTexasBarbeque") || (brand == "Slanty-Salted") || (brand == "Slanty-Vegetable") || (brand == "Slanty-Jalepeno") || (brand == "Cheetos-Poppers") || (brand == "Cheetos") || (brand == "Cheetos-Firy")) {
      chips.push_back(Product(price, brand, quantity));
    }
  }

  void Display() const{
    cout<< "Available brands in Chips category:  "<< endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:chips){
    product.Display();
    }
  }
};

class Biscuits : public Product {
private:
  vector<Product> biscuits;
public:
  Biscuits() {};
  Biscuits (int p,string b, int q) : Product(p,b,q) {};

  vector<Product> getbiscuits() {
    return biscuits;
  }

  void Brand (string brand, int price, int quantity) {
    if ((brand == "PeakFreans-Gluco") || (brand == "PeakFreans-ChocolateChip") || (brand == "PeakFreans-PartyPik") || (brand == "Bisconni-Cocomo") || (brand == "Bisconni-Novita") || (brand == "Bisconni-Saltish")) {
      biscuits.push_back(Product(price, brand, quantity));
    }
  }

  void Display() const{
    cout<< "Available brands in Biscuit category:  "<< endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for (const auto& product:biscuits){
    product.Display();
    }
  }
};

class Cart {
private:
  vector<Product> items;
public:
  void addtoacart(Product p) {
    items.push_back(p);
  }

  //void removefromcart(string p) {}

  void displaycart() {
    cout << " Shopping Cart contents" << endl;
    cout << setw(15) << setw(10) << setw(10) << endl;
    for(auto& i:items) {
        i.Display();
    }
     cout << endl;
  }

  int TotalBill() {
    int total = 0;
    for (const auto& i:items){
      total = total + i.price;
    }
    return total;
  }

};


int main () {
  fstream myFile;
  int choice;
  string readline;
  string brand;
  string input;
  int price ;
  int quantity;
  Cart customercart;
  Shampoo shampoocategory;
  Detergents detergentcategory;
  Mobilephones mobilephonecategory;
  Laptops laptopcategory;
  Beverages beveragecategory;
  Chips chipscategory;
  Biscuits biscuitcategory;
  
  while (true) {
  cout << "Available Categories : " << endl;
  cout << "1-Shampoo " << endl;
  cout << "2-Soaps & Detergents " << endl;
  cout << "3-Mobilephones " << endl;
  cout << "4-Laptops " << endl;
  cout << "5-Beverages " << endl;
  cout << "6-Chips " << endl;
  cout << "7-Biscuits " << endl;
 cout << "0-Checkout " <<endl;
  cout << "Enter a category number: " ;
  cin >> choice;

  if (choice == 0){
    break;     }

  myFile.open("items.txt", std::ios::in | std::ios::out);
   
  if (!myFile) {
    cout << "Error...." << endl;  }

  else {
  while (getline(myFile,readline)) {
    istringstream temp(readline);
    temp >> brand >> price >> quantity;

    if (choice == 1) {
      shampoocategory.Brand(brand,price,quantity);} 
    else if (choice == 2) {
      detergentcategory.Brand(brand,price,quantity);}  
    else if (choice == 3) {
      mobilephonecategory.Brand(brand,price,quantity);}  
    else if (choice == 4) {
      laptopcategory.Brand(brand,price,quantity);} 
    else if (choice == 5) {
      beveragecategory.Brand(brand,price,quantity);} 
    else if (choice == 6) {
      chipscategory.Brand(brand,price,quantity);}    
    else if (choice == 7) {
      biscuitcategory.Brand(brand,price,quantity);}  
 
 } }
  
  myFile.close();
 
 
  if (choice == 1) {
    shampoocategory.Display();
    cout << "Enter the brand you want to add to cart: "<< endl;
    cin >> input;
   
    while (input != "NO") {
    for (const auto product: shampoocategory.getshampoo()) {
      if (product.brand == input) {
      customercart.addtoacart(product);
      cout << "Item successfully added to cart " << endl;
      break;
    }
   }
   cout << "Enter brand if you want to add more items from this category: ('NO' to finish)" << endl;
    cin >> input;    
  }
 }
 
 else if (choice == 2) {
   detergentcategory.Display();
   cout << "Enter the brand you want to add to your cart (or 'NO' to finish): ";
   cin >> input;

    while (input != "NO") {
     for (const auto& product : detergentcategory.getdetergents()) {
      if (product.brand == input) {
        customercart.addtoacart(product);
        cout << "Item successfully added to cart " << endl;
         break;
       }
     }

    cout << "Enter brand if you want to add more items from this category: ('NO' to finish)" << endl;
    cin >> input;
    }
  }
  
  else if (choice == 3) {
    mobilephonecategory.Display(); 
    cout << "Enter the brand you want to add to cart: "<< endl;
    cin >> input;
  
    while (input != "NO") {
    for (const auto product: mobilephonecategory.getmobilephones()) {
      if (product.brand == input) {
      customercart.addtoacart(product);
      cout << "Item successfully added to cart " << endl;
      break;
    }
   }
    cout << "Enter brand if you want to add more items from this category: ('NO' to finish)" << endl;
    cin >> input;   
   }
  }
  
  else if (choice == 4) {
    laptopcategory.Display(); 
    cout << "Enter the brand you want to add to cart: "<< endl;
    cin >> input;

    while (input != "NO") {
    for (const auto product: laptopcategory.getlaptop()) {
      if (product.brand == input) {
      customercart.addtoacart(product);
      cout << "Item successfully added to cart " << endl;
      break;
    }
   }
   cout << "Enter brand if you want to add more items from this category: ('NO' to finish)" << endl;
   cin >> input;    
   }
  }
  
  else if (choice == 5) {
    beveragecategory.Display(); 
    cout << "Enter the brand you want to add to cart: "<< endl;
    cin >> input;

    while (input != "NO") {
    for (const auto product: beveragecategory.getbeverages()) {
      if (product.brand == input) {
      customercart.addtoacart(product);
      cout << "Item successfully added to cart " << endl;
      break;
    }
   }
    cout << "Enter brand if you want to add more items from this category: ('NO' to finish)" << endl;
    cin >> input;   
   }
  }
  else if (choice == 6) {
    chipscategory.Display(); 
     cout << "Enter the brand you want to add to cart: "<< endl;
    cin >> input;
   
    while (input != "NO") {
    for (const auto product: chipscategory.getchips()) {
      if (product.brand == input) {
      customercart.addtoacart(product);
      cout << "Item successfully added to cart " << endl;
      break;
    }
   }
    cout << "Enter brand if you want to add more items from this category: ('NO' to finish)" << endl;
    cin >> input;    
  }
  }
  else if (choice == 7) {
    biscuitcategory.Display(); 
    cout << "Enter the brand you want to add to cart: "<< endl;
    cin >> input;
    
    while (input != "NO") {
    for (const auto product: biscuitcategory.getbiscuits()) {
      if (product.brand == input) {
      customercart.addtoacart(product);
      cout << "Item successfully added to cart " << endl;
      break;
    }
   }
   cout << "Enter brand if you want to add more items from this category: ('NO' to finish)" << endl;
   cin >> input;    
  }
  }
  else if ((choice > 7) || (choice < 0)) {
    cout << "Invalid choice...";       }

  
  }

  customercart.displaycart();
  cout << "Total Bill: Rs" << customercart.TotalBill() << endl;

}

