#ifndef TASKS_RK1_H
#define TASKS_RK1_H
#include <QList>
#include <tuple>
#include <list>
#include <map>
#include <string>
#include <iostream>


//task1
class WorkWithFile {
    private :
        char* dataOfFile;
        void readFromFile(const char* fileName);	//функция чтения из файла
        void prepareTestFile(const char* fileName);	//функция для создания тестового файла

    public :
		int randomRange(int low, int high);
        WorkWithFile();
        ~WorkWithFile();

        void writeStatInfoToFile(const char* outFile);
};
//task2
char* convertDecToBin(int number);
void writeToFile(const char* fileName, const char* strNum);
//task3
char* convertBinToHex(const char* binNum);
void writeToFileHexNum(const char* filename, const char* strNum);
//task4
void buildTree(int);
//task5
std::vector<std::pair<int/*номер строки*/, float /*среднее значение*/>> averStr2DArray(const float* ar, int colCount, int rowCount);
void randFill(float* ar, int N);
void writeToFileAverStr(const char* filename, std::vector<std::pair<int,float> averStr, int rowCount);
//task6
struct Node  {
	Node* next;
	Node* prev;
	int nameNode;
	static int countNodes;
};

class LinkedList {
	private :
		Node* Head;
		Node* Tail;
		int countNodes;
	public :
		LinkedList();
		~LinkedList();
		
		void push_back(int nameNode);
		void writeToFileFromTail();
		void writeToFileFromHead();			
//task7		
		void insert(int nameNode, int pos);
};

//task8
class StudentInfo {
	private :
		std::tuple<string /*фамилия*/,string /*имя*/,char* /*№ студ билета*/> info;
		std::map<string/*название предмета*/, std::pair<std::list<int> /*список оценок*/, float /*средняя оценка*/>> subjMark;
	public :
		/*	desription	:	добавления отметки по выбранному предмету
			input		:	subjName - название предмета, mark -- оценка
			output		:	0 - оценка добавлена, 1 - нет такого предмета
			author		:
			date		:	
		*/
		int addMark(const string& subjName, int mark);
		/*	desription	:	добавления отметки по выбранному предмету
			input		:	subjName - название предмета
			output		:	0 - предмет добавлен, 1 - такой предмет уже есть
			author		:
			date		:	

		*/
		int addSubj(const string& subjName);
		/*	desription	:	добавления нового предмета
			input		:	subjName - название предмета
			output		:	среднее значение оценки
			author		:
			date		:	
		*/
		float getAverMark(const string& subjName);
		/*	desription	:	вычисления средней оценки по предметам
			input		:	subjName - название предмета
			output		:	среднее значение оценки
			author		:
			date		:	
		*/
		void printInfoStudent();
		/*	desription	:	запись данных в файл формат файла
								[Фамилия] [имя] : [номер билета]
									[предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
									[предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
			input		:	subjName - название предмета
			output		:	среднее значение оценки
			author		:
			date		:	
		*/			
		void writeAllInfoToFile();
};


#endif // TASKS_RK1_H