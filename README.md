# Graphic Car

Drawing a car using OpenGl in Visual Studio 2019

# Documentation

Every component of the car is drawn using the function glVertex3f(x, y, z). With this function, we specify the dots of the shape we want to draw. 

All these dots will connect based on the shape we specify at the beginning of the block. A block starts with glBegin(SHAPE) and ends with glEnd().

Exemple:

glBegin(GL_QUADS);

glColor3f(x1, y1, z1);

glVertex3f(x2, y2, z2);

...

glEnd();

The car moves left or right (using leftArrow or rightArrow), up or down (using upArrow or downArrow). It can also rotate using leftClick or rightClick.

Besides the car, there is a light source. 
