#include <iostream>
#include "Food.h"

const char* RecommendMeAFood(char firstLetter)
{
	GetPizzaRecipe();
    if(firstLetter=='a' || firstLetter == 'A')
        return "apple";
    else if (firstLetter=='b' || firstLetter == 'B')
        return "banana";
    else if (firstLetter=='c' || firstLetter == 'c')
        return "chocolate cake";
    else return "pizza";
}


void GetPizzaRecipe()
{
    std::cout << "To make pizza you need...";
}
