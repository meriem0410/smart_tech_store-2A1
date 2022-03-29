/*
 * QR Code generator demo (C++)
 *
 * Run this command-line program with no arguments. The program computes a bunch of demonstration
 * QR Codes and prints them to the console. Also, the SVG code for one QR Code is printed as a sample.
 *
 * Copyright (c) Project Nayuki. (MIT License)
 * https://www.nayuki.io/page/qr-code-generator-library
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "qrcode.h"

using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;


// Function prototypes
static void doBasicDemo();
static void doVarietyDemo();
static void doSegmentDemo();
static void doMaskDemo();
static void printQr(const QrCode &qr);


// The main application program.
int main2() {
    doBasicDemo();
    doVarietyDemo();
    doSegmentDemo();
    doMaskDemo();
    return EXIT_SUCCESS;
}



/*---- Demo suite ----*/

// Creates a single QR Code, then prints it to the console.
static void doBasicDemo() {
    const char *text = "Hello, world!";              // User-supplied text
    const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW;  // Error correction level

    // Make and print the QR Code symbol
    const QrCode qr = QrCode::encodeText(text, errCorLvl);
    printQr(qr);
    std::cout << qr.toSvgString(4) << std::endl;
}


