*This project has been created as part of the 42 curriculum by alamjada*

# Philosophers

## Description

You have one mission, keep all philosophers alive. But you have some conditions to solve this problem:

- Each philosophers must run on its own thread
- There is one fork between each pair of philosopher
- A philosopher need 2 forks to eat

The primary difficulty for this subject is to behavor the access of fork without data races or deadlocks.
To ensure thread safety, we use mutex function lock and unlock.
Mutex protect shared variables and ensure that only one thread can interact with variable at any given time.

## Instructions

`make`

and

`./philo number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]`

## Resources

- https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/
- https://fr.wikipedia.org/wiki/D%C3%AEner_des_philosophes
- https://www.achrafothman.net/docs/sys.expl.II.td.3.pdf
- https://www.youtube.com/watch?v=l_dnpUkkaSg
