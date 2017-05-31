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

SDLogger::SDLogger(const char* filenameFormat, const byte chipSelectPin) :
		filenameFormat(filenameFormat), chipSelectPin(chipSelectPin) {

	fs = new SdFat();
}

SDLogger::~SDLogger() {
	file.close();
	delete fs;
}

void SDLogger::write(const String& message) {
	file.println(message);
	if (file.getWriteError()) {
		if (initCard()) {
			file.clearWriteError();
			file.println(message);
		}
	}
}

void SDLogger::begin() {
	Logger::setLogger(this);
	initCard();
}

bool SDLogger::initCard() {
	file.close();
	if (!fs->begin(chipSelectPin)) {
		return false;
	}
	if (!openNewLogFile()) {
		return false;
	}
	return true;
}

bool SDLogger::openNewLogFile() {
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
