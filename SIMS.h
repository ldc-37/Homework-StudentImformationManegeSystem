/********************************************
* Copyright (c) 2017-2018 ���(221701331). All Rights Reserved.
* ������Ϣ��
*   �༶���������3��
*   ѧ�ţ�221701331
*   ���������
*   �绰��18806035755
*   �ʼ���ַ��791551236@qq.com
* �������ƣ�ѧ����Ϣ����ϵͳ���򻯰棩
* ����������Visual Studio 2017
* ���л�����Windows 10
* ����޸����ڣ�2018.5.10
* �������������Դ��ı���ʽ�������ļ������ݴ洢�ļ����ж�ȡ/д�룬�Ӷ�ʵ��ѧ����Ϣ�Ĺ������ӡ�ɾ�����޸ġ���ѯ�������ͳ���Լ����򣩡�
* ע�����1.��Ҫʹ��֧��C++11����߰汾�ı�����
            2.����ʱ�����ļ������������ļ�����ȱ��
            3.���ļ��ж�ȡѧ������δ�����飬������ȷ��������ȷ��
* �ο����ӣ�����Ʊ���/README
*********************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //get time
#include <conio.h> //_getch ()
#include <windows.h> //Sleep ()
#include <cctype>  //isupper ()
#include <iomanip> //format output

using namespace std;

#ifndef SIMS_H_

#define SCHOOL_FOUNDING_TIME 1958
int g_ThisYear;
const int dayOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const string genderCN[] = { "��","Ů" };
const int ID_Weight[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
const string prompt = "# ѧ�� ���� �Ա� ���� �������� ���� ����״�� ������ò ���֤�� ѧ����� ��ѧ���� ��ѧ��ʽ ѧԺ רҵ �꼶 ѧ�� ������� �༶ ����Ա";

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
    int nation; //����
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
        case 3:return to_string (enrollmentDate->year) + "." + to_string (enrollmentDate->month) + "." + to_string (enrollmentDate->day);
        case 4:return to_string (college);
        case 5:return to_string (major);
        case 6:return to_string (grade);
        case 7:return _class;
        case 8:return counsellor;
        case 9:return IDnumber;

        default:throw ("Not correct index!");
        }
    };
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

        default:throw ("Not correct index!");
        }
    }
};

vector<StuInfo *> StudentVec;

/*User interface*/
void ShowCopyright ();
void ShowTime ();
//main menu
void ShowUI ();
//sub-menu
void ShowAddUI ();
void ShowLookupUI ();
void ShowDelUI ();
void ShowStatisticsUI ();
void ShowModifyUI ();
void ShowModifyItemUI ();
void ShowSortUI ();

/*Input*/
void Add ();
//These two both return number of inputted stu
int Input ();
int FileInput (string filename);
void InputWithConfig (StuInfo * stu, int * attrval, string filename, string inputText, int defOpt = 0);
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

/*Show information*/
//show all
void Skim ();
//show single
void ShowStudentInfo (StuInfo * stu);

/*Search information*/
void Lookup ();
void LookupItem (size_t idx, string cmp);

/*Delete information*/
//delete selected stu
void Del ();
//delete all who have graduated over 10 years
void Clear ();

/*Modify information*/
void Modify ();
void ModifyItem (char n, StuInfo * stu);

/*Show number of students from different attributes*/
void Statistics ();
void GradeSummary ();
void CollegeSummary ();
void GenderSummary ();
void CountrySummary ();
void NationSummary ();

/*Sort information*/
void Sort ();
void Reverse ();

/*Assist*/
//clear buffer
void ClearBuff ();
//get specific attribute which relate to id from file 
string GetAttrName (string filename, int id, string configname);
string GetAttrName (string filename, int id);
//find stu using id or number,return subscript of struct which store this stu in vector
int FindSingleStu (char o, string cmp);
//save struct to file
void SaveToFile (string filename);

/*Judge*/
bool IsLegalDate (Date*);
bool IsInFile (string filename, string text);
bool StrIsNum (string);
bool IsLegalGender (StuInfo * stu);
bool IsLegalIDNumber (string n, string birthday, int sex);
bool IsLegalNumber (string num);
bool IsLegalName (StuInfo * stu);

/*Deal with error*/
void OpenFileFail (string filename);
void FindInfoFail (string filename);

#define SIMS_H_
#endif //SIMS_H_
