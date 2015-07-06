using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PopulationSimulator
{
    class Person
    {
        private static readonly Random generator = new Random();

        public readonly IEnumerable<long> Ancestors;

        private double matingPropensity = generator.NextDouble() * .5d + .5d;

        protected Person(IEnumerable<long> ancestors)
        {
            //this.canMate = canMate;
            this.Ancestors = ancestors;
        }

        public bool CanMate()
        {
            bool canMate = generator.NextDouble() < matingPropensity;
            matingPropensity *= .66666d;
            return canMate;
        }

        public Person ProduceChild(Person mate)
        {
            if (this.CanMate() && mate.CanMate())
            {
                return new Person(this.Ancestors.Union(mate.Ancestors));
            }
            else
            {
                return null;
            }
        }
    }

    class Ancestor : Person
    {
        internal static long AncestorCount;

        public Ancestor()
            : base(new long[] { AncestorCount++ })
        {
        }
    }
}
