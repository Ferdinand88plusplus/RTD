#pragma once

#include "global.h"

static std::string logText;
static const std::string logFileName = "logfile.txt";

void saveLog();
void coutLog(std::string text);

namespace rto {

	void log(std::string text);
	void error(std::string text);
	void critErr(std::string text);
}


namespace rtd {
	void log(std::string text);
	void error(std::string text);
	void critErr(std::string text);
}
