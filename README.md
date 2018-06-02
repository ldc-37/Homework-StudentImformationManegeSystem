# Homework-StudentImformationManegeSystem

程序设计实验，作业2
> 本程序以C++编写，通过文本的读取和写入实现对学生信息的存储，在此基础上进一步实现了增删改查、排序、统计等管理功能。

---

### 文件读写说明 ###
(1)所有记录储存在StudentDataMain.txt中。  
(2)管理员可以将新增的记录放到StudentDataNew.txt中，并在程序中输入时选择“从文件中输入”。  
(3)储存和读取的格式为：按顺序（如配置更改说明中所示）、只读取/保存字段，回车键/换行符（‘\n’）分开两条记录。


### 注释文本说明 ###
\#引起一段注释说明，程序会忽略\#右侧的内容  
**注意** #右侧一定要有空格，如果#左侧有内容，也要用空格隔开


### 配置更改说明 ###
（1）读取/写入顺序：学号 姓名 性别 国籍 出生日期 民族 婚姻状况 政治面貌 身份证号 学生类别 入学日期 入学方式 学院 专业 年级 学制 培养层次 班级 辅导员 录入时间戳（由程序自动填充，无需手动输入）  
（2）没有身份证时用0填充（未输入身份证时，结构体中储存的是"0"）


### 使用说明 ###
(1)程序运行时，同目录下必须有StudentDataMain.txt文件和StudentDataNew.txt文件，同时在同目录下的config文件夹中存放各个配置文件。上述文件、文件夹在程序运行时不可缺少，否则程序将报错并退出。  
(2)由于本程序只有在使用者在主界面按下Q退出程序时才会将本次运行所做的改动写入存储文件，因此使用者不可以直接关闭程序，否则会造成本次修改（增加、删除）失效。但同时，当使用者因误操作等原因，希望不保存程序本次运行所改动的数据时，可以直接关闭程序。  
(3)本程序从文件中读入数据时未进行正确性校验，管理员需自行确保数据正确，请谨慎使用。如遇读取失败或读取到非法字符时，程序将会停止读取该条非法数据并给出提示，但之前合法的数据将被读入。  


### 参考 ###
  文件读写参考：https://blog.csdn.net/wangshihui512/article/details/8921919 系列  
  地区编码（/config/RegionCode.txt）来源：http://www.360doc.com/content/13/0527/09/155444_288472935.shtml  
  vector容器参考：
https://blog.csdn.net/w_linux/article/details/71600574
https://blog.csdn.net/c20182030/article/details/69667965
http://www.cnblogs.com/oomusou/archive/2008/08/01/vector_struct.html 等等  
  配置文件部分参考：https://blog.csdn.net/fuxingwe/article/details/8836180

### 备注 ###  
能写这么多，都得*归功于*作业要求写的设计思路和使用手册。。。。。
