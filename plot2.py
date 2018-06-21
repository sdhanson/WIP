import matplotlib.pyplot as plt
t = [0, 0.051, 0.053, 0.064, 0.081, 0.097, 0.114, 0.148, 0.164, 0.182, 0.198, 0.214, 0.248, 0.265, 0.282, 0.298, 0.315, 0.332, 0.365, 0.382, 0.398, 0.415, 0.448, 0.465, 0.481, 0.499, 0.515, 0.533, 0.566, 0.582, 0.599, 0.615, 0.65, 0.665, 0.682, 0.699, 0.715, 0.749, 0.767, 0.782, 0.799, 0.816, 0.833, 0.866, 0.884, 0.903, 0.916, 0.933, 0.966, 0.983, 1.001, 1.016, 1.033, 1.068, 1.083, 1.1, 1.118, 1.133, 1.167, 1.184, 1.2, 1.217, 1.235, 1.267, 1.284, 1.301, 1.317, 1.334, 1.367, 1.384, 1.401, 1.417, 1.434, 1.467, 1.485, 1.502, 1.518, 1.534, 1.568, 1.584, 1.601, 1.618, 1.634, 1.668, 1.685, 1.701, 1.719, 1.735, 1.769, 1.785, 1.802, 1.818, 1.836, 1.868, 1.885, 1.902, 1.918, 1.935, 1.953, 1.985, 2.003, 2.019, 2.035, 2.071, 2.085, 2.104, 2.12, 2.136, 2.169, 2.186, 2.202, 2.219, 2.236, 2.254, 2.286, 2.302, 2.32, 2.336, 2.353, 2.386, 2.403, 2.42, 2.436, 2.454, 2.487, 2.503, 2.52, 2.537, 2.553, 2.587, 2.605, 2.62, 2.637, 2.654, 2.687, 2.704, 2.721, 2.738, 2.754, 2.787, 2.804, 2.821, 2.837, 2.854, 2.888, 2.904, 2.921, 2.938, 2.955, 2.988, 3.005, 3.021, 3.038, 3.054, 3.073, 3.105, 3.122, 3.139, 3.154, 3.189, 3.205, 3.223, 3.239, 3.255, 3.289, 3.305, 3.322, 3.338, 3.356, 3.389, 3.405, 3.423, 3.438, 3.455, 3.473, 3.505, 3.523, 3.539, 3.556, 3.589, 3.607, 3.622, 3.64, 3.657, 3.673, 3.707, 3.724, 3.74, 3.756, 3.774, 3.806, 3.825, 3.841, 3.857, 3.873, 3.907, 3.923, 3.941, 3.958, 3.973, 4.007, 4.024, 4.041, 4.058, 4.075, 4.107, 4.124, 4.141, 4.157, 4.174, 4.207, 4.224, 4.242, 4.257, 4.274, 4.308, 4.324, 4.341, 4.358, 4.374, 4.408, 4.425, 4.441, 4.458, 4.474, 4.508, 4.526, 4.541, 4.558, 4.575, 4.609, 4.625, 4.644, 4.661, 4.676, 4.709, 4.725, 4.742, 4.758, 4.776, 4.809, 4.826, 4.843, 4.86, 4.877, 4.893, 4.926, 4.944, 4.961, 4.977, 4.994, 5.026, 5.043, 5.059, 5.077, 5.094, 5.126, 5.144, 5.159, 5.176, 5.193, 5.226, 5.243, 5.261, 5.277, 5.294, 5.327, 5.344, 5.36, 5.377, 5.393, 5.427, 5.445, 5.46, 5.477, 5.494, 5.527, 5.544, 5.561, 5.578, 5.594, 5.627, 5.644, 5.661, 5.677, 5.695, 5.727, 5.745, 5.761, 5.778, 5.795, 5.828, 5.845, 5.862, 5.878, 5.894, 5.928, 5.945, 5.963, 5.979, 5.995, 6.028, 6.045, 6.061, 6.079, 6.097, 6.128, 6.145, 6.163, 6.179, 6.195, 6.213, 6.245, 6.262, 6.279, 6.295, 6.33, 6.345, 6.362, 6.379, 6.397, 6.429, 6.446, 6.462, 6.479, 6.496, 6.513, 6.546, 6.563, 6.579, 6.596, 6.613, 6.646, 6.663, 6.68, 6.697, 6.713, 6.749, 6.763, 6.78, 6.797, 6.813, 6.847, 6.864, 6.88, 6.897, 6.915, 6.947, 6.964, 6.98, 6.997, 7.014, 7.047, 7.064, 7.082, 7.098, 7.114, 7.148, 7.165, 7.181, 7.198, 7.215, 7.248, 7.265, 7.282, 7.298, 7.314, 7.348, 7.365, 7.382, 7.399, 7.415, 7.448, 7.465, 7.482, 7.498, 7.516, 7.549, 7.565, 7.582, 7.598, 7.616, 7.649, 7.665, 7.682, 7.699, 7.716, 7.749, 7.766, 7.782, 7.799, 7.816, 7.85, 7.866, 7.882, 7.899, 7.916, 7.933, 7.967, 7.984, 8, 8.016, 8.034, 8.066, 8.085, 8.101, 8.117, 8.133, 8.167, 8.183, 8.201, 8.217, 8.233, 8.267, 8.285, 8.301, 8.317, 8.335, 8.367, 8.384, 8.401, 8.417, 8.434, 8.467, 8.484, 8.501, 8.519, 8.534, 8.569, 8.585, 8.601, 8.618, 8.635, 8.668, 8.685, 8.701, 8.718, 8.735, 8.768, 8.786, 8.803]
y = [0.263019, 0.35155, 0.35155, 0.313086, 0.275972, 0.290309, 0.253223, 0.194251, 0.171106, 0.223286, 0.352438, 0.413382, 0.362679, 0.283328, 0.20747, 0.285915, 0.269893, 0.277502, 0.31041, 0.280987, 0.328199, 0.301542, 0.324427, 0.345798, 0.430714, 0.485909, 0.265535, 0.239065, 0.190866, 0.0772572, 0.0730133, 0.459589, 0.43642, 0.0808172, 0.0884581, 0.35515, 0.420996, 0.163976, 0.214124, 0.351305, 0.239743, 0.23893, 0.206881, 0.43158, 0.420761, 0.321874, 0.246558, 0.20847, 0.234897, 0.293639, 0.357503, 0.476042, 0.353823, 0.225758, 0.341684, 0.272951, 0.329893, 0.298191, 0.279384, 0.331288, 0.295283, 0.30074, 0.336269, 0.296494, 0.40517, 0.340311, 0.244756, 0.308068, 0.342564, 0.360686, 0.326238, 0.228568, 0.236191, 0.299104, 0.29651, 0.361952, 0.336305, 0.273992, 0.252683, 0.301195, 0.339845, 0.379377, 0.199042, 0.39193, 0.483421, 0.403245, 0.269169, 0.246269, 0.337253, 0.249084, 0.278374, 0.236958, 0.348311, 0.179147, 0.235287, 0.263987, 0.290785, 0.425057, 0.386931, 0.403799, 0.461337, 0.521565, 0.563782, 0.541346, 0.496707, 0.34804, 0.590897, 0.481733, -0.161233, -0.571469, -0.703939, -0.416719, -0.120755, 0.0764637, 0.587299, 0.998961, 0.940046, 0.202172, -0.265044, 0.795636, 1.23031, 0.869608, 0.854969, 0.839687, 0.283649, -0.16349, -0.227928, 0.130127, 0.190126, -0.44543, -0.395403, 0.208762, 0.553192, 0.34809, -0.527886, -0.209121, 0.285198, 0.355296, 0.0538607, 0.192009, 0.710853, 1.62818, 3.20667, 2.89265, -0.324087, -0.810928, -0.315504, 0.203144, 0.18534, 0.386564, 0.555678, 0.358588, 0.404501, 1.03117, 0.930267, -0.124726, -0.676013, -0.475141, -0.0434103, -0.00742722, -0.321383, -0.241427, -0.438381, -0.356461, -0.215288, -0.487413, -1.02402, -1.41341, 0.256811, 1.43298, -0.219834, 0.594497, 2.53051, 1.97671, 0.365751, -0.264032, 0.760089, 0.89457, 0.408392, 0.408007, 0.370287, 1.52172, 1.6622, 1.30021, 0.813705, -0.618457, -0.901928, -0.412332, 0.0943737, 0.153246, -0.011322, -0.144603, -0.0667038, 0.0019846, -0.0777521, 0.169218, 1.75092, 2.79169, 1.92623, -0.0486832, -0.369948, -0.441845, -0.701106, 0.413256, 1.55611, 0.240645, -0.210405, -0.154606, -0.0183134, 0.165031, 0.0602894, 0.249076, 0.28806, 0.0812283, -0.184054, -0.33624, 0.10565, 0.484595, 0.433939, 0.0742083, -0.593683, -0.442184, 0.147522, 1.3777, 1.71445, 1.21663, 0.693617, 0.871073, 0.913637, 0.146707, 0.11469, 0.221783, -0.24876, -0.211396, 0.511853, 1.11235, 0.956214, 0.556205, 0.0702725, -0.342778, -0.615111, -0.164702, 0.150798, 0.190192, 0.29054, 0.588679, 0.694851, 0.113298, -0.976, -1.25353, 0.202827, 1.37431, 1.57967, 1.7564, 0.785833, -0.42798, 0.350347, 1.91077, 1.7544, 0.499723, -0.168146, 0.412002, 0.0985699, -0.050457, -0.0339451, -0.12261, -0.507401, -0.462592, -0.0859957, 0.206673, 0.506568, 0.689839, 0.498084, 0.0191689, -0.325343, -0.841579, -1.33201, -0.0872088, 1.09547, 1.29975, 1.82716, 1.51677, -0.129449, -0.383495, 0.383599, 1.23358, 0.263031, -0.404946, 0.313426, 1.0799, 1.06301, 0.209575, -0.0556707, -0.248734, -0.195978, 0.050005, 0.161844, 0.274388, 0.268575, 0.365033, 0.433925, 0.00303459, -0.552723, -1.11833, -0.609664, 0.907598, 2.86351, 0.84018, -0.561956, -0.874058, -0.602134, -0.0467091, 1.1835, 0.506205, 0.409205, 0.868424, 0.780131, 0.222161, 0.0618591, 0.075552, -0.136554, -0.532438, -0.357927, 0.00438976, 0.321786, 0.452143, 0.486804, -0.100038, -0.403475, -0.489706, -0.405449, -0.120437, 1.30182, 0.678832, 1.184, 2.15753, 1.70856, -0.663733, -0.47136, 0.398696, 1.38949, 0.813025, -0.117845, 0.439501, 0.727061, 0.569779, 0.195958, -0.275848, -0.596211, -0.604981, -0.408783, -0.109171, 0.0810242, 0.319651, 0.421953, 0.290783, 0.0326853, -0.615386, 0.265698, 1.44547, 1.10382, 1.4688, 1.59735, -0.56453, -1.88218, -1.45242, -0.34032, 0.775186, 0.154354, 0.454865, 1.57085, 2.16724, 1.44688, 0.644043, -0.147702, -0.668839, -0.836373, -0.199107, -0.076272, 0.202854, 0.439143, 0.512057, -0.0834999, -0.498967, -1.02861, -0.709563, 0.800972, 1.14947, 0.524351, 1.24385, 1.51088, 0.550293, -0.605727, -0.392059, -0.0690498, 0.21163, 0.0105972, -0.332385, 0.0245295, 0.525921, 0.856483, 0.741488, 0.585739, 0.676394, 0.533796, 0.25566, 0.107536, 0.0479832, 0.0870542, 0.198286, 0.389215, 0.536656, 0.695656, 0.539805, 0.332254, 0.216192, 0.279289, 0.334579, 0.203171, 0.0568218, 0.078619, 0.0354767, 0.0881586, 0.281004, 0.375355, 0.453212, 0.517692, 0.527373, 0.289859, 0.408157, 0.383009, 0.371452, 0.267693, 0.183173, 0.198405, 0.325407, 0.341586, 0.257807, 0.0644331, 0.208148, 0.30436]
plt.plot(t,y)
plt.ylabel('acceleration')
plt.savefig("oh32")
plt.show()
plt.close()
