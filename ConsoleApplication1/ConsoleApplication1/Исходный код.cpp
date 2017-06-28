#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct card
{
	string one;
	string two;
	card(const string& _one, const string& _two) :one(_one), two(_two) {}

};

void print_card(const vector<card>& vector_card)
{
	for each (auto var in vector_card)
	{
		cout << var.one << "-" << var.two << endl;
	}

	cout << endl;

}

//Оценка сложности: рекурсивно, сравнивая смежные города, проталкиваем карточку на вверх списка. Алгоритм довольно быстрый, но сложен для понимания.
void fast_sort(vector<card>& vector_card)
{

	for (int i = 0; i < vector_card.size() - 1; i++)
	{
		for (int j = i; j < vector_card.size(); j++)
		{
			if (vector_card.at(i).one == vector_card.at(j).two)
			{
				if (j > i)
				{
					swap(vector_card.at(j), vector_card.at(j - 1));
					fast_sort(vector_card);
				}
			}

		}

	}

}

int main()
{
	setlocale(LC_ALL, "Russian");

	//1
	vector<card> vector_card = { card("Мельбурн", "Кельн"), card("Москва", "Париж"), card("Кельн", "Москва") };

	fast_sort(vector_card);
	print_card(vector_card);


	//2
	vector<card> vector_card2 = { card("Москва", "Париж"), card("Москва", "Париж"), card("Кельн", "Москва") };

	fast_sort(vector_card2);
	print_card(vector_card2);

	//3
	vector<card> vector_card3 = { card("Берлин", "Осло"),               //4
		card("Магадан", "Якутск"),            //6
		card("Санкт-Петербург", "Берлин"),    //3
		card("Мельбурн", "Москва"),			//1
		card("Осло", "Магадан"),              //5
		card("Москва", "Санкт-Петербург") };  //2

	fast_sort(vector_card3);
	print_card(vector_card3);

	system("pause");
	return 0;

}