# Note: V2 (still) coming soon with several improvements (as of 2020)
## Will definitely replace soil and glut with something else, also change this into a cmake project (ugh).

# Depth2Mesh
A tool to convert Grayscale depth maps to various mesh/point cloud formats. I began development on this because I couldn't find a tool or library to get a nice meaty point cloud off depth images, using photoshop/maya/etc usually ended up discarding a lot of info from the depth image.

- In order to build it you need to properly link against:
   - GLUT - The OpenGL Utility Toolkit (tested with freeglut 3.0.0-1)
   - SOIL - Simple Opengl Image Loader (from http://www.lonesock.net/soil.html)
I have tested this on windows with Visual Studio 2013, but it should work with other compiler/toolchains granted that you write the correct makefile. I tried to keep the code portable.

This is very barebones but the underlying framework is flexible, I'll work towards generalizing and improving this tool.
