# scheduler
A good and simple scheduler for Arduino

It has 2 functions, create_process and run, run checks if any of the processes time came, and runs if it's time has come.
create_process takes 2 arguments, interval and your function, interval is in miliseconds, and your function should take no arguments and return nothing.
When you use create_process, it creates a process that it will handle, not you, you should just call run and let it run it for you.
