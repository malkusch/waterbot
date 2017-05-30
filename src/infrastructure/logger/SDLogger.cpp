/*
 * SDLogger.cpp
 *
 *  Created on: 30.05.2017
 *      Author: malkusch
 */

#include "SDLogger.h"

#include <FatLib/FatApiConstants.h>
#include <FatLib/FatFile.h>
#include <FatLib/FatFileSystem.h>
#include <limits.h>
#include <stdio.h>
#include <SdCard/SdInfo.h>
#include <SPI.h>

SDLogger::SDLogger(const byte chipSelectPin) :
		chipSelectPin(chipSelectPin) {

	fs = new SdFat();
}

SDLogger::~SDLogger() {
	delete fs;
}

void SDLogger::write(const String& message) {
	file.println(message);
}

void SDLogger::begin(const char* filenameFormat) {
	Logger::setLogger(this);
	if (!fs->begin(chipSelectPin, SPI_FULL_SPEED)) {
		return;
	}
	file = SdFile();
	if (!open(filenameFormat)) {
		return;
	}
}

bool SDLogger::open(const char* filenameFormat) {
	char filename[20];
	for (unsigned long index = 0; index < ULONG_MAX; index++) {
		sprintf(filename, filenameFormat, index);
		if (!fs->exists(filename)) {
			return file.open(filename, O_CREAT | O_WRITE);
		}
	}
	return false;
}

void SDLogger::flush() {
	file.sync();
}
