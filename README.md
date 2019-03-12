# SiR2D

Simple Rasterizer - 2D is a program that takes in the description of vector shapes and converts that description into a raster image, i.e. a matrix of pixels. This software receive as input a scene description file coded in xml and outputs an image PPM that contains the rasterizaton of all Two-Dimensional (2D) primitives described in the input file. 

The SiR2D draw basic primitives such as Line, Circle and Polylines, as well as algorithms to fill in those primitives with solid colors. A color palette comes with 10 standard colors that can be easily used.

## How to compile

~~~~
$ make
~~~~

## How to execute

It to run the program is necessary specify an xml file. You can set a name for the image optionally.

~~~~
$ ./exe.out <xml_file> <image_name>
~~~~

## Color Paletter

The following colors can be used in scene description:

| Name | RGB | View |
| ---- | --- | ---- |
| red  | `(255, 0, 0)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/red.png) |
| green  | `(0, 255, 0)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/green.png) |
| blue  | `(0, 0, 255)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/blue.png) |
| black  | `(0, 0, 0)`   | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/black.png) |
| white  | `(255, 255, 255)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/white.png) |
| yellow  | `(255,255,0)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/yellow.png) |
| pink  | `(250, 91, 138)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/pink.png) |
| orange  | `(254, 123, 33)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/orange.png) |
| boldgreen  | `(34, 90, 14)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/boldgreen.png) |
| skyblue  | `(141, 207, 251)` | ![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/skyblue.png) |

## How to describe a scene
Initially, it is necessary introduce a scene through of tag `<scene></scene>`. A scene must necessarily have a canvas `<canvas></canvas>`. A shape is defined by tag `<shape></shape>`, it is necessary specify the shape type (line, polyline or circle), for example: `<shape type="circle" ...></shape>`. Each shape has a specific descriptions based on the [SVG](https://en.wikipedia.org/wiki/Scalable_Vector_Graphics) file format. A basic document is shown below.

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="circle" ... ></shape>
	<shape type="polyline" ... "></shape>
	<shape type="line" ... ></shape>
</scene>
~~~~

Each tag is composed by required and optional settings. If a required setting is not defined, a exception is thrown.

### Canvas

* Required settings
	-<p>  `height` : The canvas's height </p>
	-<p>  `width`  : The canvas's width  </p>
* Optional settings
	-<p>  `color`  : The canvas's background color (default: white)</p>

#### Examples


~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200"></canvas>
	...
</scene>
~~~~

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="red"></canvas>
	...
</scene>
~~~~

### Line


### Circle

### Polyline
