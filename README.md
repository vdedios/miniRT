# miniRT

> 👉 A small ray tracing engine written in C from scratch!

![picture alt](rendered_images/spalding.png "hello world!")

--- 

## BASIC INSTRUCTIONS

First of all you must compile the project:
``` bash
make #basic functionalities
make bonus #advance features such as texture handling and more!
``` 
For basic operation you must execute: `./miniRT "path_scene" --[options]` when compiling with `make`.

When compiling with `make bonus` you must execute `./miniRT_bonus "path_scene" --[options]`.

You can **move inside a scene** with the following controls:

Zoom | Translation | Rotation
--- | --- | ---
**Q** : Zoom in | **W** : Move up | **Mouse** : Click on the desire direction you want the camera to look at.
**E** : Zoom out | **S** : Move down
 | **A** : Move left
 | **D** : Move right

> :warning: _**Warning:** Since no bounding box or other performance algorithms are implemented movement isn't smooth in most cases since the program ray trace over and over again each frame. The purpose of this implementation was to allow the user to get the desired view quickly_ 
---

## GENERAL STANDARD OPTIONS
``` bash
--save #save rendered scene in a .bmp file. Scene will be output in ./output_bmp folder
```


## GENERAL BONUS OPTIONS
```bash
 --help : invoke this help menu
--sepia-filter : add a sepia filter to rendered image 
--antialiasing : apply aliased effect to rendered image
--no-specular : removes specular light effect which comes from default
--reference-axis : draws a set of global reference axis
``` 

## GENERAL SCENE OPTIONS

#### :flashlight: LIGHT FLAGS
```bash
parallel:1,0,0
#add parallel light following a precise direction. Example: l -20,0,5 0.7 255,255,255 parallel:1,0,0
```
#### :triangular_ruler: PLANE/TRIANGLE/SQUARE FLAGS

___Color disruptions:___
```bash    
skybox:textures/skybox.png 
#handle planar textures. Example: pl 0,0,-30 0,0,1 255,255,255 skybox:textures/skybox.png

checkered
#add a checkered pattern. Example: pl 0,0,-30 0,0,1 255,255,255 checkered
```
___Normal disruptions___
```bash
normal-disruption  
#add a normal disruption damped wave effect. Example: pl 0,0,-30 0,0,1 255,255,255 normal-disruption

bumpmap:texture/example.png 
#handle bumpmap textures. Example: pl 0,0,-30 0,0,1 255,255,255 bumpmap:texture/example.png
```

#### :basketball: SPHERE

___Color disruptions:___
```bash
rainbow
#add a color disruption rainbow effect depending on surface normal. Example: sp 0,0,0 20 255,255,255 rainbow

uv-map:texture/earth.png
#sphere texture. Example: sp 0,0,0 20 255,255,255 uv-map:texture/earth.png
```

___Normal disruptions:___
```bash    
normal-disruption
#add a normal disruption damped wave effect. Example: sp 0,0,-30 0,0,1 255,255,255 normal-disruption

bumpmap:texture/example.png
#handle bumpmap textures. Example: sp 0,0,-30 0,0,1 255,255,255 bumpmap:texture/example.png
```
#### :straight_ruler: CYLINDER

___Color disruptions:___
```bash
rainbow
#add a color disruption rainbow effect depending on surface normal. Example: sp 0,0,0 20 255,255,255 rainbow
```

1. To include these options/effects, you should add one or more of the following flags to the scene config file.
2. Each vector is presented as an example, you can substitute with your own.
3. Each texture/image file is presented as an example, you can substitute with your own. Path must be taken from the root of this proyect.
4. Each geometry can combine one option from each category: color or normal disruption. These options should be written one after oother with one space between each.
