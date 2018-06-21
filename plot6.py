import matplotlib.pyplot as plt
t = [0, 0.017, 0.034, 0.05, 0.067, 0.1, 0.116, 0.133, 0.15, 0.183, 0.2, 0.217, 0.234, 0.25, 0.283, 0.3, 0.317, 0.333, 0.351, 0.367, 0.402, 0.417, 0.433, 0.45, 0.468, 0.502, 0.518, 0.534, 0.551, 0.568, 0.601, 0.617, 0.635, 0.651, 0.668, 0.702, 0.718, 0.734, 0.751, 0.768, 0.801, 0.818, 0.835, 0.852, 0.868, 0.901, 0.918, 0.935, 0.952, 0.971, 1.002, 1.019, 1.035, 1.052, 1.069, 1.103, 1.119, 1.135, 1.152, 1.169, 1.202, 1.219, 1.236, 1.252, 1.27, 1.287, 1.319, 1.336, 1.353, 1.369, 1.387, 1.421, 1.437, 1.454, 1.469, 1.503, 1.52, 1.536, 1.553, 1.57, 1.589, 1.62, 1.637, 1.653, 1.671, 1.687, 1.72, 1.737, 1.755, 1.77, 1.787, 1.821, 1.837, 1.854, 1.872, 1.887, 1.922, 1.937, 1.954, 1.971, 1.989, 2.021, 2.037, 2.054, 2.071, 2.088, 2.121, 2.138, 2.154, 2.171, 2.188, 2.222, 2.238, 2.255, 2.272, 2.288, 2.321, 2.34, 2.355, 2.372, 2.388, 2.422, 2.438, 2.455, 2.473, 2.488, 2.507, 2.539, 2.556, 2.573, 2.589, 2.623, 2.639, 2.656, 2.672, 2.69, 2.722, 2.74, 2.756, 2.772, 2.79, 2.823, 2.84, 2.856, 2.874, 2.891, 2.923, 2.94, 2.956, 2.974, 2.99, 3.023, 3.04, 3.056, 3.073, 3.09, 3.108, 3.14, 3.157, 3.173, 3.19, 3.207, 3.24, 3.257, 3.274, 3.29, 3.307, 3.34, 3.357, 3.374, 3.391, 3.408, 3.441, 3.459, 3.474, 3.492, 3.508, 3.541, 3.558, 3.575, 3.591, 3.609, 3.642, 3.658, 3.675, 3.692, 3.708, 3.742, 3.759, 3.775, 3.792, 3.811, 3.842, 3.858, 3.875, 3.892, 3.909, 3.942, 3.96, 3.976, 3.992, 4.009, 4.042, 4.059, 4.076, 4.095, 4.111, 4.143, 4.159, 4.176, 4.192, 4.209, 4.227, 4.26, 4.276, 4.293, 4.31, 4.343, 4.36, 4.378, 4.393, 4.411, 4.443, 4.461, 4.477, 4.493, 4.511, 4.528, 4.561, 4.577, 4.594, 4.61, 4.627, 4.661, 4.677, 4.694, 4.712, 4.727, 4.764, 4.777, 4.794, 4.811, 4.829, 4.861, 4.878, 4.895, 4.911, 4.928, 4.961, 4.978, 4.996, 5.011, 5.028, 5.062, 5.078, 5.095, 5.112, 5.129, 5.162, 5.179, 5.195, 5.212, 5.229, 5.262, 5.279, 5.296, 5.312, 5.329, 5.362, 5.379, 5.396, 5.414, 5.429, 5.462, 5.48, 5.496, 5.513, 5.53, 5.563, 5.579, 5.596, 5.613, 5.629, 5.647, 5.679, 5.696, 5.713, 5.73, 5.764, 5.78, 5.797, 5.813, 5.83, 5.863, 5.88, 5.897, 5.913, 5.93, 5.963, 5.98, 5.998, 6.013, 6.03, 6.047, 6.08, 6.097, 6.115, 6.13, 6.148, 6.181, 6.197, 6.214, 6.231, 6.247, 6.281, 6.298, 6.314, 6.332, 6.349, 6.381, 6.399, 6.416, 6.431, 6.448, 6.481, 6.498, 6.515, 6.532, 6.549, 6.581, 6.598, 6.615, 6.632, 6.651, 6.682, 6.699, 6.715, 6.732, 6.75, 6.782, 6.799, 6.816, 6.832, 6.849, 6.883, 6.899, 6.916, 6.932, 6.949, 6.984, 7, 7.017, 7.033, 7.05, 7.083, 7.1, 7.117, 7.133, 7.15, 7.183, 7.2, 7.216, 7.233, 7.25, 7.284, 7.301, 7.317, 7.333, 7.35, 7.367, 7.4, 7.418, 7.434, 7.451, 7.467, 7.5, 7.517, 7.534, 7.551, 7.568, 7.601, 7.617, 7.634, 7.651, 7.668, 7.701, 7.718, 7.734, 7.751, 7.768, 7.801, 7.818, 7.835, 7.852, 7.868, 7.902, 7.919, 7.936, 7.952, 7.969, 8.002, 8.018, 8.036, 8.053, 8.069, 8.102, 8.119, 8.135, 8.153, 8.169, 8.203, 8.22, 8.237, 8.252, 8.269, 8.302, 8.319, 8.336, 8.353, 8.37, 8.387, 8.421, 8.437, 8.453, 8.47, 8.503, 8.521, 8.536, 8.553, 8.57, 8.588, 8.62, 8.636, 8.653, 8.671, 8.704, 8.72, 8.736, 8.753, 8.77, 8.787, 8.821, 8.837, 8.854, 8.87, 8.887, 8.92, 8.938, 8.954, 8.97, 8.987, 9.02, 9.037, 9.055, 9.071, 9.088, 9.121, 9.138, 9.154, 9.172, 9.188, 9.221, 9.239, 9.255, 9.271, 9.289, 9.321, 9.338, 9.355, 9.372, 9.388, 9.424, 9.438, 9.455, 9.472, 9.491, 9.522, 9.539, 9.556]
y = [0.206351, 0.229928, 0.318421, 0.321342, 0.411923, 0.509354, 0.320336, 0.316924, 0.166054, 0.221093, 0.278279, 0.29935, 0.282353, 0.338148, 0.27227, 0.340089, 0.225376, 0.245149, 0.213171, 0.284468, 0.332576, 0.340273, 0.207569, 0.265861, 0.162845, 0.131465, 0.0908022, 0.139846, 0.20759, 0.206368, 0.206612, 0.317805, 0.291756, 0.289411, 0.297953, 0.276171, 0.32357, 0.286552, 0.352359, 0.287958, 0.284416, 0.216873, 0.217322, 0.170045, 0.206365, 0.158218, 0.176987, 0.216295, 0.17565, 0.185164, 0.203638, 0.241806, 0.117477, 0.106463, 0.1664, 0.379312, 0.35048, 0.361604, 0.265177, 0.302876, 0.170342, 0.211988, 0.364467, 0.489464, 0.450147, 0.441764, 0.345644, 0.28889, 0.305347, 0.36398, 0.275537, 0.124023, 0.2704, 0.551033, 0.822234, 0.483562, 0.232625, 0.19063, 0.188682, 0.156381, 0.0694923, 0.270266, 0.119934, 0.068058, 0.319067, 0.627243, 0.787302, 0.718372, 0.365537, -0.138246, -0.786969, -0.188101, 1.29919, 2.22245, 2.14038, 1.04955, 0.18955, -0.3039, -1.06572, -1.63575, -1.58957, 0.207466, 0.897365, 0.762836, 0.463291, 0.248829, 0.539639, 0.23918, 0.369974, 0.805409, 1.16028, 0.217978, 0.144617, 0.195892, -0.0869198, -0.592397, 1.24, 1.96098, 0.372509, -0.523642, -1.64609, -1.13115, 1.63012, 2.84784, 2.27349, 1.06129, 0.422282, 1.04566, 0.166932, -0.633569, -0.928831, -0.36623, -0.136294, -0.151098, -0.0361366, 0.199998, 0.563602, 0.747549, 0.650772, 0.280242, -0.0699301, 0.24684, 0.740741, 0.600343, 0.0950451, -0.274224, 1.08174, 2.70316, 2.10528, 1.37307, 0.952447, -1.62804, -3.8169, -5.06923, -2.94008, 1.95832, 4.49611, 1.4725, 1.45397, 1.5438, 0.701353, -0.504745, -1.01236, -0.00437355, 0.695191, 0.627611, 0.0702009, -0.407391, -0.0580015, 0.52013, 0.780358, 0.431465, -0.608471, -0.781138, -0.12483, 0.438345, 0.791529, 0.0649309, -0.117484, 3.69774, 6.19428, 3.4565, -1.84842, -3.89486, -4.58099, -3.54729, -0.0662107, 2.26703, 0.393612, -0.213869, 0.606815, 1.54391, 1.09725, 0.237809, -0.109785, 0.0177841, 0.249355, 0.065712, -0.116611, 0.0292902, 0.270991, 0.309298, 0.209099, 0.235905, 0.0563173, -0.194218, -0.446595, -1.25502, -1.31755, -0.903036, -0.911657, 0.326091, 3.75844, 3.34454, 0.517756, -2.26974, -3.94248, 0.625565, 2.93213, 2.37914, 0.781962, 0.753208, 2.11329, 0.979883, -0.264257, -0.888679, -0.858957, -0.344736, -0.0160236, -0.28453, -0.371473, -0.175633, 0.202321, 0.208464, -0.0494661, -0.231026, -0.106714, 0.0244656, -0.556578, -0.89519, -1.15115, -0.993815, 2.6916, 5.84707, 2.20198, -2.74607, -5.5537, -5.58441, -0.214014, 1.84883, 1.8663, 1.57273, 2.19408, 2.54829, 1.93587, 1.50612, 1.24016, 0.972263, 0.34668, -0.00527573, -0.473577, -0.817957, -1.07695, -0.81457, -0.612337, -0.44516, -0.523668, -0.531663, 0.562393, 1.25414, 0.577212, -0.022646, -0.112881, 2.97608, 2.89773, 0.751468, -1.01588, -2.90326, -2.2921, 1.20496, 1.79684, 0.989947, 0.844673, 2.13654, 1.84721, 0.877102, 0.398973, 0.329995, 0.0894098, -0.44497, -0.831895, -0.747463, -0.441724, 0.224976, 0.225055, 0.0712385, -0.160268, -0.384606, -0.761158, -0.173032, 0.789144, 0.601057, -0.152662, -0.12952, 3.35157, 2.21145, -0.341426, -2.37726, -1.63739, 2.2711, 1.77515, 0.756082, -0.00962543, -0.002985, 0.267552, 0.194586, -0.103615, -0.480214, -0.637262, -0.18142, 0.00512695, 0.0763712, 0.135155, 0.0951557, -0.169404, 0.0677013, 0.669955, 1.00653, 1.09843, 0.523309, -0.838609, -1.86146, -2.01719, -1.67115, 4.17769, 3.31241, 1.31109, 0.413301, -0.31499, 0.306208, 2.31751, 1.91912, -0.439098, -1.61967, 0.374209, 1.17225, 0.749722, 0.470121, 0.342502, 0.207307, -0.35685, -0.671592, -0.611873, -0.206784, 0.641142, 0.671681, 0.144679, -0.52546, -1.05148, -1.30573, -1.19504, -0.714137, -0.532683, 1.53612, 4.79758, 3.09919, 0.178674, -1.17556, -0.519163, -0.289551, 0.239623, 0.250022, 0.321484, 0.300826, 0.309648, 0.400148, 0.397707, 0.0543709, -0.223625, -0.395409, -0.0696087, 0.0217018, 0.158068, 0.501173, 1.02937, 1.19249, 0.43053, -0.0943556, -0.391307, -0.518627, -0.506572, -0.903769, -1.3371, -1.47802, 0.649758, 5.28883, 2.91013, -0.278153, -2.17067, -2.73945, -1.55491, -0.629851, -0.0128794, 0.5293, 0.941362, 1.25871, 0.774363, 0.611767, 0.595152, 0.714029, 0.315398, 0.0972366, 0.139254, 0.178701, 0.140945, 0.0383635, 0.210124, 0.439464, 0.662249, 0.774964, 0.601185, 0.228437, 0.333785, 0.382264, 0.328248, 0.252205, 0.110701, -0.0870218, -0.197752, 0.0880423, 0.202289, 0.198805, 0.192857, 0.414555, 0.391384, 0.135849, 0.065073, 0.194351, 0.371219, 0.442158, 0.494506, 0.52628, 0.497014, 0.321941, 0.356472, 0.329841, 0.218806, 0.0489912, -0.0562057, -0.140455, -0.21843, -0.0874052, 0.138024, 0.252111, 0.281629, 0.312081, 0.35474, 0.439187, 0.3673, 0.365793, 0.375023, 0.327448, 0.240746, 0.229728, 0.298969, 0.241466, 0.258947, 0.305694, 0.29589, 0.274059, 0.360795, 0.20719, 0.27452, 0.272579, 0.293896, 0.360617, 0.264298, 0.37748, 0.531449]
plt.plot(t,y)
plt.ylabel('acceleration')
plt.savefig("on36")
plt.show()
plt.close()
