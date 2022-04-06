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

# Ray Casting
posX posY		// player's position
dirX dirY		// player's direction
planeX planeY	// camera plane
// put above information in `t_player` struct.

for each x(in window's width)
- get the x point in the camera space (-1 ~ 1): cameraX = 2 * x / double(screen_width) - 1  
then use this information to calculate the `rayDirection` vector: rayDirectionX = dirX + planeX * cameraX; rayDirectionY = dirY + planeY * cameraX;


## Trigonometric Functions
/ˌtrɪɡ.ə.nəˈmet.rik/

Calculate the point while rotate R [radian](https://en.wikipedia.org/wiki/Radian):
```
oldPointX = pointX;
pointX = pointX * cos(R) - dirY * sin(R);
pointY = oldPointX * sin(R) - dirY * cos(R);
```


