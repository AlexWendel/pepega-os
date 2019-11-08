typedef struct process{
    unsigned char pid;
    int priority;
    int state;
    int progress;
    int q;
    int q_process;
} *process_;
