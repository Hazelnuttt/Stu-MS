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

//��ע�����������޷�׼ȷ��ȡ�ַ��������������ȫ����Ϊ����
typedef struct node /*����ṹ��*/
{
	int num; //ѧ��
	int name;//����
	int sex; //�Ա�
	int math; //��ѧ�ɼ�
	int english; //Ӣ��ɼ�
	int all; //�ܷ�
	struct node *next; //����ָ����
}student_info;

//ѧ����Ϣ����
extern student_info* student_list;  //ȫ�ֱ�������


//��ʼ��ѧ����Ϣ����
void init_student_info_list();
//�ж�ѧ����Ϣ�����Ƿ�Ϊ��
int student_list_empty();


//���ѧ����Ϣ��¼
int add_student_info();
//����ѧ��ɾ��ѧ����Ϣ
int delete_student_info(int num);
//����ѧ���޸�ѧ����Ϣ
int modify_student_info(int num);
//����ѧ�Ż���������ѧ����Ϣ
student_info* search_student_info(int num);
void search_num(int num);
void search_name(int name);
//���ÿ��ѧ����ƽ���ɼ�
void display_average();
//��ʾ����ѧ����Ϣ
void display_student_info();
//��ѧ����Ϣ���浽�ļ�
int save_file();
//���ļ��ж�ȡѧ����Ϣ
int read_file();
//������Ů����ƽ����
void average_man();
void average_woman();
//Ӣ�����ѧ�ҿƵ���
void faile();
void failm();
//�ֻܷ�Ӣ�����ѧ���Ҹߵ���
void compareA(int grade);
void compareE(int grade);
void compareM(int grade);
//���ֻܷ�Ӣ�����ѧ��������
void sortA();
void sortE();
void sortM();



