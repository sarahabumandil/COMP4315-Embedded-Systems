import serial
import numpy as np
import matplotlib.pyplot as plt

ser = serial.Serial('COM2', 9600, timeout=0.05)

plt.ion()
fig = plt.figure(figsize=(7, 6))
ax = fig.add_subplot(111, projection='3d')

L1, L2, L3 = 4.0, 3.5, 2.0
angles = [90.0, 90.0, 90.0, 90.0]

while plt.fignum_exists(fig.number):
    try:
        # قراءة أحدث سطر وتجاهل البيانات القديمة المتراكمة
        while ser.in_waiting > 0:
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            if line:
                parts = line.split(',')
                if len(parts) == 4:
                    angles = [float(x) for x in parts]
    except Exception:
        pass

    base = np.radians(angles[0] - 90)
    shoulder = np.radians(angles[1])
    elbow = np.radians(angles[2] - 90)
    gripper_open = (angles[3] / 180.0) * 0.8 + 0.1

    x0, y0, z0 = 0, 0, 0
    x1, y1, z1 = 0, 0, L1

    r2 = L2 * np.cos(shoulder)
    x2 = r2 * np.cos(base)
    y2 = r2 * np.sin(base)
    z2 = z1 + L2 * np.sin(shoulder)

    r3 = r2 + L3 * np.cos(shoulder + elbow)
    x3 = r3 * np.cos(base)
    y3 = r3 * np.sin(base)
    z3 = z2 + L3 * np.sin(shoulder + elbow)

    perp_x = -np.sin(base) * gripper_open
    perp_y = np.cos(base) * gripper_open

    ax.clear()
    ax.set_xlim(-8, 8)
    ax.set_ylim(-8, 8)
    ax.set_zlim(0, 10)
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.set_title(f"3D Robot Arm | Base:{int(angles[0])} Sh:{int(angles[1])} El:{int(angles[2])} Grip:{int(angles[3])}")

    ax.plot([x0, x1], [y0, y1], [z0, z1], 'k-', linewidth=6)
    ax.plot([x1, x2], [y1, y2], [z1, z2], 'b-', linewidth=5)
    ax.plot([x2, x3], [y2, y3], [z2, z3], 'g-', linewidth=4)
    ax.plot([x3, x3 + perp_x], [y3, y3 + perp_y], [z3, z3], 'r-', linewidth=3)
    ax.plot([x3, x3 - perp_x], [y3, y3 - perp_y], [z3, z3], 'r-', linewidth=3)

    plt.pause(0.02)

ser.close()
