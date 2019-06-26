#include "main.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//初始化学生信息链表
void init_student_info_list()
{
	//学生信息链表头结点
	student_list = (student_info*)malloc(sizeof(student_info));
	student_list->next = NULL;
}
//判断学生信息链表是否为空
int student_list_empty()
{
	return student_list->next == NULL;
}

//添加学生信息记录
int add_student_info()
{
	student_info *pstu = (student_info*)malloc(sizeof(student_info));
	if (pstu == NULL)
	{
		error();
		printf("内存分配失败.\n");
		return 0;
	}
	mimihao();
	printf("请按要求一次输入学生的信息.\n");
	guide();
	printf("请输入学号: ");
	scanf("%d", &pstu->num);
	//判断该学号是否已经存在
	if (search_student_info(pstu->num) != NULL)
	{
		error();
		printf("该学号已经存在学生信息表中.\n");
		return 0;
	}
	guide();
	printf("请输入姓名: ");
	scanf("%d", &pstu->name);
	guide();
	printf("请输入性别: ");
	scanf("%d", &pstu->sex);
	guide();
	printf("请输入高数成绩: ");
	scanf("%d", &pstu->math);
	guide();
	printf("请输入英语成绩: ");
	scanf("%d", &pstu->english);

	pstu->all = pstu->english + pstu->math;
	//每次从学生信息链表的头部插入;
	pstu->next = student_list->next;
	student_list->next = pstu;
	return 1;
}

//根据学号删除学生信息
int delete_student_info(int num)
{
	student_info *pstu;
	student_info *qstu;
	if (search_student_info(num) == NULL)
	{
		error();
		printf("不存在该学号为%d的学生信息.\n", num);
		return 0;
	}
	pstu = student_list->next;
	qstu = student_list;
	while (pstu->num != num)
	{
		qstu = pstu;
		pstu = pstu->next;
	}
	qstu->next = pstu->next;
	free(pstu);
	return 1;
}

//根据学号修改学生信息
int modify_student_info(int num)
{
	int choice;
	student_info *pstu = search_student_info(num);
	if (pstu == NULL)
	{
		error();
		printf("不存在该学好为%d的学生信息.\n", num);
		return 0;
	}
	line2();
	printf("1.姓名 2.性别 3.英语成绩 4.数学成绩 5.总分.\n");
	line2();
	Guide();
	printf("请选择修改的信息: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		guide();
		printf("请输入新的姓名: ");
		scanf("%d", &pstu->name);
		break;
	case 2:
		guide();
		printf("请输入新的性别: ");
		scanf("%d", &pstu->sex);
		break;
	case 3:
		guide();
		printf("请输入新的英语成绩: ");
		scanf("%d", &pstu->english);
		break;
	case 4:
		guide();
		printf("请输入新的数学成绩: ");
		scanf("%d", &pstu->math);
		break;
	case 5:
		guide();
		printf("请输入新的总分: ");
		scanf("%d", &pstu->all);
		break;
	default:
		error();
		printf("请按提示要求操作.\n");
	}
	return 1;
}

//根据学号查找学生信息
student_info* search_student_info(int num)
{
	student_info *pstu;
	pstu = student_list->next;
	while (pstu  && pstu->num != num)
	{

		pstu = pstu->next;
	}
	return pstu;
}

//男生平均分
void average_man()
{
	int i = 0;
	int sum = 0;
	int average = 0;
	student_info *pstu;
	pstu = student_list->next;
	while (pstu != NULL) {
		if (pstu->sex == 1) {
			i++;
			sum = sum + pstu->all;
		}
		pstu = pstu->next;
	}
	average = (sum*1.0) / i;
	mimihao();
	printf("男生总分的平均分为%4d\n", average);
}
//女生平均分
void average_woman()
{
	int i = 0;
	int sum = 0;
	int average = 0;
	student_info *pstu;
	pstu = student_list->next;
	while (pstu != NULL) {
		if (pstu->sex == 2) {
			i++;
			sum = sum + pstu->all;
		}
		pstu = pstu->next;
	}
	average = (sum*1.0) / i;
	mimihao();
	printf("女生总分的平均分为%4d\n", average);
}
//输出男生或女生的平均成绩
void display_average()
{
	int choice;
	line1();
	printf("\t1.男生 2.女生\n");
	line1();
	Guide();
	printf("请选择: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		average_man();
		break;
	case 2:
		average_woman();
		break;
	default:
		error();
		printf("请按提示要求操作.\n");
	}
	return 1;
}

//显示所有学生信息
void display_student_info()
{
	student_info *pstu;
	pstu = student_list->next;
	mimihao();
	printf("所有学生信息如下所示.\n");
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu)
	{
		printf("%d\t", pstu->num);
		printf("%d\t", pstu->name);
		printf("%d\t", pstu->sex);
		printf("%d   \t", pstu->english);
		printf("%d  \t", pstu->math);
		printf("%d\n", pstu->all);
		pstu = pstu->next;
	}stufinish();
}

//将学生信息保存到文件
int save_file()
{
	FILE *pfile;
	student_info *pstu;
	pfile = fopen("student.txt", "w");
	if (pfile == NULL)
	{
		error();
		printf("打开文件失败.\n");
		return 0;
	}
	pstu = student_list->next;
	while (pstu)
	{
		fprintf(pfile, "%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
			pstu->english, pstu->math, pstu->all);
		pstu = pstu->next;
	}
	fclose(pfile);
	return 1;
}

//从文件中读取学生信息
int read_file()
{
	FILE *pfile;
	student_info *pstu;
	pfile = fopen("student.txt", "r");
	if (pfile == NULL)
	{
		error();
		printf("打开文件失败.\n");
		return 0;
	}
	while (!feof(pfile))
	{
		pstu = (student_info*)malloc(sizeof(student_info));
		fscanf(pfile, "%d%6d%7d%9d%9d%9d\n", &pstu->num, &pstu->name, &pstu->sex,
			&pstu->english, &pstu->math, &pstu->all);
		pstu->all = (pstu->english + pstu->math);
		//每次从学生信息链表的头部插入;
		pstu->next = student_list->next;
		student_list->next = pstu;
	}
	fclose(pfile);
	return 1;
}

//依据学号或姓名进行查询
//search num
void search_num(int num)
{
	student_info *pstu;
	pstu = student_list->next;
	while (pstu  && pstu->num != num)
	{
		pstu = pstu->next;
	}
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
		pstu->english, pstu->math, pstu->all);
	stufinish();
}
//search name
void search_name(int name)
{
	student_info *pstu;
	pstu = student_list->next;
	while (pstu  && pstu->name != name)
	{
		pstu = pstu->next;
	}
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
		pstu->english, pstu->math, pstu->all);
	stufinish();
}

//英语或数学的不及格人数
//英语不及格
void faile()
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL) {
		if (pstu->english < 60) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("英语共%d人挂科.\n", n);

}
//数学不及格
void failm()
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL) {
		if (pstu->math < 60) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}
	stufinish();
	mimihao();
	printf("数学共%d人挂科.\n", n);

}

//总分或数学或英语比我高的
//总分比我高
void compareA(int grade)
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL) {
		if (pstu->all > grade) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("共%d人总分比我高.\n", n);
}
//英语比我高
void compareE(int grade)
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL) {
		if (pstu->english > grade) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("共%d人英语比我高.\n", n);
}
//数学比我高
void compareM(int grade)
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL) {
		if (pstu->math > grade) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("共%d人数学比我高.\n", n);
}

//按总分或英语或数学降序排序
void sortA()
{
	student_info *pstu;
	pstu = student_list->next;
	student_info *r;
	student_info *s;
	student_info q;//用以中转数据
	int tempnum;
	int tempname;
	int tempsex;
	int tempall;
	int tempe;
	int tempm;
	int tempscore1;
	int tempscore2;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL)
	{
		s = pstu;
		r = pstu->next;
		while (r != NULL)
		{
			tempscore1 = s->all;
			tempscore2 = r->all;
			if (tempscore2 < tempscore1)
			{
				s = r;//一趟循环过后s最终指向单链表中的最值
			}
			r = r->next;

		}
		if (s != pstu)
		{
			q = (*pstu);//交换数据
			tempnum = s->num; pstu->num = tempnum;
			tempname = s->name; pstu->name = tempname;
			tempsex = s->sex; pstu->sex = tempsex;
			tempall = s->all; pstu->all = tempall;
			tempe = s->english; pstu->english = tempe;
			tempm = s->math; pstu->math = tempm;

			tempnum = q.num; s->num = tempnum;
			tempname = q.name; s->name = tempname;
			tempsex = q.sex; s->sex = tempsex;
			tempall = q.all; s->all = tempall;
			tempe = q.english; s->english = tempe;
			tempm = q.math; s->math = tempm;

		}//p与s的数据项全部调换
		printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
			pstu->english, pstu->math, pstu->all);
		pstu = pstu->next;
	}stufinish();

}
void sortE()
{
	student_info *pstu;
	pstu = student_list->next;
	student_info *r;
	student_info *s;
	student_info q;//用以中转数据
	int tempnum;
	int tempname;
	int tempsex;
	int tempall;
	int tempe;
	int tempm;
	int tempscore1;
	int tempscore2;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL)
	{
		s = pstu;
		r = pstu->next;
		while (r != NULL)
		{
			tempscore1 = s->english;
			tempscore2 = r->english;
			if (tempscore2 < tempscore1)
			{
				s = r;//一趟循环过后s最终指向单链表中的最值
			}
			r = r->next;

		}
		if (s != pstu)
		{
			q = (*pstu);//交换数据
			tempnum = s->num; pstu->num = tempnum;
			tempname = s->name; pstu->name = tempname;
			tempsex = s->sex; pstu->sex = tempsex;
			tempall = s->all; pstu->all = tempall;
			tempe = s->english; pstu->english = tempe;
			tempm = s->math; pstu->math = tempm;

			tempnum = q.num; s->num = tempnum;
			tempname = q.name; s->name = tempname;
			tempsex = q.sex; s->sex = tempsex;
			tempall = q.all; s->all = tempall;
			tempe = q.english; s->english = tempe;
			tempm = q.math; s->math = tempm;

		}//p与s的数据项全部调换
		printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
			pstu->english, pstu->math, pstu->all);
		pstu = pstu->next;
	}
	stufinish();

}
void sortM()
{
	student_info *pstu;
	pstu = student_list->next;
	student_info *r;
	student_info *s;
	student_info q;//用以中转数据
	int tempnum;
	int tempname;
	int tempsex;
	int tempall;
	int tempe;
	int tempm;
	int tempscore1;
	int tempscore2;
	stustart();
	printf("学号\t姓名\t性别\t英语\t数学\t总分\n");
	while (pstu != NULL)
	{
		s = pstu;
		r = pstu->next;
		while (r != NULL)
		{
			tempscore1 = s->math;
			tempscore2 = r->math;
			if (tempscore2 < tempscore1)
			{
				s = r;//一趟循环过后s最终指向单链表中的最值
			}
			r = r->next;

		}
		if (s != pstu)
		{
			q = (*pstu);//交换数据
			tempnum = s->num; pstu->num = tempnum;
			tempname = s->name; pstu->name = tempname;
			tempsex = s->sex; pstu->sex = tempsex;
			tempall = s->all; pstu->all = tempall;
			tempe = s->english; pstu->english = tempe;
			tempm = s->math; pstu->math = tempm;

			tempnum = q.num; s->num = tempnum;
			tempname = q.name; s->name = tempname;
			tempsex = q.sex; s->sex = tempsex;
			tempall = q.all; s->all = tempall;
			tempe = q.english; s->english = tempe;
			tempm = q.math; s->math = tempm;

		}//p与s的数据项全部调换
		printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
			pstu->english, pstu->math, pstu->all);
		pstu = pstu->next;
	}
	stufinish();
}


