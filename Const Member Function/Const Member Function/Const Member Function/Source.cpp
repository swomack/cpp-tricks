#include <iostream>
#include <string>

using namespace std;

class animal
{

private:

	string name;

public:

	animal(const string& _name) : name(_name)
	{

	}

	virtual ~animal()
	{

	}

	virtual void print_name() 
	{
		cout << name << endl;
	}

	virtual void change_name(const string& _name)
	{
		name = _name;
	}
};

 
class human : public animal
{
public:
	human(const string& _name) : animal(_name)
	{

	}

	virtual ~human()
	{

	}
};

void print_animal_name(const animal* p_anim)
{
	p_anim->print_name();
}

int main()
{
	human man("Mamun");

	print_animal_name(&man);

	return 0;
}