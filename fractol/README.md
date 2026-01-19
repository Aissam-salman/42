*This project has been created as part of the 42 curriculum by alamjada*


# Fract_ol 

# Description

Fractals are shapes that are smaller copies of the original shape.
Like Russian dolls, shapes contain similar shapes within themselves, and this process continues infinitely.

To work on this project, we had access to the MiniLibX library.

We had to represent both the Julia set and the Mandelbrot set.

The mathematical formula is the same for both sets:
f(z) = z² + c

However, for the Mandelbrot set, z is a constant equal to 0 and c varies, whereas for the Julia set, c is a constant given as a parameter.

In addition, the Mandelbrot set can be seen as a kind of map showing where Julia sets are connected and where they are not.

Algorithms used:
– Linear interpolation
– Smooth coloring

[subject](https://cdn.intra.42.fr/pdf/pdf/184938/en.subject.pdf)

# Instructions

- Compile the project
`make`

- Run
`./fractol mandelbrot`

`./fractol julia <param1> <param2>`

# Resources
## Videos
- https://www.youtube.com/watch?v=ANLW1zYbLcs
- https://www.youtube.com/watch?v=FFftmWSzgmk
- https://www.youtube.com/watch?v=NGMRB4O922I
- https://youtu.be/6IWXkV82oyY
## Articles
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
- https://fr.wikipedia.org/wiki/Fractale
- https://brunomarion.com/fr/les-fractales-pour-les-nuls/
- https://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value
- https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set#Histogram_coloring
- https://en.wikipedia.org/wiki/Linear_interpolation
