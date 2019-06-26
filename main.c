#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/*stuMangerMenu ���*/
void stuMangerMenu();
void stuMenu();
void teaMenu();
void firstteaMenu();
void firststuMenu();

//ѧ����Ϣ����
student_info* student_list;


int main()
{
	init_student_info_list();
	if (read_file())
	{
		mimihao();
		printf("���ļ��ж�ȡѧ����Ϣ�ɹ�.\n");
	}
	else
	{
		error();
		printf("�������ж�ȡѧ����Ϣʧ��.\n");
	}
	stuMangerMenu();

}




/*�����ӭ��ѧ������ϵͳ���ѡ��*/
void stuMangerMenu() {
	int n;

	printf("\n");
	printShortStar();
	printf("��ӭ����ѧ������ϵͳ");
	printShortStar();
	printf("\n");

	printItemS();
	printf("Made with LOVE by 102-��������");

	printItemS();
	printf("�����ϵͳ��������,ֻ��3�λ���");

	printf("\n");
	printItemF();
	printShortLine();
	printItemF();
	printf("1.��ʦ���");
	printItemF();
	printf("2.ѧ�����");
	printItemF();
	printf("3.�˳�");
	printItemF();
	printShortLine();
	printf("\n");
	printDividerStar();

	Guide();
	printf("��ѡ��");
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
		printf("����������1~3");
	}

	}

}

//��ʦ�������¼����
void firstteaMenu()
{
	//��¼����������
	int trypasswordCount = 3;
	int n;
	char username0[10], password0[10], username[10] = "admin", password[10] = "123456";
	for (n = 1; n <= trypasswordCount; n++) {
		guide();
		printf("�������¼�˺ţ�");
		scanf("%s", &username0);
		guide();
		printf("�������¼���룡");
		scanf("%s", &password0);
		if ((strcmp(password, password0) == 0) && (strcmp(username, username0) == 0)) {
			teaMenu();
			break;
		}
		else {
			error();
			printf("�˺Ż���������㻹��%d�λ���\n", trypasswordCount - n);
		}

	}
}

//ѧ���������¼����
void firststuMenu()
{
	//��¼����������
	int trypasswordCount = 3;
	int n;
	char username0[10], password0[10], username[10] = "test0", password[10] = "123456";
	for (n = 1; n <= trypasswordCount; n++) {
		guide();
		printf("�������¼�˺ţ�");
		scanf("%s", &username0);
		guide();
		printf("�������¼���룡");
		scanf("%s", &password0);
		if ((strcmp(password, password0) == 0) && (strcmp(username, username0) == 0)) {
			stuMenu();
			break;
		}
		else {
			error();
			printf("�˺Ż���������㻹��%d�λ���\n", trypasswordCount - n);
		}

	}
}

/*����Ա����*/
void teaMenu() {
	int n;
	int m;
	int num;
	printf("\n");
	printShortStar();
	printf("��ӭ�������Ա�Ľ���");
	printShortStar();
	printf("\n");

	printItemS();
	printf("Welcome,admin!");


	printf("\n");
	printItemF();
	printShortLine();
	printItemF();
	printf("1.�鿴ѧ����Ϣ.");
	printItemF();
	printf("2.���ѧ����Ϣ.");
	printItemF();
	printf("3.ɾ��ѧ����Ϣ.");
	printItemF();
	printf("4.�޸�ѧ����Ϣ.");
	printItemF();
	printf("5.ͳ��������Ů���ֵܷ�ƽ����.");
	printItemF();
	printf("6.��ѧ���ɼ����������浽 D:\\chengji.txt �ĵ���.");
	printItemF();
	printf("7.����ѧ����Ϣ.");
	printItemF();
	printf("8.ͳ�Ƶ��Ʋ�����ѧ����Ϣ�ͳɼ�.");
	printItemF();
	printf("0.�˳�ϵͳ����.");
	printItemF();
	printShortLine();
	printf("\n");

	printDividerStar();
	while (1)
	{
		Guide();
		printf("��ѡ�����: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
				display_student_info();
			break;
		case 2:
			if (add_student_info())
			{
				mimihao();
				printf("���ѧ����Ϣ�ɹ�.\n");
			}
			else
			{
				error();
				printf("���ѧ����Ϣʧ��.\n");
			}
			break;
		case 3:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
			{
				guide();
				printf("������Ҫɾ��ѧ����Ϣ��ѧ��: ");
				scanf("%d", &num);
				if (delete_student_info(num))
				{
					mimihao();
					printf("�ɹ�ɾ����ѧ�Ŷ�Ӧ��ѧ����Ϣ.\n");
				}
				else
				{
					error();
					printf("ɾ��ʧ��.\n");
				}
			}
			break;
		case 4:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
			{
				guide();
				printf("������Ҫ�޸�ѧ����Ϣ��ѧ��: ");
				scanf("%d", &num);
				if (modify_student_info(num))
				{
					mimihao();
					printf("�ɹ��޸ĸ�ѧ�Ŷ�Ӧ��ѧ����Ϣ.\n");
				}
				else
				{
					error();
					printf("�޸�ʧ��.\n");
				}
			}
			break;
		case 5:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
				display_average();
			break;
		case 6:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
				if (save_file())
				{
					mimihao();
					printf("����ѧ����Ϣ�ɹ�.\n");
				}
				else {
					error();
					printf("����ѧ����Ϣʧ��.\n");
				}
			break;
		case 7:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
			{
				line4();
				printf("1.���ֽܷ�������. 2.��Ӣ�ｵ������. 3.����ѧ��������.\n");
				line4();
				Guide();
				printf("��ѡ��");
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
					printf("�밴��ʾҪ�����.\n");
				}
			}
			break;
		case 8:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
			{
				line2();
				printf("\t1.Ӣ�ﲻ����. 2.����������.\n");
				line2();
				Guide();
				printf("��ѡ��");
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
					printf("�밴��ʾҪ�����.\n");
				}
			}
			break;
		case 0:
			mimihao();
			printf("��ӭ�´�ʹ��,�ټ�.\n");
			system("pause");
			exit(0);
			break;
		default:
			error();
			printf("�������������ѡ�����.\n");
		}
	}
	system("pause");
	return 0;


}

/*ѧ������*/
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
	printf("��ӭ����ѧ���ǽ���");
	printShortStar();
	printf("\n");

	printItemS();
	printf("Welcome,student!");


	printf("\n");
	printItemF();
	printShortLine();
	printItemF();
	printf("1.��ѯѧ����Ϣ�ͳɼ���");
	printItemF();
	printf("2.ͳ�Ƴ��ֻܷ򵥿ƿƱ��Լ������ߵ�ѧ����Ϣ�ͳɼ���");
	printItemF();
	printf("0.�˳�ϵͳ������");
	printItemF();
	printShortLine();
	printf("\n");

	printDividerStar();

	while (1)
	{
		Guide();
		printf("��ѡ�����: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
			{
				line3();
				printf("1.��ѧ�Ų�ѯ. 2.��������ѯ.\n");
				line3();
				Guide();
				printf("��ѡ�������");
				scanf("%d", &m);
				switch (m)
				{
				case 1:
					guide();
					printf("���������ѧ�ţ�");
					scanf("%d", &num);
					search_num(num);
					break;
				case 2:
					guide();
					printf("���������������");
					scanf("%d", &name);
					search_name(name);
					break;
				default:error();
					printf("�밴��ʾҪ�����.\n");
				}
			}
			break;
		case 2:
			if (student_list_empty())
			{
				error();
				printf("ѧ����Ϣ��Ϊ�գ��������ѧ����Ϣ.\n");
			}
			else
			{
				line2();
				printf("1.�ֱܷ��Ҹ�. 2.Ӣ����Ҹ�. 3.��ѧ���Ҹ�.\n");
				line2();
				Guide();
				printf("��ѡ�������");
				scanf("%d", &m);
				switch (m)
				{
				case 1:
					guide();
					printf("����������ܷ֣�");
					scanf("%d", &all);
					compareA(all);
					break;
				case 2:
					guide();
					printf("���������Ӣ�");
					scanf("%d", &english);
					compareE(english);
					break;
				case 3:
					guide();
					printf("��������ĸ�����");
					scanf("%d", &math);
					compareM(math);
					break;
				default:
					error();
					printf("�밴��ʾҪ�����.\n");
				}
			}
			break;
		case 0:
			mimihao();
			printf("��ӭ�´�ʹ��,�ټ�.\n");
			system("pause");
			exit(0);
			break;
		default:
			error();
			printf("�������������ѡ�����.\n");
		}
	}
	system("pause");
	return 0;
}
