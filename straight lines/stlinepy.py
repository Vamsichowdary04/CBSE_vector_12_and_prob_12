import numpy as np
import matplotlib.pyplot as plt

# Given line equation: x - 2y = 3
x = np.linspace(-10, 10, 100)
y_given = (x - 3) / 2

# Point (3, 2)
point = np.array([3, 2])

# Calculate the angle in radians
angle_rad = np.deg2rad(45)

# Calculate the slope of the lines
slope = -1 / np.tan(angle_rad)

# Construct the lines passing through the point (3, 2)
y1 = slope * (x - point[0]) + point[1]
y2 = -slope * (x - point[0]) + point[1]

# Plotting
plt.figure(figsize=(8, 6))
plt.plot(x, y_given, 'b-', label='x - 2y = 3')
plt.plot(x, y1, 'r-', label='45° line 1')
plt.plot(x, y2, 'g-', label='45° line 2')
plt.plot(point[0], point[1], 'ko', label='Point (3, 2)')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Lines through (3, 2) at 45° angle')
plt.legend()
plt.grid(True)
plt.xlim(-10, 10)
plt.ylim(-10, 10)
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.show()
