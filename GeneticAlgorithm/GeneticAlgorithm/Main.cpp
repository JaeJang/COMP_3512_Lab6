#include "Genetic.hpp"




int main() {

	using namespace std;

	Genetic genetic;

	//Tour population[POPULATION_SIZE];
	//City cities_to_visit[CITIES_IN_TOUR];
	vector<Tour> population;
	vector<City> cities_to_visit;

	/* Variables */
	int    index_of_shortest_tour = 0;
	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;



	genetic.Init_Cities(cities_to_visit);
	genetic.Populate(population);

	return 0;
}