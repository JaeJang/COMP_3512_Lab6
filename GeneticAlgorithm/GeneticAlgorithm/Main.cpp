#include "Genetic.hpp"
#include <iostream>
#include <iomanip>



int main() {

	using namespace std;

	double best_distance = 0.0;

	Population population;
	vector<City> cities_to_visit;


	Init_Cities(&cities_to_visit);
	population.Populate(&cities_to_visit);

	best_distance = population.getBestDistance();
	
	cout << "Shortest distance in initial population: " 
		<< fixed << setw(8) << setprecision(3) << best_distance << endl;

	for (int iterations = 0; iterations < ITERATIONS; ++iterations) {

		population.Selection();
		population.Crossover();
		population.Mutate();
		population.Evaluation(best_distance);
	}

	population.PrintResult();

	system("pause");


	return 0;
}