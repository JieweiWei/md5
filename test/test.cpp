/**
 * @file test.cpp
 * @The test file of md5.
 * @author Jiewei Wei
 * @mail weijieweijerry@163.com
 * @github https://github.com/JieweiWei
 * @data Oct 19 2014
 *
 */

#include <iostream>
#include "../src/md5.h"

using std::cout;
using std::endl;

void printMD5(const string& message) {
  cout << "md5(\"" << message << "\") = "
       << MD5(message).toStr() << endl;
}

int main() {
  printMD5("");
  printMD5("a");
  printMD5("abc");
  printMD5("message digest");
  printMD5("abcdefghijklmnopqrstuvwxyz");
  printMD5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	return 0;
}
