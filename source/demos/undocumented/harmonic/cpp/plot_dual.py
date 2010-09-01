# Import matplotlib
from pylab import *

# Import solution
from solution_dual import *

# Plot solution
plot(t, u[:,0], t, u[:,1])
xlabel('t')
ylabel('U(t)')
title('Harmonic oscillator (dual)')
show()