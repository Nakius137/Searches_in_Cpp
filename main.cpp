#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int ShowIntro();
int Menu();
void InputValue(int* );
void OutputFileAdd(int* );
void Swap(int& a, int& b);
void SelectionSort(int [], int);
void ShowOutcome(int [], int);
void ShowOutcomeInConsole(int[], int);
int BinarySearch(int[], int, int);

int num, choose;
int* board = nullptr;

int main()
{
	choose = Menu();

	while (!(choose == 1 || choose == 2 || choose == 3))
	{
		system("cls");
		cout << "Wpisz poprawna opcje" << endl;
		choose = Menu();
	}

	num = ShowIntro();
	board = new int[num];

	switch (choose)
	{
	case 1:
	{
		InputValue(board);
		SelectionSort(board, num);
		ShowOutcomeInConsole(board, num);
		break;
	}
	case 2:
	{
		InputValue(board);
		OutputFileAdd(board);
		SelectionSort(board, num);
		OutputFileAdd(board);

		ShowOutcome(board, num);
		break;
	}
	case 3:
	{
		int value, position;
		InputValue(board);
		SelectionSort(board, num);

		cout << "Wprowadz liczbe, jaka chcesz wyszukac z tablicy: ";
		cin >> value;

		position = BinarySearch(board, num, value);

		if (position == -1)
			cout << "Szukana liczba nie znaduje sie w tablicy";
		else
			cout << "Szukana liczba znajduje sie w indexie nr " << position;
		break;
	}

	delete[] board;
	board = nullptr;

	return 0;
	}
}

	int Menu()
	{
		cout << "Program ten wykonuje operacje na tablicach i plikach, wybierz operacje jaka chcesz dokonac" << endl;
		cout << "------------------------------------------------------------------------------------------" << endl;
		cout << "1.\t Sortowanie liczb bez zapisania w pliku i wyswietlenie ich w konsoli" << endl;
		cout << "2.\t Sortowanie liczb z zapiaem w pliku" << endl;
		cout << "3.\t Sortowanie liczb bez zapisu w pliku i wyszukanie liczby w niej" << endl;

		cout << "Wybieram opcje nr:";
		cin >> choose;

		system("cls");

		return choose;
}

int BinarySearch(int array[], int size, int value)
{
	int first = 0,
		last = size - 1,
		middle,
		position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (array[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
		
	}
    return position;
}

void ShowOutcomeInConsole(int board[], int num)
{
	for (int count = 0; count < num; count++) {
			cout << board[count] << endl;
	}
}


void ShowOutcome(int board[], int num)
{
	ifstream InputFile;
	InputFile.open("Output.txt");
	if (InputFile) 
	{
		cout << "Posegregowane wartosci z pliku to..." << endl;
		for (int count = 0; count < num; count++) {
			cout << board[count] << endl;
		}
	}
	else
		cout << "Plik nie zostal otwarty poprawnie";

}


void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

}

void SelectionSort(int array[], int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];

		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void OutputFileAdd(int* )
{
	ofstream OutputFile;
	OutputFile.open("Output.txt");

	for (int count = 0; count < num; count++)
	{
		OutputFile << board[count] << "\n";
	};

	OutputFile.close();
}

void InputValue(int* ) 
{
	for (int count = 0; count < num; count++) 
	{
		cout << "Wprowadz wartosc dla liczby nr " << (count + 1) << " ";
		cin >> board[count];
	}
}

int ShowIntro()
{
	cout << "Wprowadz ile chcesz wpisac liczb do programu: ";
	cin >> num;
	return num;
}


