#include <logging.h>

DataFlowException:: DataFlowException(const char *type, const char *error){
	sprintf(msg, "(%s): %s", type, error);
	Logger::LogEvent(msg);
}

FILE* Logger :: logger = fopen("logger.txt", "w");

void Logger:: LogEvent(const char *event){
	//writes message to log file
	fprintf(logger, "%s\n",event);
}

void Logger:: Finalize(){
	//closes log file
	fclose(logger);
}