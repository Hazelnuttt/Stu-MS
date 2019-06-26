#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/*stuMangerMenu 相关*/
void stuMangerMenu();
void stuMenu();
void teaMenu();
void firstteaMenu();
void firststuMenu();

//学生信息链表
student_info* student_list;


int main()
{
	init_student_info_list();
	if (read_file())
	{
		mimihao();
		printf("从文件中读取学生信息成功.\n");
	}
	else
	{
		error();
		printf("从文字中读取学生信息失败.\n");
	}
	stuMangerMenu();

}




/*输出欢迎及学生管理系统身份选择*/
void stuMangerMenu() {
	int n;

	printf("\n");
	printShortStar();
	printf("欢迎进入学生管理系统");
	printShortStar();
	printf("\n");

	printItemS();
	printf("Made with LOVE by 102-大佬宿舍");

	printItemS();
	printf("进入该系统设有密码,只有3次机会");

	printf("\n");
	printItemF();
	printShortLine();
	printItemF();
	printf("1.教师入口");
	printItemF();
	printf("2.学生入口");
	printItemF();
	printf("3.退出");
	printItemF();
	printShortLine();
	printf("\n");
	printDividerStar();

	Guide();
	printf("请选择：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		firstteaMenu(); break;
	case 2:
		firststuMenu(); break;
	case 3:
		exit(0); break;
	default:
	{
		error();
		printf("请输入数字1~3");
	}

	}

}

//老师的密码登录界面
void firstteaMenu()
{
	//登录次数计数器
	int trypasswordCount = 3;
	int n;
	char username0[10], password0[10], username[10] = "admin", password[10] = "123456";
	for (n = 1; n <= trypasswordCount; n++) {
		guide();
		printf("请输入登录账号！");
		scanf("%s", &username0);
		guide();
		printf("请输入登录密码！");
		scanf("%s", &password0);
		if ((strcmp(password, password0) == 0) && (strcmp(username, username0) == 0)) {
			teaMenu();
			break;
		}
		else {
			error();
			printf("账号或密码错误！你还有%d次机会\n", trypasswordCount - n);
		}

	}
}

//学生的密码登录界面
void firststuMenu()
{
	//登录次数计数器
	int trypasswordCount = 3;
	int n;
	char username0[10], password0[10], username[10] = "test0", password[10] = "123456";
	for (n = 1; n <= trypasswordCount; n++) {
		guide();
		printf("请输入登录账号！");
		scanf("%s", &username0);
		guide();
		printf("请输入登录密码！");
		scanf("%s", &password0);
		if ((strcmp(password, password0) == 0) && (strcmp(username, username0) == 0)) {
			stuMenu();
			break;
		}
		else {
			error();
			printf("账号或密码错误！你还有%d次机会\n", trypasswordCount - n);
		}

	}
}

/*管理员界面*/
void teaMenu() {
	int n;
	int m;
	int num;
	printf("\n");
	printShortStar();
	printf("欢迎进入管理员的界面");
	printShortStar();
	printf("\n");

	printItemS();
	printf("Welcome,admin!");


	printf("\n");
	printItemF();
	printShortLine();
	printItemF();
	printf("1.查看学生信息.");
	printItemF();
	printf("2.添加学生信息.");
	printItemF();
	printf("3.删除学生信息.");
	printItemF();
	printf("4.修改学生信息.");
	printItemF();
	printf("5.统计男生或女生总分的平均分.");
	printItemF();
	printf("6.将学生成绩导出并保存到 D:\\chengji.txt 文档中.");
	printItemF();
	printf("7.排序学生信息.");
	printItemF();
	printf("8.统计单科不及格学生信息和成绩.");
	printItemF();
	printf("0.退出系统操作.");
	printItemF();
	printShortLine();
	printf("\n");

	printDividerStar();
	while (1)
	{
		Guide();
		printf("请选择操作: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
				display_student_info();
			break;
		case 2:
			if (add_student_info())
			{
				mimihao();
				printf("添加学生信息成功.\n");
			}
			else
			{
				error();
				printf("添加学生信息失败.\n");
			}
			break;
		case 3:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
			{
				guide();
				printf("请输入要删除学生信息的学号: ");
				scanf("%d", &num);
				if (delete_student_info(num))
				{
					mimihao();
					printf("成功删除该学号对应的学生信息.\n");
				}
				else
				{
					error();
					printf("删除失败.\n");
				}
			}
			break;
		case 4:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
			{
				guide();
				printf("请输入要修改学生信息的学号: ");
				scanf("%d", &num);
				if (modify_student_info(num))
				{
					mimihao();
					printf("成功修改该学号对应的学生信息.\n");
				}
				else
				{
					error();
					printf("修改失败.\n");
				}
			}
			break;
		case 5:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
				display_average();
			break;
		case 6:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
				if (save_file())
				{
					mimihao();
					printf("保存学生信息成功.\n");
				}
				else {
					error();
					printf("保存学生信息失败.\n");
				}
			break;
		case 7:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
			{
				line4();
				printf("1.按总分降序排序. 2.按英语降序排序. 3.按数学降序排序.\n");
				line4();
				Guide();
				printf("请选择：");
				scanf("%d", &m);
				switch (m)
				{
				case 1:
					sortA();
					break;
				case 2:
					sortE();
					break;
				case 3:
					sortM();
					break;
				default:
					error();
					printf("请按提示要求操作.\n");
				}
			}
			break;
		case 8:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
			{
				line2();
				printf("\t1.英语不及格. 2.高数不及格.\n");
				line2();
				Guide();
				printf("请选择：");
				scanf("%d", &m);
				switch (m)
				{
				case 1:
					faile();
					break;
				case 2:
					failm();
					break;
				default:
					error();
					printf("请按提示要求操作.\n");
				}
			}
			break;
		case 0:
			mimihao();
			printf("欢迎下次使用,再见.\n");
			system("pause");
			exit(0);
			break;
		default:
			error();
			printf("输入错误，请重新选择操作.\n");
		}
	}
	system("pause");
	return 0;


}

/*学生界面*/
void stuMenu() {
	int n;
	int m;
	int num;
	int name;
	int english;
	int math;
	int all;

	printf("\n");
	printShortStar();
	printf("欢迎进入学生们界面");
	printShortStar();
	printf("\n");

	printItemS();
	printf("Welcome,student!");


	printf("\n");
	printItemF();
	printShortLine();
	printItemF();
	printf("1.查询学生信息和成绩；");
	printItemF();
	printf("2.统计出总分或单科科比自己分数高的学生信息和成绩；");
	printItemF();
	printf("0.退出系统操作；");
	printItemF();
	printShortLine();
	printf("\n");

	printDividerStar();

	while (1)
	{
		Guide();
		printf("请选择操作: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
			{
				line3();
				printf("1.按学号查询. 2.按姓名查询.\n");
				line3();
				Guide();
				printf("请选择操作：");
				scanf("%d", &m);
				switch (m)
				{
				case 1:
					guide();
					printf("请输入你的学号：");
					scanf("%d", &num);
					search_num(num);
					break;
				case 2:
					guide();
					printf("请输入你的姓名：");
					scanf("%d", &name);
					search_name(name);
					break;
				default:error();
					printf("请按提示要求操作.\n");
				}
			}
			break;
		case 2:
			if (student_list_empty())
			{
				error();
				printf("学生信息表为空，请先添加学生信息.\n");
			}
			else
			{
				line2();
				printf("1.总分比我高. 2.英语比我高. 3.数学比我高.\n");
				line2();
				Guide();
				printf("请选择操作：");
				scanf("%d", &m);
				switch (m)
				{
				case 1:
					guide();
					printf("请输入你的总分：");
					scanf("%d", &all);
					compareA(all);
					break;
				case 2:
					guide();
					printf("请输入你的英语：");
					scanf("%d", &english);
					compareE(english);
					break;
				case 3:
					guide();
					printf("请输入你的高数：");
					scanf("%d", &math);
					compareM(math);
					break;
				default:
					error();
					printf("请按提示要求操作.\n");
				}
			}
			break;
		case 0:
			mimihao();
			printf("欢迎下次使用,再见.\n");
			system("pause");
			exit(0);
			break;
		default:
			error();
			printf("输入错误，请重新选择操作.\n");
		}
	}
	system("pause");
	return 0;
}
