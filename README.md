# CarDealer

This is a small C++ application for an used car dealer. 

In this shop, anybody can come with a car to be sold, or to select a car to buy among what is currently available.
When a selling customer wants to sell a car, the shop owner will record the car model, the car first year registration, and the price. 
If the car is not sold in the first 30 seconds from the inclusion in the list, its price will decrease by 0.1% every 10 seconds, with a maximum depreciation of 20%.
When a buying customer comes to buy a car, the shop owner will display the list of available cars, and sell the preferred one at the current price to the customer. 
In this case, the car will be marked as sold, and will not appear anymore in the list of available cars.
At the end of the day, the shop owner may want to have an overview about the cars he/she sold so far, and what remains in stock.

The application is a simple console application with a main menu.
