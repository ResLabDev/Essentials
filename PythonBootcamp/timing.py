# # timeit - Timing the code

num_str = "-".join(str(n) for n in range(100))
print(num_str)
                   
import timeit

# for loop
execution_time = timeit.timeit('"-".join(str(n) for n in range(100))', number=10000)
print(execution_time)

# List comprehension
execution_time = timeit.timeit('"-".join([str(n) for n in range(100)])', number=10000)
print(execution_time)

# Mapping
execution_time = timeit.timeit('"-".join(map(str,range(100)))', number=10000)
print(execution_time)

