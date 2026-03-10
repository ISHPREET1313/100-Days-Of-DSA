/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty())
        return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front--;
    }

    dq[front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}

void pop_front() {
    if (empty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Removed element: %d\n", dq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (empty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Removed element: %d\n", dq[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int get_front() {
    if (empty())
        return -1;
    return dq[front];
}

int get_back() {
    if (empty())
        return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
    printf("Deque cleared\n");
}

void reverse() {
    if (empty()) return;

    int i = front, j = rear;
    while (i < j) {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++;
        j--;
    }

    printf("Deque reversed\n");
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (dq[i] > dq[j]) {
                int t = dq[i];
                dq[i] = dq[j];
                dq[j] = t;
            }
        }
    }

    printf("Deque sorted\n");
}

void display() {
    if (empty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Get Front\n");
        printf("6. Get Back\n");
        printf("7. Check Empty\n");
        printf("8. Size\n");
        printf("9. Clear\n");
        printf("10. Reverse\n");
        printf("11. Sort\n");
        printf("12. Display\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &x);
            push_front(x);
            break;

        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &x);
            push_back(x);
            break;

        case 3:
            pop_front();
            break;

        case 4:
            pop_back();
            break;

        case 5:
            printf("Front element: %d\n", get_front());
            break;

        case 6:
            printf("Rear element: %d\n", get_back());
            break;

        case 7:
            if (empty())
                printf("Deque is Empty\n");
            else
                printf("Deque is Not Empty\n");
            break;

        case 8:
            printf("Size of deque: %d\n", size());
            break;

        case 9:
            clear();
            break;

        case 10:
            reverse();
            break;

        case 11:
            sort();
            break;

        case 12:
            display();
            break;

        case 0:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}