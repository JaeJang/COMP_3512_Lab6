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
	int    i = 0, j = 0, iterations = 0;
	int    index_of_shortest_tour = 0;
	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;


	Init_Cities(cities_to_visit);
	Populate(population, cities_to_visit);

	index_of_shortest_tour = determine_fitness(population);
	best_distance = FITNESS_SCALER / population[index_of_shortest_tour].getFitness;
	
	cout << "Shortest distance in initial population: " 
		<< fixed << setw(8) << setprecision(3) << best_distance << endl;



	return 0;
}