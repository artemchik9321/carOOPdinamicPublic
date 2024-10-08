// carOOPdinamicPublic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<Windows.h>
#include <cstring>
using namespace std;

class Car
{
    char* model;
    char* country;
    int yearOfCreation;
    int price;
public:
    Car() 
    {
        model = nullptr;
        country = nullptr;
        yearOfCreation = 0;
        price = 0;
    }
    Car(const char* Model, const char* Country, int YearOfCreation, double Price) 
    {
        model = new char[strlen(Model) + 1];
        country = new char[strlen(Country) + 1];
        strcpy_s(model, strlen(Model) + 1, Model);
        strcpy_s(country, strlen(Country) + 1, Country);
        yearOfCreation = YearOfCreation;
        price = Price;
    }
    ~Car() 
    {
        delete[] model;
        delete[] country;

        cout << "\ndestructor\n";
    }

    int GetYear() 
    {
        return yearOfCreation;
    }
    int GetPrice() 
    {
        return price;
    }

    void SetYear(int a) 
    {
        yearOfCreation = a;
    }
    void SetPrice(double a) 
    {
        price = a;
    }

    void Print() 
    {
        cout << "model:" << model << "\ncountry:" << country << "\nyear:" << yearOfCreation << "\nprice:" << price << "$";
    }
    void Input() 
    {
        char arr[100];
        cout << "\nenter model ";
        cin.getline(arr, 100);
        model = new char[strlen(arr) + 1];
        strcpy_s(model, strlen(arr) + 1, arr);
        cout << "enter country ";
        cin.getline(arr, 100);
        country = new char[strlen(arr) + 1];
        strcpy_s(country, strlen(arr) + 1, arr);
        cout << "enter creation year ";
        cin >> yearOfCreation;
        cout << "enter the price ";
        cin >> price;
    }
};
int main()
{
    Car a("R class", "china", 2012, 98450);
    a.Print();
    Car b;
    b.Input();
    b.Print();
}