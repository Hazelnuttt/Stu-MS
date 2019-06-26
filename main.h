#define STUDENT_HEAD

//beauty
void printDividerStar();
void printShortStar();
void printShortLine();
void printItemS();
void printItemF();
void printItemO();
void stustart();
void stufinish();
void guide();
void Guide();
void mimihao();
void error();
void line1();
void line2();
void line3();
void line4();

//请注意由于链表无法准确读取字符串，所以我这边全部改为整型
typedef struct node /*定义结构体*/
{
	int num; //学号
	int name;//姓名
	int sex; //性别
	int math; //数学成绩
	int english; //英语成绩
	int all; //总分
	struct node *next; //链表指针域
}student_info;

//学生信息链表
extern student_info* student_list;  //全局变量声明


//初始化学生信息链表
void init_student_info_list();
//判断学生信息链表是否为空
int student_list_empty();


//添加学生信息记录
int add_student_info();
//根据学号删除学生信息
int delete_student_info(int num);
//根据学号修改学生信息
int modify_student_info(int num);
//根据学号或姓名查找学生信息
student_info* search_student_info(int num);
void search_num(int num);
void search_name(int name);
//输出每个学生的平均成绩
void display_average();
//显示所有学生信息
void display_student_info();
//将学生信息保存到文件
int save_file();
//从文件中读取学生信息
int read_file();
//男生或女生的平均分
void average_man();
void average_woman();
//英语或数学挂科的人
void faile();
void failm();
//总分或英语或数学比我高的人
void compareA(int grade);
void compareE(int grade);
void compareM(int grade);
//按总分或英语或数学降序排序
void sortA();
void sortE();
void sortM();



