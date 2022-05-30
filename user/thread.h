struct lock_t{
	uint64 locked;
};
typedef struct lock_t lock_t;

void *thread_create(void*(start_routine)(void*),void*);
int lock_init(lock_t *);
void lock_acquire(lock_t *);
void lock_release(lock_t *);