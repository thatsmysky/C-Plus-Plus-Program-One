# C-Plus-Plus-Program-One
Car Dealership. Input: car type, credit score, down payment.  Output: monthly payment

 Program 1 -- Car_Dealership.cpp
 
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

	5. Do math according to formula (pow((priceOfCar - downPayment) * (1 + rateOfInterest) , numberOfMonths)) / (12 * numberOfMonths)

	6. Display price of car per month for 1-4 years (4 outputs)
