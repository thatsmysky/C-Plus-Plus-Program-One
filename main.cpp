/*
 Lucy Kull
 lkmq7@mail.umkc.edu
 CS 201R
 Program 1 -- Car_Dealership.cpp
 Due Jan 31
 Description: User inputs what kind of car they want, as well as their credit score.
	Program calculates the compound interest the user will pay on that car.
 Inputs: User's credit score, Car user wants
 Outputs: Price per month for 1-4 years (4 outputs)
 Error Handling: if user enters invalid credit score, warn and ask again.
	If user enters car not on menu, warn and ask again.
 Algorithm:
	1. display menu of cars
	2. loop through until user picks one
	3. ask for user credit score
	4. loop through until user enters integer between 0-1000
	5. Do math according to formula
 (pow((priceOfCar - downPayment) * (1 + rateOfInterest) , numberOfMonths)) / (12 * numberOfMonths)
	6. Display price of car per month for 1-4 years (4 outputs)
 */
#include <iostream>
#include <cmath>
using namespace std;

//prototype carCost function
int carCost (int mazdaCost = 15000, int smartCarCost = 12000, int priusCost = 25000, int jaguarCost = 50000, int priceOfCar = 0);
//sets cost of car for math

//prototype downPayment function
int downPayment (int extra = 0);
//sets downpayment for the math

//prototype function to get credit score
float askForCreditScore(float rateOfInterest = 0.0);
//asks for credit score, outputs interest rate

//prototype function to get number of months
int numberOfMonths();
//asks how many years they want to spend paying for car, outputs months

int main()
{
    // declare variables, named reasonably
    int monthsForMath;
    float firstMathPart, secondMathPart, finalMath;
    
    //find out how long they will be paying this off
    monthsForMath = numberOfMonths();
    //do the math in parts, makes it easier to edit
    firstMathPart = (carCost() - downPayment(0)) * pow((1 + askForCreditScore()), monthsForMath);
    secondMathPart = 12 * monthsForMath;
    finalMath = firstMathPart / secondMathPart;
    //Let them know the damage
    cout << "You will pay " << finalMath << " dollars every month for this car."<<endl;
    return 0;
}

int numberOfMonths ()
{
    //local variables
    char years;
    int soManyYears;
    //display menu
    cout << "How many years would you like to be paying off this car?\n" << "1\n" << "2\n" << "3\n" << "4\n"<< "--->\n"<<endl;
    cin >> years;
    switch (years)
    {
        case '1': //1 year to pay off
            soManyYears = 1;
            return soManyYears;
        case '2': //2 years
            soManyYears = 2;
            return soManyYears;
        case '3': //3 years
            soManyYears = 3;
            return soManyYears;
        case '4': //4 years
            soManyYears = 4;
            return soManyYears;
        default: //didn't pick one of those numbers
            cout << "4 it is" <<endl;
            soManyYears = 4;
            return soManyYears;
    }
    return 0;
}

int carCost (int mazdaCost, int smartCarCost, int priusCost, int jaguarCost, int priceOfCar)
{
    //local variable for input
    char car;

    do
    {
        // display car choice menu
        cout << "Which car would you like to buy?\n"<<"1. Mazda\n"<<"2. Smart Car\n"<<"3. Prius\n"<<"4. Jaguar\n"<<"----> ";
        // the user will (hopefully) enter a number 1-4
        cin >> car;
        //make sure they enter a valid value
        // deal with their entry on a case by case basis
        switch(car)
        {
            case '1': //chose a mazda
                priceOfCar = mazdaCost;
                cout << "\nThe Mazda costs $15,000" <<endl;
                return priceOfCar;
            case '2': //chose a smart car
                priceOfCar = smartCarCost;
                cout << "\nThe Smart Car costs $12,000" <<endl;
                return priceOfCar;
            case '3': //chose a prius
                priceOfCar = priusCost;
                cout << "\nThe Prius costs $25,000" <<endl;
                return priceOfCar;
            case '4': //chose a jaguar
                priceOfCar = jaguarCost;
                cout << "\nThe Jaguar costs $50,000" <<endl;
                return priceOfCar;
            default: //didn't choose 1-4
                cout << "\nPlease choose a number 1 through 4" <<endl;
                //this is so the loop will ask again
                priceOfCar = 0;
        }
    }while (priceOfCar <= 1);
    return priceOfCar;
}

int downPayment (int extra)
{
    //local variables for input and output
    char yesOrNo;
    int downPayedForCar;
    while (extra == 0)
    {
        //find out if they want a down payment
        cout << "Would you like to make a down payment? [Y/N] "<<endl;
        cin >> yesOrNo;
        if (yesOrNo == 'Y')
        {
            extra = 1;
        }
        else if (yesOrNo == 'N')
        {
            extra = 1;
        }
        else
        {
            cout << "Please answer 'Y' or 'N'. "<< endl;
            extra = 0;
        }
    }
    if (yesOrNo == 'Y')
    {
        //get down payment amount
        cout << "How much would you like your down payment to be?" <<endl;
        cin >> downPayedForCar;
        return downPayedForCar;
    }
    else if (yesOrNo == 'N')
    {
        return 0;
    }
    return 0;
}

float askForCreditScore (float rateOfInterest)
{
    //local variable
    double placeHolder;
    
    //get input for credit score
    cout << "What is your credit score?" <<endl;
    cin >> placeHolder;
    
    //super easy not even math
    if (placeHolder <= 500)
        rateOfInterest = 0.05;
    else if (placeHolder > 500 && placeHolder <= 700)
        rateOfInterest = 0.02;
    else
        rateOfInterest = 0.01;
    return rateOfInterest;
}


