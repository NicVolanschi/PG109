typedef struct stack_s *stack;

extern stack init();
extern void kill(stack s);
extern int isempty(stack s);
extern int isfull(stack s);
extern int size(stack s);
extern char * peek(stack s);
extern char * pop(stack s);
extern void push(char * data, stack s);
