# Philosophers
In this project, I studied the **basics of threading a process**.
How to create threads, how to work with mutexes.

This is taken from the [subject.pdf](https://cdn.intra.42.fr/pdf/pdf/40187/en.subject.pdf).<br>

------------------------------------------------


<p float="left">
<img src="image/introduction.png" height="300"/>
<img src="image/philosophers_example.png" height="300"/>
<p>
  
To run the simulation a few variables are needed:
------------------------------------------------

1. number_of_philosophers: is the number of philosophers and also the number of forks.
2. time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’milliseconds after starting their last meal or the beginning of the simulation,it dies.
3. time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
4. time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
5. number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

## Usage
To compile the programm run `make all` in the root of the project.<br>
Then run `./philo` with the parameters you want to test explained<br><br>
i.e.: `./philo 4 410 200 200 4`<br>
Now the simulation will start and run until each philosopher has eaten 4 times or dies.<br><br>
This `./philo 4 410 200 200` should theoretically run infinite.<br>
If you want to see the usage while using you can do `./philo` and it will show you the correct usage.<br>
