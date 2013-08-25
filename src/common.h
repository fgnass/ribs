/*!
 * ribs
 * Copyright (c) 2013 Nicolas Gryman <ngryman@gmail.com>
 * MIT Licensed
 */

#ifndef __RIBS_COMMON_H__
#define __RIBS_COMMON_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>
#include <node_version.h>

#include <fcntl.h>
#include <sstream>
#include <string>

#include "leptonica/allheaders.h"
#include "nan.h"

inline static std::string FromV8String(v8::Local<v8::Value> v8Str) {
	char* cstr = NanFromV8String(v8Str);
	std::string cppstr(cstr);
	delete[] cstr;
	return cppstr;
}

static std::string RibsError(const char* message, const char* description) {
	std::ostringstream stream(message);
	stream << ": " << description << ".";
	return stream.str();
}

#endif