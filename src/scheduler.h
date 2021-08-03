#ifndef __SCHEDULER_H
#define __SCHEDULER_H

uint16_t create_process(unsigned long interval, void (*fn)(void));
void run(void);

#endif /* __SCHEDULER_H */
