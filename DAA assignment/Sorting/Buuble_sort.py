import random
import time
import numpy as np
from matplotlib import pyplot as plt

etime = []

size = [10, 50, 100, 250, 500, 1000, 2500, 5000]

for s in size:
    # Generate random data
    data = np.random.random(s)

    start_time = time.time()

    # Bubble Sort
    for i in range(len(data)):
        for j in range(len(data) - i - 1):
            if data[j] > data[j + 1]:
                t = data[j]
                data[j] = data[j + 1]
                data[j + 1] = t

    end_time = time.time()

    duration = end_time - start_time
    etime.append(duration * 10e5)

print(size)
print(etime)

plt.plot(size, etime, marker='o')
plt.xlabel("Input Size")
plt.ylabel("Execution Time")
plt.title("Bubble Sort Time Complexity")
plt.grid(True)
plt.show()