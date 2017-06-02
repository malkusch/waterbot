/*
 * Valve.h
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#pragma once

namespace waterbot {
namespace model {

class Valve {
	friend class Pot;
public:
	virtual ~Valve() {
	}
	;
protected:
	virtual void open() = 0;
	virtual void close() = 0;

};

}
}
