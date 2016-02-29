typedef struct {
    int maxSize;
    int length;
    int *min;
    int *top;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->top = (int*)malloc(maxSize * sizeof(int));
    stack->min = (int*)malloc(maxSize * sizeof(int));
    stack->length = 0;
    stack->maxSize = maxSize;
    return;
}

void minStackPush(MinStack *stack, int element) {
    int length = stack->length;
    if (length >= stack->maxSize) return;

    stack->top[length] = element;
    if (length == 0) {
        stack->min[length] = element;
    } else {
        int min = stack->min[length - 1];
        if (element < min) {
            stack->min[length] = element;
        } else {
            stack->min[length] = min;
        }
    }
    stack->length++;
    return;
}

void minStackPop(MinStack *stack) {
    if (stack->length == 0) return;
    stack->length--;
    return;
}

int minStackTop(MinStack *stack) {
    if (stack->length == 0) return 0;
    return stack->top[stack->length - 1];
}

int minStackGetMin(MinStack *stack) {
    if (stack->length == 0) return 0;
    return stack->min[stack->length - 1];
}

void minStackDestroy(MinStack *stack) {
    free(stack->top);
    free(stack->min);
}