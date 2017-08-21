#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

class internal_data
{
private:

	vector<int> v_data;

public:

	internal_data()
	{
		for (auto i = 0; i < 1000000; i++)
			v_data.push_back(i);
	}

	internal_data(const internal_data& _data)
	{
		v_data = _data.v_data;
	}

	void operator = (const internal_data& _data)
	{
		v_data = _data.v_data;
	}
};

class without_initializer_list
{
private:

	internal_data i_data;

public:

	without_initializer_list(internal_data& _i_data)
	{
		i_data = _i_data;
	}

};


class with_initializer_list
{
private:

	internal_data i_data;

public:

	with_initializer_list(internal_data& _i_data) : i_data(_i_data)
	{
		
	}

};


int main()
{
	cout << "Time taken to initialize without initializer list: ";
	auto started = std::chrono::high_resolution_clock::now();
	internal_data i_data_for_without_initializer_list;
	without_initializer_list wout_i(i_data_for_without_initializer_list);
	auto done = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << endl;

	cout << endl;

	cout << "Time taken to initialize with initializer list: ";
	started = std::chrono::high_resolution_clock::now();
	internal_data i_data_for_with_initializer_list;
	with_initializer_list with_i(i_data_for_with_initializer_list);
	done = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << endl;

	cout << endl;

	return 0;
}