# Homework-StudentImformationManegeSystem

程序设计实验，作业2

---

### 文件读写说明 ###
记录储存在-StudentDataMain.txt  
新增记录从-StudentDataNew.txt中读取

储存和读取的格式为 按顺序、只保存字段，enter键分开两条记录


### 注释文本说明 ###
\#引起一段注释说明，程序会忽略\#右侧的内容  
**注意** #右侧一定要有空格，如果#左侧有内容，也要用空格隔开


### 配置更改说明 ###
    配置文件、数据文件末尾不能有空格！（否则会导致最后一对数据重复输出等异常）【已修复】
没有身份证时用0填充（未输入身份证时，结构体中储存的是"0"）



### 参考 ###
文件读写参考：https://blog.csdn.net/wangshihui512/article/details/8921919 系列  
地区编码（/config/RegionCode.txt）来源：http://www.360doc.com/content/13/0527/09/155444_288472935.shtml  
vector容器参考：
https://blog.csdn.net/w_linux/article/details/71600574
https://blog.csdn.net/c20182030/article/details/69667965
http://www.cnblogs.com/oomusou/archive/2008/08/01/vector_struct.html 等等  
配置文件部分参考：https://blog.csdn.net/fuxingwe/article/details/8836180