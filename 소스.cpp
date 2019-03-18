#include <stdio.h>
#include <string.h>

#define max 25
#define min 20

int n;
char address[max][2][min] = {	//�ּҷ� ������ 5�� �ִ°ɷ� �ʱ�ȭ�Ѵ�
	"����","011-111-1111",
	"����","017-111-1111",
	"���","016-111-1111",
	"���ڷ�","011-777-7777",
	"������","019-111-1111",
};
int addr_add();
int addr_help();
int addr_name_sort();
int addr_number_sort();
int addr_list();
int addr_name_search();
int addr_number_search();
int addr_name_delete();

// �� ���� �Լ����� �� �Լ��� ���� �Է¹��� ������ �����ϴ� �����Դϴ�
int main()
{
	char cmd[20];

	printf("My adress program\n");
	while (1)
	{
		printf("Enter any command (help to show commands) : ");
		gets_s(cmd);

		if (!strcmp(cmd, "quit"))
		{
			printf("Have a nice day..\n");
			break;
		}
		else if (!strcmp(cmd, "help"))
			addr_help();
		else if (!strcmp(cmd, "name sort"))
			addr_name_sort();
		else if (!strcmp(cmd, "number sort"))
			addr_number_sort();
		else if (!strcmp(cmd, "list"))
			addr_list();
		else if (!strcmp(cmd, "add"))
			addr_add();
		else if (!strcmp(cmd, "name search"))
			addr_name_search();
		else if (!strcmp(cmd, "number search"))
			addr_number_search();
		else if (!strcmp(cmd, "delete"))
			addr_name_delete();
		else
		{
			printf("�߸��� ��ɾ��Դϴ�\n");
			addr_help();
		}
	}
}

//�߰� ������ �Է��ϱ� ������ 25�� �Է��� ������ 5���� �̹� �ʱ�ȭ�Ǿ� �ֱ� ������ �Է¹޴� ���� n�� 20������ �޴´�
int addr_add()
{

	printf("�߰��� �������� ���� �Է��ϼ���:");
	scanf_s("%d", &n);

	if (n <= 20)
	{
		for (int i = 0; i < n; i++)
		{
			// �ʱ�ȭ 5���� �Ǿ��ֱ� ������ �迭�� 6��° �Լ����� �Է¹޴´�
			printf("�̸��� �Է��ϼ���.");
			scanf_s("%s", address[i + 5][0], sizeof(address[i + 5][0]));
			printf("��ȣ�� �Է��ϼ���.");
			scanf_s("%s", address[i + 5][1], sizeof(address[i + 5][1]));

			printf("\t�߰��� ��ȭ��ȣ ���\n");

			printf("\t%-10s %-10s \n", address[i + 5][0], address[i + 5][1]);
		}
		n++;
	}
	else
		//������ �Ѿ��ٰ� ǥ�����ֱ�
		printf("20���� �Ѿ����ϴ�\n");

	return 0;
}
//���� ����ϱ�
int addr_help()
{
	printf("COMMAND LISTS\n");


	printf("-------------------------------------------------------------------------\n");
	int i;
	char input[20];
	char help[6][2][45] = { //���� ������ 6���� �� �ֻ��� �迭�� 6���� ��´� 
			"help : ","show commands list",
			"list : ","show all names with phone numbers",
			"sort : ","sort entries according to names",
			"add : ","add new friend's name and phone number",
			"search : ","search phone number using friend's name",
			"quit : ","quit this program"
	};
	for (i = 0; i < 6; i++)
	{
		if (!strcmp(input, help[i][0]) == 0)
		{
			printf("\t%-10s %-10s\n", help[i][0], help[i][1]);
		}
	}

	printf("-------------------------------------------------------------------------\n");

	return 0;
}
//�̸� ��ȯ�ϱ� �Լ�
int addr_name_sort()
{
	char temp[20];
	
	printf("-------------------------------------------------------------------------\n");

	for (int i = 0; i < 4; i++)//�ʱ�ȭ �� ������ �迭�� 0���� 4������ ��Ÿ�������� �ʱ�ȭ �迭 ���� ������̴�
	{
		for (int j = 0; j < 4; j++)
		{
			if (!strcmp(address[j][0], address[j+1][0]) == 0)
			{
				strcpy_s(temp, address[j][0]);//���� temp��� ĳ������ �迭�� �����ϰ� temp�� ù��° �̸� ������ 
				strcpy_s(address[j][0], address[j+1][0]);//���� �迭���� ���� ������ �� ���� �迭�� �����迭�� �־��ְ�
				strcpy_s(address[j+1][0], temp);//������ �迭�� �� �տ� ����� �迭�� �־� ������ �ٲ��ش�
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("\t %-10s \n", address[i][0]);
	}

	printf("-------------------------------------------------------------------------\n");

	return 0;
}
//��ȭ��ȣ ���� ���� �Լ�
int addr_number_sort()
{
	char temp[20];

	printf("-------------------------------------------------------------------------\n");

	for (int i = 0; i < 4; i++) //�ʱ�ȭ �� ������ �迭�� 0���� 4������ ��Ÿ�������� �ʱ�ȭ �迭 ���� ������̴�
	{
		for (int j = 0; j < 4; j++)
		{
			if (!strcmp(address[j][1], address[j + 1][1]) == 0)//�� �� �迭�� ���� �迭�� ��ġ ��,�ȿ� �ִ� ���� ���� ��
			{
				strcpy_s(temp, address[j][1]);//���� temp��� ĳ������ �迭�� �����ϰ� temp�� ù��° �̸� ������
				strcpy_s(address[j][1], address[j + 1][1]);//���� �迭���� ���� ������ �� ���� �迭�� �����迭�� �־��ְ�
				strcpy_s(address[j + 1][1], temp);//������ �迭�� �� �տ� ����� �迭�� �־� ������ �ٲ��ش�
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("\t %-10s \n", address[i][1]);
	}

	printf("-------------------------------------------------------------------------\n");

	return 0;
}
//����Ʈ ��� �Լ�
int addr_list()
{
	char input[20];
	int i;

	printf("-------------------------------------------------------------------------\n");
	for (i = 0; i < max; i++)
	{
		if (!strcmp(input, address[i][0]) == 0)//input�迭�� �Ҵ�޾� �ΰ��� �迭�� ���� ���� �ʴٸ� ����Ѵ� 
			printf("\t%-10s %-10s\n",address[i][0],address[i][1]);
	}
	printf("-------------------------------------------------------------------------\n");
	return 0;
}
//�̸� �˻��ϱ� �Լ�
int addr_name_search()
{
	char phone[max];

	printf("�̸� �Է�:");//phone�̶�� �迭�� ���� �� �ȿ� ���� �Է¹޴´�
	scanf_s("%s", phone, sizeof(phone));
	fflush(stdin);

	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < max; i++)
	{
		if (!strcmp(phone, address[i][0]))//���� phone�迭�� �Է��� ���� ���� �ִ� �迭�� ����� �ϳ��� ���� �� ����Ѵ�
			printf("�˻����: \t%-10s  %-10s �Դϴ�.\n", address[i][0], address[i][1]);
	}
	printf("-------------------------------------------------------------------------\n");

	return 0;
}
int addr_number_search()
{
	char phone[max];

	printf("��ȭ��ȣ �Է�:");
	scanf_s("%s", phone, sizeof(phone));
	fflush(stdin);

	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < max; i++)
	{
		if (!strcmp(phone, address[i][1]))
			printf("�˻����: \t%-10s  %-10s �Դϴ�.\n", address[i][0], address[i][1]);
	}
	printf("-------------------------------------------------------------------------\n");

	return 0;
}
//�̸����� �����ϴ� �Լ�
int addr_name_delete()
{
	char name[25];

	int count = 0;

	count = 5 + n;

	if (count > 0)
	{

		printf("������ �̸��� �Է��ϼ���:");
		scanf_s("%s", name, sizeof(name));//���ο� �迭�� �Է��� �� �ȿ� ������ ���� �Է��Ѵ�

		for (int i = 0; i < max; i++)
		{
			if (!strcmp(name, address[i][0]))//�Է��� ���� �迭�ȿ� ������ �ΰ��� �ְ� �� �� ������ �� ���� �Լ��� �ִ´�
			{
				count--;
				printf("�����Ͻ� �����Ͱ� �����Ǿ����ϴ�\n");
				if (i != max - 1)//�迭�� �������� �ʾҴٸ� �� �迭�� �ΰ��� �ְ� ���� �迭�� ���� �迭�� �̵��Ѵ�
				{
					for (int j = i; j < max; j++)
					{
						strcpy_s(address[j][0], address[j + 1][0]);
						strcpy_s(address[j][1], address[j + 1][1]);
					}
					*address[max - 1][0] = NULL;
					*address[max - 1][1] = NULL;
				}
				else  //�迭�� ���� á�ٸ� �� �������� �ִ� �迭�� �ΰ����� �����
				{
					*address[max - 1][0] = NULL;
					*address[max - 1][1] = NULL;
				}
				return 0;
			}
		}
	}
	else
		printf("���� �ּҷ� ������ �����ϴ�\n");

	return 0;
}