#include <iostream>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QtGlobal>
#include <stdio.h>
#include <QList>
#include <QFile>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <fstream>
#include "tasks_rk1.h"


//task1
void WorkWithFile::readFromFile(const char* fileName) {
    FILE *f1;
       f1= fopen(fileName,"r");
       fseek(f1, 0, SEEK_END);
       int begin = ftell(f1);
       fseek(f1, 0, SEEK_SET);
       this->dataOfFile=new char[begin];
       fread(this->dataOfFile, 1, begin, f1);
}
void WorkWithFile::prepareTestFile(const char* fileName){
    FILE* f1;
       f1= fopen(fileName, "w");
       for(int i =0; i<100;i++)
       {
           const char symbol = randomRange('a', 'z');
           fprintf(f1,"%c",symbol);
       }
       fclose(f1);
}
int WorkWithFile::randomRange(int low, int high) {
    return rand() % (high - low + 1) + low;
}

WorkWithFile::WorkWithFile() {}
WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}
		
void WorkWithFile::writeStatInfoToFile(const char* outFile) {
    FILE *f1;
        FILE *f2;
        f2=fopen("sourceFile_task1","r");
        f1= fopen(outFile,"w");
        fseek(f2, 0, SEEK_END);
        int begin = ftell(f2);
        fseek(f2, 0, SEEK_SET);
        char *needed = new char[begin];
        char *foroutput=new char[begin];
        int *number = new int[begin];
        int check=1;
        for (int i = 0; i < begin; i++) {

            int count = 0;
            for (int j = 0; j < begin; j++) {
                if (this->dataOfFile[i] == this->dataOfFile[j]) {
                    needed[i] = this->dataOfFile[i];
                    count++;

                }
            }
            number[i] = count;
            count = 0;
        }
        for (int i = 0; i < begin; i++) {
            for(int j=0;j<begin;j++) {
                if (needed[i] == foroutput[j]) {
                    check++;
                }
            }
            if(check<2){
                foroutput[i]=needed[i];
                fprintf(f1, "%c\t%d\n", needed[i], number[i]);
            }
            check=1;
        }
        fclose(f1);
        fclose(f2);
}

//task2
char *convertDecToBin(int number){
    char* binform=new char[32];
        for (int i = 0; i < 32; i++) {
            binform[i] = ((number & (1 << i)) >> i) + 0x30;
        }
        writeToFile("result_task2",binform);
        return binform;
}
void writeToFile(const char* filename,const char* strNum) {
    FILE *f1;
    f1 = fopen(filename, "w");

    for (int i = 31; i >= 0; i--) {

        fprintf(f1, "%c", strNum[i]);
    }
    fclose(f1);
}
//task3
char *convertBinToHex(const char *binNum){
    char* temp=new char[7];
       int* binTemp=new int[31];
       int count=0;
       for(int i=0;i<32;i++){
           binTemp[i]=0;
       }
       char* numTemp=new char[4];
       for(int i=0,i1=0;i<159;i=i+5,i1++) {

           for (int j = 0; j < 4; j++) {
               numTemp[j] = binNum[i + j];

           }
           if (numTemp[0]=='0' && numTemp[1]=='x' && numTemp[2]=='3' && numTemp[3]=='0') {

               binTemp[i1] = 0;
           }
           if (numTemp[0]=='0' && numTemp[1]=='x' && numTemp[2]=='3' && numTemp[3]=='1') {

               binTemp[i1] = 1;
           }
           if(numTemp[0]!='0'){
           }
       }

       for(int i=0;i<32;i=i+4){
           int binNum=8*binTemp[i+3]+4*binTemp[i+2]+2*binTemp[i+1]+1*binTemp[i];
           switch (binNum) {
               case 0:{
                   temp[count]='0';
               }break;
               case 1:{
                   temp[count]='1';
               }break;
               case 2:{
                   temp[count]='2';
               }break;
               case 3:{
                   temp[count]='3';
               }break;
               case 4:{
                   temp[count]='4';
               }break;
               case 5:{
                   temp[count]='5';
               }break;
               case 6:{
                   temp[count]='6';
               }break;
               case 7:{
                   temp[count]='7';
               }break;
               case 8:{
                   temp[count]='8';
               }break;
               case 9:{
                   temp[count]='9';
               }break;
               case 10:{
                   temp[count]='A';
               }break;
               case 11:{
                   temp[count]='B';
               }break;
               case 12:{
                   temp[count]='C';
               }break;
               case 13:{
                   temp[count]='D';
               }break;
               case 14:{
                   temp[count]='E';
               }break;
               case 15:{
                   temp[count]='F';
               }break;
           }
           count++;
       }
       writeToFileHexNum("result_task3",temp);
       return temp;
}
void writeToFileHexNum(const char* filename,const char* strNum) {
    FILE *f1;
    f1 = fopen(filename, "w");
    for(int i=7;i>=0;i--) {
        fprintf(f1, "%c", strNum[i]);
    }
    fclose(f1);
}
//task4
void buildTree(int height){
    for (int i = 0; i < height; i++)
        {
            for (int j = 1; j < height - i; j++)
            {
                printf(" ");
            }

            for (int j = height - 2 * i; j <= height; j++)
            {
                printf("^");
            }
            printf("\n");
        }
}
//task5
std::vector<std::pair<int, float> > averStr2DArray(const float *ar, int colCount, int rowCount)
{
    std::vector<std::pair<int,float>> avr;
        std::pair<int,float> pairForOut;
        for(int i=0;i<rowCount;i++){
            float  temp=0;
            for(int j=0;j<colCount;j++){
                temp+=ar[i*colCount+j]/(float)colCount;
            }
            pairForOut.first=i+1;
            pairForOut.second=temp;
            avr.push_back(pairForOut);
        }
        writeToFileAverStr("result_task5",avr,rowCount);
        return avr;
    return avr;
}
void randFill(float* ar, int N){
    void randFill(float* ar, int N){
        for (int i = 0; i < N; i++)
            ar[i] = rand() % 1000;
    }
}
void writeToFileAverStr(const char* fileName, std::vector<std::pair<int,float>> averStr, int rowCount){
    FILE *f1;
    f1 = fopen(fileName, "w");
    for(int i=0;i<rowCount;i++) {
        fprintf(f1, "%s%d\t%f\n","Строка ",averStr[i].first, averStr[i].second);
    }
    fclose(f1);

}
//task6

LinkedList::LinkedList() {
    Head= nullptr;
    Tail= nullptr;
}
LinkedList::~LinkedList() {
    while (Head)
        {
            Tail = Head->next;
            delete Head;
            Head = Tail;
        }
}
		
void LinkedList::push_back(int nameNode) {
    Node *temp = new Node(nameNode);
       temp->next= nullptr;
       if(Tail== nullptr){
           Head=Tail=temp;
           Head->prev= nullptr;
       }
       else{
       Tail->next=temp;
       temp->prev=Tail;

           Tail=temp;
       }
       LinkedList::countNodes++;

}
void LinkedList::writeToFileFromTail() {
    FILE *f1;
           f1 = fopen("result_task6Tail", "w");
           Node* tempTail = Tail;
           while (tempTail != nullptr)
           {
               fprintf(f1, "%s\n", tempTail->nameNode);
               tempTail = tempTail->prev;
           }
           fclose(f1);
           delete[] tempTail;
       }
}
void LinkedList::writeToFileFromHead() {
    FILE *f1;
            f1 = fopen("result_task6Head", "w");
            Node* tempHead = Head;
            while (tempHead != nullptr)
            {
                fprintf(f1, "%s\n", tempHead->nameNode);
                tempHead = tempHead->next;
            }
            fclose(f1);
            delete[] tempHead;
        }
}

//task7
void LinkedList::insert(int nameNode, int position) {
    if(position>LinkedList::countNodes+1 || position<1){
            return;
        }
        else {
            if(position==1){
                Node *temp = new Node(nameNode);
                Node *tempHead = Head;
                tempHead->prev=temp;
                temp->next=tempHead;
                temp->prev= nullptr;
                Head=temp;
            }
            else {
                if(position==LinkedList::countNodes+1){
                    Node *temp = new Node(nameNode);
                    Node *tempTail = Tail;
                    tempTail->next=temp;
                    temp->next= nullptr;
                    temp->prev=tempTail;
                    Tail=temp;
                }
                else {
                    Node *temp = new Node(nameNode);
                    Node *tempHead = Head;
                    for (int i = 1; i < position - 1; i++) {
                        tempHead = tempHead->next;
                    }
                    temp->next = tempHead->next;
                    tempHead->next->prev = temp;
                    tempHead->next = temp;
                    temp->prev = tempHead;
                    position++;
                }
            }
        }
        LinkedList::countNodes++;
}
//task8
/*	desription	:	добавления отметки по выбранному предмету
			input		:	subjName - название предмета, mark -- оценка
			output		:	0 - оценка добавлена, 1 - нет такого предмета
			author		:
			date		:	
		*/
int StudentInfo::addMark(const string& subjName, int mark){
    std::map<std::string, std::pair<std::list<int> , float >>::iterator it;
        for(it=subjMark.begin(); it!=subjMark.end();it++){
            if(subjName==it->first){
                it->second.first.push_back(mark);
                return 0;
            }
        }
        return 1;
}
/*	desription	:	добавления отметки по выбранному предмету
	input		:	subjName - название предмета
	output		:	0 - предмет добавлен, 1 - такой предмет уже есть
	author		:
	date		:	

*/
int StudentInfo::addSubj(const string& subjName){
    std::map<std::string, std::pair<std::list<int> , float >>::iterator it;
        for(it=subjMark.begin(); it!=subjMark.end();it++){
            if(subjName==it->first){
                return 1;
            }
        }
        std::pair<std::list<int>, float> secondOfMap;
        this->subjMark.emplace(subjName,secondOfMap);
        return 0;
}
/*	desription	:	добавления нового предмета
	input		:	subjName - название предмета
	output		:	среднее значение оценки
	author		:
	date		:	
*/
float StudentInfo::getAverMark(const string& subjName) {
    float averMark=0;
        std::map<std::string, std::pair<std::list<int> , float >>::iterator it;
        for(it=subjMark.begin(); it!=subjMark.end();it++){
            if(subjName==it->first) {
                std::list<int>::iterator iter;
                    for(iter=it->second.first.begin();iter!=it->second.first.end();iter++){
                        averMark=averMark+*iter;
                    }
                    averMark=averMark/(float)it->second.first.size();
                    it->second.second=averMark;
                return averMark;
            }
            }
        return 1;
}
/*	desription	:	вычисления средней оценки по предметам
	input		:	subjName - название предмета
	output		:	среднее значение оценки
	author		:
	date		:	
*/
void StudentInfo::printInfoStudent(){
    std::string surname=std::get<0>(info);
        std::string firstname=std::get<1>(info);
        char* recordBookNumber=std::get<2>(info);
        std::cout<<surname<<" "<<firstname<<" : "<<recordBookNumber<<"\n";
        std::map<std::string, std::pair<std::list<int> , float >>::iterator it;
        for(it=subjMark.begin();it!=subjMark.end();it++){
            std::cout<<it->first<<"\t:\t";
            std::list<int>::iterator iter;
            for(iter=it->second.first.begin();iter!=it->second.first.end();iter++){
                std::cout<<*iter<<" ";
            }
            std::cout<<" -- "<<getAverMark(it->first)<<"\n";
        }
}
/*	desription	:	запись данных в файл формат файла
						[Фамилия] [имя] : [номер билета]
							[предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
							[предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
	input		:	subjName - название предмета
	output		:	среднее значение оценки
	author		:
	date		:	
*/			
void StudentInfo::writeAllInfoToFile() {
    FILE *f1;
        f1= fopen("result_task8","w");
        std::string surname=std::get<0>(info);
        int lenth=surname.size();
        char* surName1=new char[lenth];
        for(int i=0;i<lenth;i++){
            surName1[i]=surname[i];
            fprintf(f1,"%c",surName1[i]);
        }
        fprintf(f1,"\t");
        std::string firstname=std::get<1>(info);
        lenth=firstname.size();
        char* firstName1=new char[lenth];
        for(int i=0;i<lenth;i++){
            firstName1[i]=firstname[i];
            fprintf(f1,"%c",firstName1[i]);
        }
        char* recordBookNumber=std::get<2>(info);
        fprintf(f1," : %s\n", recordBookNumber);
        std::map<std::string, std::pair<std::list<int> , float >>::iterator it;
        for(it=subjMark.begin();it!=subjMark.end();it++){
            fprintf(f1,"\t");
            std::string subName=it->first;
            int len=subName.size();
            char* subj=new char[len];
            for(int i=0;i<len;i++){
               subj[i]=subName[i];
                fprintf(f1,"%c", subj[i]);
            }
            fprintf(f1," : ");
            std::list<int>::iterator iter;
            for(iter=it->second.first.begin();iter!=it->second.first.end();iter++){
                fprintf(f1,"%d ",*iter);
            }
            fprintf(f1," -- %f\n",getAverMark(it->first));
        }
    }
    StudentInfo::StudentInfo(std::string surname, std::string firstname, char *recordBookNumber) {
        info=std::tie(surname,firstname,recordBookNumber);
}

