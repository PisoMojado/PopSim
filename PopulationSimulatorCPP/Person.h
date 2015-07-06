#include <vector>

#pragma once
class Person
{
private:
	std::vector<long>* ancestors;
	double matingPropensity;
public:
	bool CanMate(void);
	Person* ProduceChild(Person* mate);
	virtual ~Person(void);
protected:
	Person(std::vector<long>* ancestors);
};

class Ancestor : public Person
{
public:
	Ancestor(void);
	virtual ~Ancestor(void);
};

