//STACK WORKING UNDERSTANDING USING CODE 
#include <iostream>
using namespace std;
int stack[100], n=100, top=-1;

void push(int val) {
    if(top>=n-1)
        cout<<"Stack Overflow"<<endl;
    else {
        top++;
        stack[top]=val;
    }
}

void pop() {
    if(top<=-1)
        cout<<"Stack Underflow"<<endl;
    else {
        cout<<"The popped element is "<< stack[top] <<endl;
        top--;
    }
}

void display() {
    if(top>=0) {
        cout<<"Stack elements are:";
        for(int i=top; i>=0; i--)
            cout<<stack[i]<<" ";
        cout<<endl;
    } else
        cout<<"Stack is empty";
}

int main() {
    int ch, val;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl;
    do {
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
            case 1: {
                cout<<"Enter value to be pushed:"<<endl;
                cin>>val;
                push(val);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                cout<<"Exit"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice"<<endl;
            }
        }
    } while(ch!=4);
    return 0;
}



// USING  LINKED LIST 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

CONST INT TOP =NULL;
    void push(int data) {
        Node* temp = new Node();
        if (!temp) {
            cout << "Stack Overflow" << endl;
            return;
        }
        temp->data = data;
        temp->next = top;
        top = temp;
    }
    bool isEmpty() {
        return top == NULL;
    }
    int peek() {
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }
    void pop() {
        Node* temp;
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
    void display() {
        Node* temp;
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        temp = top;
        cout << "Stack elements are: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    int ch, val;
    Stack s;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch) {
        case 1: {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            s.push(val);
            break;
        }
        case 2: {
            s.pop();
            break;
        }
        case 3: {
            s.display();
            break;
        }
        case 4: {
            cout << "Exit" << endl;
            break;
        }
        default: {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}





