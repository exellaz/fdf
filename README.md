# FDF

<p align="center">
	<img src="https://github.com/user-attachments/assets/21ed5241-b928-4a33-b731-61e93bc7836f"
</p>

FDF is short for 'fil de fer' in French which means 'wireframe model'. The goal of this project is to convert a file with a grid of height and optionally colour values into a 3D wireframe using a simple graphics library, MiniLibX.

## Status
Finished: 2024-06-10. Grade: 125/100.

## Usage
### Install Dependencies (Linux or WSL only)
```bash
sudo apt install libx11-dev libxext-dev zlib1g-dev libbsd-dev
```
macOS should have the necessary dependencies already

### Compile Using:
```bash
make
```

### Running the program:
```bash
./fdf maps/'map-name'.fdf
```
- Some maps can be found in the `maps` directory. New maps can be made as long as they are rectangular and follow the given format

### Examples
The following is an example of a .fdf file we use as an input for our program
```bash
./fdf maps/42.fdf
```
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```
and here is the output:
![Image](https://github.com/user-attachments/assets/74ce14bb-8d57-4827-81d9-08ac66c0bb6f)

#### Example of map with pre-defined colours
![Image](https://github.com/user-attachments/assets/7ca1098c-0ad0-4bbe-9c90-120ce5a5678a)


### Controls
- Exit Program: `ESC`
- Zoom In / Out: `= / -`
- Increase / Decrease elevation: `Z / X`
- Translate Up / Down / Left / Right: `Arrow keys`
- Rotate about X-axis: `W / S`
- Rotate about Y-axis: `J / L`
- Rotate about Z-axis: `A / D`
- Isometric Projection: `I`
- Orthographic Projection: `O`
  - Top-Down view: `T`
  - Front view: `F`
  - Side view: `G`
- Reset view: `R`
- Toggle colour preset: `.`
