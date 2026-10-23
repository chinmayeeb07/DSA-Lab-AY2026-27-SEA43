//Chinmayee Bakshi
//Roll No. SEA43
//"Train Ticket Booking System Using Circular Queue”
#include <stdio.h>
#include <string.h>

#define MAX 2

char confirm[MAX][10], wait[MAX][10];
int c = 0;
int front = 0, rear = -1;
int count = 0;

void book()
{
char name[10];

printf("Enter name: ");
scanf("%s", name);

if (c < MAX)
{
strcpy(confirm[c], name);
c++;
printf("Ticket Confirmed!\n");
}
else
{
if (count == MAX)
{
printf("Waiting List Full!\n");
return;
}

rear = (rear + 1) % MAX;
strcpy(wait[rear], name);
count++;

printf("Added to Waiting List.\n");
}
}

void cancel()
{
int n, i;

printf("Enter confirmed ticket number to cancel (1-5): ");
scanf("%d", &n);

if (n < 1 || n > c)
{
printf("Invalid ticket number!\n");
return;
}

printf("Ticket Cancelled: %s\n", confirm[n - 1]);


for (i = n - 1; i < c - 1; i++)
strcpy(confirm[i], confirm[i + 1]);

c--;


if (count > 0)
{
strcpy(confirm[c], wait[front]);

printf("%s got the confirmed ticket.\n", wait[front]);

front = (front + 1) % MAX;
count++;
count--;
c++;
}
}

void display()
{
int i, x;

printf("\nConfirmed Tickets:\n");

for (i = 0; i < c; i++)
printf("%d. %s\n", i + 1, confirm[i]);

printf("\nWaiting List:\n");

x = front;

for (i = 0; i < count; i++)
{
printf("%s\n", wait[x]);
x = (x + 1) % MAX;
}
}

int main()
{
int choice;

while (1)
{
printf("\n1. Book Ticket");
printf("\n2. Cancel Ticket");
printf("\n3. Display");
printf("\n4. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);

if (choice == 1)
book();

else if (choice == 2)
cancel();

else if (choice == 3)
display();

else if (choice == 4)
break;

else
printf("Invalid Choice!\n");
}

return 0;

