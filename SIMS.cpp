#include "SIMS.h"

int main()
{
    cout << (FileInput ("StudentDataMain.txt") != 0 ? "读取储存数据成功！" : "数据储存文件为空！") << "本程序启动时自动读取文件数据，按Q退出时自动保存至文件" << endl;
    while (1)
    {
	    ShowCopyright ();
	    ShowTime ();
        cout << "当前学生人数：" << StudentVec.size () << endl;
        ShowUI ();
        char o = toupper (_getche ());
        switch (o)
        {
        case 'A':Add (); break;
        case 'B':Skim (); break;
        case 'C':Lookup (); break;
        case 'D':Del (); break;
        case 'E':Modify (); break;
        case 'F':Statistics (); break;
        case 'G':Sort (); break;
        case 'Z':Clear (); break;
        case 'Q':SaveToFile ("StudentDataMain.txt"); exit (0);

        default:cout << endl << "输入错误，请重新输入" << endl; Sleep (500);
        }
        system ("cls");
    }

    return 0;
}

void ShowCopyright ()
{
    cout << "Copyright (c) 2017-2018 李定成(221701331). All Rights Reserved." << endl << endl;
}
void ShowTime ()
{
    time_t now = time (0);
    struct tm nowTime;
    localtime_s (&nowTime, &now);
    int hour = nowTime.tm_hour;
    int min = nowTime.tm_min;
    int sec = nowTime.tm_sec;
    int year = 1900 + nowTime.tm_year;
    int month = 1 + nowTime.tm_mon;
    int day = nowTime.tm_mday;
    int weekNum = nowTime.tm_wday;
    const char *weekChn[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
    const char *week = weekChn[weekNum];

    cout << "当前日期时间：" << year << '.' << month << '.' << day << '(' << week << ") ";
    cout << (hour < 10 ? "0" : "") << hour << ':' << (min < 10 ? "0" : "")
        << min << ':' << (sec < 10 ? "0" : "") << sec << endl;
    g_ThisYear = year;
}
void ShowUI ()
{
    cout << "*****************************************************" << endl <<
        "*    A : 输入学生信息                               *" << endl <<
        "*    B : 浏览所有信息                               *" << endl <<
        "*    C : 查询学生信息                               *" << endl <<
        "*    D : 删除学生信息                               *" << endl <<
        "*    E : 修改学生信息                               *" << endl <<
        "*    F : 学生信息统计                               *" << endl <<
        "*    G : 学生信息排序                               *" << endl <<
        "*    Z : 清空数据[!]                                *" << endl <<
        "*    Q : 退出系统[请不要直接关闭程序！]             *" << endl <<
        "*****************************************************" << endl <<
        "请输入选项前的字母 : ";
}
void ShowAddUI ()
{
    cout << "输入学生信息" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    1 : 手动输入               +" << endl <<
        "+    2 : 从文件输入[无校验]     +" << endl <<
        "+    Q : 返回主菜单             +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请选择：";
}
void ShowLookupUI ()
{
    cout << "查询学生信息" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    1 : 按学号查询             +" << endl <<
        "+    2 : 按姓名查询             +" << endl <<
        "+    3 : 按入学年月查询         +" << endl <<
        "+    4 : 按学院代号查询         +" << endl <<
        "+    5 : 按专业代号查询         +" << endl <<
        "+    6 : 按年级查询             +" << endl <<
        "+    7 : 按班级号查询           +" << endl <<
        "+    8 : 按辅导员查询           +" << endl <<
        "+    Q : 返回主菜单             +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请输入查询依据：";
}
void ShowDelUI ()
{
    cout << "删除学生信息" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    1 : 按学号删除             +" << endl <<
        "+    9 : 按身份证删除           +" << endl <<
        "+    Q : 返回主菜单             +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请输入删除依据：";
}
void ShowStatisticsUI ()
{
    cout << "学生信息统计" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    1 : 按年级统计             +" << endl <<
        "+    2 : 按学院统计             +" << endl <<
        "+    3 : 按性别统计             +" << endl <<
        "+    4 : 按国别统计             +" << endl <<
        "+    5 : 按民族统计             +" << endl <<
        "+    Q : 返回主菜单             +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请输入统计项目：";
}
void ShowModifyUI ()
{
    cout << "修改学生信息-选择学生" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    1 : 按学号选择             +" << endl <<
        "+    9 : 按身份证选择           +" << endl <<
        "+    Q : 返回主菜单             +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请输入选择依据：";
}
void ShowModifyItemUI ()
{
    cout << "修改学生信息-选择属性" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    1 : 修改姓名               +" << endl <<
        "+    2 : 修改性别               +" << endl <<
        "+    3 : 修改国籍               +" << endl <<
        "+    4 : 修改出生日期           +" << endl <<
        "+    5 : 修改民族               +" << endl <<
        "+    6 : 修改婚姻               +" << endl <<
        "+    7 : 修改政治面貌           +" << endl <<
        "+    8 : 修改身份证号           +" << endl <<
        "+    9 : 修改学生类别           +" << endl <<
        "+    a : 修改入学年月           +" << endl <<
        "+    b : 修改入学方式           +" << endl <<
        "+    c : 修改学院名称           +" << endl <<
        "+    d : 修改专业名称           +" << endl <<
        "+    e : 修改年级               +" << endl <<
        "+    f : 修改学制               +" << endl <<
        "+    g : 修改培养层次           +" << endl <<
        "+    h : 修改班级               +" << endl <<
        "+    i : 修改辅导员             +" << endl <<
        "+    Q : 上一级主菜单           +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请输入：";
}
void ShowSortUI ()
{
    cout << "学生信息排序" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl <<
        "+    1 : 按学号排序             +" << endl <<
        "+    2 : 按年龄排序             +" << endl <<
        "+    3 : 按入学时间排序         +" << endl <<
        "+    4 : 按录入时间排序         +" << endl <<
        "+    9 : 排序顺序反向           +" << endl <<
        "+    Q : 返回主菜单             +" << endl <<
        "+-+-+-+-+-+-+-+-+-++-+--+-+-+-+-+" << endl <<
        "请输入排序依据：";
}

void Add ()
{
    char o;
    int finish = 0;
    do
    {
        system ("cls");
        ShowAddUI ();
        o = _getch ();
        switch (o)
        {
        case '1':
            finish = Input ();
            break;
        case '2':
            finish = FileInput ("StudentDataNew.txt");
            cout << "是否清空已读入的文件？按D清空，按其他键保留..." << endl;
            o = toupper (_getch ());
            if (o == 'D') {
                ofstream file ("StudentDataNew.txt", ios::trunc);
                file << prompt << endl;
                file.close ();
                cout << "已清空！" << endl;
            }
            else {
                cout << "文件被保留" << endl;
            }
            Sleep (1000);
            break;
        case 'q':
        case 'Q':return;

        default:cout << endl << "输入错误，请重新输入" << endl; Sleep (500); break;
        }
    } while (!finish);
    cout << endl << "已新增" << finish << "条记录！" << endl;
    system ("pause");
}
int FileInput (string filename)
{
    system ("cls");
    ifstream file (filename, ios::in);
    if (file.fail ()) {
        OpenFileFail (filename);
    }
    int addNum = 0;
    char tmp;
    string strtmp;
    while (!file.eof ()) {
        StuInfo * stu = new StuInfo;
        stu->birthday = new Date;
        stu->enrollmentDate = new Date;
        file >> tmp;
        if (file.fail ()) {
            continue;
        }
        if (tmp == '#') {
            getline (file, strtmp);
            continue;
        }
        else {
            file.seekg (-1, ios::cur); //回退文件位置指针
        }
        file >> stu->number >> stu->name >> stu->gender >> stu->country >> stu->birthday->year >> tmp >> stu->birthday->month >> tmp >> stu->birthday->day >> stu->nation >> stu->marriage >> stu->politics >> stu->IDnumber >> stu->type >> stu->enrollmentDate->year >> tmp >> stu->enrollmentDate->month >> tmp >> stu->enrollmentDate->day >> stu->enrollmentWay >> stu->college >> stu->major >> stu->grade >> stu->schoolingLength >> stu->educationLevel >> stu->_class >> stu->counsellor;
        if (file.fail ()) {
            cerr << "读取第" << addNum + 1 << "条记录时出现错误，请检查；已读取错误项之前的记录" << endl;
            system ("pause");
            file.close ();
            break;
        }
        if (filename == "StudentDataMain.txt") {
            file >> stu->timestamp;
        }
        else if (filename == "StudentDataNew.txt") {
            stu->timestamp = time (nullptr);
        }
        StudentVec.push_back (stu);
        addNum++;
    }
    file.close ();
    return addNum;
}
int Input ()
{
    system ("cls");
    StuInfo * stu = new StuInfo;
    InputNumber (stu);
    InputName (stu);
    InputGender (stu);
    InputWithConfig (stu, &stu->country, "./config/CountryCode.txt", "=>>(4/19)请输入学生的国家序号[默认值：1]：", 1);
    InputBirthday (stu);
    InputWithConfig (stu, &stu->nation, "./config/NationCode.txt", "=>>(6/19)请输入学生的民族序号[默认值：1]：", 1);
    InputWithConfig (stu, &stu->marriage, "./config/MarriageState.txt", "=>>(7/19)请输入学生的婚姻状况[默认值：1]：", 1);
    InputWithConfig (stu, &stu->politics, "./config/PoliticsStatus.txt", "=>>(8/19)请输入学生的政治面貌[默认值：3]：", 3);
    InputIDNumber (stu);
    InputWithConfig (stu, &stu->type, "./config/StudentType.txt", "=>>(10/19)请输入学生类别[默认值：无]：");
    InputEnrollmentDate (stu);
    InputWithConfig (stu, &stu->enrollmentWay, "./config/EnrollmentWay.txt", "=>>(12/19)请输入学生入学方式[默认值：1]：", 1);
    InputWithConfig (stu, &stu->college, "./config/CollegeCode.txt", "=>>(13/19)请输入学生所在学院代号：");
    InputMajor (stu);
    InputGrade (stu);
    InputSchoolingLength (stu);
    InputWithConfig (stu, &stu->educationLevel, "./config/Educationlevel.txt", "=>>(17/19)请输入学生的培养层次[默认值：1]：", 1);
    InputClass (stu);
    InputCounsellor (stu);
    stu->timestamp = time (nullptr);

    system ("cls");
    ShowStudentInfo (stu);
    cout << endl << "是否确认录入？按Q取消，按其他键录入" << endl;
    if (toupper (_getch ()) == 'Q') {
        cout << "已放弃录入！" << endl;
        return 0;
    }
    else {
        StudentVec.push_back (stu);
        return 1;
    }
}

void InputNumber (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    do
    {
        cout << "=>>(1/19)请输入学生学号：";
        getline (cin, stu->number);
        legal = IsLegalNumber (stu->number);
    } while (!legal);
    cout << "学号：" << stu->number << endl << endl;
    Sleep (1000);
}
void InputName (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    do {
        cout << "=>>(2/19)请输入学生姓名：";
        getline (cin, stu->name);
        legal = IsLegalName (stu);
        if (!legal) {
            cout << "请检查输入名字的长度！" << endl << endl;
        }
    } while (!legal);
    cout << "姓名：" << stu->name << endl << endl;
    Sleep (1000);
}
void InputGender (StuInfo * stu)
{
    system ("cls");
    cout << "[1]男\t[2]女" << endl;
    bool legal = true;
    do {
        cout << "=>>(3/19)请输入学生性别：";
        cin >> stu->gender;
        legal = IsLegalGender (stu);
        if (!legal) {
            ClearBuff ();
            cout << "只能输入1或2" << endl << endl;
        }
    } while (!legal);
    cout << "性别：" << genderCN[stu->gender - 1] << endl << endl;
    Sleep (1000);
    ClearBuff ();
}
void InputBirthday (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    char tmp;
    stu->birthday = new Date;
    do {
        cout << "=>>(5/19)请输入学生出生日期（年月日之间用-或.隔开）：" << endl;
        cin >> stu->birthday->year >> tmp
            >> stu->birthday->month >> tmp
            >> stu->birthday->day;
        legal = cin.good () && IsLegalDate (stu->birthday);
        if (!legal) {
            ClearBuff ();
            cout << "请注意日期格式或输入合法日期" << endl << endl;
        }
        else if (g_ThisYear - stu->birthday->year <= 10 || g_ThisYear - stu->birthday->year >= 100) {
            cout << "该学生年龄超过限制范围（10~100）！" << endl;
            legal = false;
        }
    } while (!legal);
    cout << "出生日期：" << stu->birthday->year << '.' << stu->birthday->month
        << '.' << stu->birthday->day << endl << endl;
    ClearBuff ();
    Sleep (1000);
}
void InputIDNumber (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    string birthday = to_string (stu->birthday->year) +
        (stu->birthday->month < 10 ? "0" : "") + to_string (stu->birthday->month) +
        (stu->birthday->day < 10 ? "0" : "") + to_string (stu->birthday->day);
    int gender = stu->gender;
    if (stu->country == 1) {
        do
        {
            cout << "=>>(9/19)请输入学生身份证号码（X需大写）：";
            getline (cin, stu->IDnumber);
            legal = IsLegalIDNumber (stu->IDnumber, birthday, gender);
        } while (!legal);
        cout << "身份证号码：" << stu->IDnumber << endl << endl;
    }
    else {
        do
        {
            cout << "=>>(9/19)该学生非中国国籍，如无身份证按确认键跳过，如有请输入（X需大写）：";
            getline (cin, stu->IDnumber);
            if (stu->IDnumber.empty ()) {
                stu->IDnumber = "0";
            }
            legal = (stu->IDnumber == "0") || IsLegalIDNumber (stu->IDnumber, birthday, gender);
        } while (!legal);
        cout << "身份证号码：" << (stu->IDnumber == "" ? "未填写" : stu->IDnumber) << endl << endl;
    }
    Sleep (1000);
}
void InputEnrollmentDate (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    char tmp;
    stu->enrollmentDate = new Date;
    do
    {
        cout << "=>>(11/19)请输入学生入学日期（年月日之间用-或.隔开）:" << endl;
        cin >> stu->enrollmentDate->year >> tmp
            >> stu->enrollmentDate->month >> tmp
            >> stu->enrollmentDate->day;
        legal = cin.good () && IsLegalDate (stu->enrollmentDate);
        if (!legal) {
            ClearBuff ();
            cout << "请注意日期格式，或输入合法日期" << endl << endl;
        }
        else if (stu->enrollmentDate->year < SCHOOL_FOUNDING_TIME || stu->enrollmentDate->year > g_ThisYear) {
            cout << "入学年份不合法，请检查" << endl << endl;
            legal = false;
        }
        else if (stu->enrollmentDate->month < 8 || stu->enrollmentDate->month > 10) {
            cout << "入学月份不正确，应为8~10月" << endl << endl;
            legal = false;
        }
    } while (!legal);
    cout << "入学日期：" << stu->enrollmentDate->year << '.' << stu->enrollmentDate->month
        << '.' << stu->enrollmentDate->day << endl << endl;
    Sleep (1000);
    ClearBuff ();
}
void InputMajor (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    ifstream file ("./config/College-major.txt", ios::in);
    if (file.fail ()) {
        OpenFileFail ("./config/College-Major.txt");
    }
    string tmp, majorname;
    int id, i = 0;
    while (!file.eof ()) {
        file >> tmp;
        if (tmp == ("[" + GetAttrName ("./config/CollegeCode.txt", stu->college) + "]")) {
            break;
        }
        if (file.eof ()) {
            cout << "数据文件不完整，请联系管理员" << endl;
        }
    }
    string correctOpt;
    while (!file.eof ()) {
        file >> id;
        if (file.fail ()) {
            cout << endl;
            break;
        }
        file >> majorname;
        correctOpt += to_string (id) + ' ' + majorname + ' ';
        cout << '[' << (id < 10 ? "0" : "") << id << ']' << majorname << '\t';
        if (++i % 5 == 0) {
            cout << endl;
        }
    }
    string str;
    do
    {
        cout << endl << "=>>(14/19)请输入学生的专业代号：";
        getline (cin, str);
        if (str.empty ()) {
            cout << "该部分信息没有默认值，请手动输入" << endl;
            legal = false;
            continue;
        }
        else {
            if (StrIsNum (str)) {
                stu->major = stoi (str);
            }
            else {
                cout << "只允许输入数字！" << endl;
                continue;
            }
        }
        legal = correctOpt.find (to_string (stu->major)) != string::npos ||
            correctOpt.find ("0" + to_string (stu->major)) != string::npos;
        if (!legal) {
            cout << "没有该选项，请重新输入" << endl << endl;
        }
    } while (!legal);
    size_t a, b, len;
    a = correctOpt.find (stu->major + '0');
    b = correctOpt.find (' ', a + 2);
    len = b;
    cout << "专业：" << (stu->major < 10 ? "0" : "") << stu->major << correctOpt.substr (a + 2, len);
    file.close ();
    Sleep (1000);
}
void InputGrade (StuInfo * stu)
{
    system ("cls");
    bool legal = true, proper = true;
    string str;
    int yearInNumber = stoi (stu->number.substr (2, 2)) + 2000;
    do
    {
        cout << "=>>(15/19)请输入学生年级（如：2015）[默认值：学号对应年级]：";
        getline (cin, str);
        if (str.empty ()) {
            stu->grade = yearInNumber;
            break;
        }
        else {
            if (StrIsNum (str)) {
                stu->grade = stoi (str);
            }
            else {
                cout << "只允许输入数字！" << endl << endl;
                legal = false;
                continue;
            }
        }
        legal = stu->grade >= SCHOOL_FOUNDING_TIME && stu->grade <= g_ThisYear;
        proper = stu->grade == yearInNumber;
        if (!legal) {
            cout << "请输入正确年级！" << endl << endl;
        }
        else if (!proper) {
            cout << "警告：年级与学号中的入学年份不一致，按确认键录入，其他键重新输入..." << endl;
            char o = _getch ();
            if (o != '\n' && o != '\r') {
                legal = false;
            }
        }
    } while (!legal);
    cout << "年级：" << stu->grade << endl << endl;
    Sleep (1000);
}
void InputSchoolingLength (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    string str;
    do
    {
        cout << "=>>(16/19)请输入学生学制（3~10年）[默认值：4]：";
        getline (cin, str);
        if (str.empty ()) {
            stu->schoolingLength = 4;
        }
        else {
            if (StrIsNum (str)) {
                stu->schoolingLength = stoi (str);
            }
            else {
                cout << "只允许输入数字！" << endl << endl;
                continue;
            }
        }
        legal = stu->schoolingLength >= 3 && stu->schoolingLength <= 10;
        try {
            legal = legal && to_string (stu->schoolingLength) ==
                GetAttrName ("./config/Major-SchoolingLength.txt", stu->college * 100 + stu->major);
        }
        catch (...) {
            cout << "提示：配置文件中没有该专业的学制，跳过检验" << endl;
        }
        if (!legal) {
            cout << "学制时长不合法！" << endl << endl;
        }
    } while (!legal);
    cout << "学制：" << stu->schoolingLength << "年" << endl << endl;
    Sleep (1000);
}
void InputClass (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    int classNum;
    do
    {
        cout << "=>>(18/19)请输入班级号（如：03）：";
        cin >> stu->_class;
        for (size_t i = 0; i < stu->_class.size (); ++i) {
            if (!isdigit (stu->_class[i])) {
                cout << "班级号只能是数字！" << endl;
                legal = false;
                goto RETRY;
            }
        }
        classNum = stoi ((stu->_class));
        legal = classNum == 10 || classNum < 10 && classNum > 0 && (*stu->_class.begin () == '0');
    RETRY:if (!legal) {
        cout << "班级号限制为01~10，请重新输入" << endl;
    }
    } while (!legal);
    cout << "班级号：" << stu->_class << endl << endl;
    Sleep (1000);
}
void InputCounsellor (StuInfo * stu)
{
    system ("cls");
    bool legal = true;
    ifstream file ("./config/Major-Counsellor.txt", ios::in);
    if (file.fail ()) {
        OpenFileFail ("./config/Major-Counsellor.txt");
    }
    string name, id, strtmp;
    char tmp;
    while (!file.eof ()) {
        file >> tmp;
        if (file.fail ()) {
            continue;
        }
        if (tmp == '#') {
            getline (file, strtmp); //忽略注释
            continue;
        }
        else {
            file.seekg (-1, ios::cur); //回退文件位置指针
        }
        file >> id;
        file >> name;
        if (stoi (id.substr (0, 2)) == stu->college && stoi (id.substr (2, 2)) == stu->major) {
            cout << '[' << id << ']' << left << setw (20) << name;
        }
    }
    string str;
    do {
        cout << endl << "=>>(19/19)请输入学生的辅导员：";
        cin >> str;
        legal = str == id;
        if (!legal) {
            cout << "没有该选项，请重新输入" << endl;
        }
    } while (!legal);
    stu->counsellor = name;
    cout << endl << "你选择的是：" << stu->counsellor << endl;
    file.close ();
    Sleep (1000);
}
void InputWithConfig (StuInfo * stu, int * attrval, string filename, string inputText, int defOpt)
{
    system ("cls");
    bool legal = true;
    ifstream file (filename, ios::in);
    if (file.fail ()) {
        OpenFileFail (filename);
    }
    string attrname, strtmp;
    char tmp;
    int id, i = 0;
    while (!file.eof ()) {
        file >> tmp;
        if (file.fail ()) {
            continue;
        }
        if (tmp == '#') {
            getline (file, strtmp); //忽略注释
            continue;
        }
        else {
            file.seekg (-1, ios::cur); //回退文件位置指针
        }
        file >> id;
        file >> attrname;
        cout << '[' << (id < 10 ? "0" : "") << id << ']' << left << setw (25) << attrname;
        if (++i % 3 == 0) {
            cout << endl;
        }
    }
    string str;
    do {
        cout << endl << inputText;
        getline (cin, str);
        if (str.empty ()) {
            if (defOpt != 0) {
                *attrval = defOpt;
            }
            else {
                cout << "该部分信息没有默认值，请手动输入" << endl;
                legal = false;
                continue;
            }
        }
        else {
            if (StrIsNum (str)) {
                *attrval = stoi (str);
            }
            else {
                cout << "只允许输入数字！" << endl;
                legal = false;
                continue;
            }
        }
        legal = IsInFile (filename, to_string (*attrval)) || IsInFile (filename, "0" + to_string (*attrval));
        if (!legal) {
            cout << "没有该选项，请重新输入" << endl;
        }
    } while (!legal);
    cout << endl << "你选择的是：[" << *attrval << ']' << GetAttrName (filename, *attrval) << endl;

    file.close ();
    Sleep (1000);
}

void ShowStudentInfo (StuInfo * stu)
{
    cout << "学号：" << stu->number << endl;
    cout << "姓名：" << stu->name << endl;
    cout << "性别：" << genderCN[stu->gender - 1] << endl;
    cout << "国别：" << GetAttrName ("./config/CountryCode.txt", stu->country) << endl;
    cout << "出生日期：" << stu->birthday->year << '.'
        << stu->birthday->month << '.' << stu->birthday->day << endl;
    cout << "民族：" << GetAttrName ("./config/NationCode.txt", stu->nation) << endl;
    cout << "婚姻状况：" << GetAttrName ("./config/MarriageState.txt", stu->marriage) << endl;
    cout << "政治面貌：" << GetAttrName ("./config/PoliticsStatus.txt", stu->politics) << endl;
    cout << "身份证号：" << stu->IDnumber << endl;
    cout << "学生类别：" << GetAttrName ("./config/StudentType.txt", stu->type) << endl;
    cout << "入学年月：" << stu->enrollmentDate->year << '.'
        << stu->enrollmentDate->month << '.' << stu->enrollmentDate->day << endl;
    cout << "入学方式：" << GetAttrName ("./config/EnrollmentWay.txt", stu->enrollmentWay) << endl;
    cout << "学院名称：" << GetAttrName ("./config/CollegeCode.txt", stu->college) << endl;
    cout << "专业名称：" << GetAttrName ("./config/College-Major.txt", stu->major,
        GetAttrName ("./config/CollegeCode.txt", stu->college)) << endl;
    cout << "年级：" << stu->grade << endl;
    cout << "学制：" << stu->schoolingLength << "年" << endl;
    cout << "培养层次：" << GetAttrName ("./config/EducationLevel.txt", stu->educationLevel) << endl;
    cout << "班级号：" << stu->_class << endl;
    cout << "辅导员：" << stu->counsellor << endl;
}

void Skim ()
{
    if (StudentVec.empty ()) {
        system ("cls");
        cout << "学生信息为空！" << endl;
        system ("pause");
        return;
    }
    for (size_t i = 0; i < StudentVec.size (); ++i) {
        system ("cls");
        cout << "第" << i + 1 << "/" << StudentVec.size () << "条信息：" << endl << endl;
        ShowStudentInfo (StudentVec[i]);
        if (i == StudentVec.size () - 1) {
            cout << endl << "---已显示所有学生信息---" << endl;
            system ("pause");
        }
        else {
            cout << endl << "按任意键显示下一条,按q返回主菜单..." << endl;
            if (toupper (_getch ()) == 'Q') {
                return;
            }
        }
    }
}

void Lookup ()
{
    while (1) {
        system ("cls");
        ShowLookupUI ();
        string search;
        int o = _getche () - '0';
        if (o == 'q' - '0' || o == 'Q' - '0') {
            break;
        }
        if (o <= 0 || o >= 9) {
            cout << endl << "选择错误";
            Sleep (500);
            continue;
        }
        cout << endl << "请输入查询内容对应代号(按日期查询时格式：xxxx.x.x)：" << endl;
        getline (cin, search);
        LookupItem (o, search);
    }
}
void LookupItem (size_t idx, string cmp)
{
    vector<StuInfo *> result;
    for (size_t i = 0; i < StudentVec.size (); ++i) {
        if (StudentVec[i]->operator[](idx) == cmp) {
            result.push_back (StudentVec[i]);
        }
    }
    if (result.empty ()) {
        cout << "未找到！" << endl;
        system ("pause");
        return;
    }
    for (size_t i = 0; i < result.size (); ++i) {
        system ("cls");
        cout << "共找到" << result.size () << "个结果，当前第" << i + 1 << "个：" << endl << endl;
        ShowStudentInfo (result[i]);
        if (i == result.size () - 1) {
            cout << endl << "---已显示所有学生信息---" << endl;
            system ("pause");
        }
        else {
            cout << endl << "按任意键显示下一条,按Q返回查询菜单..." << endl;
            if (toupper (_getch ()) == 'Q') {
                return;
            }
        }
    }
}

void Del ()
{
    while (1) {
        system ("cls");
        ShowDelUI ();
        string del;
        int o = _getche () - '0';
        if (o == 'q' - '0' || o == 'Q' - '0') {
            break;
        }
        if (o != 1 && o != 9) {
            cout << endl << "选择错误";
            Sleep (500);
            continue;
        }
        cout << endl << "请输入将要删除的学生的信息：" << endl;
        getline (cin, del);
        int idx = FindSingleStu (o, del);
        if (idx == -1) {
            continue;
        }
        system ("cls");
        ShowStudentInfo (StudentVec[idx]);
        cout << endl << "按D键删除该条记录，按任意键取消" << endl;
        o = _getch ();
        if (toupper (o) == 'D') {
            StudentVec.erase (StudentVec.begin () + idx);
            cout << endl << "本次删除完成！" << endl;
        }
        else {
            cout << endl << "本次删除取消！" << endl;
        }
        Sleep (1000);
    }
}

void Modify ()
{
    while (1) {
        system ("cls");
        ShowModifyUI ();
        string sel;
        char o = _getche ();
        if (o == 'q' || o == 'Q') {
            break;
        }
        if (o != '1' && o != '9') {
            cout << endl << "选择错误";
            Sleep (500);
            continue;
        }
        cout << endl << "请输入将被选中的学生的信息：" << endl;
        getline (cin, sel);
        int idx = FindSingleStu (o - '0', sel);
        if (idx == -1) {
            continue;
        }
        system ("cls");
        ShowStudentInfo (StudentVec[idx]);
        cout << endl << "按E键修改该条记录，按任意键取消" << endl;
        o = _getch ();
        if (toupper (o) == 'E') {
            system ("cls");
            ShowModifyItemUI ();
            o = toupper (_getch ());
            if (o == 'Q') {
                cout << endl << "本次修改取消！" << endl;
                break;
            }
            while (1) {
                if (o >= '1' && o <= '9' || o >= 'A' && o <= 'I') {
                    ModifyItem (o, StudentVec[idx]);
                    cout << "修改完成！" << endl;
                    break;
                }
                else {
                    cout << "输入有误，请重试" << endl;
                }
            }
        }
        else {
            cout << endl << "本次修改取消！" << endl;
        }
        Sleep (1000);
    }
}
void ModifyItem (char n, StuInfo * stu)
{
    switch (n)
    {
    case '1':InputName (stu); break;
    case '2':InputGender (stu); break;
    case '3':InputWithConfig (stu, &stu->country, "./config/CountryCode.txt", "=>>(4/19)请输入学生的国家序号：", 1); break;
    case '4':InputBirthday (stu); break;
    case '5':InputWithConfig (stu, &stu->nation, "./config/NationCode.txt", "=>>(6/19)请输入学生的民族序号：", 1); break;
    case '6':InputWithConfig (stu, &stu->marriage, "./config/MarriageState.txt", "=>>(7/19)请输入学生的婚姻状况：", 1); break;
    case '7':InputWithConfig (stu, &stu->politics, "./config/PoliticsStatus.txt", "=>>(8/19)请输入学生的政治面貌：", 3); break;
    case '8':InputIDNumber (stu); break;
    case '9':InputWithConfig (stu, &stu->type, "./config/StudentType.txt", "=>>(10/19)请输入学生类别："); break;
    case 'A':InputEnrollmentDate (stu); break;
    case 'B':InputWithConfig (stu, &stu->enrollmentWay, "./config/EnrollmentWay.txt", "=>>(12/19)请输入学生入学方式：", 1); break;
    case 'C':InputWithConfig (stu, &stu->college, "./config/CollegeCode.txt", "=>>(13/19)请输入学生所在学院代号："); break;
    case 'D':InputMajor (stu); break;
    case 'E':InputGrade (stu); break;
    case 'F':InputSchoolingLength (stu); break;
    case 'G':InputWithConfig (stu, &stu->educationLevel, "./config/Educationlevel.txt", "=>>(17/19)请输入学生的培养层次：", 1); break;
    case 'H':InputClass (stu); break;
    case 'I':InputCounsellor (stu); break;
    }
}

void Statistics ()
{
    while (1)
    {
        system ("cls");
        ShowStatisticsUI ();
        int o = toupper (_getch ());
        if (o != 'Q') {
            o -= '0';
        }
        switch (o)
        {
        case 1:GradeSummary (); break;
        case 2:CollegeSummary (); break;
        case 3:GenderSummary (); break;
        case 4:CountrySummary (); break;
        case 5:NationSummary (); break;
        case 'Q':return;

        default:cout << endl << "输入有误，请重新输入"; Sleep (500);
        }
    }
}
void GradeSummary ()
{
    system ("cls");
    int gradeNum[6] = { 0 };
    size_t size = StudentVec.size ();
    for (size_t i = 0; i < size; ++i) {
        for (int t = 0; t < 5; ++t) {
            if (StudentVec[i]->grade == g_ThisYear - t) {
                gradeNum[t]++;
                break;
            }
        }
    }
    gradeNum[5] = size - gradeNum[4] - gradeNum[3] - gradeNum[2] - gradeNum[1] - gradeNum[0];
    cout << g_ThisYear << "年级人数：" << gradeNum[0] << endl <<
        g_ThisYear - 1 << "年级人数：" << gradeNum[1] << endl <<
        g_ThisYear - 2 << "年级人数：" << gradeNum[2] << endl <<
        g_ThisYear - 3 << "年级人数：" << gradeNum[3] << endl <<
        g_ThisYear - 4 << "年级人数：" << gradeNum[4] << endl <<
        "其他年级人数：" << gradeNum[5] << endl << endl;
    system ("pause");
}
void CollegeSummary ()
{
    system ("cls");
    cout << "注：只显示有学生的学院" << endl;
    int collegeNum[50] = { 0 };
    size_t size = StudentVec.size ();
    for (size_t i = 0; i < size; ++i) {
        collegeNum[StudentVec[i]->college]++;
    }
    for (int i = 0; i < 50; ++i) {
        if (collegeNum[i] != 0) {
            cout << GetAttrName ("./config/CollegeCode.txt", i) << "人数：" << collegeNum[i] << endl;
        }
    }
    cout << endl;
    system ("pause");
}
void GenderSummary ()
{
    system ("cls");
    int genderNum[2] = { 0 };
    size_t size = StudentVec.size ();
    for (size_t i = 0; i < size; ++i) {
        if (StudentVec[i]->gender == 1) {
            genderNum[0]++;
        }
        else {
            genderNum[1]++;
        }
    }
    cout << "男生 " << genderNum[0] << "人" << endl <<
        "女生 " << genderNum[1] << "人" << endl << endl;
    system ("pause");
}
void CountrySummary ()
{
    system ("cls");
    int countryNum[2] = { 0 };
    size_t size = StudentVec.size ();
    for (size_t i = 0; i < size; ++i) {
        if (StudentVec[i]->country == 1) {
            countryNum[0]++;
        }
        else {
            countryNum[1]++;
        }
    }
    cout << "中国 " << countryNum[0] << "人" << endl <<
        "其他国家 " << countryNum[1] << "人" << endl << endl;
    system ("pause");
}
void NationSummary ()
{
    system ("cls");
    int nationNum[2] = { 0 };
    size_t size = StudentVec.size ();
    for (size_t i = 0; i < size; ++i) {
        if (StudentVec[i]->nation == 1) {
            nationNum[0]++;
        }
        else {
            nationNum[1]++;
        }
    }
    cout << "汉族 " << nationNum[0] << "人" << endl <<
        "少数民族 " << nationNum[1] << "人" << endl << endl;
    system ("pause");
}

void Clear ()
{
    system ("cls");
    string input;
    int num = 0, graduatedYrs;
    cout << "是否确认删除*所有*毕业10年以上的学生，确认输入delete，输入其他内容则返回" << endl;
    cin >> input;
    if (input == "delete") {
        for (size_t i = 0; i < StudentVec.size (); ++i) {
            graduatedYrs = g_ThisYear - StudentVec[i]->schoolingLength - StudentVec[i]->enrollmentDate->year;
            if (graduatedYrs > 10) {
                StudentVec.erase (StudentVec.begin () + i);
                num++;
                --i;
            }
        }
        cout << "已删除" << num << "条毕业10年以上学生的信息" << endl;
    }
    else {
        cout << "未执行删除操作" << endl;
    }
    system ("pause");
}

void Sort ()
{
    while (1)
    {
        system ("cls");
        ShowSortUI ();
        int o = _getch (), a, b;
        if (o == 'q' || o == 'Q') {
            break;
        }
        o -= '0';
        if (o == 9) {
            Reverse ();
            cout << endl << "完成数据反向排序" << endl;
            system ("pause");
            break;
        }
        if ((o < 1 || o > 4)) {
            cout << endl << "输入有误，请重新输入" << endl;
            Sleep (500);
            continue;
        }
        size_t size = StudentVec.size ();
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = i + 1; j < size; ++j) {
                switch (o)
                {
                case 1:a = StudentVec[i]->GetiNumber (); b = StudentVec[j]->GetiNumber (); break;
                case 2:a = StudentVec[i]->GetiBirthday (); b = StudentVec[j]->GetiBirthday (); break;
                case 3:a = StudentVec[i]->GetiEnrollmentDate (); b = StudentVec[j]->GetiEnrollmentDate (); break;
                case 4:a = (int)StudentVec[i]->timestamp; b = (int)StudentVec[j]->timestamp; break;
                }
                if (a > b) {
                    swap (StudentVec[i], StudentVec[j]);
                }
            }
        }
        cout << endl << "排序完成，";
        system ("pause");
        break;
    }
}
void Reverse ()
{
    size_t size = StudentVec.size ();
    for (size_t i = 0; i < size / 2; ++i) {
        swap (StudentVec[i], StudentVec[size - 1 - i]);
    }
}

void SaveToFile (string filename)
{
    ofstream file (filename, ios::trunc);
    file << prompt << "录入时间戳" << endl;
    for (size_t i = 0; i < StudentVec.size (); ++i) {
        file << StudentVec[i]->number << ' ' << StudentVec[i]->name << ' ' << StudentVec[i]->gender << ' ' << StudentVec[i]->country << ' ' << StudentVec[i]->birthday->year << '.' << StudentVec[i]->birthday->month << '.' << StudentVec[i]->birthday->day << ' ' << StudentVec[i]->nation << ' ' << StudentVec[i]->marriage << ' ' << StudentVec[i]->politics << ' ' << StudentVec[i]->IDnumber << ' ' << StudentVec[i]->type << ' ' << StudentVec[i]->enrollmentDate->year << '.' << StudentVec[i]->enrollmentDate->month << '.' << StudentVec[i]->enrollmentDate->day << ' ' << StudentVec[i]->enrollmentWay << ' ' << StudentVec[i]->college << ' ' << StudentVec[i]->major << ' ' << StudentVec[i]->grade << ' ' << StudentVec[i]->schoolingLength << ' ' << StudentVec[i]->educationLevel << ' ' << StudentVec[i]->_class << ' ' << StudentVec[i]->counsellor << ' ' << StudentVec[i]->timestamp << endl;
    }

}
string GetAttrName (string filename, int id, string configname)
{
    ifstream file (filename, ios::in);
    string tmp, attr;
    bool zeroflag = false;
    if (file.fail ()) {
        OpenFileFail (filename);
    }
    while (!file.eof ()) {
        file >> tmp;
        if (tmp == "#") {
            getline (file, tmp);
            continue;
        }
        if (tmp == "\n") {
            continue;
        }
        if (tmp == "[" + configname + "]") {
            while (!file.fail ()) {
                file >> tmp;
                if (tmp == "#") {
                    getline (file, tmp);
                    continue;
                }
                zeroflag = *tmp.begin () == '0';
                if (tmp == (id < 10 && zeroflag ? "0" : "") + to_string (id)) {
                    file >> attr;
                    file.close ();
                    return attr;
                }
            }
        }
    }
    FindInfoFail (filename);
    return "";
}
string GetAttrName (string filename, int id)
{
    ifstream file (filename, ios::in);
    string tmp, attr;
    if (file.fail ()) {
        OpenFileFail (filename);
    }
    while (!file.eof ()) {
        file >> tmp;
        if (tmp == "#") {
            getline (file, tmp); //忽略注释
            continue;
        }
        if (tmp == "\n") {
            continue;
        }
        if (tmp == to_string (id) || tmp == "0" + to_string (id)) {
            file >> attr;
            return attr;
        }
    }
    file.close ();
    FindInfoFail (filename);
    return "";
}
int FindSingleStu (char o, string cmp)
{
    for (size_t i = 0; i < StudentVec.size (); ++i) {
        if (StudentVec[i]->operator[](o) == cmp) {
            return i;
        }
    }
    cout << "未找到该名学生！" << endl;
    system ("pause");
    return -1;
}
void ClearBuff ()
{
    cin.clear ();
    cin.ignore (1024, '\n');
}

bool StrIsNum (string str)
{
    for (size_t i = 0; i < str.size (); ++i) {
        if (str[i] < -1 || str[i] > 255) {
            return false;
        }
        if (!isdigit (str[i])) {
            return false;
        }
    }
    return true;
}
bool IsInFile (string filename, string text)
{
    ifstream file (filename, ios::in);
    string tmp;
    if (file.fail ()) {
        OpenFileFail (filename);
    }
    while (!file.eof ()) {
        file >> tmp;
        if (tmp == text) {
            file.close ();
            return true;
        }
    }
    file.close ();
    return false;
}
bool IsLegalDate (Date * p)
{
    bool isReapYear = p->year % 4 == 0 && p->year % 100 != 0 || p->year % 400 == 0 ? true : false;
    if (p->month >= 1 && p->month <= 12 && p->day > 0) {
        if (isReapYear && p->month == 2) {
            return (p->day > 29 ? false : true);
        }
        else {
            return (p->day > dayOfMonth[p->month - 1] ? false : true);
        }
    }
    else {
        return false;
    }
}
bool IsLegalNumber (string num)
{
    if (num.size () != 9) {
        cout << "学号长度不正确！" << endl << endl;
        return false;
    }
    for (int i = 0; i < 9; ++i) {
        if (!isdigit (num[i])) {
            cout << "学号为纯数字！" << endl << endl;
            return false;
        }
    }
    if (!IsInFile ("./config/CollegeCode.txt", num.substr (0, 2))) {
        cout << "学院代号有误" << endl << endl;
        return false;
    }
    for (size_t i = 0; i < StudentVec.size (); ++i) {
        if (num == StudentVec[i]->number) {
            cout << "学号不允许重复" << endl << endl;
            return false;
        }
    }
    if (2000 + stoi (num.substr (2, 2)) != g_ThisYear) {
        cout << "警告：学号中的入学年份与当前年份不一致，"
            << "按任意键重新输入，按确认键继续..." << endl << endl;
        char o = _getch ();
        if (o == '\n' || o == '\r') {
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}
bool IsLegalName (StuInfo * stu)
{
    return ((stu->name).size () <= 40 && (stu->name).size () >= 4) ? true : false;
}
bool IsLegalGender (StuInfo * stu)
{
    return (stu->gender == 1 || stu->gender == 2) ? true : false;
}
bool IsLegalIDNumber (string n, string birthday, int sex)
{
    if (n.size () != 18) {
        cout << "身份证长度不正确！" << endl << endl;
        return false;
    }
    for (int i = 0; i < 18; ++i) {
        if (!isdigit (n[i]) && i < 17) {
            cout << "身份证除最后一位以外都为数字！" << endl << endl;
            return false;
        }
        else if (n[17] != 'X' && !isdigit (n[17])) {
            cout << "身份证最后一位只能是数字或X！" << endl << endl;
            return false;
        }
    }
    string a = n.substr (0, 6), b = n.substr (6, 8);
    int c = stoi ((n.substr (14, 3)));
    char d = n[17];
    if (!IsInFile ("./config/RegionCode.txt", a)) {
        cout << "地址码有误，请检查" << endl << endl;
        return false;
    }
    if (b != birthday) {
        cout << "生日不匹配，请检查" << endl << endl;
        return false;
    }
    if (c % 2 != (sex == 2 ? 0 : 1)) {
        cout << "性别不匹配，请检查" << endl << endl;
        return false;
    }
    int chkCode, sum = 0;
    for (int i = 0; i < 17; ++i) {
        sum += stoi (n.substr (i, 1)) * ID_Weight[i];
    }
    chkCode = (12 - sum % 11) % 11;
    char chkCode_ch = (chkCode == 10 ? 'X' : chkCode + '0');
    if (chkCode_ch != d) {
        cout << "身份证校验位错误，请检查" << endl << endl;
        return false;
    }
    for (size_t i = 0; i < StudentVec.size (); ++i) {
        if (n == StudentVec[i]->IDnumber) {
            cout << "身份证号码不允许重复！重复记录的学号为：" <<
                StudentVec[i]->number << endl << endl;
            return false;
        }
    }
    return true;
}

void OpenFileFail (string filename)
{
    cerr << "打开文件失败！请检查数据文件" << filename << endl;
    system ("pause");
    exit (1);
}
void FindInfoFail (string filename)
{
    cerr << "数据项未找到，请管理员检查过期学生信息或配置文件" << filename << endl;
    Sleep (5000);
}