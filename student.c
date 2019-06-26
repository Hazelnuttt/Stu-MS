#include "main.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//��ʼ��ѧ����Ϣ����
void init_student_info_list()
{
	//ѧ����Ϣ����ͷ���
	student_list = (student_info*)malloc(sizeof(student_info));
	student_list->next = NULL;
}
//�ж�ѧ����Ϣ�����Ƿ�Ϊ��
int student_list_empty()
{
	return student_list->next == NULL;
}

//���ѧ����Ϣ��¼
int add_student_info()
{
	student_info *pstu = (student_info*)malloc(sizeof(student_info));
	if (pstu == NULL)
	{
		error();
		printf("�ڴ����ʧ��.\n");
		return 0;
	}
	mimihao();
	printf("�밴Ҫ��һ������ѧ������Ϣ.\n");
	guide();
	printf("������ѧ��: ");
	scanf("%d", &pstu->num);
	//�жϸ�ѧ���Ƿ��Ѿ�����
	if (search_student_info(pstu->num) != NULL)
	{
		error();
		printf("��ѧ���Ѿ�����ѧ����Ϣ����.\n");
		return 0;
	}
	guide();
	printf("����������: ");
	scanf("%d", &pstu->name);
	guide();
	printf("�������Ա�: ");
	scanf("%d", &pstu->sex);
	guide();
	printf("����������ɼ�: ");
	scanf("%d", &pstu->math);
	guide();
	printf("������Ӣ��ɼ�: ");
	scanf("%d", &pstu->english);

	pstu->all = pstu->english + pstu->math;
	//ÿ�δ�ѧ����Ϣ�����ͷ������;
	pstu->next = student_list->next;
	student_list->next = pstu;
	return 1;
}

//����ѧ��ɾ��ѧ����Ϣ
int delete_student_info(int num)
{
	student_info *pstu;
	student_info *qstu;
	if (search_student_info(num) == NULL)
	{
		error();
		printf("�����ڸ�ѧ��Ϊ%d��ѧ����Ϣ.\n", num);
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

//����ѧ���޸�ѧ����Ϣ
int modify_student_info(int num)
{
	int choice;
	student_info *pstu = search_student_info(num);
	if (pstu == NULL)
	{
		error();
		printf("�����ڸ�ѧ��Ϊ%d��ѧ����Ϣ.\n", num);
		return 0;
	}
	line2();
	printf("1.���� 2.�Ա� 3.Ӣ��ɼ� 4.��ѧ�ɼ� 5.�ܷ�.\n");
	line2();
	Guide();
	printf("��ѡ���޸ĵ���Ϣ: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		guide();
		printf("�������µ�����: ");
		scanf("%d", &pstu->name);
		break;
	case 2:
		guide();
		printf("�������µ��Ա�: ");
		scanf("%d", &pstu->sex);
		break;
	case 3:
		guide();
		printf("�������µ�Ӣ��ɼ�: ");
		scanf("%d", &pstu->english);
		break;
	case 4:
		guide();
		printf("�������µ���ѧ�ɼ�: ");
		scanf("%d", &pstu->math);
		break;
	case 5:
		guide();
		printf("�������µ��ܷ�: ");
		scanf("%d", &pstu->all);
		break;
	default:
		error();
		printf("�밴��ʾҪ�����.\n");
	}
	return 1;
}

//����ѧ�Ų���ѧ����Ϣ
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

//����ƽ����
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
	printf("�����ֵܷ�ƽ����Ϊ%4d\n", average);
}
//Ů��ƽ����
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
	printf("Ů���ֵܷ�ƽ����Ϊ%4d\n", average);
}
//���������Ů����ƽ���ɼ�
void display_average()
{
	int choice;
	line1();
	printf("\t1.���� 2.Ů��\n");
	line1();
	Guide();
	printf("��ѡ��: ");
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
		printf("�밴��ʾҪ�����.\n");
	}
	return 1;
}

//��ʾ����ѧ����Ϣ
void display_student_info()
{
	student_info *pstu;
	pstu = student_list->next;
	mimihao();
	printf("����ѧ����Ϣ������ʾ.\n");
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
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

//��ѧ����Ϣ���浽�ļ�
int save_file()
{
	FILE *pfile;
	student_info *pstu;
	pfile = fopen("student.txt", "w");
	if (pfile == NULL)
	{
		error();
		printf("���ļ�ʧ��.\n");
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

//���ļ��ж�ȡѧ����Ϣ
int read_file()
{
	FILE *pfile;
	student_info *pstu;
	pfile = fopen("student.txt", "r");
	if (pfile == NULL)
	{
		error();
		printf("���ļ�ʧ��.\n");
		return 0;
	}
	while (!feof(pfile))
	{
		pstu = (student_info*)malloc(sizeof(student_info));
		fscanf(pfile, "%d%6d%7d%9d%9d%9d\n", &pstu->num, &pstu->name, &pstu->sex,
			&pstu->english, &pstu->math, &pstu->all);
		pstu->all = (pstu->english + pstu->math);
		//ÿ�δ�ѧ����Ϣ�����ͷ������;
		pstu->next = student_list->next;
		student_list->next = pstu;
	}
	fclose(pfile);
	return 1;
}

//����ѧ�Ż��������в�ѯ
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
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
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
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
	printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
		pstu->english, pstu->math, pstu->all);
	stufinish();
}

//Ӣ�����ѧ�Ĳ���������
//Ӣ�ﲻ����
void faile()
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
	while (pstu != NULL) {
		if (pstu->english < 60) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("Ӣ�ﹲ%d�˹ҿ�.\n", n);

}
//��ѧ������
void failm()
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
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
	printf("��ѧ��%d�˹ҿ�.\n", n);

}

//�ֻܷ���ѧ��Ӣ����Ҹߵ�
//�ֱܷ��Ҹ�
void compareA(int grade)
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
	while (pstu != NULL) {
		if (pstu->all > grade) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("��%d���ֱܷ��Ҹ�.\n", n);
}
//Ӣ����Ҹ�
void compareE(int grade)
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
	while (pstu != NULL) {
		if (pstu->english > grade) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("��%d��Ӣ����Ҹ�.\n", n);
}
//��ѧ���Ҹ�
void compareM(int grade)
{
	int n = 0;
	student_info *pstu;
	pstu = student_list->next;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
	while (pstu != NULL) {
		if (pstu->math > grade) {
			n++;
			printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
				pstu->english, pstu->math, pstu->all);
		}
		pstu = pstu->next;
	}stufinish();
	mimihao();
	printf("��%d����ѧ���Ҹ�.\n", n);
}

//���ֻܷ�Ӣ�����ѧ��������
void sortA()
{
	student_info *pstu;
	pstu = student_list->next;
	student_info *r;
	student_info *s;
	student_info q;//������ת����
	int tempnum;
	int tempname;
	int tempsex;
	int tempall;
	int tempe;
	int tempm;
	int tempscore1;
	int tempscore2;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
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
				s = r;//һ��ѭ������s����ָ�������е���ֵ
			}
			r = r->next;

		}
		if (s != pstu)
		{
			q = (*pstu);//��������
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

		}//p��s��������ȫ������
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
	student_info q;//������ת����
	int tempnum;
	int tempname;
	int tempsex;
	int tempall;
	int tempe;
	int tempm;
	int tempscore1;
	int tempscore2;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
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
				s = r;//һ��ѭ������s����ָ�������е���ֵ
			}
			r = r->next;

		}
		if (s != pstu)
		{
			q = (*pstu);//��������
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

		}//p��s��������ȫ������
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
	student_info q;//������ת����
	int tempnum;
	int tempname;
	int tempsex;
	int tempall;
	int tempe;
	int tempm;
	int tempscore1;
	int tempscore2;
	stustart();
	printf("ѧ��\t����\t�Ա�\tӢ��\t��ѧ\t�ܷ�\n");
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
				s = r;//һ��ѭ������s����ָ�������е���ֵ
			}
			r = r->next;

		}
		if (s != pstu)
		{
			q = (*pstu);//��������
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

		}//p��s��������ȫ������
		printf("%d%6d%7d%9d%9d%9d\n", pstu->num, pstu->name, pstu->sex,
			pstu->english, pstu->math, pstu->all);
		pstu = pstu->next;
	}
	stufinish();
}


