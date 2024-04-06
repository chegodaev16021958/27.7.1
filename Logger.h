#pragma once

#include <iostream>
#include <fstream>
#include <shared_mutex>
#include <string>

class Logger
{
private:
	std::fstream iofile;
	std::shared_mutex shared_mutex;
public:
	Logger()
	{
		std::fstream iofile("log.txt", std::ios::in | std::ios::out | std::ios::app);
		if (!iofile)
		{
			std::cerr << "log.txt could not be opened for writing!" << std::endl;
		}
	}
	~Logger()
	{
		iofile.close();
	}

	void writeLine(const std::string& text);
	void readLine(std::string& text, int numberOfLine);
};

