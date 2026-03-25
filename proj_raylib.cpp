#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <raylib.h>

using std::vector, std::string, std::fstream, std::istringstream;

void DrawTextCentered(const char *text, int y, int fontSize, Color color) {
    DrawText(text, GetScreenWidth() / 2 - MeasureText(text, fontSize) / 2, y, fontSize, color);  }

class Product {
public:
    int price;
    string brand;
    int quantity;
    Product() {}
    Product(int p, string b, int q) : price(p), brand(b), quantity(q) {}

    void Display(int offsetY) const {
        DrawText(brand.c_str(), GetScreenWidth() / 2 - MeasureText(brand.c_str(), 20) / 2, offsetY, 25, MAROON); }
    void DisplayWithQuantity(int offsetY) const {
        std::ostringstream oss;
        oss << brand << " - Quantity: " << quantity;
        DrawText(oss.str().c_str(), GetScreenWidth() / 2 - MeasureText(oss.str().c_str(), 20) / 2, offsetY, 25, MAROON); }
};

class Shampoo {
private:
    vector<Product> shampoo;
public:
    Shampoo() {}
    vector<Product> getShampoo() const {
        return shampoo; }
    void Brand(const string &brand, int price, int quantity) {
        if (brand == "Sunsilk" || brand == "Pantene" || brand == "PertPlus" || brand == "Head&Shoulders") {
            shampoo.push_back(Product(price, brand, quantity));   }  }
    void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((shampoo.size() + 1) * 30) / 2; 
        DrawTextCentered("Available Brands: ", 150, 30, MAROON);
        for (const auto &product : shampoo) {
            product.Display(offsetY);
            offsetY += 30;   } }
    void DisplayWithQuantities() const {
        int offsetY = 150;
        DrawTextCentered("Shampoo Quantities:", offsetY - 70, 50, MAROON);
        for (const auto &product : shampoo) {
            product.DisplayWithQuantity(offsetY);
            offsetY += 30;  }  }
};

class Detergents {
private:
    vector<Product> detergents;
public:
    Detergents() {}
    vector<Product> getDetergents() const {
        return detergents; }
    void Brand(const string &brand, int price, int quantity) {
        if (brand == "SurfExcel-(1kg)" || brand == "Brite-(1kg)" || brand == "Bounus-(1kg)" || brand == "Safeguard(White)" || brand == "Safeguard(Pink)" || brand == "Dettol(Menthol)" || brand == "Dettol(Protect)") {
            detergents.push_back(Product(price, brand, quantity)); }  }
    void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((detergents.size() + 1) * 30) / 2; 
        DrawTextCentered("Available Brands: ", 120, 30, MAROON);
        for (const auto &product : detergents) {
            product.Display(offsetY);
            offsetY += 30;   }  }
    void DisplayWithQuantities() const {
        int offsetY = 150;
        DrawTextCentered("Detergent Quantities:", offsetY - 70, 50, MAROON);
        for (const auto &product : detergents) {
            product.DisplayWithQuantity(offsetY);
            offsetY += 30;  } }
};

class Mobilephones {
private:
   vector<Product> mobilephones;
public:
  Mobilephones () {};
  vector<Product> getMobilephones() {
    return mobilephones;  }
  void Brand (const string &brand, int price, int quantity) {
    if ((brand == "Samsung(A-32)") || (brand == "Samsung(A-30)") || (brand == "Samsung(S-24)") || (brand == "Redmi(A-3)") || (brand == "Redmi(Note-12)") || (brand == "Redmi(12)") || (brand == "Oppo(A-77)") || (brand == "Oppo(A-17)") || (brand == "Oppo(A-18)")) {
      mobilephones.push_back(Product(price, brand, quantity)); } }
  void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((mobilephones.size() + 1) * 30) / 2; 
        DrawTextCentered("Available Brands: ", 100, 30, MAROON);
        for (const auto &product : mobilephones) {
            product.Display(offsetY);
            offsetY += 30; } }
  void DisplayWithQuantities() const {
        int offsetY = 150;
        DrawTextCentered("Mobilephone Quantities:", offsetY - 70, 50, MAROON);
        for (const auto &product : mobilephones) {
            product.DisplayWithQuantity(offsetY);
            offsetY += 30;  } }
};

class Laptops {
private:
  vector<Product> laptop;
public:
  Laptops () {} ;
  vector<Product> getLaptop() {
    return laptop;  }
  void Brand (string brand, int price, int quantity) {
    if ((brand == "HP(Victus-15)") || (brand == "HP(250)") || (brand == "HP(Spectre)") || (brand == "Lenovo(Thinkbook-14)") || (brand == "Lenovo(Thinkbook-17)") || (brand == "Lenovo(Thinkbook-16)")) {
      laptop.push_back(Product(price, brand, quantity)); } }
  void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((laptop.size() + 1) * 30) / 2; 
        DrawTextCentered("Available Brands: ", 100, 30, MAROON);
        for (const auto &product : laptop) {
            product.Display(offsetY);
            offsetY += 30;  } }
  void DisplayWithQuantities() const {
        int offsetY = 150;
        DrawTextCentered("Laptop Quantities:", offsetY - 70, 50, MAROON);
        for (const auto &product : laptop) {
            product.DisplayWithQuantity(offsetY);
            offsetY += 30;  } }
};

class Beverages {
private:
  vector<Product> beverages;
public:
  Beverages () {};
  vector<Product> getbeverages() {
    return beverages;  }
  void Brand (string brand, int price, int quantity) {
    if ((brand == "NestleFruitaVitals-(Chausa)") || (brand == "NestleFruitaVitals-(Guava)") || (brand == "NestleFruitaVitals-(Grape)") || (brand == "Pepsi-(50ml)") || (brand == "Sprite-(50ml)") || (brand == "CocalCola-(50ml)") || (brand == "RoohAfza-(100ml)") || (brand == "Olpers-(1lit)") || (brand == "MilkPak-(1lit)") || (brand == "Haleeb-(1lit)")) {
      beverages.push_back(Product(price, brand, quantity)); } }
  void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((beverages.size() + 1) * 30) / 2; 
        DrawTextCentered("Available Brands: ", 100, 30, MAROON);
        for (const auto &product : beverages) {
            product.Display(offsetY);
            offsetY += 30;  }  }
  void DisplayWithQuantities() const {
        int offsetY = 120;
        DrawTextCentered("Beverage Quantities:", offsetY - 70, 50, MAROON);
        for (const auto &product : beverages) {
            product.DisplayWithQuantity(offsetY);
            offsetY += 30;  } }
};

class Snacks  {
private:
  vector<Product> snacks;
public:
  Snacks () {};
  vector<Product> getSnacks() {
    return snacks;  }
 
  void Brand (string brand, int price, int quantity) {
    if ((brand == "CadburyDairymilk") || (brand == "FeraroRoacher") || (brand == "Lindit-(Dark)") ||(brand == "Lays-Masala") || (brand == "Lays-FrenchChese") || (brand == "Lays-Salted") || (brand == "PeakFreans-Gluco") || (brand == "PeakFreans-ChocolateChip") || (brand == "PeakFreans-PartyPik")) {
      snacks.push_back(Product(price, brand, quantity)); } }
  void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((snacks.size() + 1) * 30) / 2; 
        DrawTextCentered("Available Brands: ", 100, 30, MAROON);
        for (const auto &product : snacks) {
            product.Display(offsetY);
            offsetY += 30; } }
  void DisplayWithQuantities() const {
        int offsetY = 120;
        DrawTextCentered("Snacks Quantities:", offsetY - 70, 50, MAROON);
        for (const auto &product : snacks) {
            product.DisplayWithQuantity(offsetY);
            offsetY += 30;  } }
};

class Cart {
private:
    vector<Product> items;
public:
    void AddToCart(Product p) {
        items.push_back(p); }
    void DisplayCart() const {
        DrawTextCentered("Shopping Cart Contents:", 50, 20, MAROON);
        int offsetY = 70;
        for (const auto &item : items) {
            std::ostringstream oss;
            oss << item.brand << " - Price: Rs " << item.price << " - Quantity: " << item.quantity;
            DrawTextCentered(oss.str().c_str(), static_cast<int>(offsetY), 20, MAROON);
            offsetY += 30;  } }
    void TotalBill() const {
        int total = 0;
        float offsetY = 180;
        for (const auto &item : items) {
            total += item.price;  }
        std::ostringstream oss;
        oss << "Total Bill: Rs " << total;
        DrawTextCentered(oss.str().c_str(), static_cast<int>(offsetY + 250), 20, MAROON);  }
};

int main() {
  
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "JS Mart");
  SetTargetFPS(60);

  Shampoo shampoo;
  Detergents detergents;
  Mobilephones mobilephone;
  Laptops laptop;
  Beverages beverage;
  Snacks snack;

  std::ifstream file("items2.txt");
  if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return -1;  }

  std::string line;
  while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string brand;
        int price, quantity;
        if (iss >> brand >> price >> quantity) {
            shampoo.Brand(brand, price, quantity);
            detergents.Brand(brand, price, quantity);
            mobilephone.Brand(brand, price, quantity);
            laptop.Brand(brand, price, quantity);
            beverage.Brand(brand, price, quantity);
            snack.Brand(brand, price, quantity);   }  }
  file.close();

 bool display_shamp = false;
 bool display_deter = false;
 bool display_mobi = false;
 bool display_lapt = false;
 bool display_bevg = false;
 bool display_snack = false;
 bool showCheckout = false;
 bool adminLogin = false;
 bool userLogin = false;
 bool showPaymentOptions = false;
 bool showCardPaymentScreen = false;
 bool showRestockScreen = false;
 bool loginScreen = true;
 bool showLoginScreen = true;
 Cart cart;

 string inputBuffer;
 string restockBuffer;
 string username;
 string password;
 string paymentBuffer;

    while (!WindowShouldClose()) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125)) {
                if (showCardPaymentScreen) {
                    inputBuffer += (char)key;
                } else if (showRestockScreen) {
                    restockBuffer += (char)key;
                } else if (showRestockScreen) {
                    restockBuffer += (char)key;
                } else if (showPaymentOptions) {
                    paymentBuffer += (char)key;
                }else if (showLoginScreen) {
                    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
                        password += (char)key;
                    } else {
                        username += (char)key;  }  } }
                 key = GetCharPressed();  }

        BeginDrawing();
        ClearBackground(BLACK);

        if (!adminLogin && !userLogin) {
            DrawTextCentered("Select a login method", 50, 30, MAROON);
            DrawRectangle(GetScreenWidth() / 2 - 150, 150, 300, 40, BLUE);
            DrawTextCentered("1. Admin login", 160, 30, WHITE);
            DrawRectangle(GetScreenWidth() / 2 - 150, 200, 300, 40, BLUE);
            DrawTextCentered("2. User login", 210, 30, WHITE);
           
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 150, 300, 40})) {
                    adminLogin = true;
                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 200, 300, 40})) {
                    userLogin = true;   } }
        } else if (adminLogin) {
            static bool displayShampooQuantities = false;
            static bool displayDetergentQuantities = false;
            static bool displayMobilephoneQuantities = false;
            static bool displayLaptopQuantities = false;
            static bool displayBeverageQuantities = false;
            static bool displaySnackQuantities = false;

            if (!showRestockScreen && !displayShampooQuantities && !displayDetergentQuantities && !displayMobilephoneQuantities && !displayLaptopQuantities && !displayBeverageQuantities && !displaySnackQuantities) {
                DrawTextCentered("Admin Login - Item Quantities", 50, 30, MAROON);
                DrawRectangle(GetScreenWidth() / 2 - 150, 100, 300, 40, BLUE);
                DrawTextCentered("1. Shampoos", 110, 30, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 150, 150, 300, 40, BLUE);
                DrawTextCentered("2. Detergents", 160, 30, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 150, 200, 300, 40, BLUE);
                DrawTextCentered("3. Mobilephones", 210, 30, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 150, 250, 300, 40, BLUE);
                DrawTextCentered("4. Laptops", 260, 30, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 150, 300, 300, 40, BLUE);
                DrawTextCentered("5. Beverages", 310, 30, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 150, 350, 300, 40, BLUE);
                DrawTextCentered("6. Snacks", 360, 30, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 120, 500, 250, 40, BLUE);
                DrawTextCentered("Restock Items", 510, 20, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Return to Login", 560, 20, WHITE);
               
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 500, 250, 40})) {
                        showRestockScreen = true;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 100, 300, 40})) {
                         displayShampooQuantities = true;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 150, 300, 40})) {
                        displayDetergentQuantities = true;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 200, 300, 40})) {
                        displayMobilephoneQuantities = true;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 250, 300, 40})) {
                        displayLaptopQuantities = true;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 300, 300, 40})) {
                        displayBeverageQuantities = true;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 350, 300, 40})) {
                        displaySnackQuantities = true;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                        adminLogin = false;     } }
            } 
            else if (displayShampooQuantities) {
                shampoo.DisplayWithQuantities();
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Back", 560, 20, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                    displayShampooQuantities = false;    } }
            } 
            else if (displayDetergentQuantities) {
                detergents.DisplayWithQuantities();
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Back", 560, 20, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                        displayDetergentQuantities = false;     } }
            } 
            else if (displayMobilephoneQuantities) {
                mobilephone.DisplayWithQuantities();
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Back", 560, 20, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                        displayMobilephoneQuantities = false;     } }
            } 
            else if (displayLaptopQuantities) {
                laptop.DisplayWithQuantities();
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Back", 560, 20, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                        displayLaptopQuantities = false;        } }
            }
            else if (displayBeverageQuantities) {
                beverage.DisplayWithQuantities();
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Back", 560, 20, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                        displayBeverageQuantities = false;       } }
            }
           else if (displaySnackQuantities) {
                snack.DisplayWithQuantities();
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Back", 560, 20, WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                        displaySnackQuantities = false;      } }
            } 
            else {
                DrawTextCentered("Enter brand and quantity (e.g., Pantene 10)", 50, 20, MAROON);
                DrawTextCentered(restockBuffer.c_str(), 100, 30, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 120, 500, 250, 40, BLUE);
                DrawTextCentered("Submit", 510, 20, WHITE);
                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                DrawTextCentered("Return", 560, 20, WHITE);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 500, 250, 40})) {
                        std::istringstream iss(restockBuffer);
                        std::string brand;
                        int quantity;
                        if (iss >> brand >> quantity) {
                            bool updated = false;
                            for (auto &product : shampoo.getShampoo()) {
                                if (product.brand == brand) {
                                    product.quantity += quantity;
                                    updated = true;
                                    break;     } }
                            for (auto &product : detergents.getDetergents()) {
                                if (product.brand == brand) {
                                    product.quantity += quantity;
                                    updated = true;
                                    break;     } }
                            for (auto &product : mobilephone.getMobilephones()) {
                                if (product.brand == brand) {
                                    product.quantity += quantity;
                                    updated = true;
                                    break;      } }
                            for (auto &product : laptop.getLaptop()) {
                                if (product.brand == brand) {
                                    product.quantity += quantity;
                                    updated = true;
                                    break;     } }
                            for (auto &product : beverage.getbeverages()) {
                                if (product.brand == brand) {
                                    product.quantity += quantity;
                                    updated = true;
                                    break;    } }
                            for (auto &product : snack.getSnacks()) {
                                if (product.brand == brand) {
                                    product.quantity += quantity;
                                    updated = true;
                                    break;    } }
                            if (updated) {
                                std::ofstream file("items2.txt");
                                for (const auto &product : shampoo.getShampoo()) {
                                    file << product.brand << " " << product.price << " " << product.quantity << "\n";   }
                                for (const auto &product : detergents.getDetergents()) {
                                    file << product.brand << " " << product.price << " " << product.quantity << "\n";   }
                                for (const auto &product : mobilephone.getMobilephones()) {
                                    file << product.brand << " " << product.price << " " << product.quantity << "\n";   }
                                for (const auto &product : laptop.getLaptop()) {
                                    file << product.brand << " " << product.price << " " << product.quantity << "\n";   }
                                for (const auto &product : beverage.getbeverages()) {
                                    file << product.brand << " " << product.price << " " << product.quantity << "\n";   }
                                for (const auto &product : snack.getSnacks()) {
                                    file << product.brand << " " << product.price << " " << product.quantity << "\n";   }
                                file.close();   }  }
                        restockBuffer.clear();
                        showRestockScreen = false;
                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                        showRestockScreen = false;   } } }
                    } else if (userLogin && !showPaymentOptions && !showCardPaymentScreen) {
                        if (!display_shamp && !display_deter && !display_mobi && !display_lapt && !display_bevg && !display_snack && !showCheckout) {
                            DrawTextCentered("Welcome to JS Mart", 80, 50, BLUE);
                            DrawTextCentered("Available Categories:", 150, 35, MAROON);
                            DrawTextCentered("1. Shampoo", 200, 30, MAROON);
                            DrawTextCentered("2. Detergents", 230, 30, MAROON);
                            DrawTextCentered("3. Mobilephones", 260, 30, MAROON);
                            DrawTextCentered("4. Laptops", 290, 30, MAROON);
                            DrawTextCentered("5. Beverages", 320, 30, MAROON);
                            DrawTextCentered("6. Snacks", 350, 30, MAROON);
                            DrawTextCentered("7. Checkout", 380, 30, MAROON);

                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                Vector2 mousePos = GetMousePosition();
                                if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 200, 200, 30})) {
                                    display_shamp = true;
                                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 230, 200, 30})) {
                                    display_deter = true;
                                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 260, 200, 30})) {
                                display_mobi = true;
                                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 290, 200, 30})) {
                                display_lapt = true;
                                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 320, 200, 30})) {
                                display_bevg = true;
                                }  else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 350, 200, 30})) {
                                    display_snack = true;
                                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 380, 200, 30})) {
                                    showCheckout = true;     } }
                        } 
                        else if (display_shamp) {
                            shampoo.Display();
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                Vector2 mousePos = GetMousePosition();
                                int offsetY = GetScreenHeight() / 2 - ((shampoo.getShampoo().size() + 1) * 30) / 2;
                                for (const auto &product : shampoo.getShampoo()) {
                                    Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                                    if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                                        cart.AddToCart(product);  }
                                    offsetY += 30;   } }
                        } 
                        else if (display_deter) {
                            detergents.Display();
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                Vector2 mousePos = GetMousePosition();
                                int offsetY = GetScreenHeight() / 2 - ((detergents.getDetergents().size() + 1) * 30) / 2;
                                for (const auto &product : detergents.getDetergents()) {
                                    Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                                    if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                                        cart.AddToCart(product);   }
                                    offsetY += 30;     }  }
                        } 
                        else if (display_mobi) {
                            mobilephone.Display();
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                Vector2 mousePos = GetMousePosition();
                                int offsetY = GetScreenHeight() / 2 - ((mobilephone.getMobilephones().size() + 1) * 30) / 2;
                                for (const auto &product : mobilephone.getMobilephones()) {
                                    Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                                    if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                                        cart.AddToCart(product);  }
                                    offsetY += 30;   }  } 
                        } 
                        else if (display_lapt) {
                            laptop.Display();
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                            Vector2 mousePos = GetMousePosition();
                            int offsetY = GetScreenHeight() / 2 - ((laptop.getLaptop().size() + 1) * 30) / 2;
                            for (const auto &product : laptop.getLaptop()) {
                                Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                                if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                                    cart.AddToCart(product);  }
                                offsetY += 30; } }
                        }
                        else if (display_bevg) {
                            beverage.Display();
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                            Vector2 mousePos = GetMousePosition();
                            int offsetY = GetScreenHeight() / 2 - ((beverage.getbeverages().size() + 1) * 30) / 2;
                            for (const auto &product : beverage.getbeverages()) {
                                Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                                if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                                    cart.AddToCart(product);  }
                                offsetY += 30;   }  }
                        } 
                        else if (display_snack) {
                            snack.Display();
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                            Vector2 mousePos = GetMousePosition();
                            int offsetY = GetScreenHeight() / 2 - ((snack.getSnacks().size() + 1) * 30) / 2;
                            for (const auto &product : snack.getSnacks()) {
                                Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                                if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                                    cart.AddToCart(product);  }
                                offsetY += 30;   } }
                        } 
                        else if (showCheckout) {
                            static bool proceedToPayment = false;
                            if (!proceedToPayment) {
                                cart.DisplayCart();
                                cart.TotalBill();

                                DrawRectangle(GetScreenWidth() / 2 - 120, 500, 250, 40, BLUE);
                                DrawTextCentered("Proceed", 510, 20, WHITE);
                                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                                DrawTextCentered("Return to Categories", 560, 20, WHITE);

                                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                    Vector2 mousePos = GetMousePosition();
                                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 500, 250, 40})) {
                                        proceedToPayment = true;
                                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                                        display_shamp = false;
                                        display_deter = false;
                                        display_mobi  = false; 
                                        display_lapt = false; 
                                        display_bevg = false; 
                                        display_snack = false;
                                        showCheckout = false;    }  }
                            } else {
                                DrawTextCentered("Select a payment method", 50, 20, WHITE);
                                DrawRectangle(GetScreenWidth() / 2 - 150, 100, 300, 40, BLUE);
                                DrawTextCentered("1. Cash on delivery", 110, 30, WHITE);
                                DrawRectangle(GetScreenWidth() / 2 - 150, 150, 300, 40, BLUE);
                                DrawTextCentered("2. Card payment", 160, 30, WHITE);

                                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                   Vector2 mousePos = GetMousePosition();
                                   if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 100, 300, 40})) {
                                         DrawTextCentered("Thank you for your order!", 350, 30, GREEN);
                                    } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 150, 300, 40})) {
                                            showCardPaymentScreen = true;   }   }

                                DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                                DrawTextCentered("Return to Categories", 560, 20, WHITE);
                                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                                    Vector2 mousePos = GetMousePosition();
                                    if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                                        display_shamp = false;
                                        display_deter = false;
                                        display_mobi = false;
                                        display_lapt = false;
                                        display_bevg = false;
                                        display_snack = false; 
                                        showCheckout = false;
                                        proceedToPayment = false;    }  }  }
                        }
                        DrawRectangle(GetScreenWidth() / 2 - 120, 550, 250, 40, BLUE);
                        DrawTextCentered("Return to Categories", 560, 20, WHITE);
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                            Vector2 mousePos = GetMousePosition();
                            if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 120, 550, 250, 40})) {
                                display_shamp = false;
                                display_deter = false;
                                display_mobi = false;
                                display_lapt = false;
                                display_snack = false;
                                display_bevg = false; 
                                showCheckout = false;     }  }
                    } 
                    else if (showCardPaymentScreen) {
                        DrawTextCentered("Enter your card number:", 200, 30, MAROON);
                        DrawTextCentered(inputBuffer.c_str(), 300, 30, WHITE);
                        DrawRectangle(GetScreenWidth() / 2 - 150, 450, 300, 40, BLUE);
                        DrawTextCentered("Submit", 460, 30, WHITE);

                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                            Vector2 mousePos = GetMousePosition();
                            if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 150, 450, 300, 40})) {
                                DrawTextCentered("Thank you for your order!", 550, 30, GREEN);    } } }

        EndDrawing();
    }

    CloseWindow();

}