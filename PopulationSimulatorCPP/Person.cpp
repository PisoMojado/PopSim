#include "stdafx.h"
#include "Person.h"
#include <random>

static std::uniform_real_distribution<double> propensityGenerator(.5,1);
static std::uniform_real_distribution<double> matingGenerator(0,1);
static std::default_random_engine re();

static std::vector<long>* UnionedAncestors(std::vector<long>& left, std::vector<long>& right)
{
	int initialCapacity = left.size() + right.size();
	std::vector<long>* unionedAncestors = new std::vector<long>();
	for(int index = 0; index < left.size(); ++index)
	{
		unionedAncestors->push_back(left[index]);
	}
	for(int i = 0; i < right.size(); ++i)
	{
		if(std::find(unionedAncestors->begin(), unionedAncestors->end(), right[i]) == unionedAncestors->end())
		{
			unionedAncestors->push_back(right[i]);
		}
	}

	return unionedAncestors;
}

Person::Person(std::vector<long>* ancestors)
	: ancestors(ancestors), matingPropensity(propensityGenerator(re))
{
}

bool Person::CanMate(void)
{
    bool canMate = matingGenerator(re) < matingPropensity;
    matingPropensity *= .66666;
    return canMate;
}

Person* Person::ProduceChild(Person* mate)
{
    if (this->CanMate() && mate->CanMate())
    {
        //return Person(this.Ancestors.Union(mate.Ancestors));
		return new Person(UnionedAncestors(*this->ancestors, *mate->ancestors));
    }
    else
    {
        return NULL;
    }
}

Person::~Person(void)
{
	free(ancestors);
}

//***********************************************
//This is where I've chosen to put Ancestor stuff
//***********************************************
static long AncestorCount(0);
static std::vector<long>* ProduceAncestors()
{
	std::vector<long>* ancestorArray = new std::vector<long>();
	std::vector<long>::iterator iterator = ancestorArray->begin();
	ancestorArray->insert(iterator, AncestorCount++);
	return ancestorArray;
}

Ancestor::Ancestor(void)
	:Person(ProduceAncestors())
{
}

Ancestor::~Ancestor(void)
{
}


