*This project has been created as part of the 42 curriculum by dverdini.*


### Description
'fract-ol' is a graphical project from the 42 curriculum.

The goal of this project is to render and explore mathematical fractals using
the Minilibx graphical library. The program displays fractals in a window,
allows the user to zoom into their structures, move through the complex plane,
and interact with colors and parameters.

### Instructions
- clone the repo
- compilation
    make
    make clean
    make fclean
    make re
- execution
    ./fractol mandelbrot
    ./fractol julia <real> <imaginary>
    Example:        -0.8        0.156  
    ./fractol burning_ship
- Controls:
    - ESC: close the program.
    - Window close button: close the program.
    - Mouse wheel: zoom in / zoom out.
    - Arrow keys: move inside the fractal/
    - W, A, S, D: move inside the fractal.
    - C: shift the color palette.
    - Mouse movement on Julia: dynamically changes the Julia parameters.

### Explanation
MiniLibx images are used instead of drawing directly pixel by pixel to the window.
The rendering process is:
- Each screen pixel is converted into a coordinate of the complex plane.
- A specific fractal formula is applied.
- The program counts the number of iterations before escape.
- The pixel is written into the image buffer.
- The image is displayed in the window.

A central structure is used to store the program state, including MinilibX
pointers, the image buffer, the selected fractal type, zoom level, offsets,
Julia parameters, color shift, and iteration limit.

### Resources
- 42 fract-ol subject.
- Minilibx documentation.
- Wikipedia.
- Math university materials.
- Peer discussions and project correction grid.
- ai was used to refresh my memory on mathematical concepts
