#pragma once

#include <ctime>
#include <cmath>
#include <random>
#include <vector>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"

using namespace std;


constexpr static int POPULATION_SIZE = 30;

constexpr static int CITIES_IN_TOUR = 20;

// A shuffle consists of swaps
constexpr static int SHUFFLES = 32;

// Number of loops for the algorithm
constexpr static int ITERATIONS = 1000;

// Scales the fitness to move the decimal place to a reasonable spot
constexpr static double FITNESS_SCALER = 10000.0;

// Number of members randomly selected from the population, from which the
// fittest is made a 'parent'
constexpr static int PARENT_POLL_SIZE = 5;

// Chance of being mutated
constexpr static double MUTATION_RATE = 0.15;

// Number of 'parents' for each cross
constexpr static int NUMBER_OF_PARENTS = 2;

// The number of 'fittest' that remain uncrossed and unmutated into the next gen
constexpr static int NUMBER_OF_ELITES = 1;

// if we cast an int with value 65 as a char, we get 'A'
constexpr static int ASCII_OFFSET = 65;

// Size of the map (X and Y)
constexpr static int MAP_BOUNDARY = 1000;

int iterations = 0;
int    index_of_shortest_tour = 0;

void Init_Cities(vector<City> & cities_to_visit);
void Populate(vector<Tour> & population, const vector<City> & cities_to_visit);
int determine_fitness(vector<Tour> & population);
double getBestDistance(vector<Tour> & population);
void findEvolution(vector<Tour> & population);
vector<Tour> select_parents(vector<Tour> & population);
Tour crossover(vector<Tour> & parent);
