#include <iostream>
#include <random>

using namespace std;

template <class T>
class ArrayP {
public:
	T* arr; // Хранилище коллекции
	int size; // Размерность хранилища

	ArrayP(int size) { // Конструктор
		this->size = size;
		arr = new T[size];
	}

	~ArrayP() { // Деструктор
		delete[] arr;
	}

	ArrayP& operator=(const ArrayP& other_instance) { // Перегрузка присваивания
		cout << "Перегрузка присваивания" << endl;

		for (int i = 0; i < size; i++) {
			arr[i] = other_instance.arr[i];
		}

		return *this;
	}

	T operator[](int num) { // Перегрузка обращения по индексу
		cout << "Перегрузка доступа по индексу" << endl;

		return arr[num];
	}

	ArrayP& operator*(const ArrayP& other_instance) { // Перегрузка умножения
		cout << "Перегрузка умножения массивов" << endl;

		for (int i = 0; i < size; i++) {
			arr[i] *= other_instance.arr[i];
		}

		return *this;
	}

	void show() { // Метод вывода
		for (int i = 0; i < size; i++) {
			cout << arr[i] << endl;
		}
	}

	void fill() { // Метод заполнения
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 10);

		for (int i = 0; i < size; i++) {
			arr[i] = dist(gen);
		}
	}
};

int counter = 0;

class UserClass {
public:
	int value; // Значение

	UserClass() { // Конструктор
		cout << "Конструктор пользовательского класса." << endl;

		value = counter;
		counter++;
	}

	void showVal() { // Метод отображения значения
		cout << value << endl;
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	cout << "Тестируем написанный шаблон" << endl;

	int i;
	cout << "Заполняем массив A" << endl << endl;

	ArrayP<int> A(10);
	A.fill();
	A.show();

	cout << endl << "Заполняем массив B" << endl << endl;

	ArrayP<int> B(10);
	B.fill();
	B.show();

	cout << endl << "Пробуем использовать перегрузку присваивания. В массив V кладём массив A" << endl << endl;

	ArrayP<int> V(10);
	V = A;
	V.show();

	cout << endl;

	cout << "Пробуем использовать перегрузку обращения по индексу отображаем первый элемент массива A" << endl << endl;

	cout << A[0] << endl << endl;

	cout << "Пробуем использовать перегрузку умножений массива A и B" << endl << endl;

	ArrayP<int> D(10);

	D = A * B;

	cout << "Отображаем содержимое массива после умножения" << endl << endl;

	D.show();


	cout << endl << "Тестируем шаблон класса с испольованием пользовательского класса" << endl;

	ArrayP<UserClass> C(5);

	cout << "Пробуем получить второй элемент и вызвать метод для отображения значения (должно быть 1)" << endl;

	C[1].showVal();
}
