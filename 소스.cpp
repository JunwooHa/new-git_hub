#include <stdio.h>
#include <string.h>

#define max 25
#define min 20

int n;
char address[max][2][min] = {	//주소록 내용을 5개 있는걸로 초기화한다
	"유비","011-111-1111",
	"관우","017-111-1111",
	"장비","016-111-1111",
	"조자룡","011-777-7777",
	"제갈량","019-111-1111",
};
int addr_add();
int addr_help();
int addr_name_sort();
int addr_number_sort();
int addr_list();
int addr_name_search();
int addr_number_search();
int addr_name_delete();

// 이 메인 함수에는 각 함수로 부터 입력받은 내용을 실행하는 파일입니다
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
			printf("잘못된 명령어입니다\n");
			addr_help();
		}
	}
}

//추가 연락자 입력하기 원래는 25명 입력을 받으나 5명은 이미 초기화되어 있기 때문에 입력받는 변수 n을 20까지만 받는다
int addr_add()
{

	printf("추가할 연락자의 수를 입력하세요:");
	scanf_s("%d", &n);

	if (n <= 20)
	{
		for (int i = 0; i < n; i++)
		{
			// 초기화 5명이 되어있기 때문에 배열의 6번째 함수부터 입력받는다
			printf("이름을 입력하세요.");
			scanf_s("%s", address[i + 5][0], sizeof(address[i + 5][0]));
			printf("번호를 입력하세요.");
			scanf_s("%s", address[i + 5][1], sizeof(address[i + 5][1]));

			printf("\t추가된 전화번호 목록\n");

			printf("\t%-10s %-10s \n", address[i + 5][0], address[i + 5][1]);
		}
		n++;
	}
	else
		//넘으면 넘었다고 표시해주기
		printf("20명이 넘었습니다\n");

	return 0;
}
//도움말 출력하기
int addr_help()
{
	printf("COMMAND LISTS\n");


	printf("-------------------------------------------------------------------------\n");
	int i;
	char input[20];
	char help[6][2][45] = { //도움말 갯수가 6개니 맨 최상의 배열을 6으로 잡는다 
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
//이름 교환하기 함수
int addr_name_sort()
{
	char temp[20];
	
	printf("-------------------------------------------------------------------------\n");

	for (int i = 0; i < 4; i++)//초기화 된 상태의 배열은 0부터 4까지만 나타나있으니 초기화 배열 값에 맞춘것이다
	{
		for (int j = 0; j < 4; j++)
		{
			if (!strcmp(address[j][0], address[j+1][0]) == 0)
			{
				strcpy_s(temp, address[j][0]);//먼저 temp라는 캐릭터형 배열을 선언하고 temp에 첫번째 이름 내용을 
				strcpy_s(address[j][0], address[j+1][0]);//이전 배열에는 값이 없으니 그 다음 배열을 이전배열에 넣어주고
				strcpy_s(address[j+1][0], temp);//마지막 배열에 맨 앞에 저장된 배열을 넣어 순서를 바꿔준다
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
//전화번호 순서 변경 함수
int addr_number_sort()
{
	char temp[20];

	printf("-------------------------------------------------------------------------\n");

	for (int i = 0; i < 4; i++) //초기화 된 상태의 배열은 0부터 4까지만 나타나있으니 초기화 배열 값에 맞춘것이다
	{
		for (int j = 0; j < 4; j++)
		{
			if (!strcmp(address[j][1], address[j + 1][1]) == 0)//맨 앞 배열과 다음 배열의 위치 즉,안에 있는 값이 맞을 때
			{
				strcpy_s(temp, address[j][1]);//먼저 temp라는 캐릭터형 배열을 선언하고 temp에 첫번째 이름 내용을
				strcpy_s(address[j][1], address[j + 1][1]);//이전 배열에는 값이 없으니 그 다음 배열을 이전배열에 넣어주고
				strcpy_s(address[j + 1][1], temp);//마지막 배열에 맨 앞에 저장된 배열을 넣어 순서를 바꿔준다
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
//리스트 출력 함수
int addr_list()
{
	char input[20];
	int i;

	printf("-------------------------------------------------------------------------\n");
	for (i = 0; i < max; i++)
	{
		if (!strcmp(input, address[i][0]) == 0)//input배열을 할당받아 두개의 배열의 값이 맞지 않다면 출력한다 
			printf("\t%-10s %-10s\n",address[i][0],address[i][1]);
	}
	printf("-------------------------------------------------------------------------\n");
	return 0;
}
//이름 검색하기 함수
int addr_name_search()
{
	char phone[max];

	printf("이름 입력:");//phone이라는 배열을 만들어서 그 안에 값을 입력받는다
	scanf_s("%s", phone, sizeof(phone));
	fflush(stdin);

	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < max; i++)
	{
		if (!strcmp(phone, address[i][0]))//만약 phone배열의 입력한 값과 원래 있던 배열을 띄워서 하나라도 맞을 시 출력한다
			printf("검색결과: \t%-10s  %-10s 입니다.\n", address[i][0], address[i][1]);
	}
	printf("-------------------------------------------------------------------------\n");

	return 0;
}
int addr_number_search()
{
	char phone[max];

	printf("전화번호 입력:");
	scanf_s("%s", phone, sizeof(phone));
	fflush(stdin);

	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < max; i++)
	{
		if (!strcmp(phone, address[i][1]))
			printf("검색결과: \t%-10s  %-10s 입니다.\n", address[i][0], address[i][1]);
	}
	printf("-------------------------------------------------------------------------\n");

	return 0;
}
//이름으로 삭제하는 함수
int addr_name_delete()
{
	char name[25];

	int count = 0;

	count = 5 + n;

	if (count > 0)
	{

		printf("삭제할 이름을 입력하세요:");
		scanf_s("%s", name, sizeof(name));//새로운 배열을 입력해 그 안에 삭제할 값을 입력한다

		for (int i = 0; i < max; i++)
		{
			if (!strcmp(name, address[i][0]))//입력한 값이 배열안에 있으면 널값을 넣고 그 빈 공간에 그 다음 함수를 넣는다
			{
				count--;
				printf("선택하신 데이터가 삭제되었습니다\n");
				if (i != max - 1)//배열이 가득차지 않았다면 전 배열에 널값을 넣고 다음 배열을 이전 배열로 이동한다
				{
					for (int j = i; j < max; j++)
					{
						strcpy_s(address[j][0], address[j + 1][0]);
						strcpy_s(address[j][1], address[j + 1][1]);
					}
					*address[max - 1][0] = NULL;
					*address[max - 1][1] = NULL;
				}
				else  //배열이 가득 찼다면 맨 마지막에 있는 배열을 널값으로 만든다
				{
					*address[max - 1][0] = NULL;
					*address[max - 1][1] = NULL;
				}
				return 0;
			}
		}
	}
	else
		printf("남는 주소록 갯수가 없습니다\n");

	return 0;
}