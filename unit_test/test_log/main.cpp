
#include <log/log.h>

using namespace cvl;

int main(int argc, char** argv)
{
	Log(Log::LOG_INFO) << "INFO " << 0 << "  " << 0.99 << Log::End();
	Log(Log::LOG_WARN) << "WARN " << 1 << "  " << 0.99 << Log::End();
	Log(Log::LOG_ERROR) << "ERROR " << 2 << "  " << 0.99 << Log::End();
	return 0;
}