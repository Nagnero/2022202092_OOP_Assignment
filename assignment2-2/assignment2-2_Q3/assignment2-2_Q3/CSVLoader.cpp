#include "CSVLoader.h"
#include <iostream>

using namespace std;

CSVLoader::CSVLoader() {
	this->data = NULL;
	this->cols = 0;
	this->rows = 0;
}

CSVLoader::CSVLoader(const char* path) {
	FILE* fin = fopen(path, "r");



	fclose(fin);                                                                                    
}

CSVLoader::~CSVLoader() {

}


float** CSVLoader::getData() const {

}

int CSVLoader::getRows() const {

}

int CSVLoader::getCols() const {

}


void CSVLoader::parse(const char* path) {

}

void CSVLoader::print(void) {

}