#include <random>
#include <ctime>
#include <cmath>
#include <iostream>
#include "Tour.hpp"
#include "City.hpp"


//Copy constructor
Tour::Tour(const Tour & rhs) {
	fitness = rhs.fitness;
	permutation = rhs.permutation;
}

//Swap values of two objects
//PRE	: both are Tour instance
//POST	: swap each other
void swap(Tour & lhs, Tour & rhs) {
	std::swap(lhs.fitness, rhs.fitness);
	std::swap(lhs.permutation, rhs.permutation);
}

//Overloaded assignment operator
//PRE	: both sides are instance of Tour
//POST	: lhs is overrided with rhs
Tour & Tour::operator=(Tour rhs) {
	swap(*this, rhs);

	return *this;
}

void Tour::shuffle_cities(const int SHUFFLES, const int CITIES_IN_TOUR)
{
	srand(time(NULL));
	int index_one = 0, index_two = 0;
	for (int i = 0; i < SHUFFLES; ++i) {
		index_one = rand() % CITIES_IN_TOUR;
		index_two = rand() % CITIES_IN_TOUR;


		swap_cities(index_one, index_two);
	}
}

void Tour::swap_cities(int index_one, int index_two)
{	
	
	City *temp = permutation[index_one];
	permutation[index_one] = permutation[index_two];
	permutation[index_two] = temp;
}

double Tour::getFitness() {
	return fitness;
}

void Tour::setFitness(double value)
{
	fitness = value;
}

std::vector<City*> Tour::getPermutation()
{
	return permutation;
}

//Get the total distance between cities in permutation
//PRE	: NULL
//POST	: NULL
//RETURN: the total distance in double
double Tour::get_tour_distance(const int cities_in_tour)
{	
	double distance = 0.0;
	for (int i = 0; i < cities_in_tour; ++i) {
		distance += 
			permutation[i]->get_distance_between_cities(permutation[(i + 1) % cities_in_tour]);

	}
	return distance;
}


