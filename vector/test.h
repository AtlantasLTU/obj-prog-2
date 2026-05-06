#ifndef TEST_H
#define TEST_H

#include "studentas.h"
#include "ivestis.h"

/**
 * @brief Paleidžia visus Studentas klasės testus.
 */
void testas();

/**
 * @brief Išveda testo rezultatą į konsolę.
 * @param testName Testo pavadinimas.
 * @param passed Ar testas pavyko (true) ar ne (false).
 */
void testoRezultatas(const std::string& testName, bool passed);

/** @brief Testuoja numatytąjį konstruktorių. */
void testDefaultKonstruktorius();

/** @brief Testuoja konstruktorių su srautu. */
void testStreamKonstruktorius();

/** @brief Testuoja kopijavimo konstruktorių. */
void testCopyKonstruktorius();

/** @brief Testuoja kopijavimo priskyrimo operatorių. */
void testCopyAssignmentOperator();

/** @brief Testuoja perkėlimo konstruktorių. */
void testMoveKonstruktorius();

/** @brief Testuoja perkėlimo priskyrimo operatorių. */
void testMoveAssignmentOperator();

/** @brief Testuoja destruktorių. */
void testDestructor();

/** @brief Testuoja įvesties operatorių (>>). */
void testInputOperator();

/** @brief Testuoja išvesties operatorių (<<). */
void testOutputOperator();

#endif