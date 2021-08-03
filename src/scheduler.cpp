#include "scheduler.h"
#include <Arduino.h>
#include <stddef.h>
#include <stdint.h>

static struct process* proc_ptr = NULL;
static uint16_t proc_num = 0;

struct process
{
	unsigned long interval;
	unsigned long last;
	void (*fn)();
}

uint16_t create_process(uint16_t interval, void (*fn)())
{
	proc_ptr = realloc(proc_ptr, proc_num + 1);
	proc_ptr[proc_num].interval = interval;
	proc_ptr[proc_num].fn = fn;
	return proc_num++;
}

void run(void)
{
	for(uint16_t i = 0; i < proc_num; i++)
	{
		unsigned long milis = millis();
		if(milis - proc_ptr[i].interval > proc_ptr[i].last)
		{
			proc_ptr[i].last = milis;
			proc_ptr[i].fn();
		}
	}
}
