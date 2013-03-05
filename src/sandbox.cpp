/*
 * =====================================================================================
 *
 *       Filename:  sandbox.cpp
 *
 *    Description:  TouchNet 2 Sandbox
 *
 *        Version:  0.1
 *        Created:  05/03/13 14:44:29
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Bugl <Daniel.Bugl@touchlay.com>
 *   Organization:  TouchLay
 *
 * =====================================================================================
 */

// Headers
#include "sandbox.h"

Json::Value Sandbox::parseJSON(std::string result) {
 Json::Reader jReader;
 Json::Value jRoot;
 try {
  if (!jReader.parse(result, jRoot, false)) {
   #ifdef DEBUG
   std::cout << "[DEBUG] [sandbox_json] Invalid JSON (" << result << ")." << std::endl;
   #endif
   jReader.parse("{\"type\": \"error\", \"msg\": \"Invalid JSON\"}", jRoot, false);
  }
 } catch (const std::exception &e) {
  std::cout << "[ERROR] [sandbox     ] Caught an exception: " << e.what() << std::endl;
  jReader.parse("{\"type\": \"error\", \"msg\": \"Exception caught\"}", jRoot, false);
 } catch (...) {
  std::cout << "[ERROR] [sandbox     ] Caught an unknown exception." << std::endl;
  jReader.parse("{\"type\": \"error\", \"msg\": \"Exception caught\"}", jRoot, false);
 }
 return jRoot;
}

std::string Sandbox::exec(std::string cmd) {
 FILE *pipe = popen(cmd.c_str(), "r");
 if (!pipe) return "{\"type\": \"error\", \"msg\": \"Pipe failed\"}";
 char buffer[256];
 std::string rbuffer = "";
 while (!feof(pipe)) {
  if (fgets(buffer, 256, pipe) != NULL) rbuffer += buffer;
 }
 pclose(pipe);
 return rbuffer;
}

Json::Value Sandbox::run(std::string cmd, std::string args) {
 std::string buf = cmd + " " + args;
 #ifdef DEBUG
 std::cout << "[DEBUG] [sandbox     ] Running '" << cmd << "' with '" << args << "'..." << std::endl;
 #endif
 std::string result = exec(buf);
 #ifdef DEBUG
 std::cout << "[DEBUG] [sandbox     ] Result: " << result << std::endl;
 #endif
 return parseJSON(result);
}

Sandbox::Sandbox() {
 std::cout << "[TEST ] [sandbox     ] Starting sandbox test..." << std::endl;
 Json::Value result = run("./bin/sb_test", "{}");
 if (result.isMember("test")) std::cout << "[TEST ] [sandbox     ] JSON Test: " << result.get("test", result) << std::endl;
 else std::cout << "[TEST ] [sandbox     ] JSON Test failed!" << std::endl;
}
