#include "Genetic.hpp"
#include <iostream>
#include <iomanip>



int main() {

	using namespace std;

	//Tour population[POPULATION_SIZE];
	//City cities_to_visit[CITIES_IN_TOUR];
	vector<Tour> population;
	vector<City> cities_to_visit;

	/* Variables */
	
	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;


	Init_Cities(cities_to_visit);
	Populate(population, cities_to_visit);

	
	best_distance = getBestDistance(population);
	
	cout << "Shortest distance in initial population: " 
		<< fixed << setw(8) << setprecision(3) << best_distance << endl;



	return 0;
}