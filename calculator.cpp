#include <iostream>
using namespace std;

double add(double x , double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double multiply(double x , double y)
{
    return x * y;
}

double divide(double x, double y)
{
    return x / y;
}

int main()
{
    int choice;
    double num1, num2;

    cout << "select operation:"<<endl;
    cout << "1. Addition"<<endl;
    cout << "2. Subtraction"<<endl;
    cout << "3. Multiplication"<<endl;
    cout << "4. Division"<<endl;

    cout << "enter choice (1/2/3/4):";
    cin >> choice;

    if (choice >= 1 && choice <= 4)
    {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        switch (choice)
        {
            case 1:
                cout << "The result is: " << add (num1, num2) << endl;
                break;

            case 2:
                cout << "The result is: " << subtract (num1, num2) << endl;
                break;

            case 3:
                cout << "The result is: " << multiply (num1, num2) << endl;
                break;

            case 4:
                cout << "The result is: " << divide (num1, num2) << endl;
                break;

        }
        

    }

    else {
        cout<<"Invalid choice! please select a valid operation." << endl;

    }

    return 0;
}