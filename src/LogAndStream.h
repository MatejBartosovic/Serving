#ifndef SERVING_LOGANDSTREAM_H
#define SERVING_LOGANDSTREAM_H

#include <Logger/Logger.h>

#define LOG_STREAM_INFO(stream, msg) {stream << msg << std::endl; LOG_INFO(__FILE__, msg)}
#define LOG_STREAM_WARN(stream, msg) {stream << msg << std::endl; LOG_WARN(__FILE__, msg)}
#define LOG_STREAM_ERROR(stream, msg) {stream << msg << std::endl; LOG_ERROR(__FILE__, msg)}


#endif //SERVING_LOGANDSTREAM_H
