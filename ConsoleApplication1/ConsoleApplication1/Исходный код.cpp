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

//������ ���������: ����������, ��������� ������� ������, ������������ �������� �� ����� ������. �������� �������� �������, �� ������ ��� ���������.
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
	vector<card> vector_card = { card("��������", "�����"), card("������", "�����"), card("�����", "������") };

	fast_sort(vector_card);
	print_card(vector_card);


	//2
	vector<card> vector_card2 = { card("������", "�����"), card("������", "�����"), card("�����", "������") };

	fast_sort(vector_card2);
	print_card(vector_card2);

	//3
	vector<card> vector_card3 = { card("������", "����"),               //4
		card("�������", "������"),            //6
		card("�����-���������", "������"),    //3
		card("��������", "������"),			//1
		card("����", "�������"),              //5
		card("������", "�����-���������") };  //2

	fast_sort(vector_card3);
	print_card(vector_card3);

	system("pause");
	return 0;

}