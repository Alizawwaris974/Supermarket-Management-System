#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <raylib.h>

using std::vector;
using std::string;
using std::fstream;
using std::istringstream;

// Function to draw text centered horizontally
void DrawTextCentered(const char *text, int y, int fontSize, Color color) {
    DrawText(text, GetScreenWidth() / 2 - MeasureText(text, fontSize) / 2, y, fontSize, color);
}

class Product {
public:
    int price;
    string brand;
    int quantity;

    Product() {}
    Product(int p, string b, int q) : price(p), brand(b), quantity(q) {}

    void Display(int offsetY) const {
        DrawText(brand.c_str(), GetScreenWidth() / 2 - MeasureText(brand.c_str(), 20) / 2, offsetY, 20, BLACK);
    }
};

class Shampoo {
private:
    vector<Product> shampoo;

public:
    Shampoo() {}

    vector<Product> getShampoo() const {
        return shampoo;
    }

    void Brand(const string &brand, int price, int quantity) {
        if (brand == "Sunsilk" || brand == "Pantene" || brand == "PertPlus" || brand == "Head&Shoulders") {
            shampoo.push_back(Product(price, brand, quantity));
        }
    }

    void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((shampoo.size() + 1) * 30) / 2; // Adjust starting offset based on number of items
        DrawTextCentered("Available Brands: ", 150, 20, BLACK);
        for (const auto &product : shampoo) {
            product.Display(offsetY);
            offsetY += 30; // Increase offset for the next item
        }
    }
};

class Detergents {
private:
    vector<Product> detergents;

public:
    Detergents() {}

    vector<Product> getDetergents() const {
        return detergents;
    }

    void Brand(const string &brand, int price, int quantity) {
        if (brand == "SurfExcel-(1kg)" || brand == "Brite-(1kg)" || brand == "Bounus-(1kg)" || brand == "Safeguard(White)" || brand == "Safeguard(Pink)" || brand == "Dettol(Menthol)" || brand == "Dettol(Protect)") {
            detergents.push_back(Product(price, brand, quantity));
        }
    }

    void Display() const {
        int offsetY = GetScreenHeight() / 2 - ((detergents.size() + 1) * 30) / 2; // Adjust starting offset based on number of items
        DrawTextCentered("Available Brands: ", 150, 20, BLACK);
        for (const auto &product : detergents) {
            product.Display(offsetY);
            offsetY += 30; // Increase offset for the next item
        }
    }
};

// Cart class definition
class Cart {
private:
    vector<Product> items;

public:
    void AddToCart(Product p) {
        items.push_back(p);
    }

    void DisplayCart() const {
        DrawTextCentered("Shopping Cart Contents:", 50, 20, BLACK);
        int offsetY = 70;
        for (const auto &item : items) {
            std::ostringstream oss;
            oss << item.brand << " - Price: Rs " << item.price << " - Quantity: " << item.quantity;
            DrawTextCentered(oss.str().c_str(), static_cast<int>(offsetY), 20, BLACK);
            offsetY += 30;
        }
    }

    void TotalBill() const {
        int total = 0;
        float offsetY = 180;
        for (const auto &item : items) {
            total += item.price;
        }
        std::ostringstream oss;
        oss << "Total Bill: Rs " << total;
        DrawTextCentered(oss.str().c_str(), static_cast<int>(offsetY + 250), 20, BLACK);
    }
};

int main() {
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "JS Mart");

    SetTargetFPS(60);

    // Load items from file and initialize objects
    Shampoo shampoo;
    Detergents detergents;

    std::ifstream file("items.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string brand;
        int price, quantity;
        if (iss >> brand >> price >> quantity) {
            shampoo.Brand(brand, price, quantity);
            detergents.Brand(brand, price, quantity);
        }
    }

    file.close();

    bool showShampoo = false;
    bool showDetergents = false;
    bool showCheckout = false;
    Cart cart;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!showShampoo && !showDetergents && !showCheckout) {
            // Draw welcome text
            DrawTextCentered("Welcome to JS Mart", 80, 50, BLUE);

            // Draw available categories
            DrawTextCentered("Available Categories:", 150, 35, BLACK);
            DrawTextCentered("1. Shampoo", 200, 30, BLACK);
            DrawTextCentered("2. Detergents", 230, 30, BLACK);
            DrawTextCentered("3. Checkout", 260, 30, BLACK);

            // Handle category selection
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 200, 200, 30})) {
                    showShampoo = true;
                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 230, 200, 30})) {
                    showDetergents = true;
                } else if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 260, 200, 30})) {
                    showCheckout = true;
                }
            }
        } else {
            if (showShampoo) {
                // Display shampoo brands
                shampoo.Display();
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    // Assuming offsetY starts at 180 for shampoo brands
                    int offsetY = GetScreenHeight() / 2 - ((shampoo.getShampoo().size() + 1) * 30) / 2;
                    for (const auto &product : shampoo.getShampoo()) {
                        Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                        if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                            cart.AddToCart(product);
                        }
                        offsetY += 30;
                    }
                }
            } else if (showDetergents) {
                // Display detergent brands
                detergents.Display();
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    // Assuming offsetY starts at 180 for detergent brands
                    int offsetY = GetScreenHeight() / 2 - ((detergents.getDetergents().size() + 1) * 30) / 2;
                    for (const auto &product : detergents.getDetergents()) {
                        Rectangle buttonBounds = {GetScreenWidth() / 2 - MeasureText(product.brand.c_str(), 20) / 2, offsetY, MeasureText(product.brand.c_str(), 20), 30};
                        if (CheckCollisionPointRec(mousePos, buttonBounds)) {
                            cart.AddToCart(product);
                        }
                        offsetY += 30;
                    }
                }
            } else if (showCheckout) {
                // Display cart and total bill
                cart.DisplayCart();
                cart.TotalBill();
            }

            // Handle return to categories button
            DrawRectangle(GetScreenWidth() / 2 - 120, 500, 250, 40, BLUE);
            DrawTextCentered("Return to Categories", 510, 20, WHITE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (CheckCollisionPointRec(mousePos, {static_cast<float>(GetScreenWidth()) / 2 - 100, 500, 200, 40})) {
                    showShampoo = false;
                    showDetergents = false;
                    showCheckout = false;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
