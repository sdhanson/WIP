import matplotlib.pyplot as plt
t = [0, 0.041, 0.042, 0.056, 0.088, 0.105, 0.122, 0.138, 0.172, 0.188, 0.205, 0.222, 0.238, 0.272, 0.289, 0.306, 0.322, 0.34, 0.356, 0.389, 0.407, 0.422, 0.439, 0.456, 0.489, 0.507, 0.523, 0.54, 0.556, 0.59, 0.606, 0.624, 0.64, 0.657, 0.69, 0.707, 0.723, 0.74, 0.757, 0.79, 0.81, 0.825, 0.84, 0.857, 0.89, 0.907, 0.924, 0.94, 0.957, 0.99, 1.007, 1.024, 1.041, 1.059, 1.091, 1.108, 1.125, 1.141, 1.158, 1.191, 1.209, 1.225, 1.241, 1.258, 1.292, 1.308, 1.325, 1.341, 1.358, 1.391, 1.409, 1.425, 1.442, 1.458, 1.492, 1.508, 1.525, 1.542, 1.56, 1.592, 1.609, 1.625, 1.643, 1.659, 1.692, 1.709, 1.726, 1.742, 1.76, 1.776, 1.81, 1.826, 1.844, 1.859, 1.877, 1.909, 1.926, 1.943, 1.96, 1.976, 2.01, 2.026, 2.043, 2.061, 2.077, 2.111, 2.126, 2.144, 2.16, 2.177, 2.21, 2.228, 2.243, 2.261, 2.277, 2.311, 2.328, 2.344, 2.361, 2.378, 2.41, 2.428, 2.444, 2.461, 2.477, 2.511, 2.529, 2.544, 2.561, 2.578, 2.612, 2.628, 2.645, 2.661, 2.678, 2.711, 2.729, 2.745, 2.761, 2.78, 2.811, 2.828, 2.845, 2.861, 2.88, 2.896, 2.929, 2.945, 2.962, 2.978, 2.997, 3.029, 3.046, 3.064, 3.079, 3.096, 3.13, 3.145, 3.162, 3.179, 3.196, 3.229, 3.247, 3.263, 3.279, 3.296, 3.329, 3.346, 3.363, 3.38, 3.396, 3.43, 3.446, 3.464, 3.48, 3.497, 3.53, 3.547, 3.563, 3.58, 3.598, 3.63, 3.647, 3.663, 3.68, 3.697, 3.733, 3.748, 3.764, 3.781, 3.797, 3.831, 3.847, 3.864, 3.882, 3.898, 3.931, 3.949, 3.964, 3.981, 3.997, 4.031, 4.048, 4.066, 4.081, 4.098, 4.116, 4.148, 4.165, 4.181, 4.199, 4.231, 4.25, 4.265, 4.282, 4.298, 4.332, 4.349, 4.365, 4.382, 4.398, 4.416, 4.449, 4.467, 4.482, 4.499, 4.533, 4.549, 4.566, 4.583, 4.599, 4.616, 4.649, 4.666, 4.683, 4.699, 4.717, 4.75, 4.767, 4.783, 4.8, 4.821, 4.85, 4.866, 4.884, 4.9, 4.917, 4.951, 4.966, 4.983, 5, 5.017, 5.051, 5.068, 5.084, 5.1, 5.117, 5.15, 5.168, 5.184, 5.201, 5.217, 5.25, 5.267, 5.284, 5.301, 5.317, 5.351, 5.368, 5.384, 5.401, 5.418, 5.451, 5.468, 5.485, 5.501, 5.519, 5.551, 5.568, 5.585, 5.601, 5.618, 5.636, 5.668, 5.685, 5.702, 5.719, 5.753, 5.768, 5.785, 5.802, 5.818, 5.836, 5.87, 5.886, 5.902, 5.919, 5.936, 5.969, 5.986, 6.002, 6.02, 6.037, 6.071, 6.087, 6.102, 6.119, 6.137, 6.169, 6.186, 6.203, 6.22, 6.237, 6.27, 6.287, 6.303, 6.321, 6.337, 6.37, 6.387, 6.403, 6.42, 6.438, 6.47, 6.487, 6.504, 6.52, 6.537, 6.572, 6.587, 6.604, 6.622, 6.637, 6.671, 6.688, 6.704, 6.721, 6.738, 6.771, 6.789, 6.805, 6.821, 6.838, 6.871, 6.888, 6.904, 6.921, 6.938, 6.971, 6.988, 7.005, 7.021, 7.038, 7.073, 7.088, 7.105, 7.122, 7.138, 7.172, 7.189, 7.205, 7.223, 7.239, 7.273, 7.29, 7.305, 7.323, 7.339, 7.356, 7.389, 7.406, 7.422, 7.44, 7.456, 7.49, 7.507, 7.523, 7.539, 7.557, 7.589, 7.606, 7.623, 7.64, 7.657, 7.69, 7.706, 7.723, 7.74, 7.758, 7.79, 7.807, 7.823, 7.841, 7.857, 7.892, 7.908, 7.925, 7.94, 7.957, 7.99, 8.007, 8.025, 8.041, 8.057, 8.076, 8.108, 8.124, 8.141, 8.158, 8.192, 8.208, 8.225, 8.241, 8.258, 8.291, 8.308, 8.325, 8.341, 8.358, 8.392, 8.408, 8.425, 8.441, 8.459, 8.491, 8.509, 8.525, 8.541, 8.558, 8.592, 8.609, 8.626, 8.642, 8.658, 8.676, 8.709, 8.726, 8.742, 8.761, 8.792, 8.81, 8.826, 8.842, 8.859, 8.877, 8.909, 8.926, 8.944, 8.959, 8.976, 9.009, 9.026, 9.043, 9.06, 9.078, 9.11, 9.126, 9.143, 9.16, 9.177, 9.21, 9.228, 9.244, 9.26, 9.277, 9.31, 9.327, 9.344, 9.361, 9.377, 9.414, 9.427, 9.444, 9.461, 9.477, 9.511, 9.528, 9.544, 9.561, 9.578, 9.611, 9.628, 9.645, 9.661, 9.678, 9.712, 9.728, 9.745, 9.762, 9.778, 9.811, 9.829, 9.846, 9.861, 9.878, 9.912, 9.928, 9.945, 9.962, 9.978, 9.996, 10.029, 10.045, 10.063, 10.08, 10.096, 10.129, 10.145, 10.162, 10.179, 10.196, 10.229, 10.246, 10.262, 10.279, 10.296, 10.329, 10.347, 10.363, 10.379, 10.396, 10.429, 10.446, 10.463, 10.48, 10.496, 10.531, 10.546, 10.563, 10.581, 10.597, 10.63, 10.648, 10.664, 10.68, 10.698, 10.73, 10.747, 10.764, 10.781, 10.798, 10.83, 10.847, 10.864, 10.881, 10.897, 10.931, 10.947, 10.964, 10.981, 10.998, 11.031, 11.049, 11.064, 11.082, 11.099, 11.131, 11.148]
y = [0.261075, 0.263184, 0.263184, 0.248862, 0.226413, 0.158327, 0.25015, 0.316745, 0.427891, 0.317657, 0.292482, 0.286254, 0.449346, 0.459643, 0.263316, 0.242236, 0.229242, 0.29278, 0.224209, -0.0434666, -0.031167, 0.0438614, 0.278333, 0.273128, 0.0395145, 0.084754, 0.191244, 0.261059, 0.29805, 0.236368, 0.143345, 0.213018, 0.340604, 0.357861, 0.249106, 0.132121, 0.2905, 0.264142, 0.026722, 0.726836, 0.845932, 0.540659, 0.172958, 0.0359907, 0.201906, 0.0138445, 0.19552, 0.621331, 0.632814, 0.217425, 0.0798931, 0.364323, 1.00872, 0.894909, -0.217499, -0.292027, -0.0151701, 0.231775, 0.360537, 0.0422554, -0.0863924, -0.160953, 0.0286551, 0.347232, 0.45063, 0.24639, 0.0776958, 0.1756, 0.0278339, 0.124676, 0.498988, 0.553608, 0.235589, 0.210138, 0.536274, 0.585203, 0.408704, 0.361215, 0.269608, 0.192179, 0.23999, 0.164792, 0.0180407, -0.0507288, 0.307241, 0.313718, 0.14661, 0.238831, 0.138185, 0.0621386, 0.18937, 0.242678, 0.217153, 0.229954, 0.317574, 0.326424, 0.316656, 0.183812, 0.109487, 0.0289211, 0.944306, 1.24801, 1.16037, 0.646966, 0.157917, -0.144616, -0.332501, -0.1865, 0.0249929, 0.0718002, 0.0657673, 0.331686, 0.388228, 0.284058, 0.172031, 0.181597, 0.229136, 0.374488, 0.382597, 0.384431, 0.148481, 0.0587721, 0.0587969, 0.233246, 0.267832, 0.143247, -0.112588, -0.146153, -0.0353041, 0.212873, 0.342743, 0.41006, 0.351786, 0.263027, 0.219914, 0.328013, 0.366016, 0.288681, 0.256815, 0.318076, 0.333892, 0.2029, 0.320829, 0.449642, 0.461192, 0.650884, 0.713985, 0.431681, 0.314938, 0.215223, 0.192683, 0.0679331, 0.113127, 0.160608, 0.25003, 0.367125, 0.25862, 0.236876, 0.15384, 0.123209, 0.16596, -0.194699, -0.351467, -0.252955, -0.196415, -0.270025, 0.19216, 0.632729, 0.58362, 0.14538, 0.195229, 0.807944, 1.02022, 1.19466, 1.0042, 0.714196, 0.180972, 0.583731, 0.952224, 0.908673, 0.232082, -0.928343, -0.733227, -0.378534, -0.487879, -0.49015, 0.526751, 0.970178, 1.32342, 1.23878, 0.893596, -0.0756788, -0.395694, -0.0525475, 0.554633, 1.20888, 0.433335, -0.503156, -1.03961, -1.3138, -1.67248, 4.29862, 3.5007, 0.320754, -2.04334, -3.36489, -4.13668, 0.394365, 2.79096, 3.75941, 2.93935, 1.2748, 1.67289, 2.05295, 1.58154, 0.695511, -1.03075, -1.11153, -0.45385, -0.224822, -0.313692, -0.306667, -0.742838, -0.789084, -0.543399, -0.274922, -0.688533, -1.68613, -1.71443, -1.06684, -0.228814, -0.600958, 2.72516, 4.45772, 4.29063, 2.50119, 0.350892, -4.11552, -3.1359, -0.265024, 1.8283, 2.81004, 2.1956, 2.18682, 1.86146, 1.63023, 0.848121, -0.825751, -1.77834, -2.17937, -1.68383, -0.873542, 1.53544, 2.03929, 1.09153, 0.619177, 0.32298, 0.63444, 0.0633287, -1.02161, -2.13911, -1.87435, 4.59627, 5.26362, 2.25548, 1.49554, 0.685759, -4.41117, -5.06456, -2.91152, 0.119025, 1.34441, 0.995585, 1.34791, 1.87361, 1.55141, 0.85519, 1.45863, 1.67136, 1.22249, 0.417176, -0.422481, -0.826638, -0.476945, -0.0997992, 0.178545, 0.121529, -0.503116, -0.84579, -0.882903, -0.769887, -0.380624, -0.0587597, 8.48755, 2.63215, -1.82371, -3.41451, -5.47792, -4.75801, 0.0941, 4.73522, 4.4275, 2.00762, 0.654234, 1.44345, 1.96588, 1.34792, 0.503342, -0.917559, -1.09949, -0.803446, -0.454752, -0.296905, 0.960754, 1.61086, 1.36703, 0.81697, 0.396701, 0.682306, 0.192456, -0.980032, -1.98893, -2.41109, -1.52522, 0.0252228, 5.05514, 3.67972, 4.83122, -1.15841, -2.696, -2.20023, -1.35839, 0.123725, 1.70158, 1.08044, 0.31412, 0.833667, 1.16909, 0.588451, -0.0182781, -0.174003, -0.150403, -0.128497, -0.073039, 0.516677, 1.11745, 1.02934, 0.384393, -0.673261, -0.596777, -0.130958, -0.0207567, -0.408782, -1.13376, -1.50286, 0.486392, 6.15227, 5.3561, -0.444186, -4.37349, -5.58874, -3.10975, 1.06299, 2.27855, 0.160003, -0.659764, 0.0958939, 1.0477, 1.03503, -0.302612, -0.222014, 0.21436, 0.540462, 0.796745, 0.139569, -0.269128, 0.0600452, 0.852215, 1.34756, 0.443573, -0.272713, -0.386773, 0.407563, 0.831072, -0.593792, -1.07825, -0.883803, -0.755844, 2.91527, 2.35959, 2.78493, 0.537204, -2.5533, -4.57085, -2.03136, 1.09799, 2.38071, 2.32332, 1.66433, 0.608736, 0.670662, 0.78272, 0.100914, -0.531496, -0.550531, -0.0569458, 0.140515, 0.318551, 0.432611, 0.222996, 0.202635, 0.38576, 0.450118, -0.0544405, 0.544665, 0.952469, 0.894416, -0.611372, -1.42274, -0.655212, 2.64856, 2.74876, 1.95651, 0.451449, -3.4319, -4.22903, -1.40652, 1.83639, 4.30823, 2.23646, 1.18918, 0.434354, 0.397581, 0.671902, 0.233875, -1.28081, -1.12048, -0.340882, 0.625393, -0.00875854, -0.947777, -0.340108, 0.693955, 1.20805, 1.17087, -0.312081, -0.269599, 0.106381, 0.203927, -0.0246382, -1.11976, 1.48001, 10.0114, 7.39012, 0.123042, -6.1834, -3.28597, -2.2878, -1.21187, 0.116673, 1.31327, 0.432937, 0.486412, 0.885944, 1.28133, 1.96188, 1.16296, -0.0579185, -0.469359, -0.393359, -0.013341, -0.276291, -0.055994, 0.479826, 0.776373, 0.0226269, -0.51985, -0.311392, 0.167389, -0.131669, 1.15912, 0.655239, -0.0180683, -0.961857, -1.1789, 4.10209, 2.91281, 2.09492, 1.04377, -0.727012, -2.44164, -2.1668, -1.5046, -0.659865, 0.127883, 0.499916, 1.18339, 1.87365, 1.88062, 1.0984, 0.376714, 0.405313, 0.32911, 0.0882254, -0.660818, -1.22337, -1.10897, -0.929582, -0.710931, -0.402183, -0.102587, 0.115839, -0.154659, -0.612123, -1.05049, -0.70451, 0.990164, 0.901269, 0.331465, -0.0235853, -0.0481091, 0.616676, 0.154777, -0.372299, -0.679846, -0.595115, 0.255151, 0.55013, 0.693978, 0.571615, 0.329938, 0.563865, 1.47588, 2.07119, 1.9926, 1.53794, 0.511559, 0.378109, 0.430795, 0.62455, 0.590097, 0.322015, 0.256367, 0.631556, 0.865907, 0.679027, 0.300899, 0.236329, 0.332315, 0.357225, 0.246999, 0.173039, 0.308121, 0.385566, 0.31354, 0.255739, 0.106656, 0.182456]
plt.plot(t,y)
plt.ylabel('acceleration')
plt.savefig("oh21")
plt.show()
plt.close()
