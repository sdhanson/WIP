import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.animation as manimation

FFMpegWriter = manimation.writers['ffmpeg']
metadata = dict(title='Movie Test', artist='Matplotlib',
                comment='Movie support!')
writer = FFMpegWriter(fps=48, metadata=metadata)

fig = plt.figure()

# with writer.saving(fig, "writer_test.mp4", 100):
#     for k in range(10):
#         # Create a new plot object
#         plt.plot(range(k), range(k), 'o')
#         writer.grab_frame()

xsample = [0, 0.016, 0.034, 0.051, 0.083, 0.1, 0.117, 0.134, 0.151, 0.184, 0.2, 0.218, 0.235, 0.25, 0.284, 0.301, 0.317, 0.334, 0.351, 0.384, 0.402, 0.419, 0.435, 0.452, 0.484, 0.501, 0.519, 0.535, 0.551, 0.569, 0.602, 0.618, 0.636, 0.652, 0.67, 0.702, 0.719, 0.737, 0.753, 0.769, 0.803, 0.819, 0.835, 0.852, 0.886, 0.903, 0.919, 0.936, 0.952, 0.97, 1.003, 1.019, 1.037, 1.052, 1.069, 1.102, 1.119, 1.137, 1.152, 1.169, 1.203, 1.219, 1.236, 1.253, 1.271, 1.304, 1.32, 1.336, 1.353, 1.37, 1.403, 1.42, 1.437, 1.453, 1.471, 1.504, 1.52, 1.538, 1.555, 1.571, 1.605, 1.622, 1.637, 1.654, 1.672, 1.704, 1.722, 1.74, 1.754, 1.771, 1.804, 1.821, 1.838, 1.855, 1.871, 1.906, 1.921, 1.938, 1.956, 1.972, 2.005, 2.022, 2.039, 2.055, 2.072, 2.106, 2.122, 2.138, 2.156, 2.172, 2.207, 2.222, 2.239, 2.255, 2.277, 2.29, 2.324, 2.341, 2.357, 2.373, 2.39, 2.423, 2.44, 2.456, 2.472, 2.489, 2.523, 2.539, 2.556, 2.573, 2.59, 2.623, 2.641, 2.656, 2.675, 2.69, 2.724, 2.74, 2.757, 2.774, 2.79, 2.823, 2.841, 2.857, 2.873, 2.89, 2.923, 2.94, 2.957, 2.975, 2.99, 3.024, 3.041, 3.057, 3.074, 3.091, 3.124, 3.141, 3.158, 3.174, 3.191, 3.224, 3.241, 3.258, 3.275, 3.291, 3.324, 3.341, 3.359, 3.376, 3.391, 3.425, 3.443, 3.458, 3.476, 3.492, 3.509, 3.543, 3.559, 3.575, 3.593, 3.625, 3.642, 3.66, 3.677, 3.692, 3.709, 3.742, 3.759, 3.776, 3.792, 3.809, 3.843, 3.859, 3.876, 3.892, 3.909, 3.943, 3.96, 3.977, 3.993, 4.01, 4.043, 4.061, 4.076, 4.094, 4.11, 4.143, 4.16, 4.178, 4.193, 4.211, 4.243, 4.26, 4.278, 4.295, 4.31, 4.344, 4.36, 4.377, 4.395, 4.41, 4.444, 4.46, 4.477, 4.494, 4.512, 4.544, 4.561, 4.58, 4.594, 4.611, 4.644, 4.661, 4.68, 4.695, 4.711, 4.746, 4.762, 4.778, 4.795, 4.811, 4.845, 4.863, 4.879, 4.895, 4.912, 4.929, 4.962, 4.979, 4.995, 5.012, 5.045, 5.062, 5.079, 5.095, 5.113, 5.146, 5.162, 5.18, 5.196, 5.213, 5.229, 5.262, 5.28, 5.296, 5.312, 5.33, 5.363, 5.38, 5.397, 5.413, 5.429, 5.464, 5.48, 5.496, 5.513, 5.53, 5.563, 5.581, 5.597, 5.614, 5.63, 5.663, 5.681, 5.698, 5.713, 5.731, 5.764, 5.78, 5.798, 5.815, 5.83, 5.864, 5.88, 5.898, 5.914, 5.932, 5.964, 5.981, 5.999, 6.014, 6.031, 6.064, 6.081, 6.099, 6.115, 6.131, 6.164, 6.181, 6.199, 6.215, 6.232, 6.266, 6.282, 6.298, 6.315, 6.332, 6.349, 6.382, 6.399, 6.415, 6.432, 6.45, 6.482, 6.5, 6.515, 6.532, 6.549, 6.583, 6.599, 6.617, 6.632, 6.666, 6.684, 6.7, 6.716, 6.732, 6.75, 6.783, 6.8, 6.816, 6.833, 6.85, 6.883, 6.9, 6.916, 6.933, 6.95, 6.983, 7, 7.017, 7.033, 7.05, 7.083, 7.1, 7.117, 7.134, 7.151, 7.184, 7.2, 7.217, 7.235, 7.251, 7.284, 7.301, 7.318, 7.334, 7.352, 7.384, 7.401, 7.419, 7.434, 7.451, 7.469, 7.503, 7.518, 7.535, 7.551, 7.585, 7.602, 7.619, 7.635, 7.651, 7.686, 7.703, 7.718, 7.735, 7.751, 7.786, 7.802, 7.819, 7.835, 7.852, 7.87, 7.902, 7.919, 7.935, 7.953, 7.985, 8.003, 8.019, 8.036, 8.053, 8.219, 8.221, 8.222, 8.223, 8.224, 8.225, 8.226, 8.228, 8.241, 8.253]
ysample = [-2.408, -1.0689, 0.617498, 1.84634, 2.17468, 1.25721, 0.306395, -0.00431442, 0.680279, 0.910809, -0.0206699, -0.724356, -1.24564, -1.11037, -0.279271, 0.0905457, 0.109173, -0.06357, -0.0595512, -0.337032, -0.198957, 0.006073, 0.430826, 0.945806, 1.40097, 1.17546, 1.25798, 1.38484, 1.43908, 1.58562, -0.293089, -2.80444, -4.27216, -1.59591, 1.03005, 1.405, 1.32216, 2.54436, 2.33428, 1.09921, -0.76696, -0.642915, -0.147654, -0.00950813, -0.642941, -0.26124, 0.016922, 0.0263023, -0.411122, -0.536928, -0.688553, -0.456078, 0.149115, 0.719692, 1.02442, 1.64124, 0.520274, 0.838593, 1.6587, 1.05275, -0.099144, -2.56926, -2.6221, -0.0553932, 1.42802, 0.511431, 0.81284, 1.48265, 1.70474, 0.800206, -0.103259, 0.367188, 0.720648, 0.662782, 0.259725, -0.111149, -0.254906, -0.459969, -0.58691, -0.674397, -0.48401, -0.0708246, 0.0380535, -0.205836, -0.59731, -0.483185, 2.51591, 3.00431, 3.54351, 2.77555, -0.35005, 0.191121, 0.468396, -0.303736, -0.96819, 1.28135, 0.930642, -0.0670977, -0.960335, -1.07846, -0.0849171, 0.396034, 0.479786, -0.245087, -0.84739, -0.728985, -0.449574, 0.067523, 0.675096, 1.4336, 1.37523, 0.319965, -0.970744, -1.67121, -0.989815, 2.63026, 4.30592, 2.72066, -0.760324, -3.63753, -4.84115, 0.49127, 1.97982, 0.136787, -0.347773, 0.90149, 1.82819, 0.974593, 0.649126, 1.29861, 1.54797, -0.350425, -1.03676, -0.764404, -0.27687, 0.0996876, -0.0648346, -0.738502, -1.10973, -1.07788, -0.596081, 0.221172, 0.285249, 0.137296, 0.489334, 1.77083, 4.01046, 4.23827, 1.78482, -0.744515, -1.76957, 0.300673, -0.032629, -0.887875, -0.774804, -0.135321, 0.345731, -0.231729, -0.549703, -0.448481, -0.203287, -0.0951643, -0.119815, 0.192132, 0.421003, 0.724134, 0.859077, 0.267339, -0.140001, 0.208936, 0.617847, -0.0345287, -0.588931, -0.597312, 0.884222, 3.46577, 3.34101, 0.368265, -1.85785, -4.08314, -5.48635, 0.333523, 4.16922, 2.82205, 1.04994, 1.99797, 2.8944, 0.975873, -0.253274, -0.743854, -0.319718, 0.0424032, -0.247413, -0.381127, -0.0573788, -0.0400152, -0.189692, 0.0756483, -0.0564098, -0.619286, -1.16499, -1.45402, -0.343073, 0.619329, 0.73425, 0.385217, 2.24422, 2.92458, 1.62128, 0.421575, -1.82998, -2.62114, 0.509276, 1.23081, 0.714786, 0.766708, 1.58873, 1.94704, 0.959599, 0.0649462, -0.31728, -0.32319, -0.36237, -0.278029, -0.180643, -0.0653534, 0.0311108, -0.0282393, -0.084918, -0.165057, -0.272897, -0.146076, -0.219258, -0.561083, -0.872107, -0.682717, -0.921677, 5.48696, 4.15871, 1.92058, 0.142075, -1.36665, -1.77378, -0.474363, 0.731768, 0.80816, 0.102426, -0.36204, 0.0457935, 0.324273, 0.59336, 0.786974, 0.529141, 0.138008, 0.00619793, 0.0316715, 0.0509186, 0.249547, 0.187567, -0.0382233, -0.070982, 0.770204, 1.16683, 0.612558, 0.353395, 0.411998, 0.320801, 0.0421781, 0.116466, 0.151352, 0.0990992, 0.202539, 0.146693, 0.0936737, 0.0128002, -0.0106573, -0.0476284, -0.0211458, 0.183069, 0.179517, 0.37536, 0.492864, 0.552311, 0.315175, 0.204177, 0.324073, 0.267234, 0.232549, 0.496984, 0.55743, 0.503975, 0.398397, 0.260328, 0.14081, 0.129557, 0.169519, 0.205272, 0.24716, 0.200523, 0.292625, 0.240735, 0.259877, 0.250229, 0.313263, 0.27278, 0.294794, 0.423578, 0.402661, 0.400747, 0.429146, 0.385579, 0.349924, 0.283244, 0.150386, 0.319132, 0.33381, 0.190865, 0.141212, 0.0844212, 0.0275993, 0.199326, 0.215473, 0.229591, 0.295517, 0.303212, 0.359956, 0.213915, 0.303212, 0.164232, 0.16015, 0.113955, 0.151819, 0.0497732, 0.268461, 0.300742, 0.409256, 0.492979, 0.466205, 0.500816, 0.559203, 0.423543, 0.27259, 0.261287, 0.248638, 0.194578, 0.255092, 0.345474, 0.338658, 0.260188, 0.114503, 0.12286, 0.209173, 0.203082, 0.201552, 0.0426903, 0.130277, 0.156644, 0.239236, 0.372282, 0.405223, 0.409271, 0.420178, 0.370185, 0.363915, 0.483443, 0.246889, 0.295668, 0.286811, 0.23583, 0.165515, 0.229814, 0.187903, 0.224155, 0.216246, 0.189841, 0.1853, 0.294286, 0.170535, 0.219006, 0.263615, 0.222428, 0.159352, 0.156074, 0.135913, 0.0517073, 0.150419, 0.209, -0.0241795, -0.0455771, -0.0954533, -0.101459, -0.130144, -0.296772, -0.219258, -0.269655, -0.155652, 0.0437985, 0.192852, 0.393707, 0.899286, 0.996336, 0.991647, 0.928138, 0.840692, 0.838603, 0.838603, 0.838603, 0.838603, 0.838603, 0.838603, 0.838603, 0.838603, 0.35559, 0.333813]

xdata = []
ydata = []
 

 
axes = fig.add_subplot(111)
# axes.set_xlim(0, 100)
# axes.set_ylim(-50, +50)
line, = axes.plot(xdata, ydata, 'r-')
 
plt.xlabel('Nidhi 1')
plt.ylabel('Y Acceleration')
# plt.plot(xsample, ysample, 'r-')
with writer.saving(fig, 'n16.mp4', dpi=100):
    for i in range(400):
    	xdata.append(xsample[i])
    	ydata.append(ysample[i])
    	plt.plot(xdata, ydata, 'go--', linewidth=2, markersize=1)
        # plt.plot(xsample[i], ysample[i], linestyle='--', marker='o', color='b', markersize=1)
        # plt.pause(xsample[i+1]-xsample[i])
        writer.grab_frame()


# plt.xlabel('Nidhi 1')
# plt.ylabel('Y Acceleration')
# # plt.plot(xsample, ysample, 'r-')
# with writer.saving(fig, 'n1234675.mp4', dpi=100):
# 	for i in range(20):
# 		xdata.append(xsample[i])
# 		ydata.append(ysample[i])
# 		line.set_xdata(xdata);
# 		line.set_ydata(ydata);
# 		plt.plot(xdata, ydata, 'go--', linewidth=2, markersize=12)
# 		# plt.plot(xdata, ydata, linestyle='--', marker='o', color='b', markersize=1)
#         plt.pause(xsample[i+1]-xsample[i])
#         writer.grab_frame()

plt.show()