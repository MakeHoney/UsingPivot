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

member_t* buffer[100001];


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
	int nMember;			
	member_t ** members;	

	scanf("%d", &nMember);

	members = malloc(sizeof(member_t*) * nMember);

	for (int i = 0; i < nMember; i += 1) { 
		member_t* newMember = malloc(sizeof(member_t));
		scanf("%s %s %d", newMember->name, newMember->phoneNumber, &newMember->age);
		members[i] = newMember;
	}

	sort_member(members, 0, nMember - 1);

	for (int i = 0; i < nMember; i += 1)
		printf("%-20s %13s %3d\n", members[i]->name, members[i]->phoneNumber, members[i]->age);

	for (int i = 0; i < nMember; i += 1)
		free(members[i]);

	free(members);
	return 0;
}