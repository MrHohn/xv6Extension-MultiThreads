#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"

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
sem_init(int num, int max)
{
  // cprintf("semaphore[%d].value is initialized to %d\n", num, max);

  acquire(&sem[num].lock);
  if(sem[num].active != 0) 
    return -1;
  sem[num].value = max;
  sem[num].active = 1;
  release(&sem[num].lock);

  return 0;
}

int
sem_destroy(int num)
{
  acquire(&sem[num].lock);
  if(sem[num].active != 1) 
    return -1;
  sem[num].active = 0;
  // cprintf("semaphore[%d] is destroied\n", num);
  release(&sem[num].lock);

  return 0;
}

int
sem_wait(int num, int count)
{
  acquire(&sem[num].lock);
  // cprintf("wait for semaphore[%d]\n", num);
  if(sem[num].active == 0) 
    return -1;
  while(sem[num].value <= 0)
  {
    sleep(&sem[num], &sem[num].lock);
  }
  // cprintf("got semaphore[%d] and run\n", num);
  sem[num].value -= count;
  release(&sem[num].lock);

  return 0;
}

int
sem_signal(int num, int count)
{
  acquire(&sem[num].lock);
  if(sem[num].active == 0) 
    return -1; 
  // cprintf("semaphore[%d]'s value is added up %d\n", num, count);
  sem[num].value += count;
  if(sem[num].value > 0) 
    wakeup(&sem[num]);
  release(&sem[num].lock);

  return 0;
}