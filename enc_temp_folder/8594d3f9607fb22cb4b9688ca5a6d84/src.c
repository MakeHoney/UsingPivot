#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int age;
	char name[21];
	char phoneNumber[15];
} member_t;

member_t* buffer[100001]; //use this buffer if you need :D


void Swap(member_t** members, int idx1, int idx2) {
	buffer[idx1] = members[idx1];
	members[idx1] = members[idx2];
	members[idx2] = buffer[idx1];
}

int membercmp(const member_t * m1, const member_t * m2)
{
	if (!strcmp(m1->name, m2->name)) {
		if (!strcmp(m1->phoneNumber, m2->phoneNumber))
			return 0;
		else if (strcmp(m1->phoneNumber, m2->phoneNumber) > 0)
			return 1;
		else
			return -1;
	}
	else if (strcmp(m1->name, m2->name) > 0)
		return 1;
	else
		return -1;
}

int Partition(member_t** members, int left, int right) {
	char pivot[21];
	strcpy(pivot, members[left]->name);
	int low = left + 1;
	int high = right;
	printf("%s\n", members[high]->name);
	while (low <= high) {
		printf("cc");
		while (strcmp(pivot, members[low]->name) >= 0 && low <= right) {
			printf("dd");
			low++;
		}
		while (strcmp(pivot, members[high]->name) <= 0 && high >= (left + 1)) {
			printf("ee");
			high--;
		}
		printf("akjkljkljkljkljklklaa\n");
		if (low <= high)
			Swap(members, low, high);
		printf("flag\n");
	}

	Swap(members, left, high);
	return high;
}

void sort_member(member_t ** members, int left, int right)
{
	if (left <= right) {
		printf("bb");
		int pivotIdx = Partition(members, left, right);
		sort_member(members, left, pivotIdx - 1);
		sort_member(members, pivotIdx + 1, right);
	}
}



int main()
{
	int nMember;			//관리 할 멤버의 수 
	member_t ** members;	//관리 할 멤버 객체 포인터를 저장할 배열의 포인터

							//멤버 수를 입력받는다 
	scanf("%d", &nMember);

	//멤버 정보들을 저장할 배열을 동적할당한다
	members = malloc(sizeof(member_t*) * nMember);

	//각 멤버를 차례로 입력받는다
	for (int i = 0; i < nMember; i += 1)
	{
		//이번 멤버의 정보를 저장할 객체를 동적할당하여 만든다 
		member_t* newMember = malloc(sizeof(member_t));

		//해당 멤버의 정보를 입력받는다
		scanf("%s %s %d", newMember->name, newMember->phoneNumber, &newMember->age);

		//배열의 i번째 원소에 해당 멤버의 정보를 대입한다
		members[i] = newMember;
	}

	//각 멤버의 정보를 주어진 정렬 기준에 따라 정렬한다
	sort_member(members, 0, nMember - 1);

	//정렬된 멤버의 정보를 차례로 출력한다
	for (int i = 0; i < nMember; i += 1)
	{
		printf("%-20s %13s %3d\n", members[i]->name, members[i]->phoneNumber, members[i]->age);
	}

	//멤버의 정보를 저장했던 각 객체를 할당 해제한다
	for (int i = 0; i < nMember; i += 1)
	{
		free(members[i]);
	}

	//배열을 할당 해제한다
	free(members);
	return 0;
}