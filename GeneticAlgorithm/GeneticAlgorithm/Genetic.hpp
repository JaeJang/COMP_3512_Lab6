#pragma once

#include <ctime>
#include <cmath>
#include <random>
#include <vector>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"

using namespace std;


// Number of loops for the algorithm
constexpr static int ITERATIONS = 1000;


// if we cast an int with value 65 as a char, we get 'A'
constexpr static int ASCII_OFFSET = 65;

// Size of the map (X and Y)
constexpr static int MAP_BOUNDARY = 1000;

//int iterations = 0;
//int    index_of_shortest_tour = 0;

void Init_Cities(vector<City> * cities_to_visit);
void findEvolution(vector<Tour> & population);
vector<Tour> select_parents(vector<Tour> & population);
Tour crossover(vector<Tour> & parent);
