# SiR2D

Simple Rasterizer - 2D is a program that takes in the description of vector shapes and converts that description into a raster image, i.e. a matrix of pixels. This software receive as input a scene description file coded in xml and outputs an image PPM that contains the rasterizaton of all Two-Dimensional (2D) primitives described in the input file. 

The SiR2D draw basic primitives such as Line, Circle and Polylines, as well as algorithms to fill in those primitives with solid colors. A color palette comes with 10 standard colors that can be easily used.

## Dependencies

For execute this software, the `Boost c++ libaries` is necessary. If `Boost` is not installed on your PC, follow the steps:

1. Log on to the computer as the root user or as a user with sudo permissions.
2. Download the Boost C++ libraries. For example, go to [Boost C++ libaries](https://sourceforge.net/projects/boost/files/boost/1.66.0/), and download `boost_1_66_0.zip`.
3. Decompress `boost_1_66_0.zip`. For example, go to the directory where you downloaded `boost_1_66_0.zip`, and enter the following command: `unzip boost_1_66_0.zip`.
4. Go to the `boost_1_66_0` directory.
5. Enter the following command to build the installer: `./bootstrap.sh`.
6. Enter the following command to run the installer: `./b2 install`.

Reference [IBM Knowledge Center](https://www.ibm.com/support/knowledgecenter/en/SSWTQQ_1.0.0/com.ibm.swg.ba.cognos.trade_analytics.1.0.0.doc/t_trd_installboost.html)

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
	-  `height` : The canvas's height 
	-  `width`  : The canvas's width  
* Optional settings
	-  `color`  : The canvas's background color (default: white)

The largest recommended canvas size is 400 x 400
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

* Required settings
	-  `x1` : The x axis value of the init point
	-  `y1` : The y axis value of the init point
	-  `x2` : The x axis value of the target point
	-  `y2` : The y axis value of the target point
* Optional settings
	-  `stroke`  : The Line's border color (default: black)

#### Examples

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="line" x1="10" y1="10" x2="135" y2="180"></shape>
</scene>
~~~~


##### Output
![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/line1.png)

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="line" x1="10" y1="10" x2="135" y2="180" stroke="blue"></shape>
</scene>
~~~~


##### Output
![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/line2.png)

### Circle

* Required settings
	-  `cx` : The x axis value of the middle point circle
	-  `cy` : The y axis value of the middle point circle
	-  `r`  : The Circle's radius
* Optional settings
	-  `stroke` : The Circle's border color (default: black)
	-  `fill`   : The Circle's fill color (default: white)

#### Examples

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="circle" cx="100" cy="100" r="80"></shape>
</scene>	
~~~~

##### Output
![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/circle1.png)

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="circle" cx="100" cy="100" r="80" stroke="blue" fill="pink""></shape>
</scene>	
~~~~

##### Output
![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/circle2.png)

### Polyline

* Required settings
	-  `points` : The set of point that define a polyline
* Optional settings
	-  `stroke` : The Polyline's border color (default: black)
	-  `polygon`: Use the value _true_ if polyline define a polygon and _false_ othewise (default: false). If polygon value is _false_, no fill algorithm will be used.
	-  `fill`   : The Polyline's fill color (default: white)
	-  `pcolor` : Define one or more points for use the flood fill algorithm, if not defined, the scan line algorithm be use.

#### Examples

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="polyline"  points="0,40 40,40 40,80 80,80 80,120 120,120 120,160 160,160 160,180" ></shape>
</scene>	
~~~~

##### Output
![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/polyline1.png)


~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="polyline" points="190,30 190,170 10,100 190,30" stroke="boldgreen"></shape>
</scene>	
~~~~

##### Output
![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/polyline2.png)

~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>
	<canvas height="200" width="200" color="white"></canvas>
	<shape type="polyline" points="190,30 190,170 10,100 190,30" 
	       stroke="black" fill="skyblue" pcolor="185,35 12,100 100,100" polygon="true">
	</shape>
</scene>	
~~~~

##### Output
![alt text](https://github.com/GabrielArSouza/SiR2D/blob/master/common/polyline3.png)

### Complexy images
Complex images can be created using all available primitives

#### Example
~~~~
<?xml version=\"1.0\"?>
<!DOCTYPE PLAY SYSTEM play.dtd>
<scene>

	<canvas height="400" width="400" color="white"></canvas>
	
	<shape type="circle" cx="100" cy="200" r="100" stroke="black"></shape>
	<shape type="circle" cx="100" cy="200" r="90" stroke="black"></shape>
	<shape type="circle" cx="100" cy="200" r="80" stroke="black" fill="black"></shape>
	<shape type="circle" cx="100" cy="200" r="70" stroke="white" fill="black"></shape>
	<shape type="circle" cx="100" cy="200" r="60" stroke="white" fill="skyblue"></shape>
	<shape type="circle" cx="100" cy="200" r="50" stroke="black" fill="skyblue"></shape>
	<shape type="circle" cx="100" cy="200" r="40" stroke="black" fill="red"></shape>
	<shape type="circle" cx="100" cy="200" r="30" stroke="black" fill="red"></shape>
	<shape type="circle" cx="100" cy="200" r="20" stroke="black" fill="yellow"></shape>
	<shape type="circle" cx="100" cy="200" r="10" stroke="black" fill="yellow"></shape>

	<!-- body -->
	<shape type="polyline" points="225,160 225,240 320,240 320,160 225,160"
	       stroke="black" fill="orange" pcolor="250,180" polygon="true">
	</shape>

	<!-- left eye -->
	<shape type="polyline" points="240,170 240,190 260,190 260,170 240,170"
	       stroke="black" fill="white" pcolor="250,175" polygon="true">
	</shape>

	<shape type="polyline" points="240,170 240,175 255,175 255,190 260,190 260,170 240,170"
	       stroke="black" fill="black" pcolor="250,172" polygon="true">
	</shape>

	<!-- right eye -->
	<shape type="polyline" points="240,210 240,230 260,230 260,210 240,210"
	       stroke="black" fill="white" pcolor="250,220" polygon="true">
	</shape>

	<shape type="polyline" points="240,210 240,215 255,215 255,230 260,230 260,210 240,210"
	       stroke="black" fill="black" pcolor="250,212" polygon="true">
	</shape>

	<!-- mouth -->
	<shape type="polyline" points="275,180 275,220 290,210 290,190 275,180"
	       stroke="black" fill="red" pcolor="285,190" polygon="true">
	</shape>

	<!-- left leg -->
	<shape type="polyline" points="321,180 321,190 350,190 350,170 340,170 340,180 321,180"
	       stroke="black"  fill="orange" pcolor="325,188" polygon="true">
	</shape>

	<!-- right leg -->
	<shape type="polyline" points="321,210 321,220 340,220 340,230 350,230 350,210 321,210"
	       stroke="black" fill="orange" pcolor="325,218" polygon="true">
	</shape>

	<!-- left arm -->
	<shape type="polyline" points="275,158 275,145 200,145 200,158 275,158"
	       stroke="black" fill="orange" pcolor="265,155" polygon="true">
	</shape>

	<!-- right arm -->
	<shape type="polyline" points="275,242 275,255 200,255 200,242 275,242"
	       stroke="black" fill="orange" pcolor="265,243" polygon="true">
	</shape>
</scene>
~~~~

###### © 2019 Souza, Gabriel A. Powered by [TinyXML-2](https://github.com/leethomason/tinyxml2)
