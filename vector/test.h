#ifndef TEST_H
#define TEST_H
#include "studentas.h"
#include "ivestis.h"

void testas();

void testoRezultatas(const std::string& testName, bool passed);

void testDefaultKonstruktorius();

void testStreamKonstruktorius();

void testCopyKonstruktorius();

void testCopyAssignmentOperator();

void testMoveKonstruktorius();

void testMoveAssignmentOperator();

void testDestructor();

void testInputOperator();

void testOutputOperator();

#endif