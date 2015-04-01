#include "types.h"
#include "x86.h"
#include "defs.h"
#include "spinlock.h"
#include "param.h"
// #include "proc.h"

struct semaphore {
  int value;
  int active;
  struct spinlock lock;
} sem[32];

void
seminit(void)
{
  int i;
  for(i = 0; i < 32; ++i)
  {
    initlock(&sem[i].lock, "semmaphore");
    sem[i].active = 0;
    sem[i].value = 0;
  }
}

int
sys_sem_init(void)
{
  
  return 0;
}

int
sys_sem_destroy(void)
{
  
  return 0;
}

int
sys_sem_wait(void)
{
  
  return 0;
}

int
sys_sem_signal(void)
{
  // semaphore.value = 0;
  // ptable;
  // tickslock;
  // acquire(&tickslock);
  // sem;
  // acquire(&ptable.lock);
  // semtable.sem[0].value = 0;
  // acquire(&sem.lock);
  return 0;
}