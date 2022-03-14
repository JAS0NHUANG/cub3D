# cub3D
The 3D world inside a childhood memory.

# Notions:
1. The TUTO: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)  
2. [DDA](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm\)), [Rotation Matrix](https://en.wikipedia.org/wiki/Rotation_matrixhttps://en.wikipedia.org/wiki/Rotation_matrix), [Cartesian coordinate system](https://en.wikipedia.org/wiki/Cartesian_coordinate_system)), [Euclidean Distance](https://en.wikipedia.org/wiki/Euclidean_distance)

### Some Videos:
[Wolfenstein 3D's map renderer](https://www.youtube.com/watch?v=eOCQfxRQ2pY)
[Make Your Own Raycaster Part 1](https://www.youtube.com/watch?v=gYRrGTC7GtA)
[Coding Challenge #145: 2D Raycasting](https://www.youtube.com/watch?v=TOEi6T2mtHo)
[Super Fast Ray Casting in Tiled Worlds using DDA](https://www.youtube.com/watch?v=NbSee-XM7WA)
[Ray Casting versus Ray Tracing](https://www.youtube.com/watch?v=ll4_79zKapU)

[Raycasting engine in Factorio](https://www.youtube.com/watch?v=7lVAFcDX4eM)
[Writing my First Ray Casting Game using C++ and SFML - SFML Tutorial](https://www.youtube.com/watch?v=LUYxLjic0Bc)

# Steps:
1. Create `t_cub3d` struct type to store all information.  
2. Create `t_info` to store texture, celling and floor colors.
3. Read the .cub(map) file and check its content.  
	- Check if the argument finished with ".cub"  c
	- map:  
		Check all the 0s and make sure that they are all surrounded by 0 or 1.  
		Check there's only 1 player.(to be done)  
	- infos:  
		Check if all texture file ends in ".xpm".(to be done)  
		Check if all texture file can be opened.(to be done)  
		Check color code >= 0 and  <= 255.(to be done)  
		Check if there is exactly 3 numbers for celling and floor.(to be done)  
