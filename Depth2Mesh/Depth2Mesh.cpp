// Depth2Obj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XyzMeshWriter.h"

#include <string>
#include <sstream>

using namespace std;

char fileNameDepth[255], fileNameColor[255], fileNameOutput[255], option;
unsigned char *depthImageData, *colorImageData;
int widthDepth, heightDepth, channelsDepth, widthColor, heightColor, channelsColor;
int hasDepth = 0, hasColor = 0;

MeshWriter* writer;

int loadDepthImage(){
	cout << "Enter Depth Image filename: ";
	cin >> fileNameDepth;

	depthImageData = SOIL_load_image(fileNameDepth, &widthDepth, &heightDepth, &channelsDepth, SOIL_LOAD_L);
	if (0 == depthImageData){
		cerr << "\nAn error occurred while loading your depth image: " << SOIL_last_result() << endl << endl;
		return 0;
	}
	cout << "\nLoaded a " << widthDepth << 'x' << heightDepth << 'x' << channelsDepth << " Depth Image. Size in ubytes: " << widthDepth*heightDepth*channelsDepth*sizeof(unsigned char) << endl << endl;
	return 1;
}

int loadColorImage(){
	cout << "Enter Color Image filename: ";
	cin >> fileNameColor;

	colorImageData = SOIL_load_image(fileNameColor, &widthColor, &heightColor, &channelsColor, SOIL_LOAD_L);
	if (0 == colorImageData){
		cerr << "\nAn error occurred while loading your color image: " << SOIL_last_result() << endl << endl;
		return 0;
	}
	cout << "\nLoaded a " << widthDepth << 'x' << heightColor << 'x' << channelsColor << " Color Image. Size in ubytes: " << widthColor*heightColor*channelsColor*sizeof(unsigned char) << endl << endl;
	return 1;
}

int writeMesh(){
	cout << "Enter the desired name of the output file (Warning: existing files will be rewritten): ";
	cin >> fileNameOutput;

	writer = new XyzMeshWriter();
	int ret = writer->writeDepthToMeshfile(fileNameOutput, depthImageData, colorImageData, true);
	delete writer;
	if (0 == ret){
		cerr << "\nAn error occurred while writing the output file!" << strerror(errno) << endl << endl;
		return 0;
	}
	cout << "File " << fileNameOutput << " saved successfully!" << endl;
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string optionStr;

	cout << "Welcome to Depth2Mesh!\n";
	cout << "Humanity's last, best attempt at converting grayscale depth images to 1:1 meshes and point sets!\n";
	cout << "(try googling if you don't believe this)\n\n";
	cout << "This is a very early implementation, and only exports to .xyz point sets without color info.\n";
	cout << "Press a key to start working...";
	getchar();
	cout << "\n\n";

	do{
		cout << "Loaded Depth Image: " << (hasDepth ? fileNameDepth : "None") << endl;
		cout << "Loaded Depth Image: " << (hasColor ? fileNameDepth : "None") << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << "Select an option:" << endl;
		cout << "(1) Load a grayscale Depth Image" << endl;
		cout << "(2) Load a Color Image" << endl;
		cout << "(3) Export a point set or a mesh from the loaded Depth Image" << endl;
		cout << "(0) Close the program." << endl;
		cout << "--------------------------------------------------------------" << endl;
		cout << "Your Selection:";
		cin >> optionStr;
		//Hey, it works!
		std::istringstream ss(optionStr);
		ss >> option;
		switch (option){
		case '1':
			hasDepth = loadDepthImage();
			break;
		case '2':
			hasColor = loadColorImage();
			break;
		case '3':
			if (hasDepth){
				writeMesh();
			}
			else{
				cout << "\nCannot export! Please load a depth Image First!\n\n";
			}
			break;
		case '0':
			return 0;
			break;
		default:
			cout << "\nInvalid Option!\n" << endl;
			break;
		}

	} while (option != '0');
	return 0;
}