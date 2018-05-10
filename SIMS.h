#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //use to get time
#include <conio.h> //_getch ()
#include <windows.h> //Sleep ()
#include <cctype>  //idupper ()
#include <iomanip> // control output

using namespace std;

#ifndef SIMS_H_
#define SIMS_H_

#define SCHOOL_FOUNDING_TIME 1958
int g_ThisYear;

const int dayOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const string genderCN[] = { "男","女" };
const int ID_Weight[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
const string prompt = "# 学号 姓名 性别 国籍 出生日期 民族 婚姻状况 政治面貌 身份证号 学生类别 入学日期 入学方式 学院 专业 年级 学制 培养层次 班级 辅导员";

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
    time_t timestamp;

    const int GetiNumber ()
    {
        return stoi (number);
    }
    const int GetiBirthday ()
    {
        return birthday->year * 10000 + birthday->month * 100 + birthday->day;
    }
    const int GetiEnrollmentDate ()
    {
        return enrollmentDate->year * 10000 + enrollmentDate->month * 100 + enrollmentDate->day;
    }
    
    const string operator[] (size_t idx) const
    {
        switch (idx)
        {
        case 1:return number;
        case 2:return name;
        case 3:return to_string (birthday->year) + to_string (birthday->month) + to_string (birthday->day);
        case 4:return to_string (college);
        case 5:return to_string (major);
        case 6:return to_string (grade);
        case 7:return _class;
        case 8:return counsellor;
        }
    } //improve
    string operator[] (size_t idx)
    {
        switch (idx)
        {
        case 1:return number;
        case 2:return name;
        case 3:return to_string (enrollmentDate->year) + "." + to_string (enrollmentDate->month) + "." + to_string (enrollmentDate->day);
        case 4:return to_string (college);
        case 5:return to_string (major);
        case 6:return to_string (grade);
        case 7:return _class;
        case 8:return counsellor;
        case 9:return IDnumber;

        default:throw ("Not correct index!"); //debug
        }
    }

};

vector<StuInfo *> StudentVec;


//显示版权信息
void ShowCopyright ();
//显示当前时间
void ShowTime ();
//主页面
void ShowUI ();
void ShowAddUI ();
void ShowLookupUI ();
void ShowDelUI ();
void ShowStatisticsUI ();
void ShowModifyUI ();
void ShowModifyItemUI ();
void ShowSortUI ();

void Add ();
int Input ();
int FileInput (string filename);
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
int FindSingleStu (char o, string cmp);
void ShowStudentInfo (StuInfo * stu);

void Skim ();

void Lookup ();
void LookupItem (size_t idx, string cmp);


void Del ();

void Modify ();
void ModifyItem (char n, StuInfo * stu);

void Statistics ();
void GradeSummary ();
void CollegeSummary ();
void GenderSummary ();
void CountrySummary ();
void NationSummary ();

void Clear ();
void Sort ();
void Reverse ();


void SaveToFile (string filename);
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

