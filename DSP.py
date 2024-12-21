import numpy as np
import matplotlib.pyplot as plt

# 定義 n 範圍
n = np.arange(0, 11)  # n 從 0 到 10

# 第一個訊號的計算 (x1[n])
u = np.heaviside(n, 1)       # u[n]
u_shift = np.heaviside(n-2, 1)  # u[n-2]

x1_1 = 2 * (-2.0)**n * u - (-1.0)**n * u
x1_2 = -4 * (-2.0)**(n-2) * u_shift
x1_3 = 2 * (-1.0)**(n-2) * u_shift
x1 = x1_1 + x1_2 + x1_3

# 第二個訊號的計算 (x2[n])
delta = np.zeros_like(n)
delta[0] = 1  # δ[n] = 1 when n = 0

x2_1 = -delta                      # -δ[n]
x2_2 = (-2.0)**n * u               # 1(-2)^n * u[n]
x2_3 = (-1.0)**n * u               # 1(-1)^n * u[n]
x2 = x2_1 + x2_2 + x2_3

# 列印數值
np.set_printoptions(4, suppress=True)
print("n =", n)
print("x1[n] =", x1)
print("x2[n] =", x2)

# 檢查兩個訊號是否相等
if np.allclose(x1, x2):
    print("兩個訊號相同")
else:
    print("兩個訊號不同")

# 繪圖
plt.figure(figsize=(12, 4))

# 左邊顯示 x1[n]
plt.subplot(1, 2, 1)
plt.stem(n, x1, use_line_collection=True)
plt.title(r"$x_1[n] = 2(-2)^n u[n] - (-1)^n u[n] - 4(-2)^{n-2} u[n-2] + 2(-1)^{n-2} u[n-2]$")
plt.xlabel('$n$')
plt.ylabel('Amplitude')
plt.grid(True)

# 右邊顯示 x2[n]
plt.subplot(1, 2, 2)
plt.stem(n, x2, use_line_collection=True)
plt.title(r"$x_2[n] = -\delta[n] + (-2)^n u[n] + (-1)^n u[n]$")
plt.xlabel('$n$')
plt.ylabel('Amplitude')
plt.grid(True)

plt.tight_layout()
plt.show()
