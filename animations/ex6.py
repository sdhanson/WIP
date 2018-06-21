#!/usr/bin/env python
# import needed modules
import os, numpy, matplotlib, matplotlib.pyplot
# create the data arrays
x = numpy.linspace(-numpy.pi, numpy.pi, 101)
y = numpy.sin(x)
# settings
plotfilename = 'plot.png'
# make the plot
fig = matplotlib.pyplot.figure()
ax = fig.add_subplot(1,1,1)
ax.plot(x,y,marker=None,color='blue')
# annotate the plot
ax.set_title('a simple 2d plot')
ax.set_xlabel('x')
ax.set_ylabel('sin(x)')
# save the plot
fig.show();
fig.savefig(plotfilename)