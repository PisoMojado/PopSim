using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PopulationSimulator
{
    class World
    {
        private static Random generator = new Random();
        //Runs a world simulation to find the number of generations required to reach a point where everyone shares a common ancestor
        public static long RunSimulation(int ancestorCount)
        {
            long generationCounter = 0;
            long foundCommonAncestor = -1;
            //We build a list to contain all persons in the world during a generation, and another for the next:
            List<Person> population = CreateInitialPopulation(ancestorCount);
            while (foundCommonAncestor < 0)
            {
                //We randomly partition the world into pairs:
                var pairs = PartitionIntoPairs(population);
                population.Clear(); //If we had any bachelors, they die alone

                BreedPopulation(pairs, population);

                foundCommonAncestor = FindCommonAncestor(population);

                ++generationCounter;
            }
            return generationCounter;
        }

        private static long FindCommonAncestor(List<Person> population)
        {
            int populationCount = population.Count;
            var ancestors = ProduceAncestorIds(Ancestor.AncestorCount);
            return ancestors.AsParallel()
                            .Where(ancestor => population
                                .AsParallel()
                                .Where(person => person.Ancestors.Contains(ancestor))
                                .Count() == populationCount)
                            .DefaultIfEmpty(-1)
                            .First();
        }

        private static IEnumerable<long> ProduceAncestorIds(long ancestorCount)
        {
            for (long i = 0; i < ancestorCount; ++i)
            {
                yield return i;
            }
        }

        private static List<Person> CreateInitialPopulation(int ancestorCount)
        {
            //we initialize the world with some Ancestors:
            List<Person> population = new List<Person>(ancestorCount);
            for (int i = 0; i < ancestorCount; ++i)
            {
                population.Add(new Ancestor());
            }

            List<Tuple<Person, Person>> pairs = PartitionIntoPairs(population);
            population.Clear(); //If we had any bachelors, they die alone

            BreedPopulation(pairs, population);

            //We now have a population deriving from our original ancestors
            return population;
        }

        private static List<Tuple<Person, Person>> PartitionIntoPairs(List<Person> population)
        {
            List<Tuple<Person, Person>> pairs = new List<Tuple<Person, Person>>(population.Count / 2);
            while (population.Count > 1)
            {
                int partner1Index = generator.Next(population.Count);
                Person partner1 = population[partner1Index];
                population.RemoveAt(partner1Index);

                int partner2Index = generator.Next(population.Count);
                Person partner2 = population[partner2Index];
                population.RemoveAt(partner2Index);

                pairs.Add(Tuple.Create(partner1, partner2));
            }
            return pairs;
        }

        private static void BreedPopulation(List<Tuple<Person,Person>> pairs, List<Person> population)
        {
            //We populate the next generation one couple at a time, until they are infertile as a couple
            foreach (var pair in pairs)
            {
                Person child = pair.Item1.ProduceChild(pair.Item2);
                while (child != null)
                {
                    population.Add(child);
                    child = pair.Item1.ProduceChild(pair.Item2);
                }
            }
        }
    }
}
