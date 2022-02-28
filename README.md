# cub3D
The 3D world inside a childhood memory.

# Notions:
	1. The TUTO: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)  
	2. [DDA](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm\)), [Rotation Matrix](https://en.wikipedia.org/wiki/Rotation_matrixhttps://en.wikipedia.org/wiki/Rotation_matrix), [Cartesian coordinate system](https://en.wikipedia.org/wiki/Cartesian_coordinate_system)), [Euclidean Distance](https://en.wikipedia.org/wiki/Euclidean_distance)

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
