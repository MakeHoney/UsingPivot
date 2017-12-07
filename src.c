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
	member_t* pivot = (member_t*)malloc(sizeof(member_t));
	strcpy(pivot->name, members[left]->name);
	strcpy(pivot->phoneNumber, members[left]->phoneNumber);

	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (membercmp(pivot, members[low]) >= 0 && low <= right) {
			low++;
			if (low > right)
				break;
		}
		while (membercmp(pivot, members[high]) <= 0 && high >= (left + 1)) {
			high--;
			if (high < left + 1)
				break;
		}
		if (low <= high)
			Swap(members, low, high);
	}

	Swap(members, left, high);
	return high;
}

void sort_member(member_t ** members, int left, int right)
{
	if (left <= right) {
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