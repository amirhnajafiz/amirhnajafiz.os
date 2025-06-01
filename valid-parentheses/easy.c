#define MAX_SIZE 10000

typedef struct {
    char arr[MAX_SIZE];  
    int top;        
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;  
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;  
}

void push(Stack *stack, char value) {
    stack->arr[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '0';
    }
    
    char popped = stack->arr[stack->top];
    stack->top--;

    return popped;
}

bool isValid(char* s) {
    // use one stack to keep the order
    Stack stack;
    initialize(&stack);

    // loop over the input
    char* p = s;
    while(*p != '\0') {
        // switch on the character
        switch(*p) {
            case '(':
            case '{':
            case '[':
                push(&stack, *p);
                break;
            case ')':
            case '}':
            case ']':
                char value = pop(&stack);
                int distance = *p - value;
                if (distance != 1 && distance != 2) {
                    return false;
                }
        }

        // move to next character
        p++;
    }

    if (!isEmpty(&stack)) {
        return false;
    }

    // default return true
    return true;
}
