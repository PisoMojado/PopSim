using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PopulationSimulator
{
    class Program
    {
        const int ancestorCount = 20000;
        static void Main(string[] args)
        {
            Console.WriteLine("Starting simulation...");
            long generation = World.RunSimulation(ancestorCount);
            Console.WriteLine("Simulation finished. It took " + generation + " generations to identify a unifying common ancestor.");
            Console.ReadLine();
        }
    }
}
