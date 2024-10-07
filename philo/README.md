# PHILOSOPHERS 🚀
In this project we must create a simulation of the classic philosophers problem usin a mutithreaded solution.
In this simulation we have a given number o philosophers with one fork for each one. One philosopher has access to his own fork and to the fork from the philosopher on his right. And the philosophers can only eat if they have two forks available.
After they eat the must go to sleep for a given time and then think until they can eat again in an infinite loop if possible. If the philosopher spent more time that a given time (time_to_die) without eating they should die and the program must stop.
The program takes the following arguments:
$./philo number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_meals
(number_of_meals being optional)

In order to create this simulation we create a thread for every philosopher and we use mutexes to restrain the access to the forks. We also create an argos thread that works as a watcher and checks at every moment if any philosopher is starving of if they have eaten the given number of meals. In that case it changes the apocalypse flag from data- 
When apocalypse is 1 the philosophers know they must end their thread. We do evry check using mutex, even for printing in order to avoid dataraces.

* Allowed functions: memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

## Topics & Learnings
* Simulations
* Multithreaded solutions
* Threads vs processes
* Therads managing
* Concurrency
* Mutex usage and managing
* Monitor threads and deadflags
* Data races
* Deadlocks
* ThreadSanitizer usage for multithreaded issues
* Helgrind
* Times management
