<div align="center">
   <h1>MiniRT</h1>
   <p><i>MiniRT is a ray tracing program developed as a project for the 42 school. It aims to create realistic computer-generated images by simulating the behavior of light rays as they interact with objects in a scene. This project serves as a hands-on exploration of computer graphics principles, including ray tracing algorithms, lighting models, and scene rendering techniques.<br></i></p>
</div>

---

## Features

MiniRT provides the following features:

- **Scene Rendering**: MiniRT can render 3D scenes composed of various geometric objects such as spheres, planes, cylinders, and cones.
- **Camera Control**: Users can specify camera parameters including position, orientation, field of view, and aspect ratio to define the viewpoint for rendering.
- **Lighting Models**: MiniRT supports different lighting models including ambient, point, and directional lighting, allowing users to control the illumination of the scene.
- **Shading**: MiniRT implements shading models such as Phong shading to calculate the color of each pixel in the rendered image based on lighting conditions and surface properties.
- **Shadows**: MiniRT simulates shadows cast by objects in the scene, adding realism to the rendered images.
- **Specular Reflection**: MiniRT supports specular reflection effects for shiny surfaces.
- **Colored and Multi-Spot Lights**: Support multiple light sources with different colors.
- **Bump Mapping**: MiniRT can handle bump map textures for enhanced surface detail.
- **Scene Parsing**: Users can define scenes using a simple scene description language.

## Compatibility

MiniRT is compatible with:

- MacOS
- Linux

## Getting Started

### For Linux

1. Before running MiniRT on Linux, ensure that you have the necessary dependencies installed. You may need to install the following packages:

   ```bash
   sudo apt-get update
   sudo apt-get install build-essential -y
   sudo apt-get install xorg -y
   sudo apt-get install libxext-dev -y
   ```

2. Clone the repository:

   ```bash
   git clone https://github.com/jesuismarie/RayTracer-MiniRT.git
   ```

3. Change into the project directory:

   ```bash
   cd RayTracer-MiniRT
   ```

4. Compile the program:

    ```bash
    make
    ```

5. Run MiniRT with a scene file:

    ```bash
    ./minirt scenes/scene.rt
    ```

### For MacOS

1. Clone the repository:

    ```bash
    git clone https://github.com/jesuismarie/RayTracer-MiniRT.git
    ```

2. Change into the project directory:

    ```bash
    cd RayTracer-MiniRT
    ```

3. Compile the program:

    ```bash
    make
    ```

4. Run MiniRT with a scene file:

    ```bash
    ./minirt scenes/scene.rt
    ```

## Usage

MiniRT provides a command-line interface where users can specify scene parameters and rendering options. Here are some example commands:

- Render a scene with default settings:

    ```bash
    ./minirt scenes/scene.rt
    ```

For more information on available options and scene description syntax, please refer to the project documentation.

## Additional Test Cases

To further test the capabilities of MiniRT, you can use the provided scene files in the `scenes/` directory. These files contain various scenes with different geometries, lighting setups, and rendering parameters to showcase the capabilities of MiniRT.

## .rt File Specification

Scene description files (.rt) are used to define the parameters of the 3D scenes that MiniRT will render. These files provide a structured way to specify the geometry, lighting, camera, and other properties of the scene. Each type of element can be separated by one or more line break(s). Each type of information from an element can be separated by one or more space(s). Each type of element can be set in any order in the file. Elements which are defined by a capital letter can only be declared once in the scene (except lights).

### .rt File Structure

#### Ambient Lighting

Defines the ambient lighting in the scene:

- `identifire`: **A**
- `ambient lighting` ratio in range [0.0,1.0]: **0.2**
- `R,G,B colors` in range [0-255]: **255, 255, 255**

    ```
    A      0.2   255,255,255
    ```

#### Camera

Specifies the camera parameters:

- identifire: **C**
- `x,y,z coordinates` of the view point: **-50.0,0,20**
- `3d normalized orientation vector.` In range [-1,1] for each x,y,z axis: **0.0,0.0,1.0**
- `FOV`: Horizontal field of view in degrees in range [0,180]: **70**

    ```
    C  -50.0,0,20      0,0,1     70
    ```

#### Lights

Defines the light sources in the scene:

- `identifire`: **C**
- `x,y,z coordinates` of the view point: **-40.0,50.0,0.0**
- `the light brightness` ratio in range [0.0,1.0]: **0.6**
- `R,G,B colors` in range [0-255]: **10, 0, 255**

    ```
    L   -40.0,50.0,0.0    0.6   10,0,255
    ```

#### Objects

Defines the objects in the scene:

**Sphere**

- `identifier`: **sp**
- `x,y,z coordinates` of the sphere center: **0.0,0.0,20.6**
- `the sphere diameter`: **12.6**
- `R,G,B colors` in range [0-255]: **10, 0, 255**

    ```
    sp 0.0,0.0,20.6     12.6   10,0,255
    ```

**Plane**

- `identifier`: **pl**
- `x,y,z coordinates` of a point in the plane: **0.0,0.0,-10.0**
- `3d normalized normal vector.` In range [-1,1] for each x,y,z axis: **0.0,1.0,0.0**
- `R,G,B colors` in range [0-255]: **0,0,225**

    ```
    pl    0.0,0.0,-10.0    0.0,1.0,0.0   0,0,225
    ```

**Cylinder**

- `identifier`: **cy**
- `x,y,z coordinates` of the center of the cylinder: **50.0,0.0,20.6**
- `3d normalized vector` of axis of cylinder. In range [-1,1] for each x,y,z axis: **0.0,0.0,1.0**
- `the cylinder diameter`: **14.2**
- `the cylinder height`: **21.42**
- `R,G,B colors` in range [0,255]: **10, 0, 255**

    ```
    cy 50.0,0.0,20.6   0.0,0.0,1.0   14.2     21.42  10,0,255
    ```

**Cone**

- `identifier`: **cy**
- `x,y,z coordinates` of the center of the cylinder: **50.0,0.0,20.6**
- `3d normalized vector` of axis of cylinder. In range [-1,1] for each x,y,z axis: **0.0,0.0,1.0**
- `the cylinder diameter`: **14.2**
- `the cylinder height`: **21.42**
- `R,G,B colors` in range [0,255]: **10, 0, 255**

    ```
    co      50.0,0.0,20.6   0.0,0.0,1.0   14.2 21.42  10,0,255
    ```

## Project Structure

The project structure is as follows:

- `sources/`: Contains the source code files.
- `includes/`: Contains the header files.
- `scenes/`: Contains example scene files.
- `Makefile`: The Makefile for compiling the project.

## Dependencies

MiniRT has the following dependencies:

- C compiler (e.g., CC)
- Make
- miniLibX (for window management and image rendering)

## License

[**Apache 2.0 License**](./LICENSE)
