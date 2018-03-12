#include "Genetic.hpp"

//Defines acutal cities to visit named 'A', 'B', and with random X and Y
//PRE	: a vector variable of city declared;
//POST	: all cities are set into the vector
void Init_Cities(vector<City> * cities_to_visit)
{
	for (int i = 0; i < Population::CITIES_IN_TOUR; ++i) {
		(*cities_to_visit).push_back(
			City((char)(i + ASCII_OFFSET),
				rand() % (MAP_BOUNDARY + 1),
				rand() % (MAP_BOUNDARY + 1)
			)
		);
	}

	srand(time(NULL));

}

