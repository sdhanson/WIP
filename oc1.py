import matplotlib.pyplot as plt
t = [0, 0.015, 0.049, 0.066, 0.083, 0.1, 0.117, 0.149, 0.166, 0.183, 0.199, 0.217, 0.234, 0.266, 0.283, 0.299, 0.316, 0.35, 0.367, 0.383, 0.399, 0.416, 0.434, 0.468, 0.483, 0.501, 0.517, 0.533, 0.567, 0.584, 0.6, 0.617, 0.633, 0.668, 0.684, 0.701, 0.718, 0.735, 0.767, 0.784, 0.8, 0.817, 0.834, 0.868, 0.884, 0.901, 0.918, 0.935, 0.968, 0.984, 1.001, 1.018, 1.035, 1.068, 1.086, 1.101, 1.119, 1.135, 1.169, 1.185, 1.202, 1.218, 1.235, 1.268, 1.286, 1.302, 1.319, 1.335, 1.368, 1.385, 1.403, 1.419, 1.436, 1.47, 1.486, 1.502, 1.519, 1.536, 1.569, 1.586, 1.603, 1.619, 1.637, 1.654, 1.686, 1.704, 1.72, 1.737, 1.769, 1.787, 1.803, 1.82, 1.836, 1.869, 1.887, 1.903, 1.919, 1.938, 1.97, 1.987, 2.005, 2.02, 2.037, 2.053, 2.088, 2.103, 2.121, 2.137, 2.154, 2.188, 2.207, 2.221, 2.239, 2.254, 2.287, 2.305, 2.321, 2.338, 2.355, 2.387, 2.405, 2.422, 2.438, 2.455, 2.488, 2.505, 2.521, 2.538, 2.556, 2.588, 2.606, 2.623, 2.638, 2.655, 2.688, 2.706, 2.722, 2.739, 2.755, 2.788, 2.806, 2.822, 2.839, 2.855, 2.89, 2.906, 2.922, 2.94, 2.956, 2.989, 3.007, 3.023, 3.039, 3.057, 3.091, 3.106, 3.124, 3.14, 3.156, 3.174, 3.206, 3.223, 3.24, 3.256, 3.291, 3.307, 3.323, 3.34, 3.357, 3.373, 3.407, 3.423, 3.44, 3.457, 3.474, 3.507, 3.525, 3.54, 3.558, 3.574, 3.608, 3.624, 3.641, 3.657, 3.674, 3.708, 3.724, 3.741, 3.758, 3.774, 3.808, 3.824, 3.841, 3.858, 3.875, 3.908, 3.924, 3.942, 3.958, 3.975, 4.008, 4.025, 4.043, 4.059, 4.075, 4.109, 4.125, 4.142, 4.158, 4.176, 4.208, 4.226, 4.242, 4.259, 4.276, 4.309, 4.326, 4.343, 4.359, 4.375, 4.409, 4.426, 4.443, 4.46, 4.477, 4.509, 4.526, 4.542, 4.559, 4.576, 4.609, 4.626, 4.643, 4.659, 4.676, 4.694, 4.727, 4.744, 4.761, 4.776, 4.793, 4.826, 4.843, 4.861, 4.878, 4.893, 4.928, 4.943, 4.96, 4.977, 4.994, 5.027, 5.045, 5.06, 5.077, 5.096, 5.127, 5.144, 5.161, 5.18, 5.194, 5.228, 5.244, 5.261, 5.278, 5.295, 5.329, 5.344, 5.361, 5.378, 5.396, 5.428, 5.446, 5.462, 5.478, 5.495, 5.529, 5.545, 5.562, 5.579, 5.595, 5.629, 5.646, 5.662, 5.679, 5.695, 5.728, 5.746, 5.762, 5.78, 5.797, 5.813, 5.846, 5.862, 5.88, 5.896, 5.914, 5.946, 5.963, 5.979, 5.996, 6.029, 6.046, 6.063, 6.08, 6.098, 6.114, 6.147, 6.163, 6.18, 6.196, 6.213, 6.246, 6.264, 6.28, 6.297, 6.313, 6.347, 6.363, 6.38, 6.397, 6.414, 6.447, 6.465, 6.48, 6.498, 6.514, 6.547, 6.564, 6.582, 6.597, 6.615, 6.648, 6.664, 6.681, 6.698, 6.716, 6.748, 6.765, 6.781, 6.798, 6.816, 6.848, 6.865, 6.882, 6.899, 6.915, 6.949, 6.965, 6.982, 6.998, 7.016, 7.185, 7.186, 7.186, 7.187, 7.188, 7.188, 7.189, 7.19, 7.206, 7.219]
y = [-0.196853, -1.13362, -0.419687, 0.256723, 0.894122, 0.702759, 0.447308, 1.28684, 1.65919, 1.24598, 0.417778, -0.285718, -0.781575, -1.67945, -1.59429, -1.5538, -0.842014, 3.75136, 3.68148, 2.35338, 1.31558, -1.64453, -3.48612, 1.21213, 1.57548, 0.443896, -0.325087, -0.352841, 0.810277, 0.734786, 0.442158, 0.247404, -0.331847, -0.277734, 0.304963, 0.422966, 0.334692, 0.240123, 1.20186, 1.72544, 0.916406, 0.140426, -0.5457, -0.232597, -0.0191593, -0.417239, -0.575612, -0.44771, 0.11677, 3.15508, 4.25471, 2.00901, 1.47106, -0.621307, -2.51881, -4.4758, -4.38915, -1.05067, 2.96077, 2.06218, 2.14367, 1.61422, 0.496251, 0.10265, 0.271628, 0.328699, 0.0669661, -0.24633, -0.830851, -0.262343, -0.0949802, 0.291305, 0.522123, -0.0302257, -0.0098896, -0.0156336, -0.0532885, 0.184277, -0.322794, -1.57918, -2.33334, -2.48609, 2.4386, 6.33447, 1.98752, -2.61955, -3.45357, -1.00428, 1.90558, 2.28114, 0.982353, 0.290157, 0.340005, 0.160632, -0.569763, -0.848847, -0.689607, -0.32903, 0.0050354, -0.146732, -0.270331, -0.0767841, 0.622438, 1.22212, 0.581299, 0.142565, 0.0127459, 0.557567, 0.756631, -0.844448, -2.39225, -2.2374, -1.33736, 3.68841, 3.48751, 1.74879, 0.0864382, -1.54899, -4.13848, -1.91722, 1.89471, 2.96667, 2.72236, 1.41169, 0.205131, 1.0434, 2.2268, 1.64039, 0.477788, -0.814949, -0.668831, -0.524912, -0.231227, -0.100055, 0.361667, 0.335719, 0.0909214, 0.0211411, 0.148015, -0.401679, 0.356846, 0.16916, -1.20728, -2.43506, 3.30197, 6.27221, 4.03013, 0.0912046, -3.2932, -4.05776, -3.39671, 0.911041, 4.62291, 4.89439, 0.776376, 0.100094, 0.0767965, 0.505948, 0.200415, -0.854197, -1.80042, -0.599283, 0.471009, 0.877454, 0.559522, 0.700852, 0.838706, 0.539363, 0.300932, 0.186501, 0.115346, -0.152956, -0.445649, -1.11091, -1.24136, 0.379447, 0.60378, 3.25231, 3.78089, 3.37689, 1.29694, -0.891047, -4.29305, -6.06383, -4.06013, 5.0063, 4.28608, 1.40498, -0.638815, -1.20263, 0.817335, 1.78278, 1.71515, 0.858141, -0.064724, -0.909571, -0.793718, -0.340699, -0.275137, -0.220793, 0.56218, 0.210958, 0.71421, 1.20063, 0.691426, -1.13079, -1.93206, -2.25824, -1.20567, 0.0190668, 4.95983, 4.74047, 3.998, 0.973202, -2.20893, -4.09958, -1.11987, 1.93033, 3.08483, 2.32603, 0.353428, 0.942269, 2.2266, 1.5433, 0.300329, -1.89317, -2.35303, -1.59223, -0.502564, 0.706466, 1.49754, 0.679686, 0.335093, 0.301488, 0.416224, 0.744412, 0.315869, -0.295808, -0.354129, 0.234426, 0.0886631, -2.02111, -1.53996, 7.10431, 9.34655, 4.83819, -1.61393, -5.26414, -7.36913, -6.74338, -1.3776, 5.49403, 1.94497, -0.718107, -1.09547, -0.105093, 0.923141, 0.931531, 0.408253, -0.0410137, -0.16243, 0.0566053, -0.0557852, -0.0375414, -0.0769768, 0.0052166, 0.123361, -0.373157, -0.10364, 0.468014, 0.341356, -0.122928, -0.911333, -1.91472, -2.74818, -1.46873, 6.57545, 5.66115, 1.08035, -2.08176, -0.905786, 0.655868, -0.563513, -1.39429, -1.49598, -0.946836, 0.591398, 1.17744, 1.54628, 1.76759, 1.33946, 0.78341, 0.473377, 0.124508, -0.374513, -0.731205, -0.67683, -0.245806, -0.120842, -0.00401783, 0.173783, 0.343044, 0.502256, 0.768955, 0.446671, -0.00193119, -0.0695715, 0.27084, 0.412567, 0.332206, 0.326078, 0.399095, 0.229004, 0.155864, 0.239818, 0.417161, 0.43214, 0.294476, 0.237398, 0.30128, 0.406415, 0.442196, 0.396908, 0.214686, 0.172609, 0.317943, 0.353884, 0.407249, 0.247888, 0.223199, 0.165358, 0.148105, 0.157494, 0.208675, 0.297685, 0.325949, 0.289411, 0.243543, 0.23492, 0.247417, 0.358314, 0.310784, 0.285235, 0.24691, 0.160808, 0.19723, 0.262837, 0.325114, 0.295893, 0.275009, 0.212019, 0.230228, 0.286646, 0.286646, 0.286646, 0.286646, 0.286646, 0.286646, 0.286646, 0.286646, 0.267229, 0.295013]
plt.plot(t,y)
plt.ylabel('acceleration')
plt.savefig("oc18")
plt.show()
plt.close()
