#include "Tour.hpp"
#include <random>
#include <ctime>
#include <cmath>
#include "City.hpp"


Tour::Tour(const Tour & rhs) {
	fitness = rhs.fitness;
	permutation = rhs.permutation;
}

void swap(Tour & lhs, Tour & rhs) {
	std::swap(lhs.fitness, rhs.fitness);
	std::swap(lhs.permutation, rhs.permutation);
}

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

double Tour::get_tour_distane(const int cities_in_tour)
{	
	double distance = 0.0;
	for (int i = 0; i < cities_in_tour; ++i) {
		distance += 
			get_distance_between_cities(permutation[i], permutation[(i + 1) % cities_in_tour]);

	}
	return distance;
}


