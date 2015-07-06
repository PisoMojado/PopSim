// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Person.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <random>

//static const long AncestorCount = 100000;
//static std::default_random_engine re();
//
//static std::vector<std::tuple<Person,Person>>* PartitionIntoPairs(std::vector<Person>& population)
//{
//	std::vector<std::tuple<Person,Person>>* pairs = new std::vector<std::tuple<Person,Person>>(population.size() / 2);	
//	std::uniform_int_distribution<int> matchingGenerator(0, population.size() - 1);
//	while(population.size() > 1)
//	{
//		int partner1Index = matchingGenerator(re);
//
//	}
//}
//
//static std::vector<Person>* BreedPopulation(std::vector<std::tuple<Person,Person>>& pairs)
//{
//	return NULL;
//}
//
//static void CreateInitialPopulation(int ancestorCount, std::vector<Person>& population)
//{
//    //we initialize the world with some Ancestors:
//    std::vector<Person> ancestors = std::vector<Person>(ancestorCount);
//    for (int i = 0; i < ancestorCount; ++i)
//    {
//        ancestors[i] = Ancestor();
//    }
//
//	std::vector<std::tuple<Person, Person>>* pairs = PartitionIntoPairs(ancestors);
//    population.clear(); //If we had any bachelors, they die alone
//
//    //BreedPopulation(pairs, population);
//
//    //We now have a population deriving from our original ancestors
//}
//
////Runs a world simulation to find the number of generations required to reach a point where everyone shares a common ancestor
//static long RunSimulation(int ancestorCount)
//{
//    long generationCounter = 0;
//    long foundCommonAncestor = -1;
//    //We build a list to contain all persons in the world during a generation, and another for the next:
//    //List<Person> population = CreateInitialPopulation(ancestorCount);
//	std::vector<Person> population;
//	CreateInitialPopulation(AncestorCount, population);
//    //while (foundCommonAncestor < 0)
//    //{
//    //    //We randomly partition the world into pairs:
//    //    var pairs = PartitionIntoPairs(population);
//    //    population.Clear(); //If we had any bachelors, they die alone
//
//    //    BreedPopulation(pairs, population);
//
//    //    foundCommonAncestor = FindCommonAncestor(population);
//
//    //    ++generationCounter;
//    //}
//    return generationCounter;
//}

int _tmain(int argc, _TCHAR* argv[])
{
	/*std::cout << "Starting simulation..." << std::endl;
	long generation = RunSimulation(AncestorCount);
	std::cout << "Simulation finished. It took " << generation << " generations to identify a unifying common ancestor" << std::endl;
	char* dummy = NULL;
	std::cin >> dummy;
	return 0;*/

	std::cout << "Hello world." << std::endl;
	char* dummy = NULL;
	std::cin.ignore();
	return 0;
}
