#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <list>
#ifndef UNTITLED5_TASKS_RK1_H
#define UNTITLED5_TASKS_RK1_H

#endif //UNTITLED5_TASKS_RK1_H

class WorkWithFile{
private:
    char* dataOfFile;
    void readFromFile(const char* fileName);
    void prepareTestFile(const char* fileName);
public:
    void get();
    int randomRange(int low,int high);
    WorkWithFile();
    ~WorkWithFile();
    void  writeStatInfoToFile(const char* outFile);
};
char* convertDecToBin(int number);
void writeToFile(const char* fileName, const char* strNum);
void showBinNum(const char* strNum);
char* convertBinToHex(const char* binNum);
void showHexNum(const char* strNum);
void writeToFileHexNum(const char* filename,const char* strNum);
void buildTree(int height);
std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);
void randFill(float* ar, int N);
void writeToFileAverStr(const char* filename, std::vector<float> averStr, int rowCount);
struct Data{
    const char* str;
};
struct Node  {
    Node* next;
    Node* prev;
    //int nameNode;
    Data* d;
    static int countNodes;
    Node(const char* data){
        this->d=new Data;
        this->d->str=data;

    }
    ~Node(){
        delete d;
    }
};
class LinkedList {
private :
    Node* Head;
    Node* Tail;
    int countNodes=0;
public :
    LinkedList();
    ~LinkedList();
    int get_count();
    void showList();
    void insert(const char* str, int position);
    void push_back(const char* str);
    void writeToFileFromTail(const char* fileName);
    void writeToFileFromHead(const char* fileName);
};
class StudentInfo {
private :
    std::tuple<std::string ,std::string,char* > info;
    std::map<std::string, std::pair<std::list<int> , float >> subjMark;
public :
    StudentInfo(std::string surname, std::string firstname,char* recordBookNumber);
    int addMark(const std::string& subjName, int mark);
    int addSubj(const std::string& subjName);
    float getAverMark(const std::string& subjName);
    void printInfoStudent();
    void writeAllInfoToFile();
};