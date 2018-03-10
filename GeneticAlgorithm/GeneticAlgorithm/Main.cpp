#include "Genetic.hpp"
#include <iostream>
#include <iomanip>



int main() {

	using namespace std;

	/* Variables */

	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;

	Population population(POPULATION_SIZE, CITIES_IN_TOUR, SHUFFLES);
	vector<City> cities_to_visit;


	Init_Cities(&cities_to_visit);
	population.Populate(&cities_to_visit);

	best_distance = population.getBestDistance(FITNESS_SCALER);
	
	cout << "Shortest distance in initial population: " 
		<< fixed << setw(8) << setprecision(3) << best_distance << endl;



	return 0;
}