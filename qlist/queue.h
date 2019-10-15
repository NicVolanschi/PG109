typedef struct queue_s *queue;

extern queue init();
extern void kill(queue s);
extern int isempty(queue s);
extern int isfull(queue s);
extern int size(queue s);
extern char * peek(queue s);
extern char * pop(queue s);
extern void push(char * data, queue s);
