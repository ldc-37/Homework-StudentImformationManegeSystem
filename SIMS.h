#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //use to get time
#include <conio.h> //getch ()
#include <windows.h> //Sleep ()
#include <cctype> 
//#include <sstream>

using namespace std;

#ifndef SIMS_H_
#define SIMS_H_

#define SCHOOL_FOUNDING_TIME 1958
int g_ThisYear;

const int dayOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const string genderCN[] = { "男","女" };
const int ID_Weight[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };

struct Date
{
    int year;
    int month;
    int day;
};

struct StuInfo
{
    string number;
    string name; 
    int gender; 
    int country;
    Date * birthday;
    int nation; //民族
    int marriage;
    int politics;
    string IDnumber;
    int type;
    Date * enrollmentDate;
    int enrollmentWay;
    int college;
    int major;
    int grade;
    string _class;
    int schoolingLength;
    int educationLevel;
    string counsellor;
};

vector<StuInfo *> StudentVec;


//显示版权信息
void ShowCopyright ();
//显示当前时间
void ShowTime ();
//主页面
void ShowUI ();

void Add ();
int Input ();
int FileInput (string filename);
void FileOutput (string filename, bool isClearFirst);
void InputWithConfig (StuInfo * stu, int * attrval, string filename, string inputText, string resultText, int defOpt = 0);
void InputNumber (StuInfo * stu);
void InputName (StuInfo * stu);
void InputGender (StuInfo * stu);
void InputBirthday (StuInfo * stu);
void InputIDNumber (StuInfo * stu);
void InputEnrollmentDate (StuInfo * stu);
void InputMajor (StuInfo * stu);
void InputGrade (StuInfo * stu);
void InputSchoolingLength (StuInfo * stu);
void InputClass (StuInfo * stu);
void InputCounsellor (StuInfo * stu);

string GetAttrName (string filename, int id, string configname);
string GetAttrName (string filename, int id);
void ShowStudentInfo (StuInfo * stu);

void Skim ();

void Lookup ();
void LookupNumber (string number);


void Del ();

void Modify ();

void Statistic ();

void Sort ();


//Assist
void ClearBuff ();

//Judge
bool IsLegalDate (Date*);
bool IsInFile (string, string);
bool StrIsNum (string);

bool IsLegalGender (StuInfo * stu);
bool IsLegalIDNumber (string n, string birthday, int sex);
bool IsLegalNumber (string num);
bool IsLegalName (StuInfo * stu);

//Error
void OpenFileFail (string filename);
void FindInfoFail (string filename);
#endif //SIMS_H_

