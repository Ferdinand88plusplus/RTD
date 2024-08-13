#include "StatusLog.h"

void saveLog()
{
	std::ofstream logFile(logFileName);
	logFile << logText;
	logFile.close();
}

void coutLog(std::string text)
{
#ifdef SHOW_LOGS
	std::cout << text << '\n';
#endif
}

void rto::log(std::string text)

{
	std::string buf;

	buf += '\n';
	buf += "RTO::Log()\n";
	buf += text + '\n';
	buf += '\n';

	coutLog(buf);
	logText += buf;
}

void rto::error(std::string text)
{
	std::string buf;

	buf += "\n\n";
	buf += "RTO::Error()\n";
	buf += text + '\n';
	buf += "\n\n";
}

void rto::critErr(std::string text)
{
	std::string buf;

	buf += "\n------------\n";
	buf += "RTO::CRITICAL ERROR()\n";
	buf += text;
	buf += "\n------------\n";

	coutLog(buf);
	logText += buf;

	saveLog();
	exit(1);
}

void rtd::log(std::string text)
{
	std::string buf;

	buf += '\n';
	buf += "!!! RTD::Log()\n";
	buf += text + '\n';
	buf += '\n';

	coutLog(buf);
	logText += buf;
}

void rtd::error(std::string text)
{
	std::string buf;

	buf += "\n\n";
	buf += "!!! RTD::Error()\n";
	buf += text + '\n';
	buf += "\n\n";

	coutLog(buf);
	logText += buf;
}

void rtd::critErr(std::string text)
{
	std::string buf;

	buf += "\n------------\n";
	buf += "!!! RTD::CRITICAL ERROR()\n";
	buf += text;
	buf += "\n------------\n";

	coutLog(buf);
	logText += buf;

	saveLog();
	exit(1);
}