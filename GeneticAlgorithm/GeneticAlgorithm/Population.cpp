#include "Population.hpp"

void Population::Populate(std::vector<City> & cities_to_visit)
{
	for (int i = 0; i < population_size; ++i) {

		tours.push_back(Tour());
		for (int j = 0; j < cities_in_tuour; ++j) {
			tours[i].getPermutation().push_back(&cities_to_visit[j]);
		}
		tours[i].shuffle_cities(shuffles, cities_in_tuour);
		tours[i].setFitness(0);
	}
}
