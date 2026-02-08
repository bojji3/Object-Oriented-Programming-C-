// =================================================
// Filename : Visaya_PA2.cpp
// Author(s) : Kristina Visaya
// Email : kvisaya@gbox.adnu.edu.ph
// Exercise Number : 
// Assignment Number : 2
//Description : The program displays the meal and respective classes.
//Last modified: February 22, 2023
//=================================================

#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Meal {
  public:
    void AddDrink(string drink) {
      drinks.push_back(drink);
    }
    void PrintDrinks() {
      if (drinks.empty()) {
        cout << "Drinks: None" << endl;
      } else if (drinks.size() == 1) {
        cout << "Drinks: " << drinks[0] << endl;
      } else {
        cout << "Drinks: ";
        for (int i = 0; i < drinks.size() - 1; i++) {
          cout << drinks[i] << ", ";
        }
        cout << "and " << drinks.back() << endl;
      }
    }
    void AddAppetizer(string app) {
      appetizers.push_back(app);
    }
    void PrintAppetizers() {
      if (appetizers.empty()) {
        cout << "Appetizers: None" << endl;
      } else if (appetizers.size() == 1) {
        cout << "Appetizer: " << appetizers[0] << endl;
      } else {
        cout << "Appetizers: ";
        for (int i = 0; i < appetizers.size() - 1; i++) {
          cout << appetizers[i] << ", ";
        }
        cout << "and " << appetizers.back() << endl;
      }
    }
    void AddMainCourse(string mc) {
      main_courses.push_back(mc);
    }
    void PrintMainCourses() {
      if (main_courses.empty()) {
        cout << "Main Course: None" << endl;
      } else if (main_courses.size() == 1) {
        cout << "Main Course: " << main_courses[0] << endl;
      } else {
        cout << "Main Courses: ";
        for (int i = 0; i < main_courses.size() - 1; i++) {
          cout << main_courses[i] << " and ";
        }
        cout << main_courses.back() << endl;
      }
    }
    void AddDessert(string dessert) {
      desserts.push_back(dessert);
    }
    void PrintDesserts() {
      if (desserts.empty()) {
        cout << "Dessert(s): None" << endl;
      } else if (desserts.size() == 1) {
        cout << "Dessert(s): " << desserts[0] << endl;
      } else {
        cout << "Desserts: ";
        for (int i = 0; i < desserts.size() - 1; i++) {
          cout << desserts[i] << ", ";
        }
        cout << "and " << desserts.back() << endl;
      }
    }

  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};

//add class definitions above this line

int main() {
//add code below this line
  Meal dinner;
  dinner.AddDrink("Okinawa Tea");
  dinner.AddDrink("Red Wine");
  dinner.PrintDrinks();
  dinner.AddAppetizer("Deviled Eggs");
  dinner.AddAppetizer("Sweet Potato Bites");
  dinner.AddAppetizer("Teriyaki Pineapple Meatballs");
  dinner.AddAppetizer("Fried Prosciutto Tortellini");
  dinner.PrintAppetizers();
  dinner.AddMainCourse("Palak Paneer");
  dinner.AddMainCourse("Miso Braised Pork");
  dinner.AddMainCourse("Nasi Goreng");
  dinner.AddMainCourse("Easy Stuffed Zucchini");
  dinner.PrintMainCourses();
  dinner.AddDessert("Hot Cointreau Souffle");
  dinner.AddDessert("Anzac Biscuit Tarts");
  dinner.PrintDesserts();
  
  return 0;
//add code
}