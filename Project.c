#include <stdio.h>
#include <string.h>

#define SIZE 5

char buffer[SIZE][50]; // لتخزين نصوص
int front = -1, rear = -1;

// التحقق من الامتلاء
int isFull() {
    return (rear + 1) % SIZE == front;
}

// التحقق من الفراغ
int isEmpty() {
    return front == -1;
}

// إدخال
void enqueue(char data[]) {
    if (isFull()) {
        printf("Overflow!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    strcpy(buffer[rear], data);
}

// إخراج
void dequeue() {
    if (isEmpty()) {
        printf("Underflow!\n");
        return;
    }

    printf("Removed: %s\n", buffer[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

int main() {
    char name[50];

    // إدخال الاسم
    printf("Enter your name: ");
    scanf("%s", name);

    // إضافة CE-ESY
    strcat(name, "CE-ESY");

    // تخزين في المخزن
    enqueue(name);

    // قراءة البيانات
    dequeue();

    // تأكيد أن المخزن فارغ
    if (isEmpty()) {
        printf("Buffer is now empty.\n");
    }

    return 0;
}
