/**
 * In order to provide fast and flexible logging, this project uses Cocoa Lumberjack.
 * 
 * The Google Code page has a wealth of documentation if you have any questions.
 * https://github.com/robbiehanson/CocoaLumberjack
 * 
 * Here's what you need to know concerning how logging is setup for IntAirAct:
 * 
 * There are 4 log levels:
 * - Error
 * - Warning
 * - Info
 * - Verbose
 * 
 * In addition to this, there is a Trace flag that can be enabled.
 * When tracing is enabled, it spits out the methods that are being called.
 * 
 * Please note that tracing is separate from the log levels.
 * For example, one could set the log level to warning, and enable tracing.
 * 
 * All logging is asynchronous, except errors.
 * To use logging within your own custom files, follow the steps below.
 * 
 * Step 1:
 * Import this header in your implementation file:
 * 
 * #import "IALogging.h"
 * 
 * Step 2:
 * Define your logging level in your implementation file:
 * 
 * // Log levels: off, error, warn, info, verbose
 * static const int intAirActLogLevel = IA_LOG_LEVEL_VERBOSE;
 * 
 * If you wish to enable tracing, you could do something like this:
 * 
 * // Debug levels: off, error, warn, info, verbose
 * static const int intAirActLogLevel = IA_LOG_LEVEL_INFO | IA_LOG_FLAG_TRACE;
 * 
 * Step 3:
 * Replace your NSLog statements with IALog statements according to the severity of the message.
 * 
 * NSLog(@"Fatal error, no dohickey found!"); -> IALogError(@"Fatal error, no dohickey found!");
 * 
 * IALog works exactly the same as NSLog.
 * This means you can pass it multiple variables just like NSLog.
 **/

#import <CocoaLumberjack/DDLog.h>

// Define logging context for every log message coming from the IA server.
// The logging context can be extracted from the DDLogMessage from within the logging framework,
// which gives loggers, formatters, and filters the ability to optionally process them differently.

#define IA_LOG_CONTEXT 80

// Configure log levels.

#define IA_LOG_FLAG_ERROR   (1 << 0) // 0...00001
#define IA_LOG_FLAG_WARN    (1 << 1) // 0...00010
#define IA_LOG_FLAG_INFO    (1 << 2) // 0...00100
#define IA_LOG_FLAG_VERBOSE (1 << 3) // 0...01000

#define IA_LOG_LEVEL_OFF     0                                              // 0...00000
#define IA_LOG_LEVEL_ERROR   (IA_LOG_LEVEL_OFF   | IA_LOG_FLAG_ERROR)   // 0...00001
#define IA_LOG_LEVEL_WARN    (IA_LOG_LEVEL_ERROR | IA_LOG_FLAG_WARN)    // 0...00011
#define IA_LOG_LEVEL_INFO    (IA_LOG_LEVEL_WARN  | IA_LOG_FLAG_INFO)    // 0...00111
#define IA_LOG_LEVEL_VERBOSE (IA_LOG_LEVEL_INFO  | IA_LOG_FLAG_VERBOSE) // 0...01111
// Setup fine grained logging.
// The first 4 bits are being used by the standard log levels (0 - 3)
// 
// We're going to add tracing, but NOT as a log level.
// Tracing can be turned on and off independently of log level.

#define IA_LOG_FLAG_TRACE   (1 << 4) // 0...10000

// Setup the usual boolean macros.

#define IA_LOG_ERROR   (intAirActLogLevel & IA_LOG_FLAG_ERROR)
#define IA_LOG_WARN    (intAirActLogLevel & IA_LOG_FLAG_WARN)
#define IA_LOG_INFO    (intAirActLogLevel & IA_LOG_FLAG_INFO)
#define IA_LOG_VERBOSE (intAirActLogLevel & IA_LOG_FLAG_VERBOSE)
#define IA_LOG_TRACE   (intAirActLogLevel & IA_LOG_FLAG_TRACE)

// Configure asynchronous logging.
// We follow the default configuration,
// but we reserve a special macro to easily disable asynchronous logging for debugging purposes.

#define IA_LOG_ASYNC_ENABLED   YES

#define IA_LOG_ASYNC_ERROR   ( NO && IA_LOG_ASYNC_ENABLED)
#define IA_LOG_ASYNC_WARN    (YES && IA_LOG_ASYNC_ENABLED)
#define IA_LOG_ASYNC_INFO    (YES && IA_LOG_ASYNC_ENABLED)
#define IA_LOG_ASYNC_VERBOSE (YES && IA_LOG_ASYNC_ENABLED)
#define IA_LOG_ASYNC_TRACE   (YES && IA_LOG_ASYNC_ENABLED)

// Define logging primitives.

#define IALogError(frmt, ...)    LOG_OBJC_MAYBE(IA_LOG_ASYNC_ERROR,   intAirActLogLevel, IA_LOG_FLAG_ERROR,  \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogWarn(frmt, ...)     LOG_OBJC_MAYBE(IA_LOG_ASYNC_WARN,    intAirActLogLevel, IA_LOG_FLAG_WARN,   \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogInfo(frmt, ...)     LOG_OBJC_MAYBE(IA_LOG_ASYNC_INFO,    intAirActLogLevel, IA_LOG_FLAG_INFO,    \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogInfo3(mess)         LOG_OBJC_MAYBE(IA_LOG_ASYNC_INFO,    intAirActLogLevel, IA_LOG_FLAG_INFO,    \
IA_LOG_CONTEXT, @"%@[%p]: %@", THIS_FILE, self, mess)

#define IALogVerbose(frmt, ...)  LOG_OBJC_MAYBE(IA_LOG_ASYNC_VERBOSE, intAirActLogLevel, IA_LOG_FLAG_VERBOSE, \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogVerbose3(mess)      LOG_OBJC_MAYBE(IA_LOG_ASYNC_INFO,    intAirActLogLevel, IA_LOG_FLAG_VERBOSE, \
IA_LOG_CONTEXT, @"%@[%p]: %@", THIS_FILE, self, mess)

#define IALogTrace()             LOG_OBJC_MAYBE(IA_LOG_ASYNC_TRACE,   intAirActLogLevel, IA_LOG_FLAG_TRACE, \
IA_LOG_CONTEXT, @"%@[%p]: %@", THIS_FILE, self, THIS_METHOD)

#define IALogTrace2(frmt, ...)   LOG_OBJC_MAYBE(IA_LOG_ASYNC_TRACE,   intAirActLogLevel, IA_LOG_FLAG_TRACE, \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogTrace3(mess)        LOG_OBJC_MAYBE(IA_LOG_ASYNC_TRACE,   intAirActLogLevel, IA_LOG_FLAG_TRACE, \
IA_LOG_CONTEXT, @"%@[%p]: %@", THIS_FILE, self, mess)


#define IALogCError(frmt, ...)      LOG_C_MAYBE(IA_LOG_ASYNC_ERROR,   intAirActLogLevel, IA_LOG_FLAG_ERROR,   \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogCWarn(frmt, ...)       LOG_C_MAYBE(IA_LOG_ASYNC_WARN,    intAirActLogLevel, IA_LOG_FLAG_WARN,    \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogCInfo(frmt, ...)       LOG_C_MAYBE(IA_LOG_ASYNC_INFO,    intAirActLogLevel, IA_LOG_FLAG_INFO,    \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogCVerbose(frmt, ...)    LOG_C_MAYBE(IA_LOG_ASYNC_VERBOSE, intAirActLogLevel, IA_LOG_FLAG_VERBOSE, \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)

#define IALogCTrace()               LOG_C_MAYBE(IA_LOG_ASYNC_TRACE,   intAirActLogLevel, IA_LOG_FLAG_TRACE, \
IA_LOG_CONTEXT, @"%@[%p]: %@", THIS_FILE, self, __FUNCTION__)

#define IALogCTrace2(frmt, ...)     LOG_C_MAYBE(IA_LOG_ASYNC_TRACE,   intAirActLogLevel, IA_LOG_FLAG_TRACE, \
IA_LOG_CONTEXT, frmt, ##__VA_ARGS__)
